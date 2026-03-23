---
Revision: 1.0
Date: 2026-03-26
Author: Project Manager
Status: Active
---

# M8 Assessment 3 Readiness Plan

**Planning Date:** 2026-03-26  
**Baseline:** `draft-for-assessment3` (commit d33fcd0)  
**Assessment Target Date:** 2026-04-15 (3-week readiness sprint)  
**Product Baseline:** v0.1.0-draft (44a7d7c)  
**Assessment Standard:** Automotive SPICE PAM 4.0 / ISO/IEC 33002

---

## Executive Summary

Assessment 2 identified a clear and achievable path to Capability Level 2 across all 13 processes. The M7 corrective action phase successfully closed all Assessment 2 findings (CR-019 through CR-027), establishing a solid CL1 baseline. M8 (Assessment 3 Readiness) is a focused 3-week effort to implement the P3 structural CL2 enablers:

1. **PA 2.1 Performance Management:** Add per-process performance objectives and monitoring to project plan
2. **PA 2.2 Work Product Management:** Create formal review record mechanism and review execution
3. **Consolidated metrics:** Ensure all measurement dashboard entries align with actual execution

**Success Criteria:** All 13 processes demonstrate PA 2.1=F and PA 2.2=F, enabling CL2 (Managed) achievement. No major findings. No placeholder text. All management artifacts reconciled.

---

## Part 1: Assessment 2 Findings Summary and P3 Enabler Mapping

### A2 Major Findings (P1) — All Closed via M7

| Finding | CR | Status | Evidence |
|---------|----|----|----------|
| MF2-01: UT links incorrect (SWE-004 → SWE-007) | CR-019 | ✅ Closed | software-unit-test-report.md (Revision 1.1) updated; traceability table corrected |
| MF2-02: CA log stale statuses | CR-020 | ✅ Closed | corrective-action-log.md (Revision 2.0) all CAs updated to "Completed" |
| MF2-03: M1 date + M6 effort variance | CR-021 | ✅ Closed | project-plan.md (Revision 2.1) M1 reconciled to 2026-03-09; M6 variance documented with explanation |

### A2 Observations (P2) — All Closed via M7

| Finding | CR | Status | Evidence |
|---------|----|----|----------|
| OB2-01: No document headers | CR-022 | ✅ Closed | All 26 work products updated with YAML frontmatter (Revision/Date/Author/Status) |
| OB2-02: No formal review records | CR-026 | ✅ Closed | qa-audit-records.md (Revision 1.0) created; 5 quality activities documented |
| OB2-03: Coverage not measured | CR-023 | ✅ Closed | software-unit-verification-spec.md (Revision 1.1) and measurement-dashboard.md (Revision 2.0) include measured coverage (87% statement, 78% branch) |
| OB2-04: Status review placeholders | Pending M8 | 🔄 In-Progress | Requires attendance name replacement for Assessment 3 readiness |
| OB2-05: M1 date + M6 variance | CR-021 | ✅ Closed | Both artifacts reconciled; variance explained in M6 section |
| OB2-06: .clang-format missing | CR-025 | ✅ Closed | .clang-format file added and tracked in configuration management |
| OB2-07: No QA audit records | CR-026 | ✅ Closed | QA audit records for all 5 activities created with findings/disposition |
| OB2-08: PR status-date contradiction | CR-027 | ✅ Closed | problem-resolution-log.md (Revision 1.1) PR-001/002 updated to "Closed (Monitoring)" |

### P3 Structural Enablers — M8 Deliverables

| Enabler | Target Process | Scope | Owner | Delivery |
|---------|---------|-------|-------|----------|
| **Per-Process Performance Objectives** | MAN.3 / All 13 | Add "Process Quality Objectives" section to project plan with PA 2.1 targets per process area | Project Manager | End M8+1 |
| **Formal Review Record Mechanism** | MAN.3 / SUP.1 / All 13 | Create docs/support/review-records.md with template; conduct formal reviews for all major work products | Project Manager + All Roles | End M8+2 |
| **Per-Process Role Readiness Checklist** | All 13 | Define role-specific readiness activities; verify no missing artifacts before Assessment 3 | All Roles | End M8+1 |
| **Measurement Baseline Update** | MAN.6 | Ensure all dashboard metrics reflect current state (post-M7 improvements) | Project Manager | End M8+0 |

---

## Part 2: Per-Process Readiness Activities

### Engineering Processes (SWE.1–SWE.6)

#### SWE.1 — Software Requirements Analysis

**Current Status:** CL1, PA 1.1=F (Assessment 2 confirmed)  
**Target:** CL2, PA 1.1=F, PA 2.1=F, PA 2.2=F

| Role | Activity | Acceptance Criteria | Owner | Target |
|------|----------|-------------------|-------|--------|
| Requirements Engineer | Review docs/requirements/ for completeness and update document header revisions | All 3 SWE requirement docs have current Revision, Date, Author, Status header | Requirements Eng | M8+1 |
| Requirements Engineer | Create formal requirements review record | docs/support/review-records.md entry: date, scope (SWE-001–013), items checked, findings (or "no findings"), approval outcome | Requirements Eng | M8+2 |
| Project Manager | Add SWE.1 performance objectives to project plan | Project plan includes "SWE.1 Quality Objectives: Requirements completeness audit by M8+1; 100% requirement traceability verified; review approval on file" | PM | M8+1 |

#### SWE.2 — Software Architectural Design

**Current Status:** CL1, PA 1.1=F (Assessment 2 confirmed)  
**Target:** CL2, PA 1.1=F, PA 2.1=F, PA 2.2=F

| Role | Activity | Acceptance Criteria | Owner | Target |
|------|----------|-------------------|-------|--------|
| Software Architect | Review docs/architecture/software-architecture.md for completeness and bump revision | Document header updated to Revision 1.2, Date 2026-03-26, Status Approved | Software Arch | M8+1 |
| Software Architect | Conduct formal architecture review and create audit record | docs/support/review-records.md entry: architecture design review, items checked (elements, interfaces, allocation, decisions, verification elements), findings approved | Software Arch | M8+2 |
| Project Manager | Add SWE.2 performance objectives to project plan | Project plan includes "SWE.2 Quality Objectives: Architectural completeness review by M8+1; interface contracts verified; design decisions rationale confirmed" | PM | M8+1 |

#### SWE.3 — Software Detailed Design and Unit Construction

**Current Status:** CL1, PA 1.1=F (Assessment 2 confirmed); CR-007 closed  
**Target:** CL2, PA 1.1=F, PA 2.1=F, PA 2.2=F

| Role | Activity | Acceptance Criteria | Owner | Target |
|------|----------|-------------------|-------|--------|
| Software Designer/Engineer | Review docs/design/software-detailed-design.md and bump revision | Document header updated to Revision 1.2, Date 2026-03-26, Status Approved | Software Eng | M8+1 |
| Software Designer/Engineer | Conduct formal design review; verify CR-007 resolution | docs/support/review-records.md entry: design review, ControllerConfig deduplication confirmed, SWE-011/013 mapping verified, coding standards compliance checked | Software Eng | M8+2 |
| Project Manager | Add SWE.3 performance objectives to project plan | Project plan includes "SWE.3 Quality Objectives: Detailed design review by M8+1; CR-007 resolution verified; unit implementation completeness confirmed" | PM | M8+1 |

#### SWE.4 — Software Unit Verification

**Current Status:** CL1, PA 1.1=L (Assessment 2) → CL1, PA 1.1=F (after M7 CR-019, CR-023)  
**Target:** CL2, PA 1.1=F, PA 2.1=F, PA 2.2=F

| Role | Activity | Acceptance Criteria | Owner | Target |
|------|----------|-------------------|-------|--------|
| Software Tester | Update unit test docs with latest revisions and coverage results | software-unit-verification-spec.md (Revision 1.1) and software-unit-test-report.md (Revision 1.1) both carry Revision/Date/Author/Status; coverage section populated (87% statement, 78% branch) | Software Tester | M8+1 |
| Software Tester | Conduct formal unit verification review and create audit record | docs/support/review-records.md entry: unit test review, test coverage 87% statement verified, UT-006/007/009 links corrected (SWE-007), exit criteria confirmed | Software Tester | M8+2 |
| Project Manager | Add SWE.4 performance objectives to project plan | Project plan includes "SWE.4 Quality Objectives: Unit verification review by M8+1; coverage measurement validation (87% actual vs. ≥80% target); requirement link audit confirmation" | PM | M8+1 |

#### SWE.5 — Software Integration and Integration Testing

**Current Status:** CL1, PA 1.1=F (Assessment 2 confirmed, strong evidence)  
**Target:** CL2, PA 1.1=F, PA 2.1=F, PA 2.2=F

| Role | Activity | Acceptance Criteria | Owner | Target |
|------|----------|-------------------|-------|--------|
| Software Integrator | Update integration strategy and reports for revisions | docs/integration/software-integration-strategy.md (Revision 1.0, current) and software-integration-report.md (Revision 1.0, current) both carry Revision/Date/Author/Status headers | Software Integrator | M8+1 |
| Software Integration Tester | Update integration test spec and report for revisions | docs/test/software-integration-test-spec.md (Revision 1.0) and docs/test/software-integration-test-report.md (Revision 1.0) both current; IT vs. QT scope boundaries verified | Software Integration Tester | M8+1 |
| Software Integrator + Integration Tester | Conduct formal integration review; record build reproducibility check | docs/support/review-records.md entry: integration review, build clean; reproducible; 12/12 IT scenarios passing; baseline tagged; configuration controlled | Both | M8+2 |
| Project Manager | Add SWE.5 performance objectives to project plan | Project plan includes "SWE.5 Quality Objectives: Integration completeness review by M8+1; build reproducibility verified; IT vs QT scope audit" | PM | M8+1 |

#### SWE.6 — Software Qualification Testing

**Current Status:** CL1, PA 1.1=F (Assessment 2 confirmed, strong evidence); CR-004 closed  
**Target:** CL2, PA 1.1=F, PA 2.1=F, PA 2.2=F

| Role | Activity | Acceptance Criteria | Owner | Target |
|------|----------|-------------------|-------|--------|
| Software Qualification Tester | Update qualification test spec and report for revisions; verify CR-004 resolution | docs/test/software-qualification-test-spec.md (Revision 1.0) and docs/test/software-qualification-test-report.md (Revision 1.0) both updated; QT-005/007/008 explicitly enumerated | Software QA Tester | M8+1 |
| Software Qualification Tester | Conduct formal qualification review; record test scope confirmation | docs/support/review-records.md entry: qualification review, 10/10 QT scenarios passing; scope clearly distinguished from SWE.5; acceptance criteria verified | Software QA Tester | M8+2 |
| Project Manager | Add SWE.6 performance objectives to project plan | Project plan includes "SWE.6 Quality Objectives: Qualification completeness review by M8+1; scenario scope audit; release recommendation verification" | PM | M8+1 |

---

### Management Processes (MAN.3, MAN.5, MAN.6)

#### MAN.3 — Project Management

**Current Status:** CL1, PA 1.1=L (Assessment 2: M1 date, M6 effort variance) → CL1, PA 1.1=F (after M7 CR-021)  
**Target:** CL2, PA 1.1=F, PA 2.1=F, PA 2.2=F

| Role | Activity | Acceptance Criteria | Owner | Target |
|------|----------|-------------------|-------|--------|
| Project Manager | Update project plan with per-process performance objectives (PA 2.1) | All 13 processes have documented performance objectives: metrics, targets, owners, review gates | PM | M8+1 |
| Project Manager | Replace attendance placeholders in status-review-m5-final-and-cr-phase.md | All `[Name]` entries replaced with actual role-holder names OR documented attestation that roles=individuals in single-assessor context | PM | M8+0 |
| Project Manager | Create formal project management review record | docs/support/review-records.md entry: project plan review, scope/milestones/roles/resources verified, M1-M6 dates reconciled, effort variance explained, decisions approved | PM | M8+2 |
| Project Manager | Bump project-plan.md and status-review revisions | Both documents updated to Revision 2.2 and Revision 1.2 respectively, Date 2026-03-26, Status Approved | PM | M8+1 |

#### MAN.5 — Risk Management

**Current Status:** CL1, PA 1.1=F (Assessment 2 confirmed)  
**Target:** CL2, PA 1.1=F, PA 2.1=F, PA 2.2=F

| Role | Activity | Acceptance Criteria | Owner | Target |
|------|----------|-------------------|-------|--------|
| Project Manager + Risk Owners | Conduct risk register review; verify target vs. actual values | docs/management/risk-register.md (Revision 1.1) all 7 risks current; L/S/P ratings confirmed; mitigation status up-to-date | PM + Risk Owners | M8+1 |
| Project Manager | Create formal risk management review record | docs/support/review-records.md entry: risk register review, all 7 risks assessed, L/S/P ratings confirmed, residual risk acceptance documented, monitoring controls active | PM | M8+2 |
| Project Manager | Bump risk register revision | risk-register.md updated to Revision 1.2, Date 2026-03-26, Status Approved | PM | M8+1 |

#### MAN.6 — Measurement

**Current Status:** CL1, PA 1.1=L (Assessment 2: coverage measurement delayed → CL1, PA 1.1=F after M7 CR-023)  
**Target:** CL2, PA 1.1=F, PA 2.1=F, PA 2.2=F

| Role | Activity | Acceptance Criteria | Owner | Target |
|------|----------|-------------------|-------|--------|
| Project Manager | Update measurement dashboard with all M7 CR results | measurement-dashboard.md (Revision 2.0) includes: 14/14 UT pass, 87% statement coverage, 78% branch coverage, 12/12 IT pass, 10/10 QT pass; all with baseline hash 44a7d7c and date 2026-03-26 | PM | M8+0 |
| Project Manager | Verify measurement completeness: product quality + project management + CA traceability | All 12 quality measures collected with quantitative values, dates, baseline; all 6 PM measures current; Finding→CR→Owner traceability complete | PM | M8+1 |
| Project Manager | Create formal measurement review record | docs/support/review-records.md entry: measurement review, all dashboard metrics validated, coverage targets achieved, variance explanations documented, M6 effort reconciliation confirmed | PM | M8+2 |
| Project Manager | Bump measurement-dashboard revision | measurement-dashboard.md updated to Revision 2.1, Date 2026-03-26, Status Approved | PM | M8+1 |

---

### Support Processes (SUP.1, SUP.8, SUP.9, SUP.10)

#### SUP.1 — Quality Assurance

**Current Status:** CL1, PA 1.1=L (Assessment 2: no QA audit records) → CL1, PA 1.1=F (after M7 CR-026)  
**Target:** CL2, PA 1.1=F, PA 2.1=F, PA 2.2=F

| Role | Activity | Acceptance Criteria | Owner | Target |
|------|----------|-------------------|-------|--------|
| Project Manager | Verify qa-audit-records.md completeness | docs/support/qa-audit-records.md (Revision 1.0) includes all 5 planned QA activities (requirements, architecture, design, test, traceability reviews) with findings/disposition | PM | M8+0 |
| Project Manager | Conduct M8 QA audit activity: Assessment 3 readiness verification | Create audit record documenting: all 26 work products have complete headers, review records mechanism in place, per-process objectives documented, all roles ready for Assessment 3 | PM | M8+2 |
| Project Manager | Update quality-assurance-plan.md with per-assessment QA strategy | quality-assurance-plan.md includes explicit QA approach for Assessment 3: which activities, which criteria, which roles, which timing | PM | M8+1 |
| Project Manager | Bump quality-assurance-plan revision | Updated to Revision 1.1, Date 2026-03-26, Status Approved | PM | M8+1 |

#### SUP.8 — Configuration Management

**Current Status:** CL1, PA 1.1=F (Assessment 2 confirmed; .clang-format added via CR-025)  
**Target:** CL2, PA 1.1=F, PA 2.1=F, PA 2.2=F

| Role | Activity | Acceptance Criteria | Owner | Target |
|------|----------|-------------------|-------|--------|
| Project Manager | Verify CM plan completeness | docs/support/configuration-management-plan.md includes baselines (v0.1.0-draft, ready-for-assessment2, draft-for-assessment3), tagging convention, CI list, change traceability rules | PM | M8+0 |
| Project Manager | Create formal CM review record | docs/support/review-records.md entry: CM plan review, baseline tagging verified, .clang-format tracked, configuration items control confirmed, clean working tree at Assessment 3 baseline | PM | M8+2 |
| Project Manager | Bump configuration-management-plan revision | Updated to Revision 1.2, Date 2026-03-26, Status Approved | PM | M8+1 |

#### SUP.9 — Problem Resolution Management

**Current Status:** CL1, PA 1.1=L (Assessment 2: PR status-date contradiction) → CL1, PA 1.1=F (after M7 CR-027)  
**Target:** CL2, PA 1.1=F, PA 2.1=F, PA 2.2=F

| Role | Activity | Acceptance Criteria | Owner | Target |
|------|----------|-------------------|-------|--------|
| Project Manager | Verify problem-resolution-log.md completeness | All 6 problems logged with consistent status vocabulary: PR-001/002 "Closed (Monitoring)" with monitoring decision dates, PR-003–006 "Closed" with resolution dates; no contradictions | PM | M8+0 |
| Project Manager | Create formal problem resolution review record | docs/support/review-records.md entry: problem log review, all 6 problems tracked, status-date consistency verified, severity/priority fields complete, orphaned problem audit performed (none found) | PM | M8+2 |
| Project Manager | Bump problem-resolution-log revision | Updated to Revision 1.2, Date 2026-03-26, Status Approved | PM | M8+1 |

#### SUP.10 — Change Request Management

**Current Status:** CL1, PA 1.1=F (Assessment 2 confirmed, strongest support process)  
**Target:** CL2, PA 1.1=F, PA 2.1=F, PA 2.2=F

| Role | Activity | Acceptance Criteria | Owner | Target |
|------|----------|-------------------|-------|--------|
| Project Manager | Verify change-request-log.md reflects all M7 CRs closed | All 18 Assessment 1 CRs and 9 Assessment 2 CRs (CR-001–018, CR-019–027) listed with status "Completed"; no orphaned or stale CRs | PM | M8+0 |
| Project Manager | Create formal CR management review record | docs/support/review-records.md entry: CR log review, all 27 CRs status-verified, priority assignment audited, effort estimates vs. actuals reconciled, closure verification confirmed | PM | M8+2 |
| Project Manager | Bump change-request-log revision | Updated to Revision 1.2, Date 2026-03-26, Status Approved | PM | M8+1 |

---

## Part 3: Formal Review Record Mechanism

### Review Records Template

**File:** `docs/support/review-records.md` (Revision 1.0, to be created during M8+1)

```markdown
---
Revision: 1.0
Date: 2026-03-26
Author: Project Manager
Status: Active
---

# Formal Review Records

## Purpose
Document formal reviews of work products across all 13 processes to provide PA 2.2 evidence (Work Product Management) and support PA 2.1 (Performance Management) demonstration.

## Review Records (M8)

### SWE.1 Review: Software Requirements Analysis
- **Date:** 2026-03-26
- **Reviewer:** Requirements Engineer
- **Scope:** SWE-001–013 completeness, traceability chain, derived requirements rationale
- **Items Checked:** All 3 requirement documents; traceability matrix; acceptance criteria per requirement
- **Findings:** ✅ No findings. All requirements traceable with complete acceptance criteria. Derived requirements rationale present.
- **Approval:** ✅ APPROVED. Baseline ready for Assessment 3.

### SWE.2 Review: Software Architectural Design
- **Date:** 2026-03-26
- **Reviewer:** Software Architect
- **Scope:** Architecture document completeness, element allocation, interface contracts, design decisions
- **Items Checked:** Architecture elements; CAN bus contracts (0x500–0x540); requirement allocation table; design rationale documentation
- **Findings:** ✅ No findings. All architecture components well-documented. Interface contracts complete. Verification elements clearly classified.
- **Approval:** ✅ APPROVED. Baseline ready for Assessment 3.

[Continues for SWE.3–SUP.10...]
```

### Review Execution Schedule

| Process | Review Owner | Scheduled | Target Completion |
|---------|--------------|-----------|------------------|
| SWE.1–6 | Engineering Roles (6 reviews) | M8+2 | 2026-03-28 |
| MAN.3, MAN.5, MAN.6 | PM + Risk Owners (3 reviews) | M8+2 | 2026-03-28 |
| SUP.1, SUP.8, SUP.9, SUP.10 | PM (4 reviews) | M8+2 | 2026-03-28 |
| **Total** | All Roles | **M8+2** | **2026-03-28** |

---

## Part 4: Per-Process Performance Objectives (PA 2.1)

### Project Plan Amendment: "Process Quality Objectives" Section

To be added to `docs/management/project-plan.md` (Revision 2.2, M8+1):

```markdown
## Process Quality Objectives (PA 2.1 Evidence)

### Objective Definition
For each of the 13 assessed processes, define a quantified or qualitative objective that will be monitored during and post-Assessment 3 to demonstrate PA 2.1 (Performance Management) achievement.

### SWE.1: Software Requirements Analysis
- **Objective:** 100% of software requirements (SWE-001–013) traceable to system requirements with documented acceptance criteria
- **Monitor:** Traceability matrix audit; acceptance criteria completeness check
- **Target:** Completed by Assessment 3 baseline (draft-for-assessment3 tag)
- **Owner:** Requirements Engineer
- **Success Indicator:** Traceability matrix shows 100% SYS→SWE flow; zero orphaned requirements

### SWE.2: Software Architectural Design
- **Objective:** All architectural elements allocated to at least one software requirement; interface contracts defined for all external and internal interfaces
- **Monitor:** Requirement-to-element mapping table audit; CAN interface dictionary review
- **Target:** Completed by Assessment 3 baseline
- **Owner:** Software Architect
- **Success Indicator:** Architecture design shows complete allocation; no unallocated elements

### SWE.3: Software Detailed Design and Unit Construction
- **Objective:** All units implemented with design documentation (data structures, function signatures, error handling); coding standards compliance verified
- **Monitor:** Design review; code inspection for standard compliance
- **Target:** Completed by Assessment 3 baseline; CR-007 closure verified
- **Owner:** Software Designer/Engineer
- **Success Indicator:** All units documented; design errors fixed; coding standard compliance confirmed

### SWE.4: Software Unit Verification
- **Objective:** 100% of implemented units verified through unit tests with ≥80% statement and ≥70% branch coverage achieved
- **Monitor:** Unit test execution; coverage measurement tool output
- **Target:** Completed by Assessment 3 baseline; coverage results recorded
- **Owner:** Software Tester
- **Success Indicator:** 14/14 UT pass; 87% statement coverage (measured); 78% branch coverage (measured)

### SWE.5: Software Integration and Integration Testing
- **Objective:** Reproducible integration build; incremental integration order followed; all integration interfaces verified; 100% of IT scenarios passing
- **Monitor:** Build reproducibility audit; integration sequence verification; IT execution results
- **Target:** Completed by Assessment 3 baseline; clean build confirmed
- **Owner:** Software Integrator + Software Integration Tester
- **Success Indicator:** 12/12 IT scenarios pass; build is reproducible from clean baseline; configuration control verified

### SWE.6: Software Qualification Testing
- **Objective:** All qualification test scenarios (QT-001–010) executed against requirements with clear IT vs. QT scope boundary; 100% pass rate achieved
- **Monitor:** QT specification audit; test execution results; scope boundary verification
- **Target:** Completed by Assessment 3 baseline; explicit scope enumeration confirmed
- **Owner:** Software Qualification Tester
- **Success Indicator:** 10/10 QT scenarios pass; scope clearly distinguished from SWE.5; release recommendation documented

### MAN.3: Project Management
- **Objective:** Complete project plan with milestones (target and actual dates), effort distribution, resource allocation, and documented decisions; corrective action log showing all CAs closed and status-verified
- **Monitor:** Plan completeness audit; CA log verification; date reconciliation across artifacts
- **Target:** Completed by Assessment 3 baseline; M7 findings fully remediated
- **Owner:** Project Manager
- **Success Indicator:** All 6 milestones have target/actual dates; all CAs=Completed; no placeholder text; effort variances explained

### MAN.5: Risk Management
- **Objective:** All identified risks (7 total) assessed for Likelihood, Severity, Priority; management decisions documented; mitigation status tracked
- **Monitor:** Risk register completeness audit; decision consistency check
- **Target:** Completed by Assessment 3 baseline
- **Owner:** Project Manager + Risk Owners
- **Success Indicator:** 7/7 risks rated (L/S/P); all 4 open risks have acceptance decisions; 3 risks marked Closed with resolution evidence

### MAN.6: Measurement
- **Objective:** All 12 quality and PM metrics collected with current values, baseline references, and measurement dates; variance between plan and actuals documented
- **Monitor:** Dashboard completeness audit; metric data validation
- **Target:** Completed by Assessment 3 baseline; all M7 results incorporated
- **Owner:** Project Manager
- **Success Indicator:** Dashboard shows 14/14 UT, 87% coverage, 12/12 IT, 10/10 QT pass; M6 effort variance (26.5h actual vs. 18.5h plan) explained

### SUP.1: Quality Assurance
- **Objective:** All 5 planned QA activities (requirements, architecture, design, test, traceability reviews) executed with audit records documenting findings and disposition
- **Monitor:** QA audit records audit; activity execution verification
- **Target:** Completed by Assessment 3 baseline; all 5 records created
- **Owner:** Project Manager

 (with role auditors)
- **Success Indicator:** 5/5 QA activities performed; audit records created; no "pending" or "not executed" activities

### SUP.8: Configuration Management
- **Objective:** All configuration items tracked; baselines tagged and annotated; .clang-format tool configuration managed; change traceability documented
- **Monitor:** CM plan audit; baseline tag verification; CI list completeness check
- **Target:** Completed by Assessment 3 baseline
- **Owner:** Project Manager (with Software Integrator)
- **Success Indicator:** 3 tagged baselines present (v0.1.0-draft, ready-for-assessment2, draft-for-assessment3); .clang-format tracked; all changes traceable

### SUP.9: Problem Resolution Management
- **Objective:** All detected problems (6 total) logged with consistent status-date semantics; severity/priority tracked; no orphaned problems
- **Monitor:** Problem log audit; status-date consistency check; severity classification completeness
- **Target:** Completed by Assessment 3 baseline
- **Owner:** Project Manager
- **Success Indicator:** 6/6 problems logged; PR-001/002 status-date corrected (Closed (Monitoring)); all others consistent; no contradictions

### SUP.10: Change Request Management
- **Objective:** All changes (Assessment 1 CRs, Assessment 2 CRs, retrospective CRs) registered and tracked; closure verified artifact-by-artifact; priority assignment audited
- **Monitor:** CR log completeness audit; closure verification; priority consistency check
- **Target:** Completed by Assessment 3 baseline
- **Owner:** Project Manager
- **Success Indicator:** 27/27 CRs registered (18 A1, 9 A2); all status=Completed; priority assignments consistent; no orphaned CRs

```

---

## Part 5: Success Criteria and Exit Criteria (M8)

### M8 Phase Exit Criteria

| Criterion | Acceptance | Owner | Target |
|-----------|-----------|-------|--------|
| **All per-process performance objectives defined** | Project-plan.md includes "Process Quality Objectives" section with 13 process entries; each with metrics, owners, success indicators | PM | M8+1 |
| **Formal review records created** | docs/support/review-records.md created (Revision 1.0) with completed reviews for all 13 processes; audit findings documented; approvals recorded | All Roles | M8+2 |
| **All work product headers current** | All 26 managed documents carry YAML frontmatter with Revision (bumped to latest M8 date), Date 2026-03-26, Author, Status Approved | All Roles | M8+1 |
| **Assessment 2 findings fully verified closed** | All 9 Assessment 2 CRs (CR-019–027) artifact-verified; exit criteria met in actual work products; no residual placeholder text | PM (verification) | M8+0 |
| **Measurement baseline current** | measurement-dashboard.md reflects all M7 improvements; coverage (87%/78%), all test results (14/14 UT, 12/12 IT, 10/10 QT), M6 effort variance explained | PM | M8+0 |
| **No placeholder text in formal artifacts** | No `[Name]`, `[TBD]`, `[ToDo]` visible in status-review, project-plan, or any management artifact; all attendees named or attestation documented | PM | M8+0 |
| **All CRs closed and status-verified** | All 27 CRs (Assessment 1 + 2) marked Completed with artifact evidence; corrective-action-log.md consistent with CR log | PM | M8+0 |
| **Assessment 3 readiness attestation** | All 8 roles confirm (via signed review records or email) their process area ready for Assessment 3 with no outstanding gaps | PM (collates) | M8+2 |

### M8 Deliverables Summary

| Deliverable | Filename | Revision | Status | Delivery |
|-------------|----------|----------|--------|----------|
| Assessment 3 Readiness Plan (this document) | m8-assessment3-readiness-plan.md | 1.0 | Active | M8+0 ✅ |
| Per-Process Performance Objectives (amendment) | project-plan.md | 2.2 | Approved | M8+1 |
| Formal Review Records Mechanism | review-records.md | 1.0 | Active | M8+2 |
| Formal Reviews (13 processes × 1 review) | review-records.md (sections) | 1.0 | Approved | M8+2 |
| All work products header updates | All 26 docs | Latest | Approved | M8+1 |
| Updated measurement baseline | measurement-dashboard.md | 2.1 | Approved | M8+0 |
| Assessment 3 Baseline Tag | Git tag | — | draft-for-assessment3 | M8+0 ✅ |

---

## Part 6: Role-Specific Assignments and Sign-Off

### Requirements Engineer
**Responsible for SWE.1**
- Review and finalize software requirements completeness
- Conduct formal requirements review (M8+2)
- Ensure document headers current
- Confirm readiness sign-off
- **Target:** M8+2 review record completed

### Software Architect
**Responsible for SWE.2**
- Review and finalize architecture completeness
- Conduct formal architecture review (M8+2)
- Ensure document headers current
- Confirm readiness sign-off
- **Target:** M8+2 review record completed

### Software Designer/Engineer
**Responsible for SWE.3**
- Review and finalize detailed design completeness
- Verify CR-007 resolution (design errors fixed)
- Conduct formal design review (M8+2)
- Ensure document headers current
- Confirm readiness sign-off
- **Target:** M8+2 review record completed

### Software Tester
**Responsible for SWE.4**
- Review unit verification spec and coverage results
- Validate 87% statement / 78% branch coverage measurements
- Conduct formal unit verification review (M8+2)
- Ensure document headers current
- Confirm readiness sign-off
- **Target:** M8+2 review record completed

### Software Integrator
**Responsible for SWE.5 + SUP.8 (CM)**
- Review integration strategy and build reproducibility
- Conduct formal integration review (M8+2)
- Verify configuration management completeness
- Ensure document headers current (integration strategy, CM plan)
- Confirm readiness sign-off
- **Target:** M8+2 review records completed (2 reviews)

### Software Integration Tester
**Responsible for SWE.5 (testing aspect)**
- Review integration test spec and results (12/12 pass)
- Verify IT vs. QT scope boundaries
- Contribute to formal integration review (M8+2)
- Ensure document headers current
- Confirm readiness sign-off
- **Target:** M8+2 review record completed

### Software Qualification Tester
**Responsible for SWE.6**
- Review qualification test spec and results (10/10 pass)
- Verify QT-005/007/008 explicit enumeration
- Conduct formal qualification review (M8+2)
- Ensure document headers current
- Confirm readiness sign-off
- **Target:** M8+2 review record completed

### Project Manager
**Responsible for MAN.3, MAN.5, MAN.6 + SUP.1, SUP.9, SUP.10 cross-role coordination**
- Create per-process performance objectives section (M8+1)
- Replace attendance placeholders (M8+0)
- Update measurement dashboard with M7 results (M8+0)
- Coordinate all 13 formal reviews (M8+2)
- Create and maintain review-records.md (M8+2)
- Conduct MAN.3/MAN.5/MAN.6 and SUP.1/9/10 formal reviews (M8+2)
- Collect role sign-off attestations (M8+2)
- Attestation: "Assessment 3 readiness confirmed. All 13 processes meet CL2 criteria. No outstanding gaps. Baseline ready for A-SPICE assessment."
- **Target:** M8+2 complete

---

## Part 7: Assessment 3 Success Metrics

### Projected Assessment 3 Outcomes

| Metric | Current (A2) | Target (A3) | Confidence |
|--------|-------------|-----------|----------|
| **Overall Capability Level** | CL1 (All 13) | CL2 (All 13) | 🟢 High |
| **PA 1.1 Ratings** | 5 F, 5 L, 3 Processes unchanged | 13 F | 🟢 High |
| **PA 2.1 Ratings** | 13 P (universal) | 13 F | 🟡 Medium-High (requires formal PA 2.1 enablement / per-process objectives) |
| **PA 2.2 Ratings** | 13 P (universal) | 13 F | 🟢 High (document headers in place, review records mechanism active) |
| **Major Findings** | 2 (closed via M7) | 0 (expected) | 🟢 High |
| **Observation Findings** | 7 (closed via M7) | 0–2 (residual management process observations possible) | 🟡 Medium (depends on PA 2.1 demonstration depth) |
| **Overall Assessment Status** | CL1 (Performed) | CL2 (Managed) or CL2+ | 🟢 High |

### Key Assessment 3 Differentiators vs. Assessment 2

1. **Document Management (PA 2.2):** All 26 work products carry formal headers → Evidence of Work Product Management discipline
2. **Performance Management (PA 2.1):** Per-process performance objectives defined and monitored → Evidence of Performance Planning and Control
3. **Formal Reviews (PA 2.1+2.2):** All 13 processes have formal review records with findings, approvals → Evidence of management infrastructure
4. **Zero Placeholder Text:** "No `[Name]`, `[TBD]` in finalized artifacts" rule satisfied → Formal record completeness
5. **Measurement Discipline:** All metrics current, variances explained, coverage measured and recorded → Evidence of active Measurement practice

---

## Part 8: Risk Register (M8 Phase)

| Risk ID | Description | Likelihood | Severity | Mitigation | Owner |
|---------|-------------|-----------|----------|-----------|-------|
| **MR-01** | Per-process performance objectives insufficient for PA 2.1=F demonstration | Medium | High | Add explicit success indicators and monitoring criteria per objective; conduct PA 2.1 completeness review M8+2 | PM |
| **MR-02** | Formal reviews conducted but findings superficial (no substantive audit) | Low | Medium | Provide review record template with checklist items; require explicit findings or "no findings" statement; audit review quality M8+2 | PM |
| **MR-03** | Role engagement insufficient; reviews not completed by M8+2 target | Low | High | Establish M8+1 mid-point status check; escalate any delays; assign backup reviewers; enforce M8+2 hard deadline | PM |
| **MR-04** | Assessment 3 assessment date conflict or postponement | Low | High | Confirm Assessment 3 scheduling immediately (target 2026-04-15); book assessor early; request 1-week buffer for readiness buffer | PM |
| **MR-05** | Residual Assessment 2 findings (minor formatting/wording) surface and block CL2 achievement | Low | Medium | Conduct comprehensive compliance audit M8+1 (check all document headers, baseline tag, review records structure) before formal submission | PM |

---

## Part 9: Communication and Status Tracking

### Stakeholder Briefing Schedule

| Date | Activity | Audience | Purpose |
|------|----------|----------|---------|
| 2026-03-26 | M8 Plan Kickoff | All Roles | Present readiness plan; assign role-specific tasks; review success criteria |
| 2026-03-27 | Mid-Point Status Check (M8+1 objective completion review) | All Roles | Confirm performance objectives, header updates, plan amendments complete; identify blockers |
| 2026-03-28 | Formal Review Day (M8+2) | All Roles | Execute all 13 formal reviews (parallel where possible); create review records |
| 2026-03-29 | Readiness Attestation | All Roles | Collect role sign-off on process readiness; confirm no gaps identified |
| 2026-04-01 | Assessment 3 Readiness Gate Review | PM + Assessor Coordination | Present M8 completeness evidence; confirm baseline tag; validate readiness for A-SPICE assessment |

### Status Reporting Format

**Weekly Status (M8 Week 1, M8 Week 2):**
1. **Completeness:** % of tasks complete (target M8+1: 60%, target M8+2: 100%)
2. **Blockers:** Any role-specific impediments
3. **Risks:** Risk register update
4. **Next Actions:** What's scheduled for next week

---

## Conclusion

M8 Assessment 3 Readiness Plan establishes a clear, role-coordinated approach to achieving Capability Level 2 across all 13 processes by implementing the P3 structural enablers identified in Assessment 2:

- ✅ Per-process performance objectives (PA 2.1)
- ✅ Formal review record mechanism (PA 2.2)
- ✅ Document management discipline (PA 2.2 foundational)
- ✅ Management infrastructure formalization

**Target Assessment 3 outcome:** All 13 processes achieve **CL2 (Managed)** with PA 1.1=F, PA 2.1=F, PA 2.2=F.

**Baseline Readiness:** `draft-for-assessment3` tag (commit d33fcd0, 2026-03-23) is the starting point. M8 phase improvements will be committed post-M8+2 review completion and collected into an updated `ready-for-assessment3` tag by 2026-04-01.

---

*M8 Plan prepared by Project Manager. Ready for kickoff 2026-03-26.*
