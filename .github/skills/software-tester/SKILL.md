---
name: software-tester
description: 'Use when preparing and executing software unit verification aligned to Automotive SPICE 4.0. Covers unit test design, expected results, coverage intent, defect reporting, regression handling, and verification evidence for implemented software units.'
argument-hint: 'Describe the software unit, verification scope, and any quality or coverage expectations.'
---

# Software Tester

## Purpose
Use this skill to verify software units against detailed design and allocated requirements with clear expected results and objective defect evidence.

## Automotive SPICE Alignment
- Primary processes: SWE.4
- Supporting focus: SWE.3, SUP.9, SUP.10
- Intent: define unit verification cases and procedures, execute them in a controlled environment, compare actual and expected results, and record anomalies and coverage.

## When to Use
- New unit verification
- Regression verification after code change
- Investigation of low-level defects
- Review of unit test adequacy before integration

## Working Rules
- Base unit tests on requirements, design logic, interfaces, error handling, and boundary conditions.
- Define expected results before execution.
- Keep the test environment controlled and repeatable.
- Separate test case defects, code defects, and environment issues.
- Preserve traceability from unit tests back to requirements and detailed design.
- Keep the verification scope tied to the stated product and its actual units; do not reuse scenarios from unrelated codebases.

## Procedure
1. Review unit requirements, detailed design, interfaces, algorithms, states, and boundary behavior.
2. Design unit verification cases for nominal, boundary, invalid, error, and resource-related conditions.
3. Define expected results, pass or fail criteria, stubs, drivers, and environment setup.
4. Execute the tests and compare actual results to expected results.
5. Record anomalies with reproducible steps, observed behavior, expected behavior, and affected baseline.
6. Re-run impacted tests after fixes and maintain a regression set.
7. Report verification status, gaps, and residual concerns to design and integration stakeholders.

## Base Practice Checklist
- Derive unit verification cases and procedures from requirements and design.
- Define expected outcomes and acceptance criteria.
- Execute unit verification in a controlled environment.
- Compare results, log anomalies, and assess completion status.
- Maintain traceability and regression evidence.

## Expected Outputs
- Unit verification specification
- Test procedures and expected results
- Execution records and defect reports
- Requirement and design trace links
- Regression status summary

## Evidence to Keep
- Test environment configuration
- Raw execution logs and artifacts
- Coverage rationale where applicable
- Re-test evidence after fixes

## Done Criteria
- Unit verification demonstrates whether the implemented unit satisfies its detailed design and allocated requirements.