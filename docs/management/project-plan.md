---
Revision: 2.2
Date: 2026-03-27
Author: Project Manager
Status: Approved
---

# Project Plan

## Scope
Deliver a software component that polls luminance over CAN every 5 seconds, determines `DAY` or `NIGHT`, responds to state queries, and supports state-change notifications for registered consumers.

## Roles
- Project Manager
- Requirements Engineer
- Software Architect
- Software Designer/Engineer
- Software Integrator
- Software Tester
- Software Integration Tester
- Software Qualification Tester

## Work Packages
1. Management and baseline setup
2. Requirements engineering
3. Software architecture
4. Detailed design and implementation
5. Software integration
6. Unit verification
7. Software integration testing
8. Software qualification testing

## Deliverables
- Project planning and control artifacts
- Stakeholder, system, and software requirements specifications
- Architecture and detailed design
- Source code, build recipe, and self-contained tests
- Integration strategy and verification specifications
- Traceability matrix and support process artifacts

## Milestones

### M1: Requirements Baseline Approved
- **Target Date:** 2026-03-15
- **Actual Date:** 2026-03-09
- **Duration:** +3 days slip
- **Effort Estimate:** 8h (Requirements Engineer)
- Entry: Scope agreed and assumptions recorded
- Exit: Requirements are uniquely identified, testable, and traced

### M2: Architecture Baseline Approved
- **Target Date:** 2026-03-17
- **Actual Date:** 2026-03-19
- **Duration:** +2 days slip
- **Effort Estimate:** 6h (Software Architect)
- Entry: Requirements baseline approved
- Exit: Architecture defines software elements, interfaces, message contracts, and allocations

### M3: Code and Detailed Design Complete
- **Target Date:** 2026-03-19
- **Actual Date:** 2026-03-21
- **Duration:** +2 days slip
- **Effort Estimate:** 12h (Software Designer/Engineer)
- Entry: Architecture approved
- Exit: Source code, detailed design, and unit tests are aligned and reviewable

### M4: Integrated Baseline Available
- **Target Date:** 2026-03-22
- **Actual Date:** 2026-03-23
- **Duration:** +1 day slip
- **Effort Estimate:** 4h (Software Integrator)
- Entry: Units verified and configuration items identified
- Exit: Integrated baseline builds reproducibly and passes smoke checks

### M5: Verification Evidence Complete
- **Target Date:** 2026-03-23
- **Actual Date:** 2026-03-23
- **Duration:** On track
- **Effort Estimate:** 10h (Test roles + Qualification Tester)
- Entry: Integrated baseline frozen for test
- Exit: Unit, integration, and qualification evidence recorded with residual risk assessment

### M6: Corrective Action Phase (Final)
- **Planned Duration:** 2026-03-24 to 2026-03-25 (2 working days)
- **P0 Target:** Close all P0-Critical CRs by EOB 2026-03-24
- **P1 Target:** Close all P1-Major CRs by EOB 2026-03-25
- **Total Effort (Planned):** 18.5h across all roles
- **Total Effort (Actual):** 26.5h across all roles
- **Variance:** +8h (43% overage) — due to 7 additional P2-Observation CRs (CR-012–CR-018) executed in parallel with P0+P1 critical path (not initially planned for M6 timeline)
- Entry: M5 baseline frozen; assessment findings and CR log approved
- Exit: P0, P1, and P2 corrective actions closed; audit-ready evidence package

## Effort Distribution by Role (All Phases)

| Role | M1 | M2 | M3 | M4 | M5 | M6-CA (Plan) | M6-CA (Actual) | Total |
|---|---|---|---|---|---|---|---|---|
| Project Manager | 2h | 1h | 1h | 1h | 2h | 10.5h | 13.5h | 21.5h |
| Requirements Engineer | 6h | 1h | 0h | 0h | 1h | 2h | 3h | 13h |
| Software Architect | 1h | 4h | 1h | 0h | 1h | 1h | 1.5h | 9.5h |
| Software Designer/Engineer | 0h | 0h | 8h | 1h | 1h | 1h | 2h | 13h |
| Software Integrator | 0h | 0h | 2h | 4h | 0h | 0h | 0h | 6h |
| Software Tester | 0h | 0h | 2h | 1h | 4h | 2h | 4h | 13h |
| Software Integration Tester | 0h | 0h | 0h | 0h | 2h | 1h | 1h | 4h |
| Software Qualification Tester | 0h | 0h | 0h | 0h | 3h | 1h | 1.5h | 5.5h |
| **Subtotal** | **9h** | **6h** | **14h** | **7h** | **14h** | **18.5h** | **26.5h** | **94.5h** |

---

## Assumptions and External Dependencies
- Vehicle CAN network allocates provisional message IDs (R-001, R-007 risks: pending confirmation)
- Luminance sensor response timing compatible with 5-second poll interval (R-003 risk: pending vehicle integration)
- Final timeout value configurable during vehicle bring-up (R-006 risk: pending vehicle integration)
- Assessment findings and corrective action plan approved by stakeholders (2026-03-23)

---

## Process Quality Objectives (PA 2.1 Enablement)

**Purpose:** Establish per-process performance objectives to enable Capability Level 2 (Managed) for all 13 assessed processes. Each objective includes monitoring criteria, owners, and success indicators aligned to A-SPICE PA 2.1 evidence requirements.

### Engineering Processes

#### SWE.1 — Software Requirements Analysis

| Objective | Target | Monitoring | Owner | Success Indicator |
|-----------|--------|------------|-------|-------------------|
| Requirements completeness and traceability | 100% of SWE requirements (13/13) uniquely identified with testable acceptance criteria | Monthly review of traceability matrix; validate 100% bidirectional linkage (SWE ↔ SYS ↔ UT/IT/QT) during M3 and M5 gates | Requirements Engineer | Traceability matrix shows 13 SWE with all cross-references verified; no gaps in verification mapping |
| Requirement change impact analysis | All changes submitted as CRs with scope, owner, effort, approval logged | Every CR evaluated within 24h of submission; impact recorded in CR-log before implementation | Software Architect + Requirements Engineer | CR-log shows complete impact assessment for all 27 CRs; Assessment 3 shows no traceability degradation vs. A2 baseline |

#### SWE.2 — Software Architectural Design

| Objective | Target | Monitoring | Owner | Success Indicator |
|-----------|--------|------------|-------|-------------------|
| Architecture completeness: interface contracts, element allocation, design rationale | 100% allocation of 13 SWE to 3 architectural components (CAN Protocol, Day/Night Controller, Main); 8 message contracts defined; all architectural decisions documented | Quarterly architecture review; validate mapping consistency against SWE traceability matrix at M2 gate and post-CR phases | Software Architect | Architecture document shows 100% element-to-requirement mapping; design rationale recorded for all 3 major decisions; CAN interface matrix populated with 8 messages, direction, payload |
| Architectural consistency verification | No deviations between documented architecture and implemented source code detected during code review | Static code review at M3 gate and M4 integration; validate file organization, component boundaries, interface protocols match architecture document | Software Architect | Code review checklist signed-off; mapping table in design document confirmed current; no rework CRs needed due to architecture drift |

#### SWE.3 — Software Detailed Design and Unit Construction

| Objective | Target | Monitoring | Owner | Success Indicator |
|-----------|--------|------------|-------|-------------------|
| Detailed design completeness: unit-level design documented, coding standard applied, all units implement assigned requirements | 100% of source files (4 core + 1 test) documented; 100% compliance to ISO/IEC 14882:2020 + project conventions defined in QA plan | Code scan by clang-tidy at each commit; design document updated at M3; final design review at M3→M4 gate | Software Designer/Engineer | Detailed design document references all 4 core units with data structures, error handling; clang-tidy scan shows zero violations; M3 design review sign-off collected |
| Unit implementation and build reproducibility | All source units compile cleanly via `ninja -f build.ninja`; clean working tree at integration baseline | Reproducible build verified at M4 integration gate with UTC timestamp and commit hash recorded in integration report | Software Integrator + Software Designer/Engineer | Integration report documents clean build timestamp; build/day_night_tests, build/day_night_simulator, build/video_pipeline_desktop all produced; smoke tests pass |

#### SWE.4 — Software Unit Verification

| Objective | Target | Monitoring | Owner | Success Indicator |
|-----------|--------|------------|-------|-------------------|
| Unit test coverage: ≥80% statement, ≥70% branch (or approved rationale) | 14 unit tests pass with coverage measured and recorded; targets met or variance documented | Coverage measurement executed post-M4 integration; results recorded in unit test report and measurement dashboard; quarterly reviews track trend | Software Tester | Measurement dashboard displays 87% statement, 78% branch coverage (baseline 44a7d7c, date 2026-03-26); all 14 UT pass; traceability table shows SWE-001 through SWE-013 mapped with coverage scope noted |
| Unit test traceability and defect closure | 100% of unit tests (14/14) linked to SWE requirements; all defects found during UT closure handled via CR log | Test traceability audited at M4 gate and quarterly; CR log reviewed to confirm all UT-discovered issues closed with root cause and fix documented | Software Tester | Unit test report shows 14 tests with 14 unique SWE links (1:1 or M:1); no orphaned tests; all CR closure records artifact-verified |

#### SWE.5 — Software Integration and Integration Testing

| Objective | Target | Monitoring | Owner | Success Indicator |
|-----------|--------|------------|-------|-------------------|
| Integration strategy completeness: all interfaces verified, integration order justified, test evidence recorded | 6-step integration order defined with baseline contents explicit; 12 integration scenarios (IT-001–IT-012) execute and pass | Integration strategy reviewed at M2 gate; integration report at M4 gate documents reproducible build, commit hash, UTC timestamp, and all 12 IT pass status | Software Integrator + Software Integration Tester | Integration strategy document approved by Software Architect; integration report shows: (1) build reproducibility confirmed, (2) all 12 IT pass, (3) commit baseline documented, (4) residual risks and escalation triggers noted |
| Integration test handoff decision | Explicit ACCEPTED or CONDITIONAL recommendation with known residual risk stated; all integration anomalies escalated to CR or risk register | Integration test execution monitored at M4; handoff decision recorded in integration report and communicated to qualification test phase before M5 start | Software Integration Tester | Integration report contains explicit handoff section: "ACCEPTED" recommendation with residual risk list cross-referenced to risk-register.md; risk owners assigned monitoring actions |

#### SWE.6 — Software Qualification Testing

| Objective | Target | Monitoring | Owner | Success Indicator |
|-----------|--------|------------|-------|-------------------|
| Qualification test scope and execution: 100% of SWE (13/13) covered by operational scenarios; all scenarios pass | 10 qualification scenarios (QT-001–QT-010) defined to exercise all SWE requirements; all pass with baseline hash and execution date recorded | Qualification test report produced at M5 gate; scenario execution evidence (pass/fail, timestamp, baseline) recorded for all 10 QT; requirements traceability updated post-execution | Software Qualification Tester | Qualification test report lists QT-001–QT-010 individually with pass status, baseline (44a7d7c), execution date (2026-03-23); traceability section shows 13 SWE with all passing scope; measurement dashboard shows 10/10 pass |
| Release-readiness decision and residual risk acceptance | Explicit release recommendation (RECOMMENDED or CONDITIONAL) with residual risk list, acceptance decision, and owner escalation triggers documented | Release decision made at M5 gate by Project Manager + Software Architect after review of qualification report, risk register, and measurement dashboard | Software Qualification Tester + Project Manager | Qualification test report contains release section: explicit recommendation, residual risk list (cross-referenced to risk-register.md), acceptance rationale, and escalation decision recorded; all 4 open risks documented as "Accept residual" with monitoring controls |

### Management Processes

#### MAN.3 — Project Management

| Objective | Target | Monitoring | Owner | Success Indicator |
|-----------|--------|------------|-------|-------------------|
| Project plan completeness and schedule alignment | All milestones M1–M6 have target and actual dates; effort estimates per role; assumptions and external dependencies documented; variance ≤ 5% of total effort or explained | Status review meetings every 2 working days during M6-CA; milestone actuals reconciled against plan; variance explained in measurement dashboard or project plan M6 section | Project Manager | Project plan shows M1–M5 actual dates (M1=2026-03-09, M5=2026-03-23); M6 effort variance (+8h, +43%) documented with root cause; next assessment date target 2026-04-15 confirmed |
| Corrective action tracking completeness | All assessment findings mapped to CRs; CR-log populated with 27 total CRs (18 A1 + 9 A2); CA-log status synchronized with CR completion status | CA-log reviewed at every status gate; any CR marked "Completed" must have artifact verification evidence collected; stale statuses flagged for immediate update | Project Manager | Corrective-action-log.md shows CA-01 through CA-17 all marked "Completed" with last-updated date 2026-03-26; CR-log.md confirms all 27 CRs "Closed" with artifact verification timestamps |
| Stakeholder communication and decision recording | Status review records produced at M1→M2, M2→M3, M3→M4, M4→M5, M5→M6 transitions; all attendees named or role-equivalent attested; approval decisions documented with date and owner signature | Status review documents stored in docs/management/ directory with Revision, Date, Author, Status headers; all records current and approved before next phase start | Project Manager | Status review M5 document (status-review-m5-final-and-cr-phase.md) shows all 8 roles named/attested, decisions recorded for M6 approval, sign-off block completed; no [Name] placeholders remain |

#### MAN.5 — Risk Management

| Objective | Target | Monitoring | Owner | Success Indicator |
|-----------|--------|------------|-------|-------------------|
| Risk identification, assessment, and monitoring | All project risks (7 total) identified by end of M1; each assigned Likelihood, Severity, Priority; open risks monitored quarterly with decision record | Risk register reviewed at each milestone gate; new risks added with priority within 24h of identification; closed risks recorded with closure date and rationale | Project Manager + Risk Owners (Designated roles per risk) | Risk-register.md shows 7 risks (R-001–R-007) with L/S/P ratings complete; 4 open risks have explicit "Accept residual" decision dated 2026-03-23; 3 closed risks documented with closure date and rationale; monitoring triggers defined for open items |
| Escalation and decision transparency | All escalations (threshold: Medium-or-higher risks or schedule variance >5%) logged with owner, date, decision, and action items | Risk register cross-referenced in project plan and status review records; escalation decisions recorded in status review "Management Decisions" section with owner accountability | Project Manager | Project plan M6 section notes M6 effort overage (+8h) as escalation decision; status review shows risk acceptance decision dated 2026-03-23 for R-001, R-003, R-006, R-007; no silent variances in dashboard |

#### MAN.6 — Measurement

| Objective | Target | Monitoring | Owner | Success Indicator |
|-----------|--------|------------|-------|-------------------|
| Product quality measurements: completeness and accuracy | All work product deliverables measured: 13 SWE traced, 10 QT pass, 12 IT pass, 14 UT pass, 87% statement coverage, 78% branch coverage; baseline hash and date recorded | Measurement dashboard updated at each milestone gate (M1 through M5); coverage metrics collected post-M4; QT/IT/UT counts verified against test report totals | Project Manager (Measurement Owner) + Test Roles | Measurement dashboard Revision 2.0+ lists: Requirements traced 13/13, UT pass 14/14, IT pass 12/12, QT pass 10/10, Statement coverage 87%, Branch coverage 78%, all dated 2026-03-26 baseline 44a7d7c; no discrepancies between dashboard and individual test reports |
| Project management measurements: schedule and effort tracking | Milestone target vs. actual dates tracked; effort estimates vs. actuals recorded per role and phase; variance explanation provided for any deviation >10% | Measurement dashboard includes "Effort Distribution" table with Plan vs. Actual columns for M1–M6-CA; M6 variance explained in notes below table | Project Manager | Measurement dashboard shows M1–M5 milestone dates on-track or with slips explained; M6 actual 26.5h vs. plan 18.5h with explanation: "7 additional P2 CRs executed in parallel"; no silent effort variances |
| Traceability and quality indicators: consistency across all reports | Traceability matrix, unit/integration/qualification test reports, and measurement dashboard report consistent SWE requirement counts (13) and test pass rates (14 UT, 12 IT, 10 QT) | Monthly audit of traceability matrix against all test reports; any discrepancies (e.g., UT-006/007/009 wrong SWE link) flagged and corrected within 48h via CR | Software Architect (Traceability Owner) | Traceability matrix dated 2026-03-26 shows 13 SWE with 100% bidirectional linkage to UT/IT/QT; all requirement counts match across project-plan.md, measurement-dashboard.md, and test reports; assessment 3 A2 CR-019 verified closed (UT requirement links corrected) |

### Support Processes

#### SUP.1 — Quality Assurance

| Objective | Target | Monitoring | Owner | Success Indicator |
|-----------|--------|------------|-------|-------------------|
| QA plan execution: all planned review activities conducted and evidenced | 5 planned QA activities (requirements review, architecture review, design review, test spec review, traceability check) executed with audit records; all findings escalated to CR log | QA audit records created in docs/support/qa-audit-records.md; each record includes: activity date, scope, items checked, findings or "no findings", disposition; records reviewed and approved by QA role during M3→M5 gates | Project Manager (SUP.1 Owner) | QA audit records document 5 activities dated 2026-03-14 through 2026-03-23 (one per week); all records show approval status; any findings linked to CR-log with cross-reference (e.g., CR-007 corrected design review finding); zero orphaned observations |
| Coding standard compliance and tool configuration | ISO/IEC 14882:2020 defined in QA plan; `.clang-format` configuration file tracked as CI in repository; all source code passes clang-tidy scan zero-violations | Clang-tidy scan executed at every commit via CI hook; results recorded in repo or testing log; `.clang-format` file in repository root reviewed quarterly for compliance evolution | Software Designer/Engineer | Repository root contains `.clang-format` (tracked as CI); clang-tidy scan log shows zero violations on baseline 44a7d7c; QA plan version 1.0+ references implemented tool (not placeholder); clang format output consistent across all 4 core source files |
| Non-conformance escalation and closure | All quality findings (observations from reviews, test failures, code issues) logged as CRs or risk register entries; closure verified before release gate | QA role reviews all open CRs and risk register entries 48h before each milestone gate; any non-conformance without root cause recorded marked "escalate to Project Manager" | Project Manager + QA Owner | QA audit records show escalation notes for each activity; status review M5 document lists all 9 A2 CRs resolved with CR-log evidence; zero non-conformances remain open past M5 gate without escalation |

#### SUP.8 — Configuration Management

| Objective | Target | Monitoring | Owner | Success Indicator |
|-----------|--------|------------|-------|-------------------|
| Configuration items and baselines: completeness and traceability | All CIs identified and tracked in CM plan; 2 major baselines established (v0.1.0-draft at 44a7d7c, ready-for-assessment2 at dc44320); integration baseline documented at M4 | CM plan reviewed at M1 gate; CI identification verified at M3 gate; baseline creation timestamps and commit hashes recorded in integration and test reports | Software Integrator | Configuration-management-plan.md lists 8 CIs (source files, tests, build recipe, docs); integration report for M4 documents baseline commit 44a7d7c with UTC timestamp and clean working tree certification; assessment 3 baseline planned: "ready-for-assessment3" tag at d33fcd0 equivalents |
| Change traceability and reproducible builds | All changes traceable to CRs; reproducible builds demonstrated at M4 integration gate with "ninja -t clean && ninja -f build.ninja" and clean working tree certification; all test reports reference baseline hash | Build reproducibility test executed at M4 gate; output recorded in integration report with UTC timestamp; all test reports (UT, IT, QT) document baseline hash and execution environment details | Software Integrator + Test Roles | Integration report shows: clean baseline hash (44a7d7c), UTC timestamp (2026-03-23 HH:MM:SS), "clean working tree: PASS"; all test reports cite same baseline hash with execution date; no build environment surprises documented |

#### SUP.9 — Problem Resolution

| Objective | Target | Monitoring | Owner | Success Indicator |
|-----------|--------|------------|-------|-------------------|
| Problem identification, tracking, and closure | All discovered problems logged in problem-resolution-log.md with ID, detected date, status, resolution date, and impact; status vocabulary consistent (no contradictory states) | Problem log reviewed at each status gate; new problems added within 24h of detection; status updates synchronized with CR-log when problems are addressed via corrective action | Project Manager (SUP.9 Owner) | Problem-resolution-log.md lists 6 problems (PR-001–PR-006) with consistent status values: "Closed" or "Conditionally Closed (Monitoring)" (no "Resolved" + "Open (Monitoring)" contradictions); all dates match corresponding CR closure dates or monitoring decision dates |
| Escalation and mitigation tracking | High-impact problems (severity = High or priority = P0/P1) escalated to risk register and project plan within 24h; mitigation strategies documented | Risk register cross-referenced from problem log; escalation decision (escalate to risk, close, or accept residual) recorded in status review with owner accountability | Project Manager | Risk-register.md shows 2–3 problems escalated as risks (linked by ID); problem log contains escalation date and decision; status review documents escalation decision for any high-priority problems discovered during M3–M5 |

#### SUP.10 — Change Request Management

| Objective | Target | Monitoring | Owner | Success Indicator |
|-----------|--------|------------|-------|-------------------|
| Change request registry: completeness and traceability | All changes (product and process) registered in CR-log.md; 27 total CRs (18 A1 assessment-driven + 9 A2 assessment-driven); each CR has ID, title, scope, owner, priority, effort estimate, target date, and status | CR-log reviewed at every status gate; new CRs added within 24h of decision; closed CRs archived with completion date and artifact verification evidence | Project Manager (SUP.10 Owner) | Change-request-log.md lists 27 CRs with complete fields; 18 A1 CRs marked "Closed" (2026-03-14 to 2026-03-23); 9 A2 CRs marked "Closed" (2026-03-20 to 2026-03-26); artifact verification evidence collected for each (e.g., "CR-019: Artifact UT-report updated, traceability verified 2026-03-20") |
| Effort and acceptance tracking | All CRs tracked through PLAN → IMPLEMENT → VERIFY → CLOSE lifecycle; effort actuals recorded; exit criteria documented and verified before closure | CR status updated weekly or upon completion; effort actuals logged in CR-log; exit criteria verification evidence (e.g., commit hash, document review, test pass) recorded before status changed to "Closed" | Project Manager + Role Owners | CR-log shows effort actuals vs. plan for all 27 CRs (e.g., "CR-001 effort: 1h planned, 1.5h actual"); every CR marked "Closed" has exit criteria evidence linked (commit, test output, or document review); M7 corrective action closure audit shows 27/27 evidence-verified |
| Traceability to product and process improvements | All product changes (code, tests, design) traceable to CR; all process improvements (procedure changes, tool additions, doc headers) logged as CRs; no silent changes to CIs | Every CR includes "Impact" section describing affected CIs; deployment/rollout plan includes CR reference; rollback procedures document CR dependencies if needed during integration | Software Integrator (Product CIs) + Project Manager (Process CIs) | CR-log CR-022 documents: "Impact: all 26 work products receive YAML headers for PA 2.2 readiness"; CR-025 documents: ".clang-format tracking as CI"; All CIs updated are cross-referenced back to originating CR |

---

## Measurement Baseline (M8+1 Reconciliation)

**Measurement Date:** 2026-03-27  
**Baseline Revision:** 44a7d7c (final product baseline from M5)  
**Assessment 2 Tag:** ready-for-assessment2 (dc44320)  
**M7 Improvements Tag:** draft-for-assessment3 (d33fcd0)  
**Assessment 3 Target:** 2026-04-15

All 13 process quality objectives are now formally documented and tracked. Success indicators are measurable and will be audited at M8+2 formal review gate.