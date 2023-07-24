cmake_minimum_required(VERSION 3.26)
project(collectione_tests)

# Find the libcurl package (Recommended)
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

add_library(gtest_boost STATIC
    gtest_boost.cpp
    gtest_boost.h
)

set_target_properties(gtest_boost PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add the test executable
add_executable(tests 
    gtest_main.cpp
)

# Set the output directory for the 'tests' executable
set_target_properties(tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Link the test executable with Google Test library and your main project library (if any)
target_link_libraries(tests PRIVATE gtest_main)  # Assuming your main project is built into 'main' target
target_link_libraries(tests PRIVATE gtest)

# Optionally link with CURL library if specified
#option(BUILD_WITH_CURL "Build with libcurl" ON)
#if (BUILD_WITH_CURL)
#    target_link_libraries(tests PRIVATE ${CURL_LIBRARIES})
#endif()

# Register the test executable with CTest
add_test(NAME TestSuite COMMAND tests)
