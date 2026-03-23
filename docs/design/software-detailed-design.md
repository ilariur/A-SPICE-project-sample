---
Revision: 1.2
Date: 2026-03-27
Author: Software Designer/Engineer
Status: Approved
---

# Software Detailed Design

## Units

### `can_protocol.hpp`
- Defines frame layout, state and status enums, message IDs, and payload helpers.

### `day_night_controller.hpp`
- Declares `ControllerConfig`, `CanFrameSink`, and `DayNightController`.
- Stores current state, last luminance value, next poll deadline, response timeout deadline, transition timestamp, and subscriber registry.

### `day_night_controller.cpp`
- Implements the fixed-period scheduler.
- Parses luminance, query, and subscription frames.
- Monitors the oldest outstanding poll request and enters `FAULT` if no luminance response arrives before `responseTimeoutMs`.
- Applies hysteresis:
  - `UNKNOWN` becomes `DAY` if lux >= 1500, otherwise `NIGHT`
  - `FAULT` recovers to `DAY` if lux >= 1500, otherwise `NIGHT`
  - `DAY` becomes `NIGHT` only when lux < 800
  - `NIGHT` becomes `DAY` only when lux > 1500
- Emits notifications only on actual state change, including transitions into and out of `FAULT`.

### `main.cpp`
- Demonstrates poll, subscribe, luminance update, query, and transition behavior.

### `day_night_controller_tests.cpp`
- Uses a recording sink and assertions to verify scheduling, query response, subscription, and notification behavior.

## Data Structures
- `CanFrame`: fixed 8-byte CAN frame wrapper
- `ControllerConfig`: thresholds (`dayThresholdLux`, `nightThresholdLux`), poll interval (`pollIntervalMs`), response timeout (`responseTimeoutMs`), and registry bound (8 subscribers)
- Subscriber registry: `std::array<uint8_t, 8>` plus count

## Error Handling
- Unknown or malformed frames are ignored.
- Missing luminance responses beyond `responseTimeoutMs` trigger `FAULT`.
- Duplicate registrations receive `ALREADY_REGISTERED`.
- Over-capacity registrations receive `FULL`.
- Unsubscribe for absent client receives `NOT_FOUND`.
- Query before first valid sample returns state `UNKNOWN` unless a response timeout has already moved the controller to `FAULT`.

## File-to-Requirement Mapping

| File | Primary Requirements |
|---|---|
| `src/can_protocol.hpp` | SWE-003, SWE-007, SWE-011 |
| `src/day_night_controller.hpp` | SWE-001, SWE-003, SWE-006 |
| `src/day_night_controller.cpp` | SWE-001, SWE-002, SWE-004, SWE-005, SWE-007, SWE-008, SWE-009, SWE-010, SWE-011 |
| `src/main.cpp` | SWE-013 |
| `tests/day_night_controller_tests.cpp` | SWE-012, SWE-013 |