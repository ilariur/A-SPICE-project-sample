# Software Integration Strategy

## Integration Order
1. Integrate protocol definitions and controller interface.
2. Integrate scheduling and luminance response handling.
3. Integrate query response logic.
4. Integrate subscription control logic.
5. Integrate state-change notification logic.
6. Integrate demo harness and verification executable.

## Baseline Contents
- `build.ninja`
- `src/can_protocol.hpp`
- `src/day_night_controller.hpp`
- `src/day_night_controller.cpp`
- `src/main.cpp`
- `tests/day_night_controller_tests.cpp`
- All A-SPICE documents in `docs/`

## Smoke Checks
- Build succeeds from a clean workspace.
- Startup sends an initial poll request.
- Luminance response causes a stable `DAY` or `NIGHT` decision.
- Query request returns a state response frame.
- Subscription request returns an ACK.
- State transition generates one notification per subscriber.

## Configuration Items
- Toolchain: `clang++`
- Standard: C++20
- CAN identifiers and payload definitions
- Threshold configuration
- Poll interval value

## Handoff Criteria
- Integrated baseline is buildable and identified.
- Smoke checks pass.
- Known issues and assumptions are logged.
- Test specifications and traceability are available for verification roles.