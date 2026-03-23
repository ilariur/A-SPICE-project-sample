#include "day_night_controller.hpp"

#include <algorithm>

namespace aspice {

DayNightController::DayNightController(CanFrameSink& sink, ControllerConfig config)
    : sink_(sink), config_(config), nextPollDueMs_(0) {}

void DayNightController::tick(TimestampMs nowMs) {
    if (awaitingLuminanceResponse_ && nowMs >= responseDeadlineMs_) {
        handleResponseTimeout(nowMs);
    }

    while (nowMs >= nextPollDueMs_) {
        requestLuminance(nowMs);
        nextPollDueMs_ += config_.pollIntervalMs;
    }
}

void DayNightController::onFrame(const CanFrame& frame, TimestampMs nowMs) {
    switch (frame.id) {
    case CanIds::kLuminanceResponse:
        if (frame.dlc >= 2) {
            handleLuminance(readU16(frame.data, 0), nowMs);
        }
        break;
    case CanIds::kStateQueryRequest:
        if (frame.dlc >= 1) {
            handleQuery(frame, nowMs);
        }
        break;
    case CanIds::kSubscriptionControl:
        if (frame.dlc >= 2) {
            handleSubscription(frame);
        }
        break;
    default:
        break;
    }
}

DayNightState DayNightController::state() const noexcept {
    return currentState_;
}

std::uint16_t DayNightController::lastLuminanceLux() const noexcept {
    return lastLuminanceLux_;
}

std::size_t DayNightController::subscriberCount() const noexcept {
    return subscriberCount_;
}

TimestampMs DayNightController::nextPollDueMs() const noexcept {
    return nextPollDueMs_;
}

void DayNightController::requestLuminance(TimestampMs nowMs) {
    if (!awaitingLuminanceResponse_) {
        awaitingLuminanceResponse_ = true;
        responseDeadlineMs_ = nowMs + config_.responseTimeoutMs;
    }

    CanFrame frame{};
    frame.id = CanIds::kLuminancePollRequest;
    frame.dlc = 0;
    sink_.send(frame);
}

void DayNightController::handleLuminance(std::uint16_t lux, TimestampMs nowMs) {
    lastLuminanceLux_ = lux;
    const DayNightState previous = currentState_;
    awaitingLuminanceResponse_ = false;
    responseDeadlineMs_ = 0;

    if (!hasValidSample_) {
        hasValidSample_ = true;
    }

    if (previous == DayNightState::Unknown || previous == DayNightState::Fault) {
        currentState_ = (lux >= config_.dayThresholdLux) ? DayNightState::Day : DayNightState::Night;
    } else if (currentState_ == DayNightState::Day && lux < config_.nightThresholdLux) {
        currentState_ = DayNightState::Night;
    } else if (currentState_ == DayNightState::Night && lux > config_.dayThresholdLux) {
        currentState_ = DayNightState::Day;
    }

    if (currentState_ != previous) {
        lastTransitionMs_ = nowMs;
        if (previous != DayNightState::Unknown) {
            for (std::size_t index = 0; index < subscriberCount_; ++index) {
                sendNotification(subscribers_[index], previous, currentState_, nowMs);
            }
        }
    }
}

void DayNightController::handleResponseTimeout(TimestampMs nowMs) {
    awaitingLuminanceResponse_ = false;
    responseDeadlineMs_ = 0;

    if (currentState_ == DayNightState::Fault) {
        return;
    }

    const DayNightState previous = currentState_;
    currentState_ = DayNightState::Fault;
    lastTransitionMs_ = nowMs;

    for (std::size_t index = 0; index < subscriberCount_; ++index) {
        sendNotification(subscribers_[index], previous, currentState_, nowMs);
    }
}

void DayNightController::handleQuery(const CanFrame& frame, TimestampMs nowMs) {
    sendStateResponse(frame.data[0], nowMs);
}

void DayNightController::handleSubscription(const CanFrame& frame) {
    const std::uint8_t clientId = frame.data[0];
    const auto action = static_cast<SubscriptionAction>(frame.data[1]);

    if (action == SubscriptionAction::Subscribe) {
        if (isRegistered(clientId)) {
            sendSubscriptionAck(clientId, SubscriptionStatus::AlreadyRegistered);
            return;
        }
        if (subscriberCount_ >= config_.maxSubscribers) {
            sendSubscriptionAck(clientId, SubscriptionStatus::Full);
            return;
        }
        subscribers_[subscriberCount_] = clientId;
        ++subscriberCount_;
        sendSubscriptionAck(clientId, SubscriptionStatus::Ok);
        return;
    }

    if (action == SubscriptionAction::Unsubscribe) {
        for (std::size_t index = 0; index < subscriberCount_; ++index) {
            if (subscribers_[index] == clientId) {
                std::move(subscribers_.begin() + static_cast<std::ptrdiff_t>(index + 1),
                          subscribers_.begin() + static_cast<std::ptrdiff_t>(subscriberCount_),
                          subscribers_.begin() + static_cast<std::ptrdiff_t>(index));
                --subscriberCount_;
                subscribers_[subscriberCount_] = 0;
                sendSubscriptionAck(clientId, SubscriptionStatus::Ok);
                return;
            }
        }
        sendSubscriptionAck(clientId, SubscriptionStatus::NotFound);
        return;
    }

    sendSubscriptionAck(clientId, SubscriptionStatus::Invalid);
}

void DayNightController::sendStateResponse(std::uint8_t clientId, TimestampMs nowMs) {
    CanFrame frame{};
    frame.id = CanIds::kStateQueryResponse;
    frame.dlc = 4;
    frame.data[0] = clientId;
    frame.data[1] = static_cast<std::uint8_t>(currentState_);

    const auto ageSeconds = static_cast<std::uint16_t>((hasValidSample_ && nowMs >= lastTransitionMs_)
                                                           ? (nowMs - lastTransitionMs_) / 1000U
                                                           : 0U);
    writeU16(frame.data, 2, ageSeconds);
    sink_.send(frame);
}

void DayNightController::sendSubscriptionAck(std::uint8_t clientId, SubscriptionStatus status) {
    CanFrame frame{};
    frame.id = CanIds::kSubscriptionStatus;
    frame.dlc = 2;
    frame.data[0] = clientId;
    frame.data[1] = static_cast<std::uint8_t>(status);
    sink_.send(frame);
}

void DayNightController::sendNotification(std::uint8_t clientId,
                                          DayNightState previous,
                                          DayNightState next,
                                          TimestampMs nowMs) {
    CanFrame frame{};
    frame.id = CanIds::kStateChangeNotification;
    frame.dlc = 7;
    frame.data[0] = clientId;
    frame.data[1] = static_cast<std::uint8_t>(next);
    frame.data[2] = static_cast<std::uint8_t>(previous);
    writeU32(frame.data, 3, static_cast<std::uint32_t>(nowMs));
    sink_.send(frame);
}

bool DayNightController::isRegistered(std::uint8_t clientId) const noexcept {
    for (std::size_t index = 0; index < subscriberCount_; ++index) {
        if (subscribers_[index] == clientId) {
            return true;
        }
    }
    return false;
}

}  // namespace aspice