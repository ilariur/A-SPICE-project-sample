# Change Request Log

## Purpose
Track all formal changes to product scope, architecture, design, code, test, and documentation. Each CR captures assessment findings, stakeholder requests, defect corrections, and process improvements. All CRs are reviewed and approved before implementation.

---

## Change Requests from A-SPICE Assessment (2026-03-23)

| CR# | Title | Scope | Owner | Priority | Status | Est. Effort | Target |
|---|---|---|---|---|---|---|---|
| CR-001 | Add software-tester role to governance sequence | Update `.github/copilot-instructions.md` to insert software-tester between software-designer-engineer and software-integrator | Project Manager | P0-Critical | **Completed** | 0.5h | M5+1 |
| CR-002 | Create unit test report | Produce `docs/test/software-unit-test-report.md` with UT-001–UT-014 pass/fail evidence against baseline 44a7d7c | Software Tester | P0-Critical | **Completed** | 2h | M5+1 |
| CR-003 | Establish change request management process | Create `docs/support/change-request-log.md` and retrospectively register all product feature changes | Project Manager | P0-Critical | **Completed** | 3h | M5+2 |
| CR-004 | Separate integration and qualification test evidence | Update IT and QT reports to clearly enumerate which scenarios satisfy SWE.5 vs. SWE.6; explicitly list QT-005, QT-007, QT-008 in qualification report | Software Integration Tester + Software Qualification Tester | P1-Major | Open | 2h | M5+2 |
| CR-005 | Add schedule to project plan | Add target/actual dates and effort estimates for milestones M1–M5 to `docs/management/project-plan.md` | Project Manager | P1-Major | **Completed** | 3h | M5+2 |
| CR-006 | Record corrective action on risk target variance | Document decision on 4 open risks vs. target ≤2; either accept with approval or close risks; add corrective action column to measurement dashboard | Project Manager | P1-Major | **Completed** | 2h | M5+1 |
| CR-007 | Fix detailed design documentation errors | Deduplicate ControllerConfig in data structures section; add SWE-011 and SWE-013 to file-to-requirement mapping in `docs/design/software-detailed-design.md` | Software Designer/Engineer | P1-Major | **Completed** | 1h | M5+1 |
| CR-008 | Apply Git baseline tag | Create annotated Git tag `v0.1.0-draft` at commit 44a7d7ccd265a98fc03ec37c7fcb35a79345bacc and document tagging policy in configuration management plan | Project Manager | P1-Major | **Completed** | 0.5h | M5+1 |
| CR-009 | Enhance problem resolution log | Add `Status`, `Detected`, and `Resolved` columns to `docs/support/problem-resolution-log.md`; populate all 6 existing PRs with dates and close status | Project Manager | P1-Major | **Completed** | 1.5h | M5+1 |
| CR-010 | Add risk ratings to risk register | Update `docs/management/risk-register.md` to include Likelihood (H/M/L), Severity (H/M/L), and Priority columns; rate all 7 open risks | Project Manager + Risk Owners | P1-Major | **Completed** | 2h | M5+2 |
| CR-011 | Produce status review record | Create `docs/management/status-review-m5-final-and-cr-phase.md` covering integrated baseline through test completion; record findings, decisions, and open items | Project Manager | P1-Major | **Assigned** (In-Progress) | 3h | M5+2 |
| CR-012 | Document derived requirements | Label architectural constraints (bounded registry, configurable timeout) as derived requirements in `docs/requirements/software-requirements.md` | Requirements Engineer | P2-Observation | Open | 1h | M5+3 |
| CR-013 | Define code coverage target | Update unit verification specification to include a coverage target (e.g., 80% statement); measure and report against baseline | Software Tester | P2-Observation | Open | 2h | M5+2 |
| CR-014 | Reference coding standard | Add reference to a coding standard (project-local guideline or ISO/IEC standard) in quality assurance plan | Project Manager | P2-Observation | Open | 1h | M5+2 |
| CR-015 | Clarify main.cpp classification | Update architecture and integration strategy to explicitly state whether `src/main.cpp` is a product deliverable or verification-only harness | Software Architect | P2-Observation | Open | 0.5h | M5+1 |
| CR-016 | Update integration strategy baseline list | Add `tests/day_night_simulation.cpp` to the baseline contents list in `docs/integration/software-integration-strategy.md` | System Integration Lead | P2-Observation | Open | 0.5h | M5+1 |
| CR-017 | Cross-reference related risks | Link R-001 and R-007 in risk register (both concern CAN ID allocation conflicts) to clarify compound impact | Project Manager | P2-Observation | Open | 0.5h | M5+1 |
| CR-018 | Quantify measurement dashboard status | Replace narrative status entries with quantitative values, baseline ID, and date (e.g., "14/14 UT passed, 2026-03-23, 44a7d7c") | Project Manager | P2-Observation | Open | 1h | M5+2 |

---

## Retrospective Feature Changes (Not Previously Registered)

| CR# | Title | Description | Rationale | Completion Date |
|---|---|---|---|---|
| CR-H1 | Implement FAULT timeout state and recovery | Added configurable timeout behavior to `DayNightController`; added SWE-009, SWE-010; updated unit and simulation tests to verify timeout and recovery | Requirements gap: missing luminance response robustness was documented as "known limitation" rather than implemented product behavior | 2026-03-23 |
| CR-H2 | Add diagnostic fault-code CAN message | Implemented CAN ID `0x540` with timeout fault code and active/clear status; added SWE-011; updated tests to verify diagnostic entry and exit | Requirements enhancement: external diagnostics needed explicit fault-event consumption | 2026-03-23 |
| CR-H3 | Expand integration/qualification test scenarios | Added malformed-frame, delayed-response, missing-response, FAULT entry/exit, and diagnostic message scenarios to `day_night_simulation`; grew test pass set from 1 to 12 scenarios | Verification gap: negative-path and robustness edge cases were not exercised | 2026-03-23 |

---

## Process Notes

- **Priority P0-Critical:** must be resolved before delivery gate / capability level demonstration
- **Priority P1-Major:** required for complete process adherence and audit readiness
- **Priority P2-Observation:** recommended improvements for maturity and defect prevention
- **Target dates use M5+N notation:** relative to baseline completion milestone (M5); e.g., M5+1 = next 1 working day, M5+2 = within 2 days

---

## Summary

- **Total open CRs:** 18 (11 from assessment, 3 retrospective feature, 4 enhancement observations)
- **Critical path:** CR-001, CR-002, CR-003 must close first to enable the rest
- **Effort estimate (P0+P1+P2):** ~40 hours across roles
- **Recommended execution sequence:** See prioritization table in preceding assessment report
