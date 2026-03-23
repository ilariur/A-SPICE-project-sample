---
Revision: 1.1
Date: 2026-03-27
Author: Software Integration Tester
Status: Approved
---

# Software Integration Test Report

## Baseline
- Executable: `build/day_night_simulation`
- Environment: simulated CAN environment using the integrated `DayNightController`

## Executed Scenarios
- IT-001/IT-003 Poll and query path
- IT-002 Multi-subscriber transition
- IT-005 Unsubscribe suppresses notification
- IT-004 Registration edge handling
- IT-006 Malformed frame handling
- IT-007 Delayed luminance response
- IT-008/QT-010 Diagnostic fault message on FAULT enter and clear

## Result Summary
- Status: Passed
- Evidence source: console output from `./build/day_night_simulation`

## Executed Result
```text
PASS - IT-001/IT-003 Poll and query path
PASS - IT-002 Multi-subscriber transition
PASS - IT-005 Unsubscribe suppresses notification
PASS - IT-004 Registration edge handling
PASS - IT-006 Malformed frame handling
PASS - IT-007 Delayed luminance response
PASS - IT-008/QT-010 Diagnostic fault message on FAULT enter and clear
Summary: 12/12 scenarios passed.
```

## Assessment
- Poll scheduling, query response, registration handling, transition notification, and unsubscribe behavior were verified in the simulated CAN environment.
- Malformed and unknown CAN frames were ignored without corrupting state or emitting unintended responses.
- Delayed luminance responses moved the controller to `FAULT` once the timeout expired, and the controller recovered to a valid operational state when luminance data resumed.
- Dedicated diagnostic reporting was verified with CAN ID `0x540` for fault active and fault clear events.
- No integration anomalies were observed in the executed scenarios.

## Notes
- The same executable also ran qualification scenarios; the summary line reflects the full combined run.