# Software Qualification Test Specification

## Operational Context
- Embedded software item running on a deterministic target with CAN access
- Standard 11-bit CAN bus
- External luminance source provides lux values over CAN
- Consumers query and subscribe over the same CAN network

## Requirement-Based Scenarios

| ID | Scenario | Expected Result |
|---|---|---|
| QT-001 | 60-second steady daylight with repeated polls | State remains `DAY`; no spurious notifications |
| QT-002 | 60-second steady night with repeated polls | State remains `NIGHT`; no spurious notifications |
| QT-003 | Dusk profile crossing below 800 lux | State changes from `DAY` to `NIGHT` once |
| QT-004 | Dawn profile crossing above 1500 lux | State changes from `NIGHT` to `DAY` once |
| QT-005 | Query during steady day | Response is `DAY` |
| QT-006 | Query after dusk transition | Response is `NIGHT` |
| QT-007 | Two clients subscribe before transition | Both receive notification |
| QT-008 | Client unsubscribes before transition | Unsubscribed client receives no notification |
| QT-009 | Missing luminance response for multiple poll intervals after a valid sample | Polling continues and query returns the last known state |

## Residual Risks
- Vehicle CAN IDs are still provisional.
- Threshold values may require sensor-specific calibration.
- Bus-level timing on the final target still requires vehicle integration confirmation.
- No explicit fault state is emitted for missing luminance responses; current behavior retains the last known state or `UNKNOWN` before the first valid sample.

## Release Recommendation Criteria
- All functional scenarios pass.
- Traceability from requirements to tests is complete.
- No unresolved high-severity issues remain.