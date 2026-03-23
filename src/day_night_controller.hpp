#pragma once

#include "can_protocol.hpp"

#include <array>
#include <cstddef>
#include <cstdint>

namespace aspice {

struct ControllerConfig {
    std::uint16_t dayThresholdLux{1500};
    std::uint16_t nightThresholdLux{800};
    TimestampMs pollIntervalMs{5000};
    TimestampMs responseTimeoutMs{6000};
    std::size_t maxSubscribers{8};
};

class CanFrameSink {
public:
    virtual ~CanFrameSink() = default;
    virtual void send(const CanFrame& frame) = 0;
};

class DayNightController {
public:
    explicit DayNightController(CanFrameSink& sink, ControllerConfig config = {});

    void tick(TimestampMs nowMs);
    void onFrame(const CanFrame& frame, TimestampMs nowMs);

    [[nodiscard]] DayNightState state() const noexcept;
    [[nodiscard]] std::uint16_t lastLuminanceLux() const noexcept;
    [[nodiscard]] std::size_t subscriberCount() const noexcept;
    [[nodiscard]] TimestampMs nextPollDueMs() const noexcept;

private:
    void requestLuminance(TimestampMs nowMs);
    void handleLuminance(std::uint16_t lux, TimestampMs nowMs);
    void handleResponseTimeout(TimestampMs nowMs);
    void handleQuery(const CanFrame& frame, TimestampMs nowMs);
    void handleSubscription(const CanFrame& frame);
    void sendStateResponse(std::uint8_t clientId, TimestampMs nowMs);
    void sendSubscriptionAck(std::uint8_t clientId, SubscriptionStatus status);
    void sendNotification(std::uint8_t clientId, DayNightState previous, DayNightState next, TimestampMs nowMs);
    void sendDiagnosticFault(FaultCode code, bool active, DayNightState previous, DayNightState next, TimestampMs nowMs);
    [[nodiscard]] bool isRegistered(std::uint8_t clientId) const noexcept;

    CanFrameSink& sink_;
    ControllerConfig config_{};
    std::array<std::uint8_t, 8> subscribers_{};
    std::size_t subscriberCount_{0};
    bool hasValidSample_{false};
    std::uint16_t lastLuminanceLux_{0};
    DayNightState currentState_{DayNightState::Unknown};
    TimestampMs lastTransitionMs_{0};
    TimestampMs nextPollDueMs_{0};
    bool awaitingLuminanceResponse_{false};
    TimestampMs responseDeadlineMs_{0};
};

}  // namespace aspice