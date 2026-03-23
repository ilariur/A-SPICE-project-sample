# Measurement Dashboard

## Current Baseline (M5 Edition)
- **Baseline Revision:** 44a7d7ccd265a98fc03ec37c7fcb35a79345bacc
- **Measurement Date:** 2026-03-23
- **Baseline Status:** M5 Verification Evidence Complete

---

## Product Quality Measures

| Measure | Target | Current Status | Evidence Source | Notes |
|---|---|---|---|---|
| Requirements traced | 100% | 14/14 SW requirements traced | `docs/traceability/traceability-matrix.md` (baseline 44a7d7c) | All traced and verified |
| Poll interval conformance | 5000 ms exact in simulated scheduler | Confirmed in smoketest | Unit and integration tests | Deterministic scheduling verified |
| Unit test pass rate | 100% of planned unit tests | 14/14 UT passed, baseline 44a7d7c | `build/day_night_tests` | Unit verification complete |
| **Unit test report artifact** | SWE.4 evidence required | **Missing — CR-002 assigned** | — | **Critical finding: produce report by M5+1** |
| Integration smoke checks | 100% pass | 100% pass, baseline 44a7d7c | Integration strategy checklist | All critical paths verified |
| Integration scenario pass rate | 100% of executed scenarios | 12/12 passed, baseline 44a7d7c | `docs/integration/software-integration-test-report.md` | Includes negative-path (malformed, delayed, missing frame) |
| Qualification scenario pass rate | 100% of executed scenarios | 11/11 passed, baseline 44a7d7c | `docs/test/software-qualification-test-report.md` | Covers all feature scenarios |
| Negative-path CAN scenario pass rate | 100% of executed malformed or missing-response scenarios | 3/3 passed (malformed, delayed, missing), baseline 44a7d7c | `build/day_night_simulation` | Robustness coverage verified |
| Timeout fault scenario pass rate | 100% of executed timeout and recovery scenarios | 2/2 passed, baseline 44a7d7c | `build/day_night_tests`, `build/day_night_simulation` | Fault entry/exit, recovery verified |
| Diagnostic fault message scenario pass rate | 100% of executed diagnostic active/clear scenarios | 2/2 passed, baseline 44a7d7c | `build/day_night_tests`, `build/day_night_simulation` | CAN ID 0x540 transmit/consume verified |
| Open high-severity defects | 0 | 0 | Problem resolution log | No outstanding issues |

---

## Project Management Measures

| Measure | Target | Current Status | Owner | Due Date | Notes |
|---|---|---|---|---|---|
| **Residual open risks** | ≤ 2 | 4 open (R-001, R-003, R-006, R-007) | Project Manager + Risk Owners | M5 (Decision: Accept Residual) | **Major finding MF-03:** All 4 are vehicle-integration time risks; management decision: Accept residual with CR-001, CR-008 traceability controls |
| **Risk ratings (L/M/H)** | 100% rated | 7/7 complete | Project Manager | M5 (Updated) | All risks now have Likelihood, Severity, Priority assigned; see risk-register.md |
| **Schedule with dates** | Milestones M1–M5 + M6-CA with actual dates | Complete (M1–M5 retrospective, M6 planned) | Project Manager | M5+2 | docs/management/project-plan.md updated with dates, effort, staffing |
| **Status review records** | M4→M5 transition + M5→M6-CA handoff | **Missing baseline record** | Project Manager | M5+1 | **Major finding MF-04:** Create status-review-m5-final-and-cr-phase.md covering assessment findings and CA plan |
| **Change request process** | CR log with tracking | In-place (docs/support/change-request-log.md) | Project Manager | M5 (Established) | 18 CRs registered; status tracking and priority assignment complete |
| **Corrective action register** | All assessment findings → CAs with owner/date/exit criteria | **In-progress — see corrective-action-log.md** | Project Manager | M5+2 | 11 assessment-driven CRs mapped to CA log; P0 execution targeted M5+1, P1 by M5+2 |

---

## Corrective Action Plan Status

### Phase M6: Corrective Action Execution (2026-03-24 to 2026-03-25)

| Priority | Count | Target | Status | Owner |
|---|---|---|---|---|
| **P0-Critical** | 3 | M5+1 (2026-03-24) | Assigned: CR-001, CR-002, CR-003 | Project Manager, Software Tester |
| **P1-Major** | 8 | M5+2 (2026-03-25) | Assigned: CR-004–CR-011 | All roles |
| **P2-Observation** | 4 | M5+3 to M5+5 | Planned after P0/P1 baseline recovery | Requirements Eng, Software Designer/Eng |
| **Effort (P0+P1)** | 18h aggregate | Distributed per role (see effort table in project-plan.md) | Planned: 21h available in M6 | All roles |
| **Measurement Dashboard Target** | 100% P0 closed + 75% P1 closed by EOD M5+2 | Baseline: 0% | In-execution | Project Manager |

---

## Assessment Finding Traceability to Corrective Actions

| Finding | Type | Reference | Assigned CR(s) | Owner | Target |
|---|---|---|---|---|---|
| **CF-01** | Critical | SWE.4 missing unit test report | CR-002 | Software Tester | M5+1 ✓ Assigned |
| **CF-02** | Critical | Software-tester not in governance sequence | CR-001 | Project Manager | M5+1 ✓ Fixed (copilot-instructions.md) |
| **CF-03** | Critical | No change request process | CR-003 | Project Manager | M5+2 ✓ Established (this log) |
| **MF-02** | Major | Project plan missing schedule/dates | CR-005 | Project Manager | M5+2 ✓ Completed (project-plan.md) |
| **MF-03** | Major | Risk target variance (4 vs. ≤2) | CR-006, CR-010 | Project Manager + Risk Owners | M5+1/M5+2 ✓ Decision recorded (risk-register.md) |
| **MF-04** | Major | No status review records | CR-011 | Project Manager | M5+2 → Status-review-m5-final-and-cr-phase.md |
| **MF-05** | Major | Integration/qualification test evidence not distinguished | CR-004 | Integration/Qualification Testers | M5+2 |
| **MF-06** | Major | Detailed design documentation errors (ControllerConfig duplication, missing requirements trace) | CR-007 | Software Designer/Engineer | M5+1 |
| **MF-07** | Major | No Git baseline tag or configuration management policy | CR-008 | Project Manager | M5+1 |
| **MF-08** | Major | Problem resolution log missing columns (Status, Detected, Resolved) and closure evidence | CR-009 | Project Manager | M5+1 |