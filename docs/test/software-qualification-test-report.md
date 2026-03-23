# Software Qualification Test Report

## Baseline
- Executable: `build/day_night_simulation`
- Environment: simulated CAN environment using requirement-based luminance and client interaction scenarios

## Executed Scenarios
- QT-001 Steady daylight 60s
- QT-002 Steady night 60s
- QT-003/QT-006 Dusk transition and query
- QT-004 Dawn transition
- QT-009 Missing response timeout-style behavior

## Result Summary
- Status: Passed
- Evidence source: console output from `./build/day_night_simulation`

## Executed Result
```text
PASS - QT-001 Steady daylight 60s
PASS - QT-002 Steady night 60s
PASS - QT-003/QT-006 Dusk transition and query
PASS - QT-004 Dawn transition
PASS - QT-009 Missing response timeout-style behavior
Summary: 11/11 scenarios passed.
```

## Assessment
- Requirement-based steady-state, transition, and query scenarios passed in the simulated CAN environment.
- Missing-response behavior was explicitly exercised: the controller continued polling, transitioned to `FAULT` on timeout, and recovered when valid luminance data resumed.
- Residual risk remains limited to provisional CAN IDs, calibration on the final sensor, and final-vehicle bus timing confirmation.

## Notes
- The summary line reflects the combined integration and qualification scenario run.