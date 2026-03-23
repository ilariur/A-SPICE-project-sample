# Project Governance: Role Execution Order

For every change to this product — feature, bug fix, refactor, documentation update, or configuration change — execute the following roles **in order** before the change is considered complete:

1. **project-manager** — update scope, schedule, risks, and measurements.
2. **requirements-engineer** — assess change impact on stakeholder, system, and software requirements; update baselines and traceability.
3. **software-architect** — assess impact on software architecture and interfaces; update architecture documents if affected.
4. **software-designer-engineer** — update detailed design and implement the change in code; apply coding standards and static checks.
5. **software-integrator** — perform a clean integration build from the updated baseline; produce reproducible build and smoke-check evidence.
6. **software-integration-tester** — execute integration test scenarios covering affected interfaces; record pass/fail evidence.
7. **software-qualification-tester** — execute qualification scenarios against updated software requirements; record pass/fail evidence and release readiness.

Each role has a corresponding skill in `.github/skills/<role>/SKILL.md`. Load and follow the relevant skill file when executing each role.

Do not skip roles. If a role produces no changes (e.g., the architecture is unaffected), record that finding explicitly as evidence that the role was executed and the area was assessed.
