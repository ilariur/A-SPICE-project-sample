---
name: software-integrator
description: 'Use when assembling software units and components into integrated software items aligned to Automotive SPICE 4.0. Covers integration strategy, build reproducibility, interface checks, dependency resolution, configuration integrity, and integration evidence.'
argument-hint: 'Describe the target baseline, components to integrate, and the build or platform context.'
---

# Software Integrator

## Purpose
Use this skill to combine software elements in a controlled sequence, verify that interfaces and dependencies match, and produce reproducible integrated baselines.

## Automotive SPICE Alignment
- Primary processes: SWE.5
- Supporting focus: SWE.2, SWE.3, SUP.8, SUP.10
- Intent: define how software units are integrated, execute the integration sequence, control baselines, and capture evidence that integrated items are ready for test.

## When to Use
- New baseline assembly
- Dependency or platform updates
- Multi-team merge and integration windows
- Build failures or interface compatibility problems

## Working Rules
- Integrate in a defined order based on dependencies and risk.
- Keep build inputs, tool versions, and configuration items reproducible.
- Validate interface compatibility before and after integration.
- Distinguish integration defects from unit defects and environmental issues.
- Preserve evidence for what was integrated, when, and from which versions.
- Keep the integration plan anchored to the active product baseline; do not pull assumptions or artifacts from unrelated workspace projects.

## Procedure
1. Prepare the integration strategy: sequence, entry criteria, environments, toolchain versions, and rollback plan.
2. Confirm that candidate units satisfy configuration, review, and verification prerequisites.
3. Assemble the baseline incrementally, resolving interface mismatches, dependency gaps, and build issues.
4. Run smoke checks for startup, communication, error reporting, and critical control paths after each integration step.
5. Record the integrated configuration, known limitations, and unresolved anomalies.
6. Hand over an identified baseline with release notes and evidence to software integration testing.

## Base Practice Checklist
- Define and maintain an integration strategy.
- Establish integrated baselines from controlled configuration items.
- Verify interfaces, dependencies, and build consistency during assembly.
- Record integration results, anomalies, and configuration status.
- Make the integrated item available for formal integration testing.

## Expected Outputs
- Software integration strategy
- Reproducible integrated baseline
- Build and packaging record
- Interface issue log
- Integration status report and release notes

## Evidence to Keep
- Component versions and hashes
- Toolchain and environment details
- Build logs and smoke check results
- Defect handoff to developers or testers

## Done Criteria
- The integrated baseline is reproducible, identified, and fit to enter software integration testing.