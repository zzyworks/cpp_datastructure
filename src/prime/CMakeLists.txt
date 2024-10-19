cmake_minimum_required(VERSION 3.20)

project(prime)

aux_source_directory(./ srcs)

include_directories(${include_path})

link_libraries(${bitmap_lib})

set(LIBRARY_OUTPUT_PATH ${lib_path})

add_library(${prime_lib} STATIC ${srcs}) 