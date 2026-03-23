# Software Unit Verification Specification

## Units Under Test
- `DayNightController` scheduler
- `DayNightController` state machine
- `DayNightController` query handler
- `DayNightController` subscription registry and notification behavior

## Test Cases

| ID | Objective | Expected Result |
|---|---|---|
| UT-001 | First `tick(0)` sends a poll request | One CAN frame with ID `0x500` |
| UT-002 | `tick()` before next deadline does not re-poll | No additional poll frame |
| UT-003 | `tick()` at 5000 ms sends the next poll request | Second CAN frame with ID `0x500` |
| UT-004 | Luminance response above day threshold sets state to `DAY` | Internal state is `DAY` |
| UT-005 | Query request returns client ID, state, and age | Response frame `0x511` contains correct values |
| UT-006 | Subscribe request acknowledges with `OK` | ACK frame `0x521` status `OK` |
| UT-007 | Duplicate subscribe returns `ALREADY_REGISTERED` | ACK frame `0x521` status `ALREADY_REGISTERED` |
| UT-008 | State change from `DAY` to `NIGHT` sends notification | One frame `0x530` per subscriber |
| UT-009 | Unsubscribe removes client and returns `OK` | ACK frame `0x521` status `OK` |
| UT-010 | Unregistered client does not receive later notifications | No `0x530` frame for removed client |
| UT-011 | Missing luminance response beyond timeout moves state to `FAULT` | Query returns `FAULT` and notification is sent to subscribers |
| UT-012 | Valid luminance response after `FAULT` recovers to `DAY` or `NIGHT` | Notification reports recovery state |

## Environment
- Self-contained C++ executable
- Recording sink for transmitted CAN frames
- Direct invocation of `tick()` and `onFrame()`

## Acceptance
- All test cases pass without external framework dependencies.