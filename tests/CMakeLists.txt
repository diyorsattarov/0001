cmake_minimum_required(VERSION 3.26)
project(collectione_tests)

set(MOCK_SOURCES STATIC
    gmock_foo.cpp
    gmock_performance.cpp
)

# Add the gtest library
add_library(gmock_sources STATIC
    ${MOCK_SOURCES}
)

set_target_properties(gmock_sources PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_executable(tests 
    gtest_main.cpp
)


set_target_properties(tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


target_link_libraries(tests PRIVATE gtest_main)
target_link_libraries(tests PRIVATE gtest)
target_link_libraries(tests PRIVATE gmock)



add_test(NAME TestSuite COMMAND tests)
