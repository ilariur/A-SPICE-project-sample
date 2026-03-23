---
name: software-integration-tester
description: 'Use when planning and executing software integration testing aligned to Automotive SPICE 4.0. Covers integration test strategy, interface verification, sequencing, environment readiness, anomaly handling, regression, and evidence for integrated software items.'
argument-hint: 'Describe the integrated baseline, interfaces under test, and the test objective.'
---

# Software Integration Tester

## Purpose
Use this skill to verify that integrated software elements interact correctly, exchange data as intended, and behave properly across interfaces, sequences, and failure conditions.

## Automotive SPICE Alignment
- Primary processes: SWE.5
- Supporting focus: SWE.2, SWE.3, SUP.9, SUP.10
- Intent: define and execute tests for integrated software items, verify internal and external interfaces, and evaluate results against integration expectations.

## When to Use
- Baseline entry into integration test
- Interface regression after architecture or dependency changes
- Multi-component behavior verification
- Build acceptance for qualification test entry

## Working Rules
- Base integration tests on architecture, interface contracts, sequences, states, and error handling.
- Test interactions incrementally and preserve execution order evidence.
- Validate both functional behavior and interface robustness.
- Keep environment, data sets, simulators, and tooling under control.
- Record anomalies with enough detail to separate interface, logic, timing, and environment issues.
- Keep all interface and sequence definitions specific to the active product baseline; avoid importing unrelated components or workflows from other workspace folders.

## Procedure
1. Review the integration strategy, software architecture, interface specifications, and integrated baseline contents.
2. Define integration test cases and procedures for interfaces, control flow, sequencing, timing, shared resources, and negative conditions.
3. Prepare the environment, simulators, stubs, data, and baseline identification needed for repeatable execution.
4. Execute tests according to the planned sequence and compare results with expected interface and behavior criteria.
5. Record anomalies, impacted interfaces, suspected root-cause area, and regression needs.
6. Re-test after fixes and maintain status of passed, failed, blocked, and not-run cases.
7. Recommend entry or hold decisions for software qualification testing based on objective readiness evidence.

## Base Practice Checklist
- Derive integration tests from architecture and interface definitions.
- Define integration test procedures and expected results.
- Execute tests on controlled integrated baselines.
- Compare results with expectations and log anomalies.
- Maintain regression status and readiness evidence.

## Expected Outputs
- Software integration test specification
- Test procedures and expected results
- Execution records and anomaly reports
- Interface coverage traceability
- Integration test status report

## Evidence to Keep
- Baseline and environment identification
- Interface versions and configuration data
- Test logs, traces, and packet or signal captures where relevant
- Exit recommendation and unresolved issue list

## Done Criteria
- Integrated software behavior has been objectively checked across key interfaces and sequences, with entry readiness for qualification testing clearly justified.