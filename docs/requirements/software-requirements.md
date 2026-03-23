# Software Requirements

## Derived Requirements
These requirements emerged from architectural and technical decisions to satisfy parent stakeholder/system requirements.

| ID | Source | Rationale | Allocated To |
|---|---|---|---|
| SWE-006 | SYS-007 (bounded registry) | Memory determinism for embedded environment | Controller bounded to 8 subscribers |
| SWE-009 | SYS-009 (fault handling) | Network latency tolerance; configurable per vehicle | Controller supports responseTimeoutMs tuning |
| SWE-004 | SYS-002 (day/night distinction) | Chatter prevention in transition zones | Configurable threshold hysteresis |

## Software Requirements

| ID | Requirement | Allocation |
|---|---|---|
| SWE-001 | `DayNightController` shall schedule poll requests at a fixed 5000 ms interval. | `src/day_night_controller.cpp` |
| SWE-002 | `DayNightController` shall parse luminance responses from CAN payload bytes 0-1. | `src/day_night_controller.cpp` |
| SWE-003 | `DayNightController` shall maintain states `DAY`, `NIGHT`, `FAULT`, and `UNKNOWN` internally and expose the current state in query responses and notifications. | `src/day_night_controller.hpp` |
| SWE-004 | `DayNightController` shall apply hysteresis using configurable `dayThresholdLux` and `nightThresholdLux`. | `src/day_night_controller.cpp` |
| SWE-005 | `DayNightController` shall answer state query frames with client ID, state, and age in seconds. | `src/day_night_controller.cpp` |
| SWE-006 | `DayNightController` shall maintain a bounded subscriber list of 8 client IDs. | `src/day_night_controller.hpp` |
| SWE-007 | `DayNightController` shall acknowledge subscription control requests with status `OK`, `ALREADY_REGISTERED`, `FULL`, `NOT_FOUND`, or `INVALID`. | `src/day_night_controller.cpp` |
| SWE-008 | `DayNightController` shall emit one notification frame per registered client when the state changes. | `src/day_night_controller.cpp` |
| SWE-009 | `DayNightController` shall detect missing luminance responses using configurable timeout `responseTimeoutMs` and transition to `FAULT` when the timeout expires. | `src/day_night_controller.cpp` |
| SWE-010 | `DayNightController` shall recover from `FAULT` to `DAY` or `NIGHT` when a valid luminance response is later received. | `src/day_night_controller.cpp` |
| SWE-011 | `DayNightController` shall emit CAN ID `0x540` with diagnostic payload `{faultCode, activeFlag, previousState, currentState, timestamp}` on fault enter and fault clear events. | `src/day_night_controller.cpp` |
| SWE-012 | The implementation shall avoid exceptions and dynamic allocation on the control path. | `src/*.hpp`, `src/*.cpp` |
| SWE-013 | The product shall be verifiable with a self-contained test executable that does not require external test frameworks. | `tests/day_night_controller_tests.cpp` |