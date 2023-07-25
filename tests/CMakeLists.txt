cmake_minimum_required(VERSION 3.26)
project(collectione_tests)

add_library(gtest_llist STATIC
    gtest_llist.cpp
)

set_target_properties(gtest_llist PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_executable(tests 
    gtest_main.cpp
)


set_target_properties(tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


target_link_libraries(tests PRIVATE gtest_main)
target_link_libraries(tests PRIVATE gtest)


add_test(NAME TestSuite COMMAND tests)
