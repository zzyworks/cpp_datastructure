cmake_minimum_required(VERSION 3.20)

project(bitmap)

aux_source_directory(./ srcs)

include_directories(${include_path})

set(LIBRARY_OUTPUT_PATH ${lib_path})

add_library(${bitmap_lib} STATIC ${srcs}) 