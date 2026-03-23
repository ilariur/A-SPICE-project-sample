# Software Unit Test Report

**Report Date:** 2026-03-23  
**Baseline Revision:** 44a7d7ccd265a98fc03ec37c7fcb35a79345bacc  
**Test Environment:** macOS CLI; unit test executable `./build/day_night_tests`  
**Execution Status:** All tests passed

---

## Executive Summary

Software unit verification (SWE.4) was executed against the Day/Night State Manager product baseline (44a7d7c). All 14 unit test cases covering the `DayNightController` (scheduler, state machine, query, subscription registry, and notification behavior) passed without failures. Test results are recorded with unit-to-requirement traceability and environmental configuration details.

---

## Test Execution Results

| Test ID | Objective | Requirement Link | Expected Result | Actual Result | Status | Execution Date | Baseline |
|---|---|---|---|---|---|---|---|
| **UT-001** | First `tick(0)` sends poll request | SWE-001 | One CAN frame ID `0x500` | Poll frame transmitted | ✅ PASS | 2026-03-23 | 44a7d7c |
| **UT-002** | `tick()` before deadline—no re-poll | SWE-001 | No additional frame | No frame sent | ✅ PASS | 2026-03-23 | 44a7d7c |
| **UT-003** | `tick()` at 5000 ms sends next poll | SWE-001 | Second CAN frame `0x500` | Second poll transmitted | ✅ PASS | 2026-03-23 | 44a7d7c |
| **UT-004** | Luminance response above day threshold → `DAY` state | SWE-002 | Internal state is `DAY` | State set to `DAY` | ✅ PASS | 2026-03-23 | 44a7d7c |
| **UT-005** | Query request returns client ID, state, age | SWE-003 | Response `0x511` with correct fields | Query response frame issued | ✅ PASS | 2026-03-23 | 44a7d7c |
| **UT-006** | Subscribe request returns `OK` | SWE-004 | ACK frame `0x521` status `OK` | Subscribe ACK sent | ✅ PASS | 2026-03-23 | 44a7d7c |
| **UT-007** | Duplicate subscribe returns `ALREADY_REGISTERED` | SWE-004 | ACK `0x521` status `ALREADY_REGISTERED` | Duplicate rejection sent | ✅ PASS | 2026-03-23 | 44a7d7c |
| **UT-008** | State change `DAY`→`NIGHT` sends notification | SWE-005 | One frame `0x530` per subscriber | Notifications broadcast | ✅ PASS | 2026-03-23 | 44a7d7c |
| **UT-009** | Unsubscribe removes client, returns `OK` | SWE-004 | ACK `0x521` status `OK` | Unsubscribe ACK sent | ✅ PASS | 2026-03-23 | 44a7d7c |
| **UT-010** | Unregistered client no notifications | SWE-005 | No `0x530` for removed client | Client excluded from broadcast | ✅ PASS | 2026-03-23 | 44a7d7c |
| **UT-011** | Missing response beyond timeout → `FAULT` state | SWE-009 | State `FAULT`, notification sent | Timeout transition executed | ✅ PASS | 2026-03-23 | 44a7d7c |
| **UT-012** | Valid response after `FAULT` recovers state | SWE-010 | Notification reports recovery | Recovery state notification sent | ✅ PASS | 2026-03-23 | 44a7d7c |
| **UT-013** | Timeout → `FAULT` emits diagnostic message | SWE-011 | Frame `0x540` with timeout code, active flag | Diagnostic active sent | ✅ PASS | 2026-03-23 | 44a7d7c |
| **UT-014** | Recovery from `FAULT` emits diagnostic clear | SWE-011 | Frame `0x540` with timeout code, clear flag | Diagnostic clear sent | ✅ PASS | 2026-03-23 | 44a7d7c |

---

## Test Summary

| Metric | Count | Status |
|---|---|---|
| **Total Test Cases** | 14 | ✅ Planned |
| **Passed** | 14 | ✅ |
| **Failed** | 0 | ✅ |
| **Blocked** | 0 | ✅ |
| **Pass Rate** | 100% | ✅ PASS |

---

## Test Environment Configuration

| Component | Configuration |
|---|---|
| **Test Executable** | `./build/day_night_tests` |
| **Platform** | macOS (arm64) |
| **Compile Flags** | GCC/Clang; unit test framework built-in harness |
| **CAN Frame Recording** | In-memory sink; validated via frame assertions |
| **Baseline Revision** | 44a7d7ccd265a98fc03ec37c7fcb35a79345bacc |
| **Execution Host** | CI/Local development workstation |

---

## Traceability to Detailed Design

All 14 unit tests trace to design elements defined in [software-detailed-design.md](../design/software-detailed-design.md):

- **UT-001, UT-002, UT-003:** DayNightController::_scheduler interval and poll request timing (Section: Scheduler)
- **UT-004, UT-008, UT-010:** DayNightController state machine transitions and notification dispatch (Section: State Machine)
- **UT-005:** Query handler response frame formation (Section: Query Handler)
- **UT-006, UT-007, UT-009:** Registry subscription management (Section: Registry)
- **UT-011, UT-012, UT-013, UT-014:** Timeout detection, FAULT state, recovery, and diagnostic CAN frames (Section: Robustness & Error Handling)

---

## Traceability to Software Requirements

All 14 tests trace to allocated requirements in [software-requirements.md](../requirements/software-requirements.md):

| Requirement | Test Coverage | Status |
|---|---|---|
| SWE-001 | UT-001, UT-002, UT-003 | ✅ Verified |
| SWE-002 | UT-004 | ✅ Verified |
| SWE-003 | UT-005 | ✅ Verified |
| SWE-004 | UT-006, UT-007, UT-009 | ✅ Verified |
| SWE-005 | UT-008, UT-010 | ✅ Verified |
| SWE-006 | (Integration test scope) | — |
| SWE-007 | (Integration test scope) | — |
| SWE-008 | (Integration test scope) | — |
| SWE-009 | UT-011 | ✅ Verified |
| SWE-010 | UT-012 | ✅ Verified |
| SWE-011 | UT-013, UT-014 | ✅ Verified |
| SWE-012 | (Integration test scope) | — |
| SWE-013 | (Integration test scope) | — |

---

## Quality Observations

1. **Coverage:** Unit tests exercise nominal, boundary, error, and recovery paths for all four major controller subsystems.
2. **Defects Found:** Zero defects. All test cases passed on first execution.
3. **Test Adequacy:** Test cases align with design and requirements. No gaps identified.
4. **Repeatability:** Tests are self-contained and produce consistent results across multiple runs.
5. **Evidence Preservation:** Execution environment is reproducible; baseline commit ID and test harness are documented.

---

## Verification Sign-Off

**Test Execution Completed:** 2026-03-23  
**Baseline Revision Tested:** 44a7d7ccd265a98fc03ec37c7fcb35a79345bacc  
**Status:** ✅ Unit verification (SWE.4) complete — all 14 unit tests pass  
**Recommendation:** Ready for integration phase (SWE.5)

---

## Related Documents

- [Software Requirements](../requirements/software-requirements.md)
- [Software Detailed Design](../design/software-detailed-design.md)
- [Software Unit Verification Specification](./software-unit-verification-spec.md)
- [Software Integration Test Report](./software-integration-test-report.md)
- [Software Qualification Test Report](./software-qualification-test-report.md)
