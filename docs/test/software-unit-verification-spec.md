---
Revision: 1.1
Date: 2026-03-26
Author: Software Tester
Status: Approved
---

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
| UT-013 | Timeout transition to `FAULT` emits diagnostic fault message | One frame `0x540` with timeout fault code and active flag |
| UT-014 | Recovery from `FAULT` emits diagnostic clear message | One frame `0x540` with timeout fault code and cleared flag |

## Coverage Objectives
- **Statement coverage target:** ≥ 80% (for 14-unit SLOC ~500 lines → target ≥ 400 statements executed)
- **Branch coverage target:** ≥ 70% (state machine transitions, timeout conditions, subscription registry limits)

---

## Coverage Execution (CR-023)

| Measure | Target | Measured | Status | Date |
|---|---|---|---|---|
| **Statement Coverage** | ≥ 80% | 87% | ✅ Meets Target | 2026-03-26 |
| **Branch Coverage** | ≥ 70% | 78% | ✅ Meets Target | 2026-03-26 |
| **Execution Method** | clang++ -fprofile-instr-generate, llvm-cov report | Clang toolchain; macOS arm64 environment | ✅ Confirmed | 2026-03-26 |
| **Baseline** | 44a7d7ccd265a98fc03ec37c7fcb35a79345bacc | 44a7d7c | ✅ Hit Target | 2026-03-26 |

**Coverage Details:**
- 458/526 statements executed (87%)
- 29/37 branches exercised (78%)
- Uncovered lines concentrated in: debug/diagnostic paths (10 statements), error bounds checking preceding timeout behavior (8 statements), forward-compatibility reserved registry slots (5 statements)
- All covered nominal, boundary, and error paths as per test case design
- **MC/DC (Modified Condition/Decision Coverage):** Not required for this component (non-safety-critical)

## Coverage Measurement
- Tool: `clang++ -fprofile-instr-generate -fcoverage-mapping` with `llvm-cov` for report
- Baseline: Run `./build/day_night_tests` with coverage instrumentation
- Reporting: Coverage summary in unit test report (SWE.4 evidence)

## Environment
- Self-contained C++ executable
- Recording sink for transmitted CAN frames
- Direct invocation of `tick()` and `onFrame()`

## Acceptance
- All test cases pass without external framework dependencies.