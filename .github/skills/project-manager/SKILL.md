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
10. **Execute and record QA audit activities (SUP.1 contribution):** For each planned quality activity (requirements review, architecture review, design review, test readiness, traceability check), conduct the activity and create a QA audit record documenting: activity date, scope/artifact reviewed, items checked, findings (defects/observations or "no findings"), and disposition (accepted/rework). Maintain a QA audit log and cross-reference to corrective actions.

## Base Practice Checklist (PA 1.1 Completeness for MAN.3/MAN.6/SUP.1/SUP.9)
- **Project plan completeness (MAN.3):** Scope, deliverables, milestones, work packages, roles, resources, dependencies, assumptions, quality gates, and reviews are defined. Effort and schedule estimates are justified.
- **Measurement completeness (MAN.6):** Progress metrics, requirement coverage, defect tracking, build health, test completion, risk exposure, code coverage, and quality indicators are defined. All metrics are collected, recorded, and trended.
- **Status review completeness (MAN.3):** Milestone status, milestone dates (target vs. actual), variance, corrective action, risks, and management decisions are recorded. Attendees are named; decisions are documented with owners and dates.
- **Corrective action completeness (MAN.3):** CR log reflects all changes. CA log status matches CR status (completed CAs have completed CRs). Date consistency across plan, status review, and dashboard. All effort variance is explained.
- **Problem resolution completeness (SUP.9):** All problems are tracked with ID, status, detected date, resolution date, priority, and impact. Status values are consistent and non-contradictory. No orphaned or undocumented problems.
- **Quality assurance completeness (SUP.1):** All planned QA activities (requirements review, architecture review, design review, test readiness, traceability check, etc.) are executed and recorded in a QA audit log. Each audit record includes activity date, scope, items checked, findings, and disposition. Defects and observations are escalated to CR or CA logs.
- **Report status using current objective data and agreed indicators.**

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

## Done Criteria (PA 1.1 Fully Achieved for MAN.3/MAN.6/SUP.1/SUP.9)
- **MAN.3 (Project Management):** The project plan is complete, milestones have target and actual dates, all variances are documented with recovery actions, corrective actions are tracked and closed, status review records are complete with named attendees and decisions, all CR and CA logs are fully populated and consistent.
- **MAN.6 (Measurement):** All defined metrics are collected. Product quality measures (test pass rates, coverage, requirement completeness) include quantitative values, baseline hash, and date. Project management measures (schedule variance, effort variance, risk count) are recorded and trended. Quality variances are documented with explanation.
- **SUP.1 (Quality Assurance):** All planned QA activities have been executed and documented in a QA audit log. Each audit record includes date, scope, items checked, findings (or "no findings"), and disposition. Any findings are escalated to CR or CA logs. Quality activities cover the full lifecycle (requirements through release).
- **SUP.9 (Problem Resolution):** All detected problems are logged with ID, status, detected date, resolution date (if resolved), impact, and priority. Problem status values are consistent and non-contradictory. No problems remain orphaned or undocumented.
- **Each closed CR has been artifact-verified:** the affected work product was read and exit criteria confirmed directly, not inferred from role reporting.
- **All management artifact dates are reconciled:** project plan, status review, and measurement dashboard show consistent milestone actual dates. Any discrepancies are explicitly documented and resolved.
- **Effort and quality variances are explained:** no silent gaps between plan and actuals.
- **No placeholder text remains:** all formal records use concrete names, dates, and values.
- **All managed work products carry revision/date/author/status headers.**
- **Evidence of comprehensive execution:** all plan/measurement/control/audit processes are documented, traceable, and demonstrate that project management was actively performed, not retrospectively inferred.