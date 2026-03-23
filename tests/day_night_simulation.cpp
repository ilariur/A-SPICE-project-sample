#include "../src/day_night_controller.hpp"

#include <cstdint>
#include <iostream>
#include <string_view>
#include <vector>

namespace aspice {

class SimulatedCanBus final : public CanFrameSink {
public:
    explicit SimulatedCanBus(ControllerConfig config = {}) : controller(*this, config) {}

    void send(const CanFrame& frame) override {
        transmittedFrames.push_back(frame);
    }

    void clearFrames() {
        transmittedFrames.clear();
    }

    void advanceTo(TimestampMs timestampMs) {
        nowMs = timestampMs;
        controller.tick(nowMs);
    }

    void injectLuminance(std::uint16_t lux) {
        CanFrame frame{};
        frame.id = CanIds::kLuminanceResponse;
        frame.dlc = 2;
        writeU16(frame.data, 0, lux);
        controller.onFrame(frame, nowMs);
    }

    void injectRawFrame(const CanFrame& frame) {
        controller.onFrame(frame, nowMs);
    }

    void query(std::uint8_t clientId) {
        CanFrame frame{};
        frame.id = CanIds::kStateQueryRequest;
        frame.dlc = 1;
        frame.data[0] = clientId;
        controller.onFrame(frame, nowMs);
    }

    void subscribe(std::uint8_t clientId) {
        CanFrame frame{};
        frame.id = CanIds::kSubscriptionControl;
        frame.dlc = 2;
        frame.data[0] = clientId;
        frame.data[1] = static_cast<std::uint8_t>(SubscriptionAction::Subscribe);
        controller.onFrame(frame, nowMs);
    }

    void unsubscribe(std::uint8_t clientId) {
        CanFrame frame{};
        frame.id = CanIds::kSubscriptionControl;
        frame.dlc = 2;
        frame.data[0] = clientId;
        frame.data[1] = static_cast<std::uint8_t>(SubscriptionAction::Unsubscribe);
        controller.onFrame(frame, nowMs);
    }

    [[nodiscard]] std::size_t countFrames(std::uint16_t id) const {
        std::size_t count = 0;
        for (const auto& frame : transmittedFrames) {
            if (frame.id == id) {
                ++count;
            }
        }
        return count;
    }

    [[nodiscard]] const CanFrame* lastFrame(std::uint16_t id) const {
        for (auto it = transmittedFrames.rbegin(); it != transmittedFrames.rend(); ++it) {
            if (it->id == id) {
                return &(*it);
            }
        }
        return nullptr;
    }

    DayNightController controller;
    TimestampMs nowMs{0};
    std::vector<CanFrame> transmittedFrames;
};

struct ScenarioResult {
    std::string_view name;
    bool passed{true};
    std::vector<std::string> failures;
};

ScenarioResult makeScenarioResult(std::string_view name) {
    ScenarioResult result{};
    result.name = name;
    return result;
}

void expect(ScenarioResult& result, bool condition, std::string message) {
    if (!condition) {
        result.passed = false;
        result.failures.push_back(std::move(message));
    }
}

ScenarioResult scenario_poll_and_query_path() {
    ScenarioResult result = makeScenarioResult("IT-001/IT-003 Poll and query path");
    SimulatedCanBus bus;

    bus.advanceTo(0);
    expect(result, bus.countFrames(CanIds::kLuminancePollRequest) == 1, "Expected initial poll request at t=0.");

    bus.injectLuminance(2000);
    expect(result, bus.controller.state() == DayNightState::Day, "Expected DAY after first high luminance sample.");

    bus.clearFrames();
    bus.query(0x31);
    const CanFrame* response = bus.lastFrame(CanIds::kStateQueryResponse);
    expect(result, response != nullptr, "Expected state query response frame.");
    if (response != nullptr) {
        expect(result, response->data[0] == 0x31, "Expected query response client id 0x31.");
        expect(result, response->data[1] == static_cast<std::uint8_t>(DayNightState::Day), "Expected query response state DAY.");
    }

    return result;
}

ScenarioResult scenario_subscription_and_transition() {
    ScenarioResult result = makeScenarioResult("IT-002 Multi-subscriber transition");
    SimulatedCanBus bus;

    bus.subscribe(0x21);
    bus.subscribe(0x22);
    expect(result, bus.countFrames(CanIds::kSubscriptionStatus) == 2, "Expected two subscription acknowledgements.");

    bus.clearFrames();
    bus.injectLuminance(2000);
    bus.injectLuminance(500);

    expect(result, bus.controller.state() == DayNightState::Night, "Expected NIGHT after crossing low threshold.");
    expect(result, bus.countFrames(CanIds::kStateChangeNotification) == 2, "Expected one notification per registered subscriber.");

    const CanFrame* lastNotification = bus.lastFrame(CanIds::kStateChangeNotification);
    expect(result, lastNotification != nullptr, "Expected at least one state-change notification.");
    if (lastNotification != nullptr) {
        expect(result,
               lastNotification->data[1] == static_cast<std::uint8_t>(DayNightState::Night),
               "Expected notified state NIGHT.");
        expect(result,
               lastNotification->data[2] == static_cast<std::uint8_t>(DayNightState::Day),
               "Expected previous state DAY in notification.");
    }

    return result;
}

ScenarioResult scenario_unsubscribe_and_no_notification() {
    ScenarioResult result = makeScenarioResult("IT-005 Unsubscribe suppresses notification");
    SimulatedCanBus bus;

    bus.subscribe(0x40);
    bus.subscribe(0x41);
    bus.unsubscribe(0x40);
    expect(result, bus.controller.subscriberCount() == 1, "Expected one remaining subscriber after unsubscribe.");

    bus.clearFrames();
    bus.injectLuminance(2000);
    bus.injectLuminance(500);

    expect(result, bus.countFrames(CanIds::kStateChangeNotification) == 1, "Expected one notification after unsubscribe.");
    const CanFrame* notification = bus.lastFrame(CanIds::kStateChangeNotification);
    expect(result, notification != nullptr, "Expected notification for remaining subscriber.");
    if (notification != nullptr) {
        expect(result, notification->data[0] == 0x41, "Expected notification only for client 0x41.");
    }

    return result;
}

ScenarioResult scenario_steady_day_qualification() {
    ScenarioResult result = makeScenarioResult("QT-001 Steady daylight 60s");
    SimulatedCanBus bus;

    bus.advanceTo(0);
    bus.injectLuminance(2000);
    bus.clearFrames();

    for (TimestampMs timestamp = 5000; timestamp <= 60000; timestamp += 5000) {
        bus.advanceTo(timestamp);
        expect(result,
               bus.countFrames(CanIds::kLuminancePollRequest) == 1,
               "Expected exactly one poll request at each 5 second boundary.");
        bus.clearFrames();
        bus.injectLuminance(2200);
        expect(result, bus.controller.state() == DayNightState::Day, "Expected state to remain DAY during steady daylight.");
        expect(result,
               bus.countFrames(CanIds::kStateChangeNotification) == 0,
               "Expected no state-change notification during steady daylight.");
    }

    return result;
}

ScenarioResult scenario_steady_night_qualification() {
    ScenarioResult result = makeScenarioResult("QT-002 Steady night 60s");
    SimulatedCanBus bus;

    bus.advanceTo(0);
    bus.injectLuminance(200);
    bus.clearFrames();

    for (TimestampMs timestamp = 5000; timestamp <= 60000; timestamp += 5000) {
        bus.advanceTo(timestamp);
        expect(result,
               bus.countFrames(CanIds::kLuminancePollRequest) == 1,
               "Expected exactly one poll request at each 5 second boundary.");
        bus.clearFrames();
        bus.injectLuminance(300);
        expect(result, bus.controller.state() == DayNightState::Night, "Expected state to remain NIGHT during steady darkness.");
        expect(result,
               bus.countFrames(CanIds::kStateChangeNotification) == 0,
               "Expected no state-change notification during steady darkness.");
    }

    return result;
}

ScenarioResult scenario_dusk_transition_and_query() {
    ScenarioResult result = makeScenarioResult("QT-003/QT-006 Dusk transition and query");
    SimulatedCanBus bus;

    bus.subscribe(0x55);
    bus.clearFrames();

    bus.injectLuminance(2000);
    expect(result, bus.controller.state() == DayNightState::Day, "Expected initial DAY state for dusk scenario.");

    bus.clearFrames();
    bus.advanceTo(5000);
    bus.injectLuminance(700);

    expect(result, bus.controller.state() == DayNightState::Night, "Expected NIGHT after dusk threshold crossing.");
    expect(result, bus.countFrames(CanIds::kStateChangeNotification) == 1, "Expected one notification for dusk transition.");

    bus.clearFrames();
    bus.query(0x56);
    const CanFrame* response = bus.lastFrame(CanIds::kStateQueryResponse);
    expect(result, response != nullptr, "Expected query response after dusk transition.");
    if (response != nullptr) {
        expect(result,
               response->data[1] == static_cast<std::uint8_t>(DayNightState::Night),
               "Expected NIGHT in query response after dusk transition.");
    }

    return result;
}

ScenarioResult scenario_dawn_transition() {
    ScenarioResult result = makeScenarioResult("QT-004 Dawn transition");
    SimulatedCanBus bus;

    bus.subscribe(0x61);
    bus.clearFrames();
    bus.injectLuminance(100);
    expect(result, bus.controller.state() == DayNightState::Night, "Expected initial NIGHT state for dawn scenario.");

    bus.clearFrames();
    bus.advanceTo(5000);
    bus.injectLuminance(1600);

    expect(result, bus.controller.state() == DayNightState::Day, "Expected DAY after dawn threshold crossing.");
    expect(result, bus.countFrames(CanIds::kStateChangeNotification) == 1, "Expected one notification for dawn transition.");

    return result;
}

ScenarioResult scenario_duplicate_and_full_registration() {
    ScenarioResult result = makeScenarioResult("IT-004 Registration edge handling");
    ControllerConfig config{};
    config.maxSubscribers = 2;
    SimulatedCanBus bus(config);

    bus.subscribe(0x01);
    bus.subscribe(0x01);
    bus.subscribe(0x02);
    bus.subscribe(0x03);

    expect(result, bus.controller.subscriberCount() == 2, "Expected subscriber count to remain bounded at 2.");
    expect(result, bus.countFrames(CanIds::kSubscriptionStatus) == 4, "Expected one acknowledgement per registration request.");

    const CanFrame& duplicateAck = bus.transmittedFrames[1];
    const CanFrame& fullAck = bus.transmittedFrames[3];
    expect(result,
           duplicateAck.data[1] == static_cast<std::uint8_t>(SubscriptionStatus::AlreadyRegistered),
           "Expected duplicate subscription status ALREADY_REGISTERED.");
    expect(result,
           fullAck.data[1] == static_cast<std::uint8_t>(SubscriptionStatus::Full),
           "Expected overflow subscription status FULL.");

    return result;
}

ScenarioResult scenario_malformed_frames_are_ignored() {
    ScenarioResult result = makeScenarioResult("IT-006 Malformed frame handling");
    SimulatedCanBus bus;

    bus.injectLuminance(2000);
    expect(result, bus.controller.state() == DayNightState::Day, "Expected baseline DAY state before malformed frame checks.");

    bus.clearFrames();

    CanFrame malformedQuery{};
    malformedQuery.id = CanIds::kStateQueryRequest;
    malformedQuery.dlc = 0;
    bus.injectRawFrame(malformedQuery);

    CanFrame malformedSubscription{};
    malformedSubscription.id = CanIds::kSubscriptionControl;
    malformedSubscription.dlc = 1;
    malformedSubscription.data[0] = 0x70;
    bus.injectRawFrame(malformedSubscription);

    CanFrame unknownFrame{};
    unknownFrame.id = 0x7FF;
    unknownFrame.dlc = 8;
    bus.injectRawFrame(unknownFrame);

    expect(result, bus.transmittedFrames.empty(), "Expected no transmitted frames in response to malformed or unknown frames.");
    expect(result, bus.controller.state() == DayNightState::Day, "Expected state to remain unchanged after malformed or unknown frames.");

    return result;
}

ScenarioResult scenario_delayed_luminance_response() {
    ScenarioResult result = makeScenarioResult("IT-007 Delayed luminance response");
    SimulatedCanBus bus;

    bus.advanceTo(0);
    bus.clearFrames();
    bus.advanceTo(5000);
    expect(result, bus.countFrames(CanIds::kLuminancePollRequest) == 1, "Expected second poll request at 5 seconds before any response.");

    bus.clearFrames();
    bus.advanceTo(10000);
    expect(result, bus.countFrames(CanIds::kLuminancePollRequest) == 1, "Expected third poll request at 10 seconds before delayed response.");
    expect(result, bus.controller.state() == DayNightState::Fault, "Expected FAULT state after startup response timeout.");

    bus.clearFrames();
    bus.query(0x71);
    const CanFrame* faultResponse = bus.lastFrame(CanIds::kStateQueryResponse);
    expect(result, faultResponse != nullptr, "Expected query response while waiting for delayed luminance response.");
    if (faultResponse != nullptr) {
        expect(result,
               faultResponse->data[1] == static_cast<std::uint8_t>(DayNightState::Fault),
               "Expected FAULT state after response timeout and before delayed luminance response arrives.");
    }

    bus.clearFrames();
    bus.advanceTo(12000);
    bus.injectLuminance(1800);
    expect(result, bus.controller.state() == DayNightState::Day, "Expected delayed luminance response to establish DAY state.");
    expect(result, bus.countFrames(CanIds::kStateChangeNotification) == 0, "Expected no notification on fault recovery without subscribers.");

    return result;
}

ScenarioResult scenario_missing_response_timeout_behavior() {
    ScenarioResult result = makeScenarioResult("QT-009 Missing response timeout-style behavior");
    SimulatedCanBus bus;

    bus.injectLuminance(1700);
    expect(result, bus.controller.state() == DayNightState::Day, "Expected initial DAY state before timeout-style scenario.");

    bus.clearFrames();
    bus.advanceTo(5000);
    expect(result, bus.countFrames(CanIds::kLuminancePollRequest) == 2, "Expected poll requests to continue even when no luminance response is received.");

    bus.clearFrames();
    bus.advanceTo(10000);
    expect(result, bus.countFrames(CanIds::kLuminancePollRequest) == 1, "Expected another poll request after one missed response interval.");

    bus.clearFrames();
    bus.advanceTo(15000);
    expect(result, bus.countFrames(CanIds::kLuminancePollRequest) == 1, "Expected continued polling after repeated missed responses.");
    expect(result, bus.controller.state() == DayNightState::Fault, "Expected FAULT state after repeated missing-response intervals.");

    bus.clearFrames();
    bus.query(0x72);
    const CanFrame* response = bus.lastFrame(CanIds::kStateQueryResponse);
    expect(result, response != nullptr, "Expected query response during missing-response interval.");
    if (response != nullptr) {
        expect(result,
               response->data[1] == static_cast<std::uint8_t>(DayNightState::Fault),
               "Expected FAULT state in query response during missing-response interval.");
    }

    return result;
}

    ScenarioResult scenario_diagnostic_fault_reporting() {
        ScenarioResult result = makeScenarioResult("IT-008/QT-010 Diagnostic fault message on FAULT enter and clear");
        SimulatedCanBus bus;

        bus.injectLuminance(1700);
        expect(result, bus.controller.state() == DayNightState::Day, "Expected initial DAY state before diagnostic scenario.");

        bus.clearFrames();
        bus.advanceTo(5000);
        bus.clearFrames();
        bus.advanceTo(11000);

        const CanFrame* activeDiagnostic = bus.lastFrame(CanIds::kDiagnosticFault);
        expect(result, activeDiagnostic != nullptr, "Expected diagnostic fault frame when timeout drives FAULT state.");
        if (activeDiagnostic != nullptr) {
         expect(result,
             activeDiagnostic->data[0] == static_cast<std::uint8_t>(FaultCode::LuminanceResponseTimeout),
             "Expected timeout fault code in active diagnostic frame.");
         expect(result, activeDiagnostic->data[1] == 1U, "Expected active flag set in diagnostic fault frame.");
         expect(result,
             activeDiagnostic->data[2] == static_cast<std::uint8_t>(DayNightState::Day),
             "Expected previous state DAY in active diagnostic frame.");
         expect(result,
             activeDiagnostic->data[3] == static_cast<std::uint8_t>(DayNightState::Fault),
             "Expected current state FAULT in active diagnostic frame.");
        }

        bus.clearFrames();
        bus.injectLuminance(2000);

        const CanFrame* clearedDiagnostic = bus.lastFrame(CanIds::kDiagnosticFault);
        expect(result, clearedDiagnostic != nullptr, "Expected diagnostic fault clear frame after recovery luminance.");
        if (clearedDiagnostic != nullptr) {
         expect(result,
             clearedDiagnostic->data[0] == static_cast<std::uint8_t>(FaultCode::LuminanceResponseTimeout),
             "Expected timeout fault code in clear diagnostic frame.");
         expect(result, clearedDiagnostic->data[1] == 0U, "Expected cleared flag in diagnostic clear frame.");
         expect(result,
             clearedDiagnostic->data[2] == static_cast<std::uint8_t>(DayNightState::Fault),
             "Expected previous state FAULT in diagnostic clear frame.");
         expect(result,
             clearedDiagnostic->data[3] == static_cast<std::uint8_t>(DayNightState::Day),
             "Expected current state DAY in diagnostic clear frame.");
        }

        return result;
    }

}  // namespace aspice

int main() {
    using namespace aspice;

    const std::vector<ScenarioResult> results{
        scenario_poll_and_query_path(),
        scenario_subscription_and_transition(),
        scenario_unsubscribe_and_no_notification(),
        scenario_duplicate_and_full_registration(),
        scenario_malformed_frames_are_ignored(),
        scenario_delayed_luminance_response(),
        scenario_steady_day_qualification(),
        scenario_steady_night_qualification(),
        scenario_dusk_transition_and_query(),
        scenario_dawn_transition(),
        scenario_missing_response_timeout_behavior(),
        scenario_diagnostic_fault_reporting(),
    };

    std::size_t passed = 0;
    for (const auto& result : results) {
        std::cout << (result.passed ? "PASS" : "FAIL") << " - " << result.name << '\n';
        if (!result.passed) {
            for (const auto& failure : result.failures) {
                std::cout << "  * " << failure << '\n';
            }
        } else {
            ++passed;
        }
    }

    std::cout << "Summary: " << passed << "/" << results.size() << " scenarios passed.\n";
    return passed == results.size() ? 0 : 1;
}