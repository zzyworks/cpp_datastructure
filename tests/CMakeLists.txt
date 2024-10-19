cmake_minimum_required(VERSION 3.20)

project(tests)

include_directories(${include_path})

link_directories(${lib_path})
link_libraries(${bitmap_lib})
link_libraries(${huffman_lib})
link_libraries(${prime_lib})
link_libraries(${string_pm_lib})

set(EXECUTABLE_OUTPUT_PATH ${bin_path})
aux_source_directory(./ src)
add_executable(exe_string_pm ${src})