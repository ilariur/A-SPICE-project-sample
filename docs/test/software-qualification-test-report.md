---
Revision: 1.0
Date: 2026-03-23
Author: Software Qualification Tester
Status: Approved
---

# Software Qualification Test Report

## Baseline
- Executable: `build/day_night_simulation`
- Environment: simulated CAN environment using requirement-based luminance and client interaction scenarios

## Executed Scenarios

| QT ID | Scenario | Simulation Evidence | Result |
|---|---|---|---|
| QT-001 | Steady daylight 60s | Direct qualification run | PASS |
| QT-002 | Steady night 60s | Direct qualification run | PASS |
| QT-003 | Dusk transition (crossing below 800 lux) | Direct qualification run | PASS |
| QT-004 | Dawn transition (crossing above 1500 lux) | Direct qualification run | PASS |
| QT-005 | Query during steady day — response is `DAY` | IT-001/IT-003 poll-and-query scenario | PASS |
| QT-006 | Query after dusk transition — response is `NIGHT` | QT-003 combined run | PASS |
| QT-007 | Two clients subscribe before transition — both receive notification | IT-002 multi-subscriber scenario | PASS |
| QT-008 | Client unsubscribes before transition — no notification to unsubscribed client | IT-005 unsubscribe scenario | PASS |
| QT-009 | Missing luminance response — polling continues, `FAULT` entered, diagnostic emitted | Direct qualification run | PASS |
| QT-010 | Valid luminance after timeout fault — recovery to `DAY`/`NIGHT`, diagnostic clear emitted | IT-008/QT-010 diagnostic scenario | PASS |

**Total: 10/10 qualification scenarios executed and passed.**

## Result Summary
- Status: Passed (all 10 QT scenarios)
- Evidence source: console output from `./build/day_night_simulation`; IT scenario cross-references documented above

## Executed Result
```text
PASS - QT-001 Steady daylight 60s
PASS - QT-002 Steady night 60s
PASS - QT-003 Dusk transition
PASS - QT-004 Dawn transition
PASS - QT-005 Query during steady day [evidence: IT-001/IT-003 poll-and-query]
PASS - QT-006 Query after dusk transition
PASS - QT-007 Two clients subscribe before transition [evidence: IT-002 multi-subscriber]
PASS - QT-008 Client unsubscribes before transition [evidence: IT-005 unsubscribe]
PASS - QT-009 Missing response timeout-style behavior
PASS - QT-010 Diagnostic fault message on FAULT enter and clear [evidence: IT-008/QT-010]
Summary: 10/10 qualification scenarios passed.
```

## Requirement Traceability

| Requirement | QT Coverage | Status |
|---|---|---|
| SWE-001 (polling at 5000 ms) | QT-001, QT-002, QT-009 | ✅ Verified |
| SWE-002 (luminance parsing) | QT-003, QT-004, QT-010 | ✅ Verified |
| SWE-003 (state query) | QT-005, QT-006 | ✅ Verified |
| SWE-004 (hysteresis thresholds) | QT-003, QT-004 | ✅ Verified |
| SWE-005 (query response: client ID, state, age) | QT-005, QT-006 | ✅ Verified |
| SWE-006 (bounded subscriber list) | QT-007, QT-008 | ✅ Verified |
| SWE-007 (subscription ACK statuses) | QT-007, QT-008 | ✅ Verified |
| SWE-008 (notification per subscriber on state change) | QT-007, QT-008 | ✅ Verified |
| SWE-009 (configurable timeout → FAULT) | QT-009 | ✅ Verified |
| SWE-010 (recovery from FAULT) | QT-010 | ✅ Verified |
| SWE-011 (diagnostic CAN ID 0x540 on fault/clear) | QT-010 | ✅ Verified |

## Assessment
- All 10 requirement-based qualification scenarios executed and passed in the simulated CAN environment.
- Steady-state, transition, query, subscription, timeout-fault, and diagnostic scenarios are fully covered.
- QT-005 (query during steady day) and QT-006 (query after transition) verify SWE-003 and SWE-005 end-to-end.
- QT-007 (multi-client subscription) and QT-008 (unsubscribe before transition) verify SWE-006, SWE-007, and SWE-008; simulation evidence from IT-002 and IT-005 respectively.
- QT-009 and QT-010 verify fault detection (SWE-009), recovery (SWE-010), and diagnostic reporting (SWE-011).
- Residual risk remains limited to provisional CAN IDs, calibration on the final sensor, and final-vehicle bus timing confirmation.

## Notes
- QT-005, QT-007, and QT-008 are covered by integration simulation scenarios (IT-001/IT-003, IT-002, IT-005) which were executed in the same `day_night_simulation` binary under the M5 baseline (44a7d7c). Cross-reference to integration test report is maintained for audit traceability (CR-004 resolution).
- Execution date: 2026-03-23; Baseline: 44a7d7ccd265a98fc03ec37c7fcb35a79345bacc