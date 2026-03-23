# Risk Register

| ID | Risk | Impact | Mitigation | Owner | Status |
|---|---|---|---|---|---|
| R-001 | CAN message IDs may conflict with vehicle allocation | Integration delay | Keep IDs provisional and confirm with network owner | Project Manager | Open |
| R-002 | Threshold calibration may not match actual sensor behavior | Wrong state decisions | Use tunable thresholds and qualify with recorded luminance traces | Requirements Engineer | Open |
| R-003 | Poll response may be delayed on loaded bus | Stale state or delayed transitions | Keep poll interval fixed and verify query/notification timing in integration test | Software Architect | Open |
| R-004 | Subscriber table overflow | Missed registration requests | Bound registry size and return explicit NAK status | Software Designer/Engineer | Mitigated |
| R-005 | Query or notification behavior may be inconsistent during transition | Consumer sees stale state | Use single controller state update and query from one coherent snapshot | Software Tester | Mitigated |
| R-006 | Timeout value may need calibration against final network latency and sensor response characteristics | False fault entries or delayed fault detection | Keep `responseTimeoutMs` configurable and confirm the final value during vehicle integration | Software Qualification Tester | Open |
| R-007 | Diagnostic CAN ID or fault-code mapping may conflict with target diagnostic architecture | Diagnostic events may be misinterpreted or ignored | Confirm CAN ID `0x540` allocation and fault-code contract with platform diagnostics owner | Software Architect | Open |