---
Revision: 1.1
Date: 2026-03-27
Author: Requirements Engineer
Status: Approved
---

# Stakeholder Requirements

| ID | Requirement | Acceptance Criteria |
|---|---|---|
| SH-001 | The product shall provide a `DAY` or `NIGHT` state derived from luminance available on the vehicle CAN network. | State output is available after first valid luminance response. |
| SH-002 | The product shall update the luminance input by polling every 5 seconds. | Poll request is emitted every 5000 ms. |
| SH-003 | Other software shall be able to query the current state over CAN at any time. | Query response contains current state and state age. |
| SH-004 | Other software shall be able to register for state-change notifications over CAN. | Registration request is acknowledged and state-change notifications are sent to registered clients. |
| SH-005 | The product shall behave deterministically on a bounded-memory embedded target. | Registry size is bounded and dynamic memory is avoided in the control path. |
| SH-006 | The product shall expose a timeout fault status when luminance responses are missing for too long and recover automatically when valid luminance data resumes. | Query or notification reports `FAULT` within the configured timeout window and later returns `DAY` or `NIGHT` after a valid response. |