# A-SPICE Assessment Report — Assessment 2

**Project:** Luminance Day/Night State Manager  
**Assessor Role:** A-SPICE Certified Assessor  
**Assessment Date:** 2026-03-23  
**Assessment Baseline:** `ready-for-assessment2` → commit `dc44320`  
**Product Baseline:** `v0.1.0-draft` → commit `44a7d7c`  
**Assessment Standard:** Automotive SPICE PAM 4.0 / ISO/IEC 33002  
**Scope:** SWE.1–SWE.6, MAN.3, MAN.5, MAN.6, SUP.1, SUP.8, SUP.9, SUP.10  
**Previous Assessment:** Assessment 1 (pre-M6), findings resolved via 18 CRs, tag `ready-for-assessment2`

---

## 1. Executive Summary

This second assessment covers the project at the `ready-for-assessment2` tag, following the M6 corrective action phase that addressed all 18 findings raised in Assessment 1. The assessment evaluates 13 process areas across engineering, management, and support process groups.

**Assessment 1 finding resolution: CONFIRMED.** All 18 change requests are closed and the corresponding artifacts have been updated. The three critical findings (CF-01: software-tester governance gap; CF-02: missing derived requirements; CF-03: no CR process) are fully resolved.

**Overall Project Capability Level: CL1 (Performed)**

All 13 assessed process areas achieve Capability Level 1 (Performed). No process area achieves Capability Level 2 (Managed). The project demonstrates uniform L1 execution with strong evidence pockets — particularly in SWE.5, SUP.8, and SUP.10 — but does not yet achieve L2 due to systemic absence of document-level version/approval metadata (PA 2.2 blocker) and the lack of per-process performance management records (PA 2.1 blocker).

**Assessment 2 new findings:** 2 Major, 7 Observations. No new Critical findings.

---

## 2. Capability Level Rating Summary

| Process | Process Name | PA 1.1 | PA 2.1 | PA 2.2 | **Capability Level** |
|---------|-------------|--------|--------|--------|----------------------|
| **SWE.1** | Software Requirements Analysis | F | P | P | **CL1** |
| **SWE.2** | Software Architectural Design | F | P | P | **CL1** |
| **SWE.3** | Software Detailed Design and Unit Construction | F | P | P | **CL1** |
| **SWE.4** | Software Unit Verification | L | P | P | **CL1 ⚠** |
| **SWE.5** | Software Integration and Integration Testing | F | P | P | **CL1** |
| **SWE.6** | Software Qualification Testing | F | P | P | **CL1** |
| **MAN.3** | Project Management | L | P | P | **CL1 ⚠** |
| **MAN.5** | Risk Management | F | P | P | **CL1** |
| **MAN.6** | Measurement | L | P | P | **CL1 ⚠** |
| **SUP.1** | Quality Assurance | L | P | P | **CL1 ⚠** |
| **SUP.8** | Configuration Management | F | P | P | **CL1** |
| **SUP.9** | Problem Resolution Management | L | P | P | **CL1** |
| **SUP.10** | Change Request Management | F | P | P | **CL1** |

**PA Rating Scale:** N = Not achieved (0–15%) · P = Partially achieved (>15–50%) · L = Largely achieved (>50–85%) · F = Fully achieved (>85–100%)  
**⚠** = CL1 achieved with notable weaknesses in PA 1.1. All other CL1 ratings have PA 1.1 = Fully achieved.  
**CL2 not achieved for any process.** Universal PA 2.1=P and PA 2.2=P across all processes due to absence of per-process performance management planning and absence of document-level version/approval control.

---

## 3. Process-by-Process Assessment

### 3.1 SWE.1 — Software Requirements Analysis · **CL1**

**Artifacts reviewed:** `docs/requirements/software-requirements.md`, `docs/requirements/stakeholder-requirements.md`, `docs/requirements/system-requirements.md`, `docs/traceability/traceability-matrix.md`

**PA 1.1 — Fully Achieved (F)**

| A-SPICE Outcome | Evidence | Status |
|----------------|----------|--------|
| SW requirements derived from SYS | SH→SYS→SWE traceability chain; 13 SWE-IDs with source SYS links | ✅ |
| Derived requirements documented | SWE-004, SWE-006, SWE-009 with rationale and SYS parent reference | ✅ |
| Requirements are uniquely identified | SWE-001 through SWE-013 with unique IDs | ✅ |
| Interface requirements captured | CAN message interface defined in architecture, cross-referenced by SWE | ✅ |
| Acceptance criteria | Verification Method column at SYS level; adequate for current project scope | ✅ |

**PA 2.1 — Partially Achieved (P):** M2 milestone planned for requirements activity. No per-activity performance targets, no monitoring record, no requirements review metrics.

**PA 2.2 — Partially Achieved (P):** Documents exist in git configuration control. No document version field, no date field, no approver field in document headers. No formal review/approval record exists for any requirements document.

**L2 Gap:** Document control metadata and formal review records absent throughout.

---

### 3.2 SWE.2 — Software Architectural Design · **CL1**

**Artifacts reviewed:** `docs/architecture/software-architecture.md`

**PA 1.1 — Fully Achieved (F)**

| A-SPICE Outcome | Evidence | Status |
|----------------|----------|--------|
| Software architecture defined | Architecture document with elements, runtime sequence, CAN interface contracts | ✅ |
| Allocation of requirements to elements | Explicit requirement-function-to-element mapping table | ✅ |
| Interface contracts documented | CAN message dictionary: 8 IDs (0x500–0x540), direction, payload layout | ✅ |
| Architectural decisions captured | Rationale documented for single-controller, bounded registry, tick model | ✅ |
| Verification-only elements classified | `main.cpp` explicitly classified as non-deliverable (CR-015 resolved) | ✅ |

**PA 2.1 — Partially Achieved (P):** Architecture work planned under project milestones. No explicit architecture review meeting record, no verification of architectural consistency documented.

**PA 2.2 — Partially Achieved (P):** Document in git. No version header, no review sign-off, no baseline reference embedded in the document.

**L2 Gap:** Same as SWE.1 — document control metadata absent.

---

### 3.3 SWE.3 — Software Detailed Design and Unit Construction · **CL1**

**Artifacts reviewed:** `docs/design/software-detailed-design.md`, source file set

**PA 1.1 — Fully Achieved (F)**

| A-SPICE Outcome | Evidence | Status |
|----------------|----------|--------|
| Detailed design for all units | Units documented: `can_protocol.hpp`, `day_night_controller.hpp/.cpp`, `main.cpp`, test file | ✅ |
| Data structures and error handling | `CanFrame`, `ControllerConfig`, subscriber registry; 6 error conditions documented | ✅ |
| File-to-requirement mapping | SWE-011, SWE-013 added to mapping (CR-007 resolved) | ✅ |
| Coding standard defined | ISO/IEC 14882:2020 (C++20) + project conventions in QA plan | ✅ |
| Units implemented and compiling | C++20 source compiles cleanly via `ninja -f build.ninja`, 3 executables produced | ✅ |

**Observation:** Constructor/destructor lifecycle and initialization order are not documented. Acceptable for current non-safety-critical classification but noted as future gap.

**PA 2.1 / PA 2.2 — Partially Achieved:** Same systemic L2 gap.

---

### 3.4 SWE.4 — Software Unit Verification · **CL1 ⚠**

**Artifacts reviewed:** `docs/test/software-unit-verification-spec.md`, `docs/test/software-unit-test-report.md`

**PA 1.1 — Largely Achieved (L)**

| A-SPICE Outcome | Evidence | Status |
|----------------|----------|--------|
| Unit verification specification | 14 test cases (UT-001–UT-014) with ID, objective, expected result | ✅ |
| Coverage objectives defined | ≥80% statement, ≥70% branch; MC/DC excluded with rationale (CR-013 resolved) | ✅ |
| Test execution recorded | All 14 tests PASS with execution date and baseline hash per row | ✅ |
| Traceability to requirements | Requirement link per test case; traceability section in report | ⚠ |
| Coverage measurement | Tooling described; **actual coverage % never measured or reported** | ⚠ |

**Finding MF2-01 (Major):** UT-006, UT-007, and UT-009 all reference SWE-004 (hysteresis) as the requirement link, but these tests exercise subscription management ACK statuses — the correct requirement is SWE-007. Consequence: the traceability table in the report classifies SWE-007 as "Integration test scope / not unit-verified" when in fact unit tests do cover it. This creates a false negative traceability gap that is incorrect evidence.

**Finding OB2-03 (Observation):** Coverage targets (≥80% statement, ≥70% branch) are defined and measurement tooling is specified, but no actual coverage measurement run has been performed or recorded. Coverage percentage is absent from the test report, the measurement dashboard, and all other artifacts.

---

### 3.5 SWE.5 — Software Integration and Integration Testing · **CL1**

**Artifacts reviewed:** `docs/integration/software-integration-strategy.md`, `docs/integration/software-integration-report.md`, `docs/test/software-integration-test-spec.md`, `docs/test/software-integration-test-report.md`

**PA 1.1 — Fully Achieved (F)**

| A-SPICE Outcome | Evidence | Status |
|----------------|----------|--------|
| Integration strategy | 6-step incremental integration order; baseline contents explicit | ✅ |
| Reproducible build evidence | `ninja -t clean && ninja -f build.ninja`; UTC timestamp; clean working tree | ✅ |
| Integration test specification | IT-001–IT-008 covering all 5 interface types | ✅ |
| Integration test execution | All 12 scenarios PASS; explicit IT vs. QT scope classification | ✅ |
| Handoff decision | Explicit ACCEPTED recommendation with known residual risk stated | ✅ |
| Configuration item baseline | All 8 items listed including `day_night_simulation.cpp` (CR-016 resolved) | ✅ |

This is the strongest SWE process area in the artifact set. Particularly strong: commit-hash-level traceability in the integration report and explicit ACCEPTED handoff recommendation.

**PA 2.1 / PA 2.2 — Partially Achieved:** Same systemic L2 gap.

---

### 3.6 SWE.6 — Software Qualification Testing · **CL1**

**Artifacts reviewed:** `docs/test/software-qualification-test-spec.md`, `docs/test/software-qualification-test-report.md`

**PA 1.1 — Fully Achieved (F)**

| A-SPICE Outcome | Evidence | Status |
|----------------|----------|--------|
| Qualification test specification | 10 scenarios (QT-001–QT-010) against operational profiles | ✅ |
| All scenarios executed and passed | QT-001 through QT-010 individually enumerated in report (CR-004 resolved) | ✅ |
| SWE-001–SWE-011 traceability | Full requirement traceability section in report | ✅ |
| QT/IT scope separation | QT-005, QT-007, QT-008 evidence cross-referenced to IT scope (CR-004) | ✅ |
| Release recommendation | Explicit recommendation stated in test spec with residual risk list | ✅ |

**Finding MF2-03 (Major — see §4.2):** Measurement dashboard records "11/11 pass (QT-001–010)". The range QT-001 through QT-010 contains exactly 10 items, not 11. The qualification test report correctly states "10/10". This contradiction in a measured quality metric undermines the integrity of the dashboard.

**Observation:** No explicit approval/sign-off block in the qualification test report. No version header.

---

### 3.7 MAN.3 — Project Management · **CL1 ⚠**

**Artifacts reviewed:** `docs/management/project-plan.md`, `docs/management/status-review-m5-final-and-cr-phase.md`

**PA 1.1 — Largely Achieved (L)**

| A-SPICE Outcome | Evidence | Status |
|----------------|----------|--------|
| Project plan with scope, roles, milestones | Milestones M1–M6 with entry/exit criteria, effort distribution | ✅ |
| Resource and effort tracking | 8 roles defined; effort estimates per phase; 68.5h grand total | ✅ |
| Status review record | M5 final + M6 closure review document | ✅ |
| Corrective action tracking | Corrective-action-log with 11 CAs and exit criteria | ✅ |
| Date tracking | Target vs. actual dates recorded per milestone | ⚠ |
| Effort actuals | M6 effort discrepancy: plan=18.5h, CR log=26.5h (not reconciled) | ⚠ |

**Finding MF2-04 (Major — see §4.2):** The project plan records M1 Actual as 2026-03-18, but the status review record shows M1 as 2026-03-09. This date inconsistency across two primary management artifacts is a project data integrity problem. An assessor cannot determine the authoritative milestone actual date.

**Finding OB2-04 (Observation):** Status review attendance section contains `[Name]` placeholder text for all 8 role attendees. No named individuals are recorded. This is insufficient evidence of formal review participation.

**Finding OB2-05 (Observation):** M6 effort discrepancy — project plan M6 row shows 18.5h but summing all closed CR effort estimates in the CR log yields approximately 26.5h. Neither variance nor explanation is documented.

---

### 3.8 MAN.5 — Risk Management · **CL1**

**Artifacts reviewed:** `docs/management/risk-register.md`

**PA 1.1 — Fully Achieved (F)**

| A-SPICE Outcome | Evidence | Status |
|----------------|----------|--------|
| Risk identification | 7 risks (R-001–R-007) documented | ✅ |
| Risk assessment (L/S/P) | Likelihood, Severity, Priority columns completed (CR-010 resolved) | ✅ |
| Risk cross-references | R-001↔R-007 cross-referenced (CR-017 resolved) | ✅ |
| Management decisions | All 4 open risks have explicit "Accept residual" decision with rationale | ✅ |
| Mitigation tracking | 3 risks Closed; 4 Open with monitoring controls referencing vehicle integration | ✅ |

**Observation:** No per-risk review date column. No explicit escalation trigger criteria per risk entry.

---

### 3.9 MAN.6 — Measurement · **CL1 ⚠**

**Artifacts reviewed:** `docs/management/measurement-dashboard.md`

**PA 1.1 — Largely Achieved (L)**

| A-SPICE Outcome | Evidence | Status |
|----------------|----------|--------|
| Product quality measures defined and collected | 9 measures with quantitative values, baseline hash, and date | ✅ |
| Project management measures | 6 PM measures with targets, owners, due dates | ✅ |
| Corrective action traceability | Finding IDs → CRs → owners in dashboard | ✅ |
| Measurement data completeness | "11/11 pass (QT-001–010)" is internally inconsistent — 10 IDs span QT-001–010 | ⚠ |
| Coverage measurement | Targets defined but actual result never collected | ⚠ |

---

### 3.10 SUP.1 — Quality Assurance · **CL1 ⚠**

**Artifacts reviewed:** `docs/support/quality-assurance-plan.md`

**PA 1.1 — Largely Achieved (L)**

| A-SPICE Outcome | Evidence | Status |
|----------------|----------|--------|
| QA plan exists | QA objectives, coding standard, 5 planned quality activities defined | ✅ |
| Coding standard | ISO/IEC 14882:2020 + project conventions (no exceptions, no dynamic alloc) | ✅ |
| Non-conformance management | Assessment-driven corrective actions handled via CR/CA logs (indirect evidence) | ⚠ |
| QA activity execution records | No review minutes, checklists, audit records, or non-conformance reports exist | ⚠ |
| Tool reference | `clang-format` referenced; no `.clang-format` file in repository (OB2-06) | ⚠ |

**Finding OB2-07 (Observation):** The QA plan lists 5 planned quality activities (requirements review, architecture review, design review, test evidence review, traceability check). No execution records, checklists, or review outcomes exist as artifacts in the project. The only indirect QA evidence is the corrective-action-log resulting from external assessment findings — quality assurance was not proactively performed during development.

---

### 3.11 SUP.8 — Configuration Management · **CL1**

**Artifacts reviewed:** `docs/support/configuration-management-plan.md`, git repository

**PA 1.1 — Fully Achieved (F)**

| A-SPICE Outcome | Evidence | Status |
|----------------|----------|--------|
| CM plan | CI list, baseline descriptions, tag convention, release gate criteria | ✅ |
| Baselines established | `v0.1.0-draft` (44a7d7c) and `ready-for-assessment2` (dc44320) annotated tags | ✅ |
| Configuration items tracked | All source, test, and documentation files committed to git | ✅ |
| Change traceability | Integration report and test reports reference commit hash with UTC timestamp | ✅ |
| Clean baseline verification | Clean working tree at integration time documented | ✅ |

Second-strongest support process after SUP.10. The commit-hash-level evidence in test and integration reports is exemplary practice.

**Finding OB2-06 (Observation):** The QA plan references `clang-format` with a project-local `.clang-format` config as the mandatory formatting tool. No `.clang-format` file exists in the repository. This tool configuration, if relied upon for coding standard compliance, is a missing and unmanaged configuration item.

---

### 3.12 SUP.9 — Problem Resolution Management · **CL1**

**Artifacts reviewed:** `docs/support/problem-resolution-log.md`

**PA 1.1 — Largely Achieved (L)**

| A-SPICE Outcome | Evidence | Status |
|----------------|----------|--------|
| Problem tracking | 6 problems (PR-001–PR-006) with ID, detected date, resolved date, status | ✅ |
| Resolution evidence | Links to risk register and CR log where applicable | ✅ |
| Semantic consistency | PR-001 and PR-002 have "Resolved" date but status = "Open (Monitoring)" | ⚠ |
| Severity classification | No severity/priority column per problem | ⚠ |

**Finding OB2-08 (Observation):** PR-001 and PR-002 list a "Resolved" date of 2026-03-23 alongside status "Open (Monitoring)". These are mutually contradictory states. If the items are being monitored for recurrence, the appropriate status is "Conditionally Closed" or "Monitoring" without a Resolved date, or the Resolved date should represent the monitoring decision date with explanation.

---

### 3.13 SUP.10 — Change Request Management · **CL1**

**Artifacts reviewed:** `docs/support/change-request-log.md`

**PA 1.1 — Fully Achieved (F)**

| A-SPICE Outcome | Evidence | Status |
|----------------|----------|--------|
| CR registry with structured fields | 18 CRs + 3 retrospective CRs; title, scope, owner, priority, effort, target | ✅ |
| All CRs closed with artifact verification | Final verification pass: 2026-03-23; all 18 CRs "Completed" | ✅ |
| Retrospective change transparency | CR-H1/H2/H3 capture pre-process changes; honest historical record | ✅ |
| Priority classification | P0/P1/P2 with definitions; correct priority assignment per finding severity | ✅ |

Strongest support process. CR-level traceability is well-maintained and the retrospective CRs demonstrate transparency.

---

## 4. Findings

### 4.1 Assessment 1 Finding Status

All 18 CRs from Assessment 1 are confirmed closed. The following critical findings are verified resolved:

| Finding | Description | Resolution | Status |
|---------|-------------|------------|--------|
| **CF-01** | software-tester missing from governance sequence | `.github/copilot-instructions.md` updated; role added as step 5 | ✅ Closed |
| **CF-02** | No derived requirements in SWE SRS | SWE-004/SWE-006/SWE-009 added to software-requirements.md with rationale | ✅ Closed |
| **CF-03** | No change request process established | `docs/support/change-request-log.md` created; 18 CRs registered and managed | ✅ Closed |
| **MF-01** | QT report missing QT-005/007/008 scenarios | All 10 QT IDs enumerated individually in qualification test report | ✅ Closed |

---

### 4.2 Assessment 2 New Findings

#### Major Findings

| ID | Severity | Process | Description | Proposal |
|----|----------|---------|-------------|----------|
| **MF2-01** | Major | SWE.4 | **Incorrect requirement links in unit test report.** UT-006, UT-007, and UT-009 link to SWE-004 (hysteresis) but test subscription management (SWE-007). The traceability table consequently shows SWE-007 as "not unit-verified" when unit tests do cover it. This constitutes false traceability evidence. | Correct requirement links to SWE-007 for UT-006/007/009. Update the traceability table at the bottom of the unit test report to show SWE-007 as verified (with appropriate scope note if SWE-007 is partially integration-scope). |
| **MF2-02** | Major | MAN.3 / SUP.9 | **Corrective-action-log has stale statuses.** CA-06 still shows "In-Progress" (status review document has been created). CA-07 still shows "Open" (CR-004 has been completed and QT report updated). All P2 observation CAs also show "Assigned/Open" despite all 18 CRs being closed. This document is the official CA management artifact yet does not reflect actual closure state. | Update corrective-action-log.md: set CA-06 to Completed, CA-07 to Completed, and all P2 CAs to Completed. Add a "Last Updated" date to the log. |

#### Observations

| ID | Severity | Process | Description | Proposal |
|----|----------|---------|-------------|----------|
| **OB2-01** | Observation | All processes | **No document-level version/revision headers.** None of the 25+ project work products contain a Version, Revision, Date, Author, or Approved-by field. This is the universal and primary barrier to achieving Capability Level 2 (PA 2.2 — Work Product Management). Every document in the project is affected. | Add a standard document header block to all work products. Minimum fields: `Revision`, `Date`, `Author`, `Status (Draft/Approved)`. Can be a YAML frontmatter block or a metadata table. |
| **OB2-02** | Observation | All processes | **No formal review records.** The QA plan lists 5 planned quality review activities. No execution artifacts exist: no review minutes, no sign-off sheets, no checklists, no inspection records. The only evidence that work products were reviewed is the M6 corrective action cycle (which was assessor-driven, not self-driven). This undermines PA 2.1 and PA 3.2 in the path to CL3. | Create a minimal review record summary document or add a "Review History" section to each major work product. At minimum: reviewer role, date, and outcome (approved/approved with comments). |
| **OB2-03** | Observation | SWE.4 / MAN.6 | **Code coverage not measured.** Coverage targets (≥80% statement, ≥70% branch) and tooling (clang++ -fprofile-instr-generate / llvm-cov) are specified in the verification spec. No coverage run has been executed. The measurement dashboard does not carry a coverage % figure. | Execute coverage measurement: `clang++ -fprofile-instr-generate -fcoverage-mapping`; run tests; `llvm-profdata merge`; `llvm-cov report`. Record result in the unit test report and measurement dashboard. |
| **OB2-04** | Observation | MAN.3 | **Status review attendance placeholders.** The status-review-m5-final-and-cr-phase.md attendance section shows `[Name]` for all 8 roles — no actual named individuals. For an A-SPICE evidence artifact, the review is only traceable if attendees are identified. | Replace `[Name]` placeholders with actual names (or, in the absence of named individuals in this project context, document explicitly that roles and individuals are equivalent in this single-assessor project execution and attest accordingly). |
| **OB2-05** | Observation | MAN.3 / MAN.6 | **M1 actual date inconsistency between project plan and status review record.** Project-plan.md records M1 Actual as 2026-03-18. The status review record shows M1 as 2026-03-09. No authoritative actual date can be determined from the artifact set. Additionally, M6 effort variance (plan: 18.5h, CR log total: ~26.5h) is not reconciled. | Reconcile milestone actual dates between the two documents. Document the M6 effort variance as an actuals vs. plan comparison in the measurement dashboard or project plan — do not silently leave an unexplained gap. |
| **OB2-06** | Observation | SUP.1 / SUP.8 | **`.clang-format` configuration file not tracked as a configuration item.** The QA plan references `clang-format` with a project-local `.clang-format` config as the enforcement tool for coding standard compliance. No `.clang-format` file exists in the Git repository. If this tool is relied upon, the configuration is unmanaged and non-reproducible. | Either add a `.clang-format` file to the repository as a tracked CI (recommended), or update the QA plan to remove the reference and describe an alternative coding standard verification method. |
| **OB2-07** | Observation | SUP.1 | **No QA audit execution records.** Quality assurance was planned (5 activities in QA plan) but no audit records, review summaries, non-conformance reports, or checklist results exist. The sole evidence of QA activity is the external assessment-driven CR cycle. Self-driven quality assurance — the primary purpose of SUP.1 — has not produced documented evidence. | After each planned QA activity, create a brief QA audit record (1 page or less): activity date, scope, items checked, findings (or "no findings"), and disposition. This can be a single `docs/support/qa-audit-records.md` with one section per activity. |
| **OB2-08** | Observation | SUP.9 | **Problem resolution log semantic inconsistency.** PR-001 and PR-002 carry a "Resolved" date of 2026-03-23 alongside status "Open (Monitoring)". A problem cannot be simultaneously resolved and open. The intent — monitoring for recurrence — should be expressed as a distinct status (e.g., "Monitoring") without a Resolved date, or the Resolved date should represent the point of monitoring decision with an explanatory note. | Update PR-001 and PR-002: either set status to "Conditionally Closed (Monitoring)" with an explanation, or remove the Resolved date and add a "Monitoring since" field. Ensure the status vocabulary is consistently applied across all 6 entries. |

---

## 5. Barrier Analysis: Why CL2 Is Not Achieved

The universal barrier to Capability Level 2 is the complete absence of two management practices across all 13 assessed processes:

**PA 2.1 — Performance Management:** The project plan documents milestones and effort estimates, but there is no record of per-process performance objectives being set (e.g., "requirements review to complete by M2+3 days"), monitored against actuals, or adjusted when deviating. The status review document partially addresses this for the overall project but not for individual processes.

**PA 2.2 — Work Product Management:** None of the work products carry formal version control metadata (revision number, date, author, approval status). Git commit history provides traceability of when files changed, but not the formal document management lifecycle expected by PA 2.2 (defined documentation requirements per WP, review outcomes, controlled status).

**To achieve CL2, the project must implement:**
1. Document headers on all work products (Version, Date, Author, Status)
2. Per-work product review records (minimal but formal)
3. Per-process performance planning entries in the project plan (not just milestones, but process-specific objectives and monitoring criteria)

These are achievable improvements, and the current artifact quality is strong enough in most processes that CL2 is within reach in a single improvement iteration.

---

## 6. Proposals to the Project Manager

The following proposals are prioritized for the project manager's consideration in a potential M7 improvement phase.

### Priority P1 — Major Findings (Mandatory for next assessment)

| CR Proposal | Scope | Owner | Rationale |
|-------------|-------|-------|-----------|
| **CR-019** | Fix requirement links UT-006/007/009 → SWE-007 in unit test report; update SWE traceability table | Software Tester | MF2-01: False traceability evidence |
| **CR-020** | Update corrective-action-log.md: set CA-06, CA-07, and all P2 CAs to "Completed"; add last-updated date | Project Manager | MF2-02: Official CA log does not reflect closure state |
| **CR-021** | Reconcile M1 actual date across project plan and status review; document M6 effort variance | Project Manager | MF2-03+OB2-05: Data integrity across management artifacts |

### Priority P2 — Observations (Recommended for CL2 readiness)

| CR Proposal | Scope | Owner | Rationale |
|-------------|-------|-------|-----------|
| **CR-022** | Add document header block (Revision, Date, Author, Status) to all 25+ work product files | All Roles | OB2-01: Universal CL2 PA 2.2 blocker |
| **CR-023** | Execute code coverage measurement run; record actual % in test report and measurement dashboard | Software Tester | OB2-03: Coverage targets exist without results |
| **CR-024** | Fix measurement dashboard "11/11 pass (QT-001–010)" → "10/10 pass" | Project Manager | MF2-03: Quality metric count error |
| **CR-025** | Add `.clang-format` file to repository as tracked CM item | Software Designer-Engineer | OB2-06: Unmanaged coding tool configuration |
| **CR-026** | Create minimal QA audit record for each of the 5 planned QA activities | Project Manager | OB2-07: No evidence of planned QA activity execution |
| **CR-027** | Fix PR-001 and PR-002 status/date inconsistency in problem resolution log | Project Manager | OB2-08: Semantic contradiction in PRL |

### Priority P3 — Structural CL2 Enablers (For next phase planning)

| Item | Description |
|------|-------------|
| **Add per-process performance objectives to project plan** | Add a "Process Quality Objectives" section per process area in the project plan. This enables PA 2.1 evidence. |
| **Create formal review record mechanism** | Define a lightweight review record format. Can be a single `docs/support/review-records.md` with one section per work product review. This enables PA 2.2 evidence. |
| **Consider a CL2 readiness sprint** | The project is uniformly at CL1 with strong artifact quality in most processes. A focused M7 phase (~1–2 weeks) targeting document headers, review records, coverage measurement, and CA log closure could bring all 13 processes to demonstrable CL2. |

---

## 7. Overall Assessment Conclusion

**Overall Project A-SPICE Capability Level: CL1 (Performed)**

The Luminance Day/Night State Manager project has made substantial progress since Assessment 1. All 18 previously identified findings have been resolved, the project governance has been strengthened with explicit role sequencing, and the artifact set demonstrates genuine technical completeness: 14/14 unit tests pass, 12/12 integration scenarios pass, 10/10 qualification scenarios pass, and all requirements are bidirectionally traceable.

The project achieves Capability Level 1 across all 13 assessed process areas, which is a positive result for a development baseline of this scope. The engineering processes (SWE.1–SWE.6) are performing well with high artifact quality, particularly in SWE.5 and SWE.6. The support processes (SUP.8, SUP.10) are also notably strong.

The path to Capability Level 2 is clear and well-scoped. The primary requirement is a single document-level discipline improvement — adding version/approval headers to work products — combined with lightweight review records and per-process performance planning. These are not substantive changes to the engineering work but rather necessary formalization of the management infrastructure.

**Recommended next action:** Pass this assessment report to the project manager for planning of P1 corrections (CR-019 through CR-021) and initiation of a CL2 readiness sprint.

---

*Assessment conducted in role of A-SPICE Certified Assessor. Standard applied: Automotive SPICE PAM 4.0 aligned to ISO/IEC 33002.*  
*Assessment date: 2026-03-23. Assessor baseline: `ready-for-assessment2` (dc44320).*
