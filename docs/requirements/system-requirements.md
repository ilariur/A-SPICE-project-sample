# System Requirements

| ID | Requirement | Verification Method |
|---|---|---|
| SYS-001 | The system shall emit a luminance poll request on CAN every 5000 ms. | Unit test, integration test |
| SYS-002 | The system shall accept a luminance response frame containing a `uint16` lux value. | Unit test |
| SYS-003 | The system shall switch to `DAY` when luminance rises above 1500 lux. | Unit test, qualification test |
| SYS-004 | The system shall switch to `NIGHT` when luminance drops below 800 lux. | Unit test, qualification test |
| SYS-005 | The system shall retain the previous state while luminance remains between the two thresholds. | Unit test |
| SYS-006 | The system shall answer a CAN query with the current state and age of the current state in seconds. | Unit test, integration test |
| SYS-007 | The system shall support subscription and unsubscription over CAN and send one notification per state change to each registered client. | Unit test, integration test |
| SYS-008 | The system shall return explicit registration status codes for duplicate, full, and not-found cases. | Unit test |
| SYS-009 | The system shall enter `FAULT` state if a luminance response is not received within 6000 ms of the oldest outstanding poll request. | Unit test, integration test, qualification test |
| SYS-010 | The system shall recover from `FAULT` to `DAY` or `NIGHT` on the next valid luminance response according to threshold rules. | Unit test, integration test, qualification test |
| SYS-011 | The system shall emit a dedicated diagnostic CAN message with fault code when entering `FAULT` due to luminance response timeout and a clear message when recovering from that fault. | Unit test, integration test, qualification test |