# Problem Resolution Log

| ID | Issue | Impact | Resolution |
|---|---|---|---|
| PR-001 | Final vehicle CAN IDs are not yet confirmed | Integration contract may change | Keep message IDs provisional and isolate them in `can_protocol.hpp` |
| PR-002 | Threshold values may need calibration against physical sensor behavior | Qualification results may shift | Keep thresholds configurable in `ControllerConfig` |
| PR-003 | Role outputs initially drifted into unrelated workspace products | Artifact quality risk during document generation | Updated role skills to enforce strict product-scope behavior |
| PR-004 | Negative-path evidence for malformed and missing CAN frames was not initially executed | Verification coverage gap | Added simulated malformed-frame, delayed-response, and missing-response scenarios to `day_night_simulation` and updated test reports |
| PR-005 | Missing luminance responses were only documented as a limitation, not implemented as product behavior | Incomplete robustness requirement fulfillment | Added configurable timeout fault state and recovery behavior in code, tests, simulation scenarios, and project documentation |
| PR-006 | FAULT state had no dedicated diagnosable fault-code CAN message | External diagnostics could not consume explicit fault events | Added CAN ID `0x540` diagnostic message with timeout fault code and active/clear status, plus test and documentation updates |