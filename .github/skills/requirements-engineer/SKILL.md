---
name: requirements-engineer
description: 'Use when performing stakeholder, system, and software requirements engineering aligned to Automotive SPICE 4.0. Covers elicitation, analysis, quality checks, traceability, acceptance criteria, interfaces, change impact, and requirement baseline preparation.'
argument-hint: 'Describe the feature, item, or change request and the level to refine: stakeholder, system, or software.'
---

# Requirements Engineer

## Purpose
Use this skill to turn needs and constraints into clear, testable, consistent requirements and maintain bidirectional traceability across the engineering chain.

## Automotive SPICE Alignment
- Primary processes: SYS.1, SYS.2, SWE.1
- Supporting focus: SUP.10, SUP.8, MAN.5
- Intent: capture needs, analyze them into technical requirements, define acceptance criteria, and control requirement changes and trace links.

## When to Use
- New feature definition
- Requirement decomposition from stakeholder to system to software level
- Requirement clarification during design, implementation, or testing
- Change request impact analysis
- Release or audit preparation for requirement quality and traceability

## Working Rules
- Write one requirement per statement when practical.
- Prefer measurable language over intent-only wording.
- State source, rationale, assumptions, constraints, and verification method.
- Keep interfaces, timing, operating modes, diagnostics, safety, and failure handling explicit.
- Maintain bidirectional traceability between source, derived requirements, architecture, implementation, and tests.

## Procedure
1. Collect inputs: stakeholder requests, regulations, interface definitions, platform constraints, safety or cybersecurity assumptions, and change requests.
2. Classify each statement as stakeholder, system, or software requirement; separate true requirements from design decisions and notes.
3. Refine requirements into atomic statements with unique identifiers, acceptance criteria, units, tolerances, and preconditions.
4. Check quality: completeness, consistency, feasibility, verifiability, unambiguity, and conflict-free behavior across modes and interfaces.
5. Derive dependent requirements for error handling, startup and shutdown, degraded behavior, calibration, logging, and diagnostics.
6. Link every requirement to its source and to downstream design elements and verification artifacts.
7. Evaluate changes for scope, impact, risk, open issues, and rework across architecture, code, integration, and tests.
8. Baseline the reviewed requirement set and record unresolved issues, assumptions, and rationale.

## Base Practice Checklist
- Elicit and agree relevant needs, constraints, and external interfaces.
- Transform inputs into analyzed technical requirements at the correct abstraction level.
- Define criteria that make each requirement verifiable.
- Analyze consistency, feasibility, conflicts, and omissions.
- Identify derived requirements introduced by technical decisions.
- Maintain traceability to predecessors and successors.
- Communicate requirement changes and keep baselines under configuration control.

## Expected Outputs
- Stakeholder, system, or software requirement specification
- Requirement quality review log
- Traceability matrix
- Derived requirement list
- Change impact assessment
- Requirement baseline and approval record

## Evidence to Keep
- Source references and rationale
- Review comments and dispositions
- Trace links to architecture, code, and tests
- Open issue list and deviation decisions

## Done Criteria
- Requirements are uniquely identified, testable, and internally consistent.
- Traceability is complete in both directions for the scoped item.
- A reviewer can determine what will verify each requirement and where change impact lands.