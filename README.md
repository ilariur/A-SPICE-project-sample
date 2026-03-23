# A-SPICE Day/Night State Manager

This project contains a small Automotive SPICE-aligned product that:

- polls luminance over a CAN interface every 5 seconds
- decides between exactly two states: `DAY` and `NIGHT`
- answers state queries from other software over CAN
- allows other software to register for state-change notifications over CAN

## Build

```sh
cd /Users/lale/learn/all/a-spice-prj
mkdir -p build
ninja -f build.ninja
```

## Run

```sh
./build/a_spice_product
./build/day_night_tests
./build/day_night_simulation
```

## Project Layout

- `product.md`: project memory, decisions, and artifact index
- `docs/management`: management work products
- `docs/requirements`: stakeholder, system, and software requirements
- `docs/architecture`: software architecture description
- `docs/design`: detailed software design
- `docs/integration`: software integration strategy
- `docs/test`: unit, integration, and qualification test specifications
- `docs/test`: unit, integration, and qualification specifications plus executable evidence reports
- `docs/support`: supporting process artifacts
- `docs/traceability`: traceability matrix
- `src`: implementation
- `tests`: self-contained verification executable