cmake_minimum_required(VERSION 3.20)

project(tests)

include_directories(${include_path})

set(EXECUTABLE_OUTPUT_PATH ${bin_path})
aux_source_directory(./ src)
add_executable(exe_sorts ${src})