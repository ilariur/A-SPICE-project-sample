---
Revision: 1.0
Date: 2026-03-28
Author: A-SPICE Certified Assessor
Status: Final
---

# A-SPICE Assessment Report — Assessment 3

**Project:** Luminance Day/Night State Manager  
**Assessor Role:** A-SPICE Certified Assessor  
**Assessment Date:** 2026-03-28  
**Assessment Baseline:** `ready-for-assessment3` -> commit `40c8487`  
**Product Baseline:** `v0.1.0-draft` -> commit `44a7d7c`  
**Assessment Standard:** Automotive SPICE PAM 4.0 / ISO/IEC 33002  
**Scope:** SWE.1-SWE.6, MAN.3, MAN.5, MAN.6, SUP.1, SUP.8, SUP.9, SUP.10  
**Previous Assessment:** Assessment 2 (`ready-for-assessment2`), CL1 with 2 Major and 7 Observation findings

---

## 1. Executive Summary

This third assessment evaluates the project at the `ready-for-assessment3` baseline after completion of M7 corrective actions and M8 CL2-readiness activities. Evidence was reviewed across all 13 scoped process areas with focus on PA 1.1 (performance of process), PA 2.1 (performance management), and PA 2.2 (work product management).

**Assessment 2 findings closure: CONFIRMED.**
- All Assessment 2 corrective actions (CR-019 through CR-027) are closed and artifact-verified.
- No unresolved Major findings remain.
- Previously observed systemic gaps (document headers, review records, coverage measurement, QA execution records, status consistency) are addressed with objective evidence.

**Overall Project Capability Level: CL2 (Managed)**

All 13 assessed process areas achieve CL2. For every assessed process, PA 1.1, PA 2.1, and PA 2.2 are rated Fully Achieved (F).

---

## 2. Capability Level Rating Summary

| Process | Process Name | PA 1.1 | PA 2.1 | PA 2.2 | Capability Level |
|---------|-------------|--------|--------|--------|------------------|
| SWE.1 | Software Requirements Analysis | F | F | F | CL2 |
| SWE.2 | Software Architectural Design | F | F | F | CL2 |
| SWE.3 | Software Detailed Design and Unit Construction | F | F | F | CL2 |
| SWE.4 | Software Unit Verification | F | F | F | CL2 |
| SWE.5 | Software Integration and Integration Testing | F | F | F | CL2 |
| SWE.6 | Software Qualification Testing | F | F | F | CL2 |
| MAN.3 | Project Management | F | F | F | CL2 |
| MAN.5 | Risk Management | F | F | F | CL2 |
| MAN.6 | Measurement | F | F | F | CL2 |
| SUP.1 | Quality Assurance | F | F | F | CL2 |
| SUP.8 | Configuration Management | F | F | F | CL2 |
| SUP.9 | Problem Resolution Management | F | F | F | CL2 |
| SUP.10 | Change Request Management | F | F | F | CL2 |

**PA Rating Scale:** N = Not achieved (0-15%) · P = Partially achieved (>15-50%) · L = Largely achieved (>50-85%) · F = Fully achieved (>85-100%)

---

## 3. Assessment Basis and Evidence

### 3.1 Baseline and Configuration Integrity
- Assessment baseline tag `ready-for-assessment3` verified at commit `40c8487`.
- Product baseline `v0.1.0-draft` retained at commit `44a7d7c`.
- Configuration management evidence confirms controlled baselines, CI tracking, and reproducible build records.

### 3.2 Cross-Process Evidence Supporting CL2
- **PA 2.1 evidence:** Process performance objectives defined and monitored for all 13 processes in `docs/management/project-plan.md` (Revision 2.2).
- **PA 2.2 evidence:** Work product management controls implemented via consistent document metadata headers (Revision, Date, Author, Status) across managed artifacts.
- **Formal review evidence:** `docs/support/review-records.md` documents formal review execution and approval for all 13 processes with zero major findings.
- **QA execution evidence:** `docs/support/qa-audit-records.md` records all 5 planned QA activities with findings/disposition and CR linkage.
- **Measurement evidence:** `docs/management/measurement-dashboard.md` includes quantitative results and corrected consistency checks (e.g., QT 10/10, coverage reported).

### 3.3 Quantitative Product and Verification Evidence
- Requirements traceability: 13/13 SWE mapped.
- Unit tests: 14/14 pass.
- Integration scenarios: 12/12 pass.
- Qualification scenarios: 10/10 pass.
- Statement coverage: 87% (target >= 80%).
- Branch coverage: 78% (target >= 70%).

---

## 4. Process-by-Process Conclusion

### SWE.1 - SWE.6 (Engineering)
Engineering process evidence demonstrates complete requirement/design/test traceability, controlled verification execution, corrected report consistency, and maintained interface/architecture integrity. Managed-process evidence (targets, monitoring, and formal reviews) is present and current.

**Result:** SWE.1, SWE.2, SWE.3, SWE.4, SWE.5, SWE.6 all rated **CL2**.

### MAN.3, MAN.5, MAN.6 (Management)
Management artifacts show reconciled milestone data, documented effort variance rationale, complete corrective action closure, quantified measurement set, and explicit risk decisions with traceability.

**Result:** MAN.3, MAN.5, MAN.6 all rated **CL2**.

### SUP.1, SUP.8, SUP.9, SUP.10 (Support)
Support processes show complete QA execution records, controlled CM/tagging practice, semantically consistent problem status tracking, and complete CR governance with artifact-verified closures.

**Result:** SUP.1, SUP.8, SUP.9, SUP.10 all rated **CL2**.

---

## 5. Findings

### 5.1 New Findings in Assessment 3
- **Critical:** 0
- **Major:** 0
- **Observations:** 0

### 5.2 Residual Risk Statement
Residual technical/project risks remain documented in the risk register as accepted, monitored integration-time risks. These do not invalidate process capability conclusions and are managed within defined controls.

---

## 6. Overall Assessment Conclusion

The Luminance Day/Night State Manager project demonstrates a complete transition from CL1 (Assessment 2 baseline) to CL2 at the `ready-for-assessment3` baseline.

Evidence confirms:
- Process performance is fully achieved across all 13 scoped processes.
- Process performance management is planned, monitored, and recorded.
- Work products are managed under formal metadata and review control.

**Final Project Capability Rating: CL2 (Managed)**

**Assessor Recommendation:** Baseline `ready-for-assessment3` is suitable for official third-party/certified assessor review and external reporting.

---

*Assessment conducted in role of A-SPICE Certified Assessor. Standard applied: Automotive SPICE PAM 4.0 aligned to ISO/IEC 33002.*
