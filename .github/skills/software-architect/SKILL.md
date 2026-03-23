---
name: software-architect
description: 'Use when defining or evolving a software architecture aligned to Automotive SPICE 4.0. Covers software architectural design, interfaces, component allocation, quality attributes, technical constraints, derived requirements, and architecture verification readiness.'
argument-hint: 'Describe the system context, software item, and the architectural concern to address.'
---

# Software Architect

## Purpose
Use this skill to produce a coherent software architecture that satisfies requirements, supports integration, and makes quality and constraint decisions explicit.

## Automotive SPICE Alignment
- Primary processes: SWE.2
- Supporting focus: SWE.1, SWE.5, SUP.10
- Intent: define software elements, interfaces, dynamic behavior, resource constraints, and allocation decisions needed for construction and verification.

## When to Use
- New software item architecture
- Architectural refactoring or platform migration
- Interface definition across components or ECUs
- Non-functional tradeoff work for performance, safety, diagnostics, timing, memory, and maintainability
- Preparation for integration and qualification testing

## Working Rules
- Keep architecture decisions traceable to requirements and constraints.
- Distinguish logical design, runtime behavior, and deployment concerns.
- Define interfaces precisely: data, control, timing, ownership, error behavior, and version compatibility.
- Record rationale for tradeoffs and rejected alternatives.
- Expose assumptions that affect integration, testability, and operability.
- Stay within the stated product scope and do not invent extra features, domains, states, safety levels, or interfaces that were not requested.

## Procedure
1. Review allocated software requirements, constraints, operating modes, and external interfaces.
2. Partition the software into elements with clear responsibilities, dependencies, and interface contracts.
3. Allocate requirements to architectural elements and identify derived requirements introduced by the design.
4. Define static structure, dynamic behavior, sequencing, state behavior, resource budgets, and fault handling paths.
5. Analyze the architecture for cohesion, coupling, feasibility, testability, safety-related constraints, and integration risk.
6. Verify consistency between architecture, interfaces, and requirement traceability.
7. Prepare downstream guidance for designers, integrators, and testers, including interface expectations and quality attribute budgets.
8. Baseline the architecture and record assumptions, open issues, and change impact rules.

## Base Practice Checklist
- Develop a software architecture from allocated requirements.
- Define software elements and their interfaces.
- Allocate requirements and constraints to software elements.
- Describe dynamic behavior, control flow, and interaction patterns as needed.
- Analyze the architecture against functional and non-functional objectives.
- Maintain architecture traceability and consistency with requirements.

## Expected Outputs
- Software architecture description
- Interface specification
- Requirement-to-architecture allocation
- Derived requirement list
- Architecture review record
- Technical decision log

## Evidence to Keep
- Diagrams and interface tables
- Resource and timing budgets
- Tradeoff decisions and rejected options
- Architecture review findings and closures

## Done Criteria
- Software elements and interfaces are sufficiently defined for detailed design and integration.
- Architectural choices are traceable, reviewable, and testable.