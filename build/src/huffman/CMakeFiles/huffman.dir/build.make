# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zzy0/workspace_vscode/data_structure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zzy0/workspace_vscode/data_structure/build

# Include any dependencies generated for this target.
include src/huffman/CMakeFiles/huffman.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/huffman/CMakeFiles/huffman.dir/compiler_depend.make

# Include the progress variables for this target.
include src/huffman/CMakeFiles/huffman.dir/progress.make

# Include the compile flags for this target's objects.
include src/huffman/CMakeFiles/huffman.dir/flags.make

src/huffman/CMakeFiles/huffman.dir/buff_char.cpp.o: src/huffman/CMakeFiles/huffman.dir/flags.make
src/huffman/CMakeFiles/huffman.dir/buff_char.cpp.o: ../src/huffman/buff_char.cpp
src/huffman/CMakeFiles/huffman.dir/buff_char.cpp.o: src/huffman/CMakeFiles/huffman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zzy0/workspace_vscode/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/huffman/CMakeFiles/huffman.dir/buff_char.cpp.o"
	cd /home/zzy0/workspace_vscode/data_structure/build/src/huffman && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/huffman/CMakeFiles/huffman.dir/buff_char.cpp.o -MF CMakeFiles/huffman.dir/buff_char.cpp.o.d -o CMakeFiles/huffman.dir/buff_char.cpp.o -c /home/zzy0/workspace_vscode/data_structure/src/huffman/buff_char.cpp

src/huffman/CMakeFiles/huffman.dir/buff_char.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman.dir/buff_char.cpp.i"
	cd /home/zzy0/workspace_vscode/data_structure/build/src/huffman && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zzy0/workspace_vscode/data_structure/src/huffman/buff_char.cpp > CMakeFiles/huffman.dir/buff_char.cpp.i

src/huffman/CMakeFiles/huffman.dir/buff_char.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman.dir/buff_char.cpp.s"
	cd /home/zzy0/workspace_vscode/data_structure/build/src/huffman && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zzy0/workspace_vscode/data_structure/src/huffman/buff_char.cpp -o CMakeFiles/huffman.dir/buff_char.cpp.s

# Object files for target huffman
huffman_OBJECTS = \
"CMakeFiles/huffman.dir/buff_char.cpp.o"

# External object files for target huffman
huffman_EXTERNAL_OBJECTS =

../lib/libhuffman.a: src/huffman/CMakeFiles/huffman.dir/buff_char.cpp.o
../lib/libhuffman.a: src/huffman/CMakeFiles/huffman.dir/build.make
../lib/libhuffman.a: src/huffman/CMakeFiles/huffman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zzy0/workspace_vscode/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libhuffman.a"
	cd /home/zzy0/workspace_vscode/data_structure/build/src/huffman && $(CMAKE_COMMAND) -P CMakeFiles/huffman.dir/cmake_clean_target.cmake
	cd /home/zzy0/workspace_vscode/data_structure/build/src/huffman && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/huffman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/huffman/CMakeFiles/huffman.dir/build: ../lib/libhuffman.a
.PHONY : src/huffman/CMakeFiles/huffman.dir/build

src/huffman/CMakeFiles/huffman.dir/clean:
	cd /home/zzy0/workspace_vscode/data_structure/build/src/huffman && $(CMAKE_COMMAND) -P CMakeFiles/huffman.dir/cmake_clean.cmake
.PHONY : src/huffman/CMakeFiles/huffman.dir/clean

src/huffman/CMakeFiles/huffman.dir/depend:
	cd /home/zzy0/workspace_vscode/data_structure/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zzy0/workspace_vscode/data_structure /home/zzy0/workspace_vscode/data_structure/src/huffman /home/zzy0/workspace_vscode/data_structure/build /home/zzy0/workspace_vscode/data_structure/build/src/huffman /home/zzy0/workspace_vscode/data_structure/build/src/huffman/CMakeFiles/huffman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/huffman/CMakeFiles/huffman.dir/depend

