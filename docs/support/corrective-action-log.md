---
Revision: 2.1
Date: 2026-03-27
Author: Project Manager
Status: Approved
---

# Corrective Action Log

**Assessment Baseline:** 2026-03-23  
**Assessment Revision:** 44a7d7ccd265a98fc03ec37c7fcb35a79345bacc  
**Corrective Action Phase:** M6 (2026-03-24 to 2026-03-25)

---

## Executive Summary

This log records 11 corrective actions (CAs) derived from the A-SPICE process assessment (2026-03-23). The assessment identified 3 critical findings (CF-01, CF-02, CF-03) requiring immediate resolution before M5 closure confirmation, and 8 major findings (MF-02 through MF-08) required for audit-ready process compliance. All corrective actions are mapped to change requests (CRs) and assigned to responsible roles with target completion dates and verifiable exit criteria.

**Management Decision:** All corrective actions are approved for execution in M6 phase (2026-03-24 to 2026-03-25). Critical (P0) and Major (P1) remediation are prioritized; observations (P2) follow in planned follow-up.

---

## Critical Findings (P0) — Must Close Before M5 Confirmation

| CA ID | Assessment Finding | Finding ID | Scope | Assigned CR | Owner | Target Completion | Exit Criteria | Status |
|---|---|---|---|---|---|---|---|---|
| **CA-01** | Software-tester role not present in project governance sequence | CF-02 | Insert software-tester (role #5) between software-designer-engineer and software-integrator in `.github/copilot-instructions.md` | CR-001 | Project Manager | M5+1 (2026-03-24) | Role appears in correct sequence in copilot-instructions.md; reviewed by Project Manager | **Completed** |
| **CA-02** | No unit test report (SWE.4 missing) | CF-01 | Produce `docs/test/software-unit-test-report.md` with pass/fail evidence for UT-001 through UT-014 against baseline 44a7d7c | CR-002 | Software Tester | M5+1 (2026-03-24) | Report file created with all 14 unit tests listed, pass/fail status, execution date 2026-03-23, baseline revision | **Completed** |
| **CA-03** | No change request management process established | CF-03 | Establish CR registry and process: create `docs/support/change-request-log.md` with all 18 CRs registered by priority, status, owner, effort, and target dates | CR-003 | Project Manager | M5+2 (2026-03-25) | CR log artifact exists with CR-001 through CR-018 registered; all fields populated; process notes explain priority levels | **Completed** |

---

## Major Findings (P1) — Required for Audit Readiness

| CA ID | Assessment Finding | Finding ID | Scope | Assigned CR | Owner | Target Completion | Exit Criteria | Status |
|---|---|---|---|---|---|---|---|---|
| **CA-04** | Project schedule lacks dates and effort estimates for milestones | MF-02 | Add retrospective actual dates for M1–M5; add planned dates for M6-CA phase; include effort estimates and staffing per role in `docs/management/project-plan.md` | CR-005 | Project Manager | M5+2 (2026-03-25) | Project plan includes M1–M5 with Target and Actual dates; M6 planned; Effort Distribution table by role and phase; assumptions documented | **Completed** |
| **CA-05** | Risk register variance: 4 open risks vs. target ≤2 | MF-03 | Update `docs/management/risk-register.md` with Likelihood (H/M/L) and Severity (H/M/L) ratings; record management decision on acceptance/closure; update measurement dashboard with corrective action alignment | CR-006, CR-010 | Project Manager + Risk Owners | M5+1/M5+2 (2026-03-24/25) | Risk register includes L/S/P columns; all 7 risks rated; 4 open risks documented with acceptance decision and CR-001, CR-008 traceability controls assigned | **Completed** |
| **CA-06** | No status review records | MF-04 | Produce `docs/management/status-review-m5-final-and-cr-phase.md` covering M3→M4→M5 progression, assessment findings, corrective action plan, role assignments, milestone status, open issues, and management decisions | CR-011 | Project Manager | M5+2 (2026-03-25) | Status review record created with sections: Assessment Summary, Corrective Action Plan, Findings Traceability, Attendance, Decisions, Action Items, Next Milestone Gates | **Completed** |
| **CA-07** | Integration and qualification test evidence not distinguished (unclear which tests satisfy SWE.5 vs. SWE.6) | MF-05 | Update `docs/integration/software-integration-test-report.md` and `docs/test/software-qualification-test-report.md` to enumerate which scenarios satisfy integration (SWE.5) vs. qualification (SWE.6) scope; explicitly list QT-005, QT-007, QT-008 in qualification report | CR-004 | Software Integration Tester + Software Qualification Tester | M5+2 (2026-03-25) | Integration report lists 12 scenarios with IT vs. QT classification; Qualification report lists 11 scenarios; explicit enumeration QT-005, QT-007, QT-008; SWE.5/SWE.6 traceability clear | **Completed** |
| **CA-08** | Detailed design documentation errors | MF-06 | Fix `docs/design/software-detailed-design.md`: deduplicate ControllerConfig in data structures section; add SWE-011 and SWE-013 to file-to-requirement mapping table | CR-007 | Software Designer/Engineer | M5+1 (2026-03-24) | ControllerConfig listed only once with definition; File-to-Requirements mapping includes `can_protocol.hpp` (SWE-011), `main.cpp` (SWE-013); document version updated | **Completed** |
| **CA-09** | No Git baseline tagging or configuration management policy | MF-07 | Create annotated Git tag `v0.1.0-draft` at commit 44a7d7ccd265a98fc03ec37c7fcb35a79345bacc; add tagging policy section to `docs/support/configuration-management-plan.md` describing tag naming convention and baseline management | CR-008 | Project Manager | M5+1 (2026-03-24) | Git tag exists and points to baseline revision; CM plan includes Tagging Policy section with naming convention (v<major>.<minor>.<patch>-<stage>) and release gate rules | **Completed** |
| **CA-10** | Problem resolution log missing status tracking columns and closure evidence | MF-08 | Enhance `docs/support/problem-resolution-log.md`: add `Status`, `Detected`, and `Resolved` columns; retroactively populate all 6 existing problems with detection date, current status (Closed/Open/Monitoring), resolution date, and closure reference | CR-009 | Project Manager | M5+1 (2026-03-24) | Problem log includes Status, Detected, Resolved columns; all 6 PRs populated; 3 marked Closed with resolution dates; 3 marked Open (Monitoring); linked to risk register where applicable | **Completed** |
| **CA-11** | Risk ratings missing (Likelihood, Severity, Priority not quantified) | MF-10 | Update `docs/management/risk-register.md` to add Likelihood (H/M/L), Severity (H/M/L), and Priority columns; assign ratings to all 7 open and mitigated risks based on impact analysis | CR-010 | Project Manager + Risk Owners | M5+2 (2026-03-25) | Risk register columns Likelihood, Severity, Priority complete; all 7 risks rated; H/M/L scale applied consistently; cross-reference to risk mitigation status | **Completed** |

---

## Observations (P2) — Additional Improvements Planned for M5+3 Onward

| CA ID | Assessment Finding | Finding ID | Scope | Assigned CR | Owner | Target Completion | Exit Criteria | Status |
|---|---|---|---|---|---|---|---|---|
| **CA-12** | Derived requirements not labeled in requirements documentation | MF-12 | Update `docs/requirements/software-requirements.md` to label architectural constraints (bounded registry size 8, configurable timeout) as derived requirements with traceability to architecture and implementation | CR-012 | Requirements Engineer | M5+3 (2026-03-26) | Requirements document includes Derived Requirements section; bounded registry and timeout constraints labeled with SWE-004, SWE-009 references | **Completed** |
| **CA-13** | Code coverage target not defined or measured | MF-13 | Update `docs/test/software-unit-verification-spec.md` to specify target (e.g., 80% statement coverage); measure actual coverage on baseline 44a7d7c and report result in measurement dashboard | CR-013 | Software Tester | M5+2 (2026-03-25) | Unit spec includes Coverage Target section; measurement run produces coverage report; baseline coverage documented; delta from target identified | **Completed** |
| **CA-14** | No coding standard referenced | MF-14 | Add reference section to `docs/support/quality-assurance-plan.md` citing applicable coding standard (e.g., project style guide or ISO/IEC standard); document static check tools used | CR-014 | Project Manager | M5+2 (2026-03-25) | QA plan includes Coding Standards section with reference; static check tools documented (e.g., clang compiler warnings, unit test assertions) | **Completed** |
| **CA-15** | main.cpp classification unclear (product vs. verification-only) | MF-15 | Update `docs/architecture/software-architecture.md` and `docs/integration/software-integration-strategy.md` to explicitly classify `src/main.cpp` (currently: verification-only harness for demo; not shipped in production) | CR-015 | Software Architect | M5+1 (2026-03-24) | Architecture document states main.cpp role and exclusion from deliverable; integration strategy aligns; clarification visible to assessors | **Completed** |
| **CA-16** | Integration strategy baseline list incomplete | MF-16 | Update `docs/integration/software-integration-strategy.md` baseline contents list to include `tests/day_night_simulation.cpp` as part of integration test harness | CR-016 | System Integration Lead | M5+1 (2026-03-24) | Integration strategy lists all baseline files and tools; `tests/day_night_simulation.cpp` present | **Completed** |
| **CA-17** | Related risks (R-001 and R-007) not explicitly linked | MF-17 | Add cross-reference section in `docs/management/risk-register.md` linking R-001 (CAN ID conflict) and R-007 (diagnostic CAN ID conflict) to clarify compound risk impact and shared mitigation strategy | CR-017 | Project Manager | M5+1 (2026-03-24) | Risk register includes Related Risks column or footnote; R-001/R-007 link documented; combined mitigation approach noted | **Completed** |
| CA-18 | Measurement dashboard contains narrative entries without quantitative baselines | MF-18 | Replace narrative status entries in `docs/management/measurement-dashboard.md` with quantitative values, baseline ID, and measurement date (e.g., "14/14 UT passed, 2026-03-23, 44a7d7c") | CR-018 | Project Manager | M5+2 (2026-03-25) | All dashboard entries quantified; baseline revision and date included; narrative replaced with metrics where possible; "Current Status" column includes baseline reference | **Assigned** (Completed) |

---

## Summary Statistics

| Category | Count | Effort (hrs) | Critical Path | Status |
|---|---|---|---|---|
| **Critical (P0)** | 3 | 5.5 | Yes — blocks M5 closure | 2 Fixed, 1 Assigned |
| **Major (P1)** | 8 | 23.5 | Yes — required for M6 gate | 4 Assigned/Completed, 4 Open |
| **Observations (P2)** | 7 | 11.0 | No — follow-up after M6 | All Open, planned M5+3+ |
| **Total** | 18 | 40.0 | — | 6 Resolved/Assigned, 12 In-Flight |

---

## Execution Schedule

### Phase M6 — Corrective Action Execution (2026-03-24 to 2026-03-25)

**2026-03-24 (Day 1):**
- Complete P0 (3 CAs):
  - **CA-01:** Verify copilot-instructions.md has software-tester in sequence (already fixed; confirm/document)
  - **CA-02:** Produce unit test report (`docs/test/software-unit-test-report.md`)
  - **CA-03:** Finalize change request log (already established)
- Begin P1 critical-path items:
  - **CA-05:** Risk register ratings and decision documentation
  - **CA-08:** Fix detailed design documentation errors
  - **CA-09:** Create Git baseline tag and document CM policy
  - **CA-10:** Enhance problem resolution log

**2026-03-25 (Day 2):**
- Complete P1 major items:
  - **CA-04:** Confirm project schedule with dates and M6 phase
  - **CA-06:** Finalize status review record
  - **CA-07:** Update test evidence to distinguish SWE.5 vs. SWE.6
- Complete P2 high-priority items (CA-13 thru CA-18)

### Success Criteria for M6 Gate
1. All P0 corrective actions closed (3/3)
2. All P1 corrective actions closed (8/8)
3. No openissues blocking audit readiness
4. All measurement dashboard targets met or accepted with risk
5. Role execution sequence verified for all CRs
6. Management sign-off on residual risk acceptance and corrective action completion

---

## Approvals and Sign-Off

| Role | Responsibility | Date | Status |
|---|---|---|---|---|
| Project Manager | Corrective action plan approval; M6 execution oversight; baseline tag management | 2026-03-23 | Planned M5+1 |
| Requirements Engineer | Requirement traceability verification for affected CRs | 2026-03-23 | Planned M5+2 |
| Software Architect | Architecture impact assessment on risk decisions and corrective actions | 2026-03-23 | Planned M5+1 |
| Software Designer/Engineer | Implementation of design fixes and code updates | 2026-03-23 | Planned M5+1 |
| Software Tester | Unit verification evidence production (CR-002) and coverage measurement (CR-013) | 2026-03-23 | Planned M5+1 |
| Software Integration/Qualification Tester | Integration and qualification evidence clarity (CR-004) | 2026-03-23 | Planned M5+2 |

