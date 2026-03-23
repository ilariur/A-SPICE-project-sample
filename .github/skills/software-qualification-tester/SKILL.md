---
name: software-qualification-tester
description: 'Use when planning and executing software qualification testing aligned to Automotive SPICE 4.0. Covers test scope against software requirements, operational scenarios, pass-fail criteria, defect handling, regression, and release-quality evidence.'
argument-hint: 'Describe the software item, target release, operational context, and qualification objective.'
---

# Software Qualification Tester

## Purpose
Use this skill to verify that the integrated software item satisfies its software requirements in its intended operational context and to provide objective release evidence.

## Automotive SPICE Alignment
- Primary processes: SWE.6
- Supporting focus: SWE.1, SWE.5, SUP.9, SUP.10
- Intent: define and execute qualification tests against software requirements, evaluate results, manage anomalies, and support release decisions with traceable evidence.

## When to Use
- Release candidate validation
- Requirement-based end-to-end software verification
- Regression qualification after significant change
- Audit or assessment preparation for software test evidence

## Working Rules
- Base qualification tests on software requirements, use cases, operating modes, and acceptance criteria.
- Run tests on identified baselines in representative environments.
- Keep pass or fail criteria objective and reviewable.
- Distinguish unresolved requirement issues from environment or test procedure issues.
- Report residual risk and non-covered requirements explicitly.
- Constrain qualification scenarios to approved product requirements and operational context only; do not expand scope with unrelated product behaviors.

## Procedure
1. Review software requirements, qualification entry criteria, integrated baseline status, and open anomaly list.
2. Define qualification test cases and procedures that cover normal operation, degraded behavior, interfaces, diagnostics, startup and shutdown, and key non-functional expectations.
3. Establish expected results, test data, environment setup, and requirement traceability.
4. Execute tests, compare actual results to expected results, and document deviations.
5. Record anomalies with impact on requirements, release risk, and workaround status.
6. Re-run affected tests after corrections and maintain regression evidence.
7. Summarize requirement coverage, outstanding issues, and release recommendation.

## Base Practice Checklist
- Derive qualification tests from software requirements.
- Define test procedures, data, environment, and expected results.
- Execute qualification tests on controlled baselines.
- Compare results with expected outcomes and log anomalies.
- Maintain requirement coverage and support release decisions with evidence.

## Expected Outputs
- Software qualification test specification
- Requirement-based test procedures
- Execution records and anomaly reports
- Requirement coverage matrix
- Qualification summary and release recommendation

## Evidence to Keep
- Baseline identification and environment details
- Raw logs and captured results
- Requirement traceability to tests and outcomes
- Residual risk and deviation decisions

## Done Criteria
- Software qualification status is clear at requirement level, including passed scope, failed scope, blocked scope, and residual release risk.