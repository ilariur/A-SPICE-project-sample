#include "../src/day_night_controller.hpp"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

namespace aspice {

class TestSink final : public CanFrameSink {
public:
    void send(const CanFrame& frame) override {
        frames.push_back(frame);
    }

    void clear() {
        frames.clear();
    }

    std::vector<CanFrame> frames;
};

CanFrame makeLuminance(std::uint16_t lux) {
    CanFrame frame{};
    frame.id = CanIds::kLuminanceResponse;
    frame.dlc = 2;
    writeU16(frame.data, 0, lux);
    return frame;
}

CanFrame makeQuery(std::uint8_t clientId) {
    CanFrame frame{};
    frame.id = CanIds::kStateQueryRequest;
    frame.dlc = 1;
    frame.data[0] = clientId;
    return frame;
}

CanFrame makeSubscription(std::uint8_t clientId, SubscriptionAction action) {
    CanFrame frame{};
    frame.id = CanIds::kSubscriptionControl;
    frame.dlc = 2;
    frame.data[0] = clientId;
    frame.data[1] = static_cast<std::uint8_t>(action);
    return frame;
}

void test_poll_schedule() {
    TestSink sink;
    DayNightController controller(sink);

    controller.tick(0);
    assert(sink.frames.size() == 1);
    assert(sink.frames[0].id == CanIds::kLuminancePollRequest);

    sink.clear();
    controller.tick(4999);
    assert(sink.frames.empty());

    controller.tick(5000);
    assert(sink.frames.size() == 1);
    assert(sink.frames[0].id == CanIds::kLuminancePollRequest);
}

void test_query_response() {
    TestSink sink;
    DayNightController controller(sink);

    controller.onFrame(makeLuminance(1600), 100);
    sink.clear();
    controller.onFrame(makeQuery(0x33), 2100);

    assert(sink.frames.size() == 1);
    assert(sink.frames[0].id == CanIds::kStateQueryResponse);
    assert(sink.frames[0].data[0] == 0x33);
    assert(sink.frames[0].data[1] == static_cast<std::uint8_t>(DayNightState::Day));
    assert(readU16(sink.frames[0].data, 2) == 2);
}

void test_registration_and_notification() {
    TestSink sink;
    DayNightController controller(sink);

    controller.onFrame(makeSubscription(0x44, SubscriptionAction::Subscribe), 0);
    assert(sink.frames.size() == 1);
    assert(sink.frames[0].id == CanIds::kSubscriptionStatus);
    assert(sink.frames[0].data[1] == static_cast<std::uint8_t>(SubscriptionStatus::Ok));

    sink.clear();
    controller.onFrame(makeLuminance(2000), 10);
    assert(controller.state() == DayNightState::Day);
    assert(sink.frames.empty());

    controller.onFrame(makeLuminance(500), 20);
    assert(controller.state() == DayNightState::Night);
    assert(sink.frames.size() == 1);
    assert(sink.frames[0].id == CanIds::kStateChangeNotification);
    assert(sink.frames[0].data[0] == 0x44);
    assert(sink.frames[0].data[1] == static_cast<std::uint8_t>(DayNightState::Night));
    assert(sink.frames[0].data[2] == static_cast<std::uint8_t>(DayNightState::Day));
}

void test_unsubscribe() {
    TestSink sink;
    DayNightController controller(sink);

    controller.onFrame(makeSubscription(0x51, SubscriptionAction::Subscribe), 0);
    controller.onFrame(makeSubscription(0x51, SubscriptionAction::Unsubscribe), 5);
    assert(sink.frames.back().id == CanIds::kSubscriptionStatus);
    assert(sink.frames.back().data[1] == static_cast<std::uint8_t>(SubscriptionStatus::Ok));

    sink.clear();
    controller.onFrame(makeLuminance(2000), 10);
    controller.onFrame(makeLuminance(500), 20);
    assert(controller.state() == DayNightState::Night);
    assert(sink.frames.empty() || sink.frames[0].id != CanIds::kStateChangeNotification);
}

void test_timeout_fault_and_recovery() {
    TestSink sink;
    DayNightController controller(sink);

    controller.onFrame(makeSubscription(0x60, SubscriptionAction::Subscribe), 0);
    controller.tick(0);
    controller.onFrame(makeLuminance(1700), 10);
    assert(controller.state() == DayNightState::Day);

    sink.clear();
    controller.tick(5000);
    assert(sink.frames.size() == 1);
    assert(sink.frames[0].id == CanIds::kLuminancePollRequest);

    sink.clear();
    controller.tick(11000);
    assert(controller.state() == DayNightState::Fault);
    assert(sink.frames.size() == 3);
    assert(sink.frames[0].id == CanIds::kDiagnosticFault);
    assert(sink.frames[0].data[0] == static_cast<std::uint8_t>(FaultCode::LuminanceResponseTimeout));
    assert(sink.frames[0].data[1] == 1U);
    assert(sink.frames[0].data[2] == static_cast<std::uint8_t>(DayNightState::Day));
    assert(sink.frames[0].data[3] == static_cast<std::uint8_t>(DayNightState::Fault));
    assert(sink.frames[1].id == CanIds::kStateChangeNotification);
    assert(sink.frames[1].data[1] == static_cast<std::uint8_t>(DayNightState::Fault));
    assert(sink.frames[1].data[2] == static_cast<std::uint8_t>(DayNightState::Day));
    assert(sink.frames[2].id == CanIds::kLuminancePollRequest);

    sink.clear();
    controller.onFrame(makeQuery(0x61), 11100);
    assert(sink.frames.size() == 1);
    assert(sink.frames[0].id == CanIds::kStateQueryResponse);
    assert(sink.frames[0].data[1] == static_cast<std::uint8_t>(DayNightState::Fault));

    sink.clear();
    controller.onFrame(makeLuminance(500), 11200);
    assert(controller.state() == DayNightState::Night);
    assert(sink.frames.size() == 2);
    assert(sink.frames[0].id == CanIds::kStateChangeNotification);
    assert(sink.frames[0].data[1] == static_cast<std::uint8_t>(DayNightState::Night));
    assert(sink.frames[0].data[2] == static_cast<std::uint8_t>(DayNightState::Fault));
    assert(sink.frames[1].id == CanIds::kDiagnosticFault);
    assert(sink.frames[1].data[0] == static_cast<std::uint8_t>(FaultCode::LuminanceResponseTimeout));
    assert(sink.frames[1].data[1] == 0U);
    assert(sink.frames[1].data[2] == static_cast<std::uint8_t>(DayNightState::Fault));
    assert(sink.frames[1].data[3] == static_cast<std::uint8_t>(DayNightState::Night));
}

}  // namespace aspice

int main() {
    using namespace aspice;

    test_poll_schedule();
    test_query_response();
    test_registration_and_notification();
    test_unsubscribe();
    test_timeout_fault_and_recovery();

    std::cout << "All day/night controller tests passed.\n";
    return 0;
}