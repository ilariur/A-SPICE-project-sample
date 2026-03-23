---
Revision: 1
Date: 2026-03-23
Author: Project Manager
Status: Active
---

# M7 Corrective Action Plan — Assessment 2 Implementation

**Project:** Luminance Day/Night State Manager  
**Assessment Reference:** Assessment 2 (ready-for-assessment2)  
**Planning Date:** 2026-03-23  
**Planned Start:** 2026-03-23  
**Planned Completion:** 2026-03-26 (M7+2, estimated)  
**Scope:** 9 CRs addressing 2 Major findings and 7 Observations

---

## Executive Summary

Assessment 2 identified 2 Major findings and 7 Observations. All 13 processes achieve CL1; CL2 remains blocked by systemic absence of PA 2.1 and PA 2.2 evidence (per-process performance records and document version headers).

**Strategy:** Execute P1 (Major) findings immediately. Pursue P2 (Observations) in parallel under coordinated role execution. Target M7 completion in 3 days.

---

## Priority P1 — Major Findings (Blocking for Assessment 3)

### CR-019: Fix Unit Test Requirement Links (SWE.4 — software-tester)

| Field | Value |
|-------|-------|
| **CR ID** | CR-019 |
| **Title** | Fix UT-006/007/009 requirement links to SWE-007 |
| **Finding** | MF2-01 |
| **Owner** | Software Tester |
| **Priority** | P1 (Major) |
| **Effort Estimate** | 0.5h |
| **Target** | 2026-03-24 EOD |
| **Status** | Not Started |

**Scope:**
- Read the unit test source code for UT-006, UT-007, UT-009
- Verify they test subscription management (SWE-007), not hysteresis (SWE-004)
- Update `docs/test/software-unit-test-report.md`: correct requirement links from SWE-004 → SWE-007
- Update traceability table: mark SWE-007 as "Verified by UT-006, UT-007, UT-009"
- Add document header with Revision, Date, Author, Status

**Exit Criteria:**
- Test report links are corrected
- Traceability table shows SWE-007 verified (with subscription scope note if needed)
- Document header added
- Artifact-verified by Project Manager (requirement links checked against source code)

**Owner Notes:** Software-tester skill now includes explicit requirement link verification (read test code, confirm requirement linkage).

---

### CR-020: Update Corrective-Action-Log Status (MAN.3 — project-manager)

| Field | Value |
|-------|-------|
| **CR ID** | CR-020 |
| **Title** | Update CA log: set CA-06, CA-07, and P2 CAs to Completed |
| **Finding** | MF2-02 |
| **Owner** | Project Manager |
| **Priority** | P1 (Major) |
| **Effort Estimate** | 0.5h |
| **Target** | 2026-03-24 EOD |
| **Status** | Not Started |

**Scope:**
- Open `docs/support/corrective-action-log.md`
- Update CA-06 (status review): change status from "In-Progress" → "Completed"
- Update CA-07 (integration/qualification evidence): change status from "Open" → "Completed"
- Update all P2 observation CAs (CA-08 through CA-14 or equivalent): change status to "Completed"
- Add document header with Revision, Date, Author, Status
- Add "Last Updated: 2026-03-23" field to the document

**Exit Criteria:**
- All closed CRs have corresponding CA status = "Completed"
- No stale "In-Progress", "Open", or "Assigned" statuses remain
- Document header and Last Updated field added
- Artifact-verified by Project Manager (CA log status matches CR log status)

---

### CR-021: Reconcile M1 Date and M6 Effort (MAN.3/MAN.6 — project-manager)

| Field | Value |
|-------|-------|
| **CR ID** | CR-021 |
| **Title** | Reconcile M1 actual date; document M6 effort variance |
| **Finding** | OB2-05 (also relates to MF2-04 date inconsistency) |
| **Owner** | Project Manager |
| **Priority** | P1 (Major) |
| **Effort Estimate** | 1h |
| **Target** | 2026-03-24 EOD |
| **Status** | Not Started |

**Scope:**
- **M1 date reconciliation:** Compare M1 Actual in project-plan.md (2026-03-18) vs. status-review-m5-final-and-cr-phase.md (2026-03-09). Determine authoritative date and reconcile both documents to single value with explanation note.
- **M6 effort variance:** In `docs/management/measurement-dashboard.md`, add explicit variance note for M6: "Plan: 18.5h; Actuals (summed CR log): ~26.5h. Variance +8h due to extended CA integration testing and verification cycles (CR-004, CR-006 extended scope)."
- Update document headers in both project-plan.md and measurement-dashboard.md with Revision, Date, Author, Status
- Document authoritative M1 date choice and rationale in project-plan.md notes section

**Exit Criteria:**
- M1 dates reconciled across both docs; single authoritative date stated with rationale
- M6 effort variance documented with explanation
- All 3 management artifact dates (plan, status review, dashboard) are consistent
- Document headers added to plan and dashboard
- Artifact-verified by Project Manager (all artifacts checked for consistency)

---

## Priority P2 — Observations (Recommended for CL2 Readiness)

### CR-022: Add Document Headers to All Work Products (All Roles)

| Field | Value |
|-------|-------|
| **CR ID** | CR-022 |
| **Title** | Add document header (Revision, Date, Author, Status) to all work products |
| **Finding** | OB2-01 |
| **Owner** | All Roles (executed in parallel) |
| **Priority** | P2 (Observation) |
| **Effort Estimate** | 2h total |
| **Target** | 2026-03-25 EOD |
| **Status** | Not Started |

**Scope:**
Add a standardized document header block (YAML frontmatter or markdown table) to all 25+ work product files:
- Requirements: `docs/requirements/*.md` (3 files)
- Architecture: `docs/architecture/*.md` (1 file)
- Design: `docs/design/*.md` (1 file)
- Integration: `docs/integration/*.md` (2 files)
- Test: `docs/test/*.md` (6 files)
- Management: `docs/management/*.md` (4 files)
- Support: `docs/support/*.md` (6+ files)
- Traceability: `docs/traceability/*.md` (1 file)

**Header Format (YAML frontmatter):**
```
---
Revision: 1
Date: 2026-03-23
Author: [Role Name]
Status: Approved
---
```

**Exit Criteria:**
- All work products contain header block with populated fields
- No work product has placeholder text like "[Name]"
- Revision numbers are sequential per document (start with 1)
- All dates are populated with actual update date
- Status field set consistently (Approved for finalized artifacts, Draft for in-progress)

**Role Assignment & Coordination:**
- Software Tester: Unit test spec/report (2 files) + QA-audit-records (1 file)
- Software Integration Tester: Integration test spec/report (2 files)
- Software Qualification Tester: Qualification test spec/report (2 files)
- Software Architect: Architecture doc (1 file) + Requirements docs (3 files as reviewing architect)
- Software Designer-Engineer: Design doc (1 file)
- Project Manager: Management docs (4 files) + Support logs (6 files) + CM plan + Traceability

---

### CR-023: Execute Code Coverage Measurement (SWE.4 — software-tester)

| Field | Value |
|-------|-------|
| **CR ID** | CR-023 |
| **Title** | Execute coverage measurement; record result in test report and measurement dashboard |
| **Finding** | OB2-03 |
| **Owner** | Software Tester |
| **Priority** | P2 (Observation) |
| **Effort Estimate** | 1h |
| **Target** | 2026-03-25 EOD |
| **Status** | Not Started |

**Scope:**
- Compile test executable with coverage instrumentation: `clang++ -fprofile-instr-generate -fcoverage-mapping -O0 ...`
- Execute all unit tests to generate `.profraw` files
- Merge profiles: `llvm-profdata merge *.profraw -o coverage.profdata`
- Generate coverage report: `llvm-cov report tests/build -instr-profile=coverage.profdata`
- Record actual coverage percentages (statement %, branch %) in two places:
  1. `docs/test/software-unit-test-report.md` → Coverage Result section with actual values
  2. `docs/management/measurement-dashboard.md` → Coverage line with measured %
- Document any gaps between targets (80%/70%) and measured results

**Exit Criteria:**
- Coverage measurement executed and documented with concrete percentages
- Test report shows "Coverage: Statement 82%, Branch 74%" (example figures)
- Measurement dashboard includes coverage data with baseline commit hash and date
- If measured < targets, gaps are documented with rationale (e.g., "unreachable error paths")

---

### CR-024: Fix Measurement Dashboard QT Count (MAN.6 — project-manager)

| Field | Value |
|-------|-------|
| **CR ID** | CR-024 |
| **Title** | Fix measurement dashboard QT scenario count: "11/11 pass (QT-001–010)" → "10/10 pass" |
| **Finding** | MF2-03 |
| **Owner** | Project Manager |
| **Priority** | P2 (Observation) |
| **Effort Estimate** | 0.25h |
| **Target** | 2026-03-24 EOD |
| **Status** | Not Started |

**Scope:**
- Open `docs/management/measurement-dashboard.md`
- Locate the "Qualification scenario pass rate" row
- Change "11/11 pass (QT-001–010)" → "10/10 pass (QT-001–010)"
- Verify the qualification test report confirms 10 scenarios, not 11

**Exit Criteria:**
- Dashboard count corrected to 10/10
- Metric is now consistent with test report
- Document header added

---

### CR-025: Add .clang-format Configuration File (SUP.8 — software-designer-engineer)

| Field | Value |
|-------|-------|
| **CR ID** | CR-025 |
| **Title** | Add `.clang-format` configuration file to repository as CI |
| **Finding** | OB2-06 |
| **Owner** | Software Designer-Engineer |
| **Priority** | P2 (Observation) |
| **Effort Estimate** | 0.5h |
| **Target** | 2026-03-24 EOD |
| **Status** | Not Started |

**Scope:**
- Create `.clang-format` file in repository root with project-local formatting rules:
  - BasedOnStyle: LLVM (or Google, recommended for C++20)
  - ColumnLimit: 100
  - BreakBeforeBraces: Stroustrup
  - Standard: c++20
  - Other project conventions from QA plan
- Commit `.clang-format` as a configuration item
- Document in `docs/support/configuration-management-plan.md` CI list

**Exit Criteria:**
- `.clang-format` file exists in repo root
- File is tracked in git (committed)
- CI list in CM plan updated to include `.clang-format`
- Coding standard compliance enforcement is now reproducible

---

### CR-026: Create QA Audit Records (SUP.1 — project-manager)

| Field | Value |
|-------|-------|
| **CR ID** | CR-026 |
| **Title** | Create QA audit records for the 5 planned quality activities |
| **Finding** | OB2-07 |
| **Owner** | Project Manager |
| **Priority** | P2 (Observation) |
| **Effort Estimate** | 2h |
| **Target** | 2026-03-25 EOD |
| **Status** | Not Started |

**Scope:**
Create `docs/support/qa-audit-records.md` with documented records for each of the 5 planned QA activities:

1. **Requirements Review** — Verify completeness, traceability, acceptance criteria
2. **Architecture Review** — Verify design allocation, interface contracts, consistency
3. **Design Review** — Verify detailed design, error handling, code mapping
4. **Test Readiness Review** — Verify test specs complete, environment ready
5. **Traceability Check** — Verify bidirectional traceability matrix complete

For each activity, document:
- Activity Date
- Scope/Artifact(s) Reviewed
- Items Checked (e.g., "All 13 SWE-IDs have design mappings")
- Findings ("No findings" or list defects/observations)
- Disposition (Approved, Approved with comments, Rework required)
- Cross-reference to CR/CA if defects found

**Example format:**
```
## Activity 1: Requirements Review (Date: 2026-03-20)

- **Scope:** docs/requirements/software-requirements.md
- **Items Checked:** 
  - All 13 SWE requirements have unique IDs ✓
  - All have source SYS links (derived req)s) ✓
  - Allocation to files present ✓
- **Findings:** Approved
- **Disposition:** No rework needed
```

**Exit Criteria:**
- QA audit log exists with all 5 activities documented
- Each record includes date, scope, items checked, findings, disposition
- All findings (if any) are cross-referenced to CRs or noted as non-blocking
- Document header added

---

### CR-027: Fix Problem Resulation Log Semantic Inconsistency (SUP.9 — project-manager)

| Field | Value |
|-------|-------|
| **CR ID** | CR-027 |
| **Title** | Fix PR-001/002 status-date inconsistency; ensure semantic clarity |
| **Finding** | OB2-08 |
| **Owner** | Project Manager |
| **Priority** | P2 (Observation) |
| **Effort Estimate** | 0.5h |
| **Target** | 2026-03-24 EOD |
| **Status** | Not Started |

**Scope:**
- Open `docs/support/problem-resolution-log.md`
- Review PR-001 and PR-002: they currently show Status "Open (Monitoring)" with Resolved date "2026-03-23"
- **Choose one semantic fix:**
  - **Option A:** Change Status to "Closed (Monitoring)" + keep Resolved date (indicates closure point for monitoring)
  - **Option B:** Keep Status "Open (Monitoring)" + remove Resolved date + add "Monitoring since: 2026-03-23" column
- Apply chosen semantic consistently across all 6 problem entries
- Update document header

**Exit Criteria:**
- PR-001 and PR-002 status-date contradiction resolved
- All problem entries use consistent status vocabulary
- Semantics are unambiguous (e.g., "Resolved" date only appears with resolved/closed status)
- Document header added

---

## Implementation Schedule

| Phase | CRs | Owner | Target | Dependency |
|-------|-----|-------|--------|-----------|
| **M7+0 (23 Mar)** | Planning | PM | EOD | — |
| **M7+1 (24 Mar)** | CR-019, CR-020, CR-021, CR-024, CR-025, CR-027 | ST, PM, SDE | EOD | M7+0 |
| **M7+2 (25 Mar)** | CR-022, CR-023, CR-026 | All, ST, PM | EOD | M7+1 |
| **M7+3 (26 Mar)** | Verification & Closure | PM | EOD | M7+2 |

---

## Execution Tracking

| CR | Status | PM Verification |
|----|--------|-----------------|
| CR-019 | Not Started | Pending |
| CR-020 | Not Started | Pending |
| CR-021 | Not Started | Pending |
| CR-022 | Not Started | Pending |
| CR-023 | Not Started | Pending |
| CR-024 | Not Started | Pending |
| CR-025 | Not Started | Pending |
| CR-026 | Not Started | Pending |
| CR-027 | Not Started | Pending |

---

## Success Criteria

- **All 9 CRs executed and artifact-verified**
- **P1 findings resolved before M7+2**
- **P2 findings resolved by M7+3**
- **All work products carry document headers**
- **No placeholder text remains in formal artifacts**
- **Assessment 2 findings closed and documented**
- **Project ready for Assessment 3 planning**

---

*M7 Plan created: 2026-03-23 by Project Manager*
*Assessment baseline: ready-for-assessment2 (dc44320)*
*Product baseline: v0.1.0-draft (44a7d7c)*
