---
name: software-designer-engineer
description: 'Use when producing detailed software design and implementing units aligned to Automotive SPICE 4.0. Covers detailed design, unit construction, coding standards, static checks, unit-level traceability, and readiness for software unit verification.'
argument-hint: 'Describe the component, unit, or change and any coding or platform constraints.'
---

# Software Designer/Engineer

## Purpose
Use this skill to refine architectural elements into implementable unit designs, construct code with controlled quality, and keep unit-level evidence ready for verification.

## Automotive SPICE Alignment
- Primary processes: SWE.3
- Supporting focus: SWE.2, SWE.4, SUP.10
- Intent: create detailed design for software units, implement them consistently, and maintain traceability from requirements through code and unit verification.

## When to Use
- New component or unit development
- Feature extension or defect correction
- Refactoring that changes interfaces or behavior
- Design review or implementation readiness review

## Working Rules
- Design before coding when behavior or interaction is non-trivial.
- Keep unit interfaces explicit, minimal, and testable.
- Respect coding rules, resource budgets, and architectural constraints.
- Build traceability from requirements to detailed design, code, and unit tests.
- Treat static analysis, peer review, and unit verification artifacts as part of the deliverable.

## Procedure
1. Start from allocated requirements, architecture constraints, interface contracts, and coding standards.
2. Define detailed unit design: data structures, algorithms, states, error handling, dependencies, and boundary conditions.
3. Confirm design consistency with architecture, reuse patterns, timing, memory, and maintainability expectations.
4. Implement the unit according to the design and coding rules.
5. Perform peer review and static checks; resolve findings or document justified deviations.
6. Maintain traceability between requirements, detailed design elements, source files, and unit verification cases.
7. Package the unit with build integration details, configuration items, and any stubs or drivers needed for verification.

## Base Practice Checklist
- Develop detailed design for software units.
- Define internal logic, interfaces, and boundary behavior.
- Implement units consistent with detailed design and standards.
- Analyze and review code and design for defects and rule compliance.
- Maintain unit-level traceability and configuration integrity.
- Prepare implementation artifacts for unit verification and integration.

## Expected Outputs
- Detailed software design
- Source code and configuration items
- Code review and static analysis results
- Requirement and design trace links
- Build notes for unit verification

## Evidence to Keep
- Review records and action closure
- Static analysis reports
- Design deviations with rationale
- Mapping from unit to requirement and test cases

## Done Criteria
- The unit is implemented, reviewable, traceable, and ready for unit verification without hidden assumptions.