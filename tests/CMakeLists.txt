# Add vendored GoogleTest from third_party
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../third_party/googletest googletest-build)

file(GLOB BOOK_SOURCES Book/*.cpp)

# Test executable
add_executable(ShipStabilityLibTests
    test_main.cpp
    test_GMCalculator.cpp

    # Book
    ${BOOK_SOURCES}
)

target_link_libraries(ShipStabilityLibTests
    PRIVATE
    ShipStabilityLib
    gtest_main
)

target_include_directories(ShipStabilityLibTests PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/generated
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(GoogleTest)
gtest_discover_tests(ShipStabilityLibTests)
