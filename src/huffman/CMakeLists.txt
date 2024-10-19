cmake_minimum_required(VERSION 3.20)

project(huffman)

aux_source_directory(./ srcs)

include_directories(${include_path})

set(LIBRARY_OUTPUT_PATH ${lib_path})

add_library(${huffman_lib} STATIC ${srcs}) 