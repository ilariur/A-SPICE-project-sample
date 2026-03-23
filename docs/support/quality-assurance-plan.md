# Quality Assurance Plan

## Objectives
- Ensure each work product is reviewable, traceable, and consistent.
- Ensure implementation and verification are aligned to requirements and architecture.

## Coding Standard
- **Primary:** ISO/IEC 9899:2018 (C99) with C++20 extensions per ISO/IEC 14882:2020 (C++20)
- **Project conventions:**
  - No exceptions on critical path; exceptions only in harness code marked with `// Exception: <rationale>`
  - No dynamic allocation (all stacks and fixed arrays per `std::array`)
  - Function naming: `camelCase`, class naming: `PascalCase`, macro naming: `UPPER_SNAKE`
  - Max line length: 120 columns
  - Braces: Allman style (opening brace on new line for functions, K&R for control flow)
- **Tool:** `clang-format` with `.clang-format` config file (project-local standard applied at build time)

## Planned Quality Activities
- Review requirements for clarity and verifiability.
- Review architecture for scope consistency and interface completeness.
- Review detailed design and code for requirement alignment.
- Review tests for coverage of nominal, boundary, and error behavior.
- Review traceability before qualification conclusion.

## Evidence
- Review comments and resolutions
- Test results
- Traceability matrix
- Problem resolution log