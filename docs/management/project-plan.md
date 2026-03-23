---
Revision: 2.1
Date: 2026-03-26
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