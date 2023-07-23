# Add all the source files in the 'src' directory to the 'main' executable
add_executable(main main.cpp)

# Set the output directory for the 'main' executable
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)