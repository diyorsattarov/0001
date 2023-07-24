cmake_minimum_required(VERSION 3.26)
project(collectione_tests)

find_package(Boost REQUIRED COMPONENTS 
    chrono 
    timer 
    system 
    log 
    log_setup
    thread 
    filesystem
    regex
)

include_directories(${Boost_INCLUDE_DIRS})

add_library(gtest_boost STATIC
    gtest_boost.cpp
    gtest_boost.h
)

set_target_properties(gtest_boost PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_executable(tests 
    gtest_main.cpp
)


set_target_properties(tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


target_link_libraries(tests PRIVATE gtest_main)
target_link_libraries(tests PRIVATE gtest)
target_link_libraries(tests PRIVATE ${Boost_LIBRARIES})
target_link_libraries(tests PRIVATE Boost::log_setup)  # Link Boost Log Setup library


add_test(NAME TestSuite COMMAND tests)
