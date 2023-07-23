cmake_minimum_required(VERSION 3.26)
project(collectione)

# Add the 'src' subdirectory
add_subdirectory(src)

# Check if 'extern/googletest' subdirectory exists
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/extern/googletest/.git)
    message(STATUS "Google Test submodule not found. Cloning...")
    execute_process(
        COMMAND git clone https://github.com/google/googletest.git extern/googletest
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif()

# Add the 'extern/googletest' subdirectory
add_subdirectory(extern/googletest)

# Enable CTest (optional but recommended for running tests)
enable_testing()

# Link the 'main' executable with Google Test library
target_link_libraries(main gtest_main)

# Custom function to create directories (if you added it)
function(create_directories)
    file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)
    # Add more directories as required
endfunction()

# Call the custom function to create directories (if you added it)
create_directories()

# Add a custom 'clean' target (as shown in the previous responses)
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/build
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/bin
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/lib
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/cmake_install.cmake
    COMMENT "Cleaning build artifacts"
)

# Add your tests (assuming 'tests' is a subdirectory in your project)
#add_subdirectory(tests)

# ... (rest of your configuration) ...
