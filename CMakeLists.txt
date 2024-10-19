# 使用cmake最低版本
cmake_minimum_required(VERSION 3.20)
# 项目名字
project(data_structure)
# 使用什么c++标准
set(CMAKE_CXX_STANDARD 14)
# 是否输出结合clangd的编译文件
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# 可执行文件路径
set(bin_path ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 头文件路径
set(include_path ${CMAKE_CURRENT_SOURCE_DIR}/include
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/avl
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/bin_tree
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/bitmap
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/bst
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/dictionary
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/entry
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/graph
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/hash_table
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/huffman
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/pq
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/list
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/prime
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/queue
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/share
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/sorts
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/stack
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/string_pm
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/tests
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/union_print
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/vector
)

set(lib_path ${CMAKE_CURRENT_SOURCE_DIR}/lib)

set(bitmap_lib bitmap)
set(huffman_lib huffman)
set(prime_lib prime)
set(string_pm_lib string_pm)

add_subdirectory(src)
add_subdirectory(tests)