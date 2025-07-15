# ShipStabilityLib

## What is ShipStabilityLib?

**ShipStabilityLib** is a modern C++ library for hydrostatics and basic ship stability calculations, inspired by *Ship Stability for Masters and Mates*.  
It provides:

**Work in Progress**  
![Progress](https://img.shields.io/badge/Progress-5%20-yellowgreen)
This library is in early development. Features and API may change.
See [ROADMAP.md](ROADMAP.md) for full development plans.

- Core hydrostatic and stability calculations (GM, KG, KM, GZ curves, free surface effect, etc.)
- Clear domain models for vessels, tanks, weights, and hydrostatic tables
- Chapter-based calculation modules aligned with the book
- A clean API (`StabilityAPI`) for easy integration into CLI, GUI, or simulation applications
- Unit-testable, stateless calculation classes for reliable engineering computations

The library is designed to be **lightweight, extensible, and test-friendly**.  
In the future, it may also expand to cover **hydrodynamics** (added resistance, roll damping, wave response).

---

## Prerequisites

To build and use **ShipStabilityLib**, you’ll need:

- **CMake ≥ 3.16**  
  Used as the build system.
- **C++17 or later**  
  Modern C++ standard for cleaner and safer code.
- **A C++ compiler**  
  - Linux: `g++` or `clang++`
  - Windows: MSVC (Visual Studio 2019/2022)
  - macOS: AppleClang
- *(Optional)* **GoogleTest**  
  Automatically fetched by CMake if `BUILD_TESTS=ON`.

You may also later add:
- **Eigen** (for advanced math, optional in the first version)

---

## Project Structure
=================

ShipStabilityLib/
  CMakeLists.txt         -> Top-level build configuration for the entire project

  include/               -> Public headers (the exposed API of the library)
    ShipStabilityLib/
      StabilityAPI.h     -> Facade for external usage
      Domain/            -> Core data models (Vessel, Tank, Weight, etc.)
      Calculations/      -> Calculation modules (GM, GZ curve, free surface effect)
      IO/                -> Parsers & serializers for vessel data

  src/                   -> Private implementation of the library
    Domain/              -> Implementation of domain models
    Calculations/        -> Core calculation logic
    IO/                  -> File handling (e.g., JSON parsing)
    StabilityAPI.cpp     -> Facade implementation

  tests/                 -> Unit tests for each module
    CMakeLists.txt       -> Separate test build configuration
    test_main.cpp        -> Test entrypoint
    test_GMCalculator.cpp
    test_FreeSurface.cpp

  examples/              -> Minimal example programs demonstrating usage
    minimal_usage.cpp

  third_party/           -> External dependencies (e.g., GoogleTest)


## Directory Breakdown
-------------------

include/
  Contains all public headers that external projects can include.
  Organized into subfolders for clarity:
    - Domain/ -> Core data models like Vessel, Tank, Weight, etc.
    - Calculations/ -> Stateless calculators (GM, GZ curve, free surface effect, etc.)
    - IO/ -> Parsers and serializers for vessel data (JSON, CSV).
    - StabilityAPI.h -> A simple facade for users who want quick access to the main functions.

src/
  Contains the implementation files (.cpp) for everything declared in include/.
  Mirrors the same structure (Domain, Calculations, IO), keeping things organized and modular.
  StabilityAPI.cpp implements the high-level facade.

tests/
  Contains unit tests for each calculation module.
  Uses GoogleTest (automatically fetched by CMake).
  test_main.cpp is the entrypoint for running all tests.
  Example tests like test_GMCalculator.cpp verify GM calculations with known reference cases.

examples/
  Contains simple CLI examples that show how to use the library in external projects.
  minimal_usage.cpp is a quick demo for building and running basic stability calculations.

third_party/
  Holds external dependencies that are either downloaded by CMake (e.g., GoogleTest) or manually added later.
  Keeps the main codebase clean from vendor code.

CMakeLists.txt
  The main build configuration that ties everything together.
  Builds the core library, the examples, and optionally the tests.

Getting Started for Contributors
================================

This project is a C++17 library for ship stability and hydrostatic calculations.
It uses CMake as the build system and GoogleTest (vendored) for unit testing.

Requirements
------------
- CMake 3.16 or later
- A C++17 compiler (MSVC 2019/2022, g++, or clang++)
- Qt Creator or any IDE that supports CMake (optional)

Directory Overview
------------------
- include/ShipStabilityLib/   -> Public headers (API)
- src/                       -> Private implementations
- tests/                     -> Unit tests
- tests/Book/                -> Tests per chapter from the book
- third_party/googletest/    -> Vendored GoogleTest for offline builds
- examples/                  -> Minimal example programs

How to Build
------------
1. Create a build directory:
   mkdir build && cd build

2. Configure CMake:
   cmake .. -DBUILD_TESTS=ON

3. Build the library, example, and tests:
   cmake --build . -j4

4. Run the example:
   ./stability_example

Running Tests
-------------
After building with BUILD_TESTS=ON, run all tests with:

   ctest --output-on-failure

You can also run the test binary directly:
   ./tests/ShipStabilityLibTests

Adding a New Chapter (Book-based Learning)
------------------------------------------
1. Create a new header and cpp under:
   include/ShipStabilityLib/Book/
   src/Book/

2. Write test cases under:
   tests/Book/

3. Rebuild and run tests to validate.

Coding Style
------------
- Use C++17 features (e.g., auto, structured bindings)
- Keep headers Doxygen-ready
- Keep calculations stateless and testable
- Namespace:
  - Core library: Stability::
  - Book chapters: Stability::Book::ChapterXX

Line Endings and Git
--------------------
- This repo enforces LF line endings via .gitattributes
- .gitignore ignores build/ and IDE-specific files
