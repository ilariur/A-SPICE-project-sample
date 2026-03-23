#pragma once

#include <array>
#include <cstdint>

namespace aspice {

using TimestampMs = std::uint64_t;

struct CanFrame {
    std::uint16_t id{0};
    std::uint8_t dlc{0};
    std::array<std::uint8_t, 8> data{};
};

enum class DayNightState : std::uint8_t {
    Night = 0x00,
    Day = 0x01,
    Fault = 0x02,
    Unknown = 0xFF,
};

enum class SubscriptionAction : std::uint8_t {
    Unsubscribe = 0x00,
    Subscribe = 0x01,
};

enum class SubscriptionStatus : std::uint8_t {
    Ok = 0x00,
    AlreadyRegistered = 0x01,
    Full = 0x02,
    NotFound = 0x03,
    Invalid = 0x04,
};

struct CanIds {
    static constexpr std::uint16_t kLuminancePollRequest = 0x500;
    static constexpr std::uint16_t kLuminanceResponse = 0x501;
    static constexpr std::uint16_t kStateQueryRequest = 0x510;
    static constexpr std::uint16_t kStateQueryResponse = 0x511;
    static constexpr std::uint16_t kSubscriptionControl = 0x520;
    static constexpr std::uint16_t kSubscriptionStatus = 0x521;
    static constexpr std::uint16_t kStateChangeNotification = 0x530;
};

inline std::uint16_t readU16(const std::array<std::uint8_t, 8>& data, std::size_t offset) {
    return static_cast<std::uint16_t>(data[offset]) |
           static_cast<std::uint16_t>(data[offset + 1] << 8U);
}

inline std::uint32_t readU32(const std::array<std::uint8_t, 8>& data, std::size_t offset) {
    return static_cast<std::uint32_t>(data[offset]) |
           static_cast<std::uint32_t>(data[offset + 1] << 8U) |
           static_cast<std::uint32_t>(data[offset + 2] << 16U) |
           static_cast<std::uint32_t>(data[offset + 3] << 24U);
}

inline void writeU16(std::array<std::uint8_t, 8>& data, std::size_t offset, std::uint16_t value) {
    data[offset] = static_cast<std::uint8_t>(value & 0xFFU);
    data[offset + 1] = static_cast<std::uint8_t>((value >> 8U) & 0xFFU);
}

inline void writeU32(std::array<std::uint8_t, 8>& data, std::size_t offset, std::uint32_t value) {
    data[offset] = static_cast<std::uint8_t>(value & 0xFFU);
    data[offset + 1] = static_cast<std::uint8_t>((value >> 8U) & 0xFFU);
    data[offset + 2] = static_cast<std::uint8_t>((value >> 16U) & 0xFFU);
    data[offset + 3] = static_cast<std::uint8_t>((value >> 24U) & 0xFFU);
}

inline const char* toString(DayNightState state) {
    switch (state) {
    case DayNightState::Night:
        return "NIGHT";
    case DayNightState::Day:
        return "DAY";
    case DayNightState::Fault:
        return "FAULT";
    case DayNightState::Unknown:
        return "UNKNOWN";
    }

    return "UNKNOWN";
}

}  // namespace aspice