# Agent Project Instructions: C Tool Box (ctb)

This document provides foundational mandates and context for working on the `c-tool-box` project.

## Project Overview

**C Tool Box (ctb)** is a lightweight C utility library providing common data structures and macros. The project emphasizes strict code quality, comprehensive testing, and clear documentation.

- **Main Technologies:** C (C99/C11), Ceedling (build and test framework), Unity/CMock (unit testing), Doxygen (documentation).
- **Architecture:** The library is designed with a modular, object-oriented approach. Each component (e.g., SList, DList, Queue, Stack) has its own header and source file, using a `self` pointer pattern for operations on data structure instances.

## Building and Running

The project uses **Ceedling** for build management.

- **Build Release:** `ceedling release` (outputs `ctb.a` in `build/release`).
- **Clean:** `ceedling clean`.
- **Generate Documentation:** Run Doxygen with the `docs/Doxyfile` configuration.

## Testing

Testing is a core part of the development lifecycle.

- **Run All Tests:** `ceedling test:all`.
- **Run Specific Test:** `ceedling test:<test_file_name>` (e.g., `ceedling test:ctb_SList`).
- **Code Coverage:** `ceedling gcov:all` (reports generated in `build/artifacts/gcov`).
- **Static Analysis:**
    - `python3 scripts/run-cppcheck.py`: Runs Cppcheck for static analysis.
    - `python3 scripts/run-lizard.py`: Runs Lizard for cyclomatic complexity analysis.

## Development Conventions

### Naming & Style

- **Prefix:** All public symbols must be prefixed with `ctb_`.
- **Types:** Typedefs follow the pattern `ctb_<Component>_t` (e.g., `ctb_SList_t`).
- **Functions:** Named as `ctb_<Component>_<Action>` (e.g., `ctb_SList_addFirst`).
- **Methods:** Implementation follows an OO-like pattern where the first argument is a pointer to the instance, named `self`.
- **Formatting:** Adhere to the `.clang-format` configuration (based on LLVM with specific alignments). Use 4 spaces for indentation, never tabs.
- **Strictness:** The project uses strict compiler flags (`-Wall -Wextra -Werror -Wpedantic`). Ensure no warnings are introduced.

### Documentation

- **Doxygen:** Use Doxygen-style comments for all public headers. Include `@file`, `@brief`, `@param`, and `@return` tags as appropriate.
- **Readme:** Updates to the main documentation should be reflected in `README.md`.

## Project Structure

- `src/`: Core library source files (`.c`) and public headers (`.h`).
- `test/`: Unit tests using the Unity framework. Files are prefixed with `test_`.
- `docs/`: Doxygen configuration and generated documentation (if built).
- `scripts/`: Python utility scripts for changelog generation and analysis.
- `project.yml`: Ceedling configuration file.
