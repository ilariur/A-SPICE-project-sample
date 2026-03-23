# Software Architecture

## Software Elements
- `DayNightController`: central application logic, polling schedule, state machine, query handling, subscription handling
- `CanFrameSink`: abstract transmission port used by the controller
- `main.cpp` demo harness: simulates the external bus and prints transmitted frames
- `day_night_tests.cpp`: verification harness using a recording sink

## CAN Message Dictionary

| ID | Direction | Meaning | Payload |
|---|---|---|---|
| `0x500` | Tx | Luminance poll request | none |
| `0x501` | Rx | Luminance response | bytes 0-1: lux `uint16` |
| `0x510` | Rx | State query request | byte 0: client ID |
| `0x511` | Tx | State query response | byte 0: client ID, byte 1: state (`NIGHT`, `DAY`, `FAULT`, `UNKNOWN`), bytes 2-3: age seconds |
| `0x520` | Rx | Subscription control | byte 0: client ID, byte 1: action (`1` subscribe, `0` unsubscribe) |
| `0x521` | Tx | Subscription status | byte 0: client ID, byte 1: status |
| `0x530` | Tx | State-change notification | byte 0: client ID, byte 1: new state, byte 2: previous state, bytes 3-6: timestamp ms |
| `0x540` | Tx | Diagnostic fault status | byte 0: fault code, byte 1: active (`1`) or cleared (`0`), byte 2: previous state, byte 3: current state, bytes 4-7: timestamp ms |

## Runtime Sequence
1. On startup, the controller schedules its first poll immediately.
2. Every 5000 ms, the controller sends CAN ID `0x500`.
3. The external luminance provider replies with CAN ID `0x501` carrying lux.
4. If the oldest outstanding poll request exceeds the configured response timeout, the controller transitions to `FAULT`.
5. When a valid luminance response arrives, the controller updates or recovers the state using hysteresis.
6. When timeout causes a transition into `FAULT`, the controller emits a dedicated diagnostic fault message.
7. When a valid luminance response clears `FAULT`, the controller emits a dedicated diagnostic clear message.
8. When the state changes, including transitions into or out of `FAULT`, the controller sends one notification per registered client.
9. At any time, external software may query using `0x510` and receive `0x511`.
10. External software may register or unregister using `0x520` and receive `0x521`.

## Allocation

| Requirement | Architecture Element |
|---|---|
| Polling | `DayNightController` scheduler |
| Day/Night decision | `DayNightController` state machine |
| Timeout fault detection | `DayNightController` timeout monitor |
| Diagnostic fault reporting | `DayNightController` diagnostic emitter |
| CAN query | `DayNightController` query handler |
| Registration and notification | `DayNightController` subscription registry and notifier |
| Transmission abstraction | `CanFrameSink` |

## Architecture Decisions
- Single controller object to keep state updates, query replies, and notifications coherent.
- Bounded registry to keep memory deterministic.
- Polling and responses are event-driven by explicit `tick` and `onFrame` calls, making unit verification straightforward.
- State thresholds are configurable to support later calibration without architecture change.
- Response timeout is configurable so timeout-fault behavior can be aligned with the final network contract without redesign.