cmake_minimum_required(VERSION 3.26)
project(collectione)

add_subdirectory(src)

add_subdirectory(tests)

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/extern/googletest/.git)
    message(STATUS "Google Test submodule not found. Cloning...")
    execute_process(
        COMMAND git clone https://github.com/google/googletest.git extern/googletest
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif()

add_subdirectory(src/extern/googletest)

enable_testing()

function(create_directories)
    file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)
endfunction()

create_directories()

add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/build
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/cmake_install.cmake
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/.ninja_deps
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/.ninja_log
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/build.ninja_deps
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CTestTestfile
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/bin
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/lib
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles
    COMMENT "Cleaning build artifacts"
)