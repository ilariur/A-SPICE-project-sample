---
Revision: 1.1
Date: 2026-03-27
Author: Software Integration Tester
Status: Approved
---

# Software Integration Report

## Scope
- Process area: SWE.5 Software Integration and Integration Test
- Role execution: software-integrator
- Objective: Verify that the identified baseline is reproducibly buildable and passes integration smoke checks.

## Baseline Identification
- Branch: `master`
- Commit: `44a7d7ccd265a98fc03ec37c7fcb35a79345bacc`
- Working tree state at execution start: clean (`git status --short --branch` showed `## master`)
- Execution timestamp (UTC): `2026-03-23 15:20:03Z`

## Reproducible Build Evidence
- Command: `ninja -t clean && ninja -f build.ninja`
- Result: pass
- Evidence summary: clean operation removed previous build outputs; full rebuild succeeded with all targets linked.

## Integration Smoke Evidence
1. Product smoke run
- Command: `./build/a_spice_product`
- Result: pass
- Evidence summary: startup poll request emitted, subscription ACK observed, state query response observed, runtime reported stable `NIGHT` state with one subscriber.

2. Unit smoke run
- Command: `./build/day_night_tests`
- Result: pass
- Evidence summary: all day/night controller unit tests passed.

3. Integration/qualification scenario smoke run
- Command: `./build/day_night_simulation`
- Result: pass
- Evidence summary: all 12/12 scenarios passed, including timeout FAULT transition and diagnostic fault active/clear behavior.

## Configuration Items Integrated
- `build.ninja`
- `src/can_protocol.hpp`
- `src/day_night_controller.hpp`
- `src/day_night_controller.cpp`
- `src/main.cpp`
- `tests/day_night_controller_tests.cpp`
- `tests/day_night_simulation.cpp`
- `docs/` A-SPICE lifecycle artifacts

## Known Issues and Residual Risks
- No blocking integration defects found in this execution.
- Residual risk: evidence is generated in a self-contained simulation harness and should be complemented with target-vehicle network timing validation in system integration.

## Handoff Decision
- Integration readiness: **ACCEPTED**
- Recommendation: hand off this baseline to software qualification and system integration activities with current evidence package.
