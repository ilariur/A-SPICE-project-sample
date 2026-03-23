# Software Integration Test Specification

## Interfaces Under Test
- Poll request and luminance response interface
- Query request and response interface
- Subscription control and status interface
- State-change notification interface
- Diagnostic fault reporting interface

## Integration Sequences

| ID | Sequence | Expected Result |
|---|---|---|
| IT-001 | Startup, first poll, first luminance response | Product reaches known `DAY` or `NIGHT` state |
| IT-002 | Subscribe client, cause transition, inspect notification | ACK received and notification delivered |
| IT-003 | Query during stable state | Response matches current state |
| IT-004 | Query after transition | Response returns new state |
| IT-005 | Subscribe, unsubscribe, then transition | Removed client receives no notification |
| IT-006 | Malformed query, malformed subscription, and unknown CAN frame | Frames are ignored without state corruption or unintended response |
| IT-007 | Delayed luminance response across multiple poll cycles | Polling continues, query returns `FAULT` after timeout until valid luminance response arrives |
| IT-008 | Timeout transition and recovery | CAN ID `0x540` fault message is emitted on timeout and clear message is emitted on recovery |

## Environment
- Same executable baseline as unit verification
- Simulated CAN stimuli via `onFrame()`
- Timing exercised via explicit millisecond values passed to `tick()`

## Exit Criteria
- All interfaces behave consistently across the defined sequences.
- No unresolved major anomalies remain.