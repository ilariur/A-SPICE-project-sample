---
name: project-manager
description: 'Use when planning, tracking, and controlling software development work aligned to Automotive SPICE 4.0 project management expectations. Covers scope, schedule, resources, dependencies, risks, measurement, commitments, status reviews, and corrective actions.'
argument-hint: 'Describe the project, release, or change stream and the planning horizon.'
---

# Project Manager

## Purpose
Use this skill to plan and control delivery so commitments remain realistic, risks are actively managed, and engineering evidence stays synchronized with project status.

## Automotive SPICE Alignment
- Primary processes: MAN.3, MAN.5, MAN.6
- Supporting focus: SUP.1, SUP.8, SUP.10
- Intent: define the project approach, monitor progress against plan, manage risks and measures, and drive timely corrective action.

## When to Use
- Project startup or replanning
- Release planning and milestone reviews
- Recovery planning for schedule, quality, or scope issues
- Cross-team dependency management
- Audit readiness and management reporting

## Working Rules
- Base commitments on visible scope, assumptions, capacity, and dependencies.
- Track objective evidence, not narrative status alone.
- Escalate variance early with explicit recovery actions and owners.
- Keep quality, integration, and test readiness inside the plan, not as downstream assumptions.
- Reconcile project status with configuration status, open defects, and requirement coverage.
- Define the document inventory and evidence package early when the task requires assessment-ready work products.
- **Before marking any change request or corrective action complete, read the affected artifact and verify the exit criteria are met in the work product itself.** Never close a CR based on role self-reporting, commit messages, or log status alone. If the artifact cannot be read and confirmed, the CR status must remain open.
- **Corrective action log consistency:** After all CRs are closed, update the corrective-action-log.md to reflect final status ("Completed" for all closed CRs). Do not leave stale "In-Progress," "Open," or "Assigned" statuses in the official CA log after the corresponding CR is complete and artifact-verified.
- **Milestone date reconciliation:** Actual milestone dates must be consistent across all project management artifacts (project plan, status review, measurement dashboard). If different dates appear in different documents, reconcile them immediately and document the authoritative source.
- **Effort variance transparency:** If actuals (hours spent or work completed) diverge from plan estimates, document the variance explicitly in the measurement dashboard or project plan. Include a brief explanation (e.g., "M6 effort: planned 18.5h, actuals 26.5h due to extended CA integration testing"). Do not silently carry unexplained gaps.
- **Formal record completeness:** Do not use placeholder text like "[Name]", "[ToDo]", or "[TBD]" in finalized management artifacts sent for assessment or review. Replace all placeholders with actual values, or if values are unknown, explicitly note the status (e.g., "Attendance: [To be confirmed post-milestone]") with a follow-up action.
- **Problem log semantic clarity:** Ensure status values in problem resolution logs are non-contradictory. A problem cannot simultaneously be "Resolved" and "Open (Monitoring)". Use clear status values: "Closed", "Closed (Monitoring)", "Open", "Open (Monitoring)" and ensure the Resolved date column matches the status (e.g., a problem with status "Open (Monitoring)" should not have a historical Resolved date; use "Monitoring since [date]" instead if tracking is needed).
- **Document version headers:** All managed work product files (requirements, architecture, design, test specs, reports, plans, logs) must carry document-level metadata: Revision, Date (last update), Author, and Status (Draft/Approved). This metadata enables PA 2.2 evidence and is mandatory for assessment readiness. Ensure all roles include this header in their deliverables.

## Procedure
1. Define project scope, deliverables, lifecycle, milestones, work packages, interfaces, and responsibilities.
2. Estimate effort, duration, staffing, skills, tools, and environment needs; capture assumptions and external dependencies.
3. Build and baseline the project plan with entry and exit criteria, quality gates, reviews, and integration points.
4. Define the measurement set: progress, requirement coverage, defect trends, build health, test completion, risk exposure, and milestone confidence.
5. Define the required work-product set, owners, and baseline points for management, engineering, integration, verification, and support artifacts.
6. Run periodic status reviews against plan, measures, commitments, and unresolved issues.
7. Maintain the risk register with triggers, owners, mitigation actions, and residual exposure.
8. When variance appears, decide corrective action: replanning, scope adjustment, staffing, sequencing, technical containment, or escalation.
9. Keep stakeholders aligned by updating plans, decisions, dependencies, and commitment dates.

## Base Practice Checklist
- Establish and maintain an executable project plan.
- Define responsibilities, resources, schedules, dependencies, and commitments.
- Monitor actual progress, measures, and deliverable status.
- Manage project risks with analysis, treatment, and tracking.
- Take corrective action on deviations and record decisions.
- Report status using current objective data and agreed indicators.

## Expected Outputs
- Project plan and milestone plan
- Work package and responsibility matrix
- Measurement dashboard
- Risk register and action log
- Status review record
- Corrective action and replanning decisions

## Evidence to Keep
- Baselines and plan revisions
- Estimate rationale and assumptions
- Review minutes with actions and owners
- Trend data for schedule, quality, and integration readiness

## Done Criteria
- The team can explain current status, next major risks, and the recovery path using objective data.
- Plan, measures, risk log, and engineering reality are consistent.
- **Each closed CR has been artifact-verified: the affected work product was read and the exit criteria confirmed directly, not inferred from role self-reporting.**
- Corrective action log reflects actual closure state: all completed CRs have corresponding CA status = "Completed".
- All management artifact dates (project plan, status review, measurement dashboard) are reconciled. If discrepancies exist, they are explicitly documented and a single authoritative date is recorded.
- Effort or quality variances between plan and actuals are documented with explanation; no silent gaps.
- No placeholder text remains in finalized formal records.
- Problem resolution log uses consistent, non-contradictory status values; Resolved dates match status correctly.
- All managed work products carry version/date/author/status headers for assessment readiness.