#include "day_night_controller.hpp"

#include <iomanip>
#include <iostream>
#include <vector>

namespace aspice {

class RecordingSink final : public CanFrameSink {
public:
    void send(const CanFrame& frame) override {
        frames.push_back(frame);
    }

    std::vector<CanFrame> frames;
};

void printFrame(const CanFrame& frame) {
    std::cout << "CAN 0x" << std::hex << frame.id << std::dec << " dlc=" << static_cast<int>(frame.dlc) << " data=";
    for (std::size_t index = 0; index < frame.dlc; ++index) {
        std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(frame.data[index]) << ' ';
    }
    std::cout << std::dec << '\n';
}

}  // namespace aspice

int main() {
    using namespace aspice;

    RecordingSink sink;
    DayNightController controller(sink);

    controller.tick(0);

    CanFrame subscribe{};
    subscribe.id = CanIds::kSubscriptionControl;
    subscribe.dlc = 2;
    subscribe.data[0] = 0x21;
    subscribe.data[1] = static_cast<std::uint8_t>(SubscriptionAction::Subscribe);
    controller.onFrame(subscribe, 1);

    CanFrame luminanceDay{};
    luminanceDay.id = CanIds::kLuminanceResponse;
    luminanceDay.dlc = 2;
    writeU16(luminanceDay.data, 0, 2000);
    controller.onFrame(luminanceDay, 10);

    CanFrame query{};
    query.id = CanIds::kStateQueryRequest;
    query.dlc = 1;
    query.data[0] = 0x10;
    controller.onFrame(query, 20);

    controller.tick(5000);

    CanFrame luminanceNight{};
    luminanceNight.id = CanIds::kLuminanceResponse;
    luminanceNight.dlc = 2;
    writeU16(luminanceNight.data, 0, 500);
    controller.onFrame(luminanceNight, 5010);

    for (const auto& frame : sink.frames) {
        printFrame(frame);
    }

    std::cout << "Current state: " << toString(controller.state()) << '\n';
    std::cout << "Subscribers: " << controller.subscriberCount() << '\n';

    return 0;
}