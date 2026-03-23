# Product Memory

## Product
- Name: Luminance Day/Night State Manager
- Scope: Poll luminance over CAN every 5 seconds, determine `DAY` or `NIGHT`, answer CAN state queries, and notify registered software of state changes.
- Language: C++20
- Interface style: Standard 11-bit CAN frames with fixed message identifiers.

## Key Decisions
- The product sends a luminance poll request every 5000 ms and expects a luminance response frame.
- The product enters `FAULT` if luminance responses are missing longer than the configured timeout, defaulting to 6000 ms.
- The product emits CAN ID `0x540` with timeout fault code on fault enter and a clear message on fault recovery.
- State logic uses hysteresis to avoid chatter: switch to `DAY` above 1500 lux, switch to `NIGHT` below 800 lux.
- A valid luminance response after `FAULT` recovers the product to `DAY` or `NIGHT` using the same threshold rules.
- Query responses are point-to-point by client identifier carried in the payload.
- Notifications are sent once per state change to each registered client.
- Subscription registry is bounded to 8 clients to keep memory usage deterministic.

## Open Assumptions
- Vehicle network allocates these CAN identifiers for this software item.
- Luminance sensor value is encoded as `uint16` lux in the response payload.
- Poll request and response timing on the vehicle bus permit a 5-second control loop.

## Project Memories
- Management artifacts were created first to establish document inventory, risks, measures, and phase gates.
- Several role skill runs drifted into unrelated workspace projects; affected role skills were updated to enforce product-scope discipline.
- The implementation is intentionally deterministic and self-contained so unit and integration evidence can be produced without external frameworks.
- The project was built successfully with `ninja -f build.ninja`, and the self-contained unit verification executable passed.
- The simulated CAN scenario runner passed 11 of 11 combined integration and qualification scenarios, including malformed-frame, delayed-response, and missing-response cases.
- Timeout fault behavior is now implemented end to end: query and notification paths expose `FAULT`, and recovery on valid luminance response is verified.
- Dedicated diagnosable fault reporting is implemented alongside `FAULT` state transitions and verified in unit and simulation scenarios.

## Artifact Index
- `docs/management/project-plan.md`
- `docs/management/risk-register.md`
- `docs/management/measurement-dashboard.md`
- `docs/requirements/stakeholder-requirements.md`
- `docs/requirements/system-requirements.md`
- `docs/requirements/software-requirements.md`
- `docs/architecture/software-architecture.md`
- `docs/design/software-detailed-design.md`
- `docs/integration/software-integration-strategy.md`
- `docs/test/software-unit-verification-spec.md`
- `docs/test/software-integration-test-spec.md`
- `docs/test/software-integration-test-report.md`
- `docs/test/software-qualification-test-spec.md`
- `docs/test/software-qualification-test-report.md`
- `docs/support/configuration-management-plan.md`
- `docs/support/quality-assurance-plan.md`
- `docs/support/problem-resolution-log.md`
- `docs/traceability/traceability-matrix.md`

## Baseline Status
- Version: `0.1.0-draft`
- Entry status: Build-validated, unit-test-validated, and simulation-validated for integration and qualification scenarios.