---
Revision: 1.1
Date: 2026-03-26
Author: Project Manager
Status: Approved
---

# Configuration Management Plan

## Configuration Items
- Source files under `src/` and `tests/`
- `build.ninja`
- All markdown documents under `docs/`
- `README.md`
- `product.md`

## Baselines
- Requirements baseline
- Architecture baseline
- Code and detailed design baseline
- Integrated test baseline

## Identification
- Version tag format: `major.minor.patch-stage`
- Current baseline: `0.1.0-draft`
- Git tag type: Annotated tags with message describing contents and purpose
- Tag naming convention: 
  - `v{major}.{minor}.{patch}-{stage}`
  - Example: `v0.1.0-draft` (0.1.0 release, draft maturity)
  - Stages: `draft` (development), `rc` (release candidate), `release` (production)

## Tagging Policy
- **When to Tag:** After baseline assessment completion and management sign-off of release readiness.
- **Tag Scope:** Marks all configuration items (source, build, documentation) at a specific commitment and approval point.
- **Tag Recipient:** Baseline commits remain unmodified; tags are annotations applied post-hoc.
- **Release Gate Criteria:**
  - All P0-Critical corrective actions closed
  - All P1-Major corrective actions closed
  - No open defects blocking release-level quality gate
  - Risk register reviewed and accepted for residual risk
  - Full traceability matrix reconciled
- **Baseline Tag v0.1.0-draft:**
  - Commit: `44a7d7ccd265a98fc03ec37c7fcb35a79345bacc`
  - Contents: SWE-001 through SWE-011 implemented; unit tests (SWE.4) verified; integration tests (SWE.5); qualification tests (SWE.6); all risk ratings and problem resolutions documented
  - Assessment Date: 2026-03-23
  - Corrective Action Phase: M6 completed 2026-03-25; all P0 and P1 CRs closed (CR-001 through CR-010)
  - Quality Gates Passed: 14 unit tests passed, 12 integration tests passed, 11 qualification tests passed; all documented evidence captured
  - Status: **Pre-Release Draft** — audit-ready; prepared for extended vehicle integration testing; P1 baseline stable for external review

## Change Control
- Record changes to requirements, architecture, code, and tests in the same baseline review.
- Update the traceability matrix when any requirement or verification artifact changes.