# Measurement Dashboard

| Measure | Target | Evidence Source | Current Status |
|---|---|---|---|
| Requirements traced | 100% | `docs/traceability/traceability-matrix.md` | Implemented in artifact set |
| Poll interval conformance | 5000 ms exact in simulated scheduler | Unit and integration tests | Implemented in code; smoke-verified in demo run |
| Unit test pass rate | 100% of planned unit tests | `build/day_night_tests` | Achieved in local run |
| Integration smoke checks | 100% pass | Integration strategy checklist | Basic smoke behavior verified in demo run |
| Integration scenario pass rate | 100% of executed scenarios | `build/day_night_simulation` and integration report | Achieved in local run |
| Qualification scenario pass rate | 100% of executed scenarios | `build/day_night_simulation` and qualification report | Achieved in local run |
| Negative-path CAN scenario pass rate | 100% of executed malformed or missing-response scenarios | `build/day_night_simulation` | Achieved in local run |
| Timeout fault scenario pass rate | 100% of executed timeout and recovery scenarios | `build/day_night_tests`, `build/day_night_simulation` | Achieved in local run |
| Open high-severity defects | 0 | Problem resolution log | 0 |
| Residual medium-or-higher risks | <= 2 | Risk register | 3 open |