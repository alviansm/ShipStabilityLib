cmake_minimum_required(VERSION 3.16)
project(ShipStabilityLib VERSION 0.1.0 LANGUAGES CXX)

# === Global settings ===
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Option to build tests
option(BUILD_TESTS "Build unit tests" ON)

set(GENERATED_INCLUDE_DIR ${CMAKE_CURRENT_BINARY_DIR}/generated)

# === Version header generation ===
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ShipStabilityLib/Version.h.in
    ${GENERATED_INCLUDE_DIR}/Version.h
    @ONLY
)

# === Include directories ===
set(PUBLIC_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB BOOK_SOURCES src/Book/*.cpp)
file(GLOB BOOK_HEADERS include/ShipStabilityLib/Book/*.h)

# === Source files ===
set(SHIPSTABILITYLIB_SOURCES
    # Facade
    src/StabilityAPI.cpp

    # Domain
    src/Domain/Vessel.cpp    # later if you add .cpp implementation
    src/Domain/Weight.cpp    # optional if needed
    src/Domain/Section.cpp   # currently no need, it's header-only

    # Calculations
    src/Calculations/GMCalculator.cpp
    src/Calculations/FreeSurfaceEffect.cpp
    src/Calculations/GZCurveCalculator.cpp

    # IO
    src/IO/VesselJsonParser.cpp

    # Book
    ${BOOK_SOURCES}
)

set(SHIPSTABILITYLIB_HEADERS
    ${PUBLIC_HEADERS_DIR}/ShipStabilityLib/StabilityAPI.h

    ${PUBLIC_HEADERS_DIR}/ShipStabilityLib/Domain/Vessel.h
    ${PUBLIC_HEADERS_DIR}/ShipStabilityLib/Domain/Weight.h
    ${PUBLIC_HEADERS_DIR}/ShipStabilityLib/Domain/Section.h

    ${PUBLIC_HEADERS_DIR}/ShipStabilityLib/Calculations/GMCalculator.h
    ${PUBLIC_HEADERS_DIR}/ShipStabilityLib/Calculations/FreeSurfaceEffect.h
    ${PUBLIC_HEADERS_DIR}/ShipStabilityLib/Calculations/GZCurveCalculator.h

    ${PUBLIC_HEADERS_DIR}/ShipStabilityLib/IO/VesselJsonParser.h

    ${BOOK_HEADERS}
)

# === Main Library Target ===
add_library(ShipStabilityLib ${SHIPSTABILITYLIB_SOURCES} ${SHIPSTABILITYLIB_HEADERS}
    include/ShipStabilityLib/Version.h.in
    include/ShipStabilityLib/Version.h)

target_include_directories(ShipStabilityLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${GENERATED_INCLUDE_DIR}
)

# === Example program ===
add_executable(stability_example examples/minimal_usage.cpp)
target_link_libraries(stability_example PRIVATE ShipStabilityLib)

# (No need for explicit include dirs here because it inherits from the library)

# === Tests ===
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
