cmake_minimum_required(VERSION 3.26)
project(collectione_tests)

# Create the 'bin' directory inside the build directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add the test executable
add_executable(tests 
    gtest_main.cpp
    gtest_mytempclass.cpp)

# Set the output directory for the 'tests' executable
set_target_properties(tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Link the test executable with Google Test library and your main project library (if any)
target_link_libraries(tests PRIVATE gtest_main)  # Assuming your main project is built into 'main' target

# Register the test executable with CTest
add_test(NAME TestSuite COMMAND tests)
