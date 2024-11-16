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
include src/prime/CMakeFiles/prime.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/prime/CMakeFiles/prime.dir/compiler_depend.make

# Include the progress variables for this target.
include src/prime/CMakeFiles/prime.dir/progress.make

# Include the compile flags for this target's objects.
include src/prime/CMakeFiles/prime.dir/flags.make

src/prime/CMakeFiles/prime.dir/eratosthenes.cpp.o: src/prime/CMakeFiles/prime.dir/flags.make
src/prime/CMakeFiles/prime.dir/eratosthenes.cpp.o: ../src/prime/eratosthenes.cpp
src/prime/CMakeFiles/prime.dir/eratosthenes.cpp.o: src/prime/CMakeFiles/prime.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zzy0/workspace_vscode/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/prime/CMakeFiles/prime.dir/eratosthenes.cpp.o"
	cd /home/zzy0/workspace_vscode/data_structure/build/src/prime && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/prime/CMakeFiles/prime.dir/eratosthenes.cpp.o -MF CMakeFiles/prime.dir/eratosthenes.cpp.o.d -o CMakeFiles/prime.dir/eratosthenes.cpp.o -c /home/zzy0/workspace_vscode/data_structure/src/prime/eratosthenes.cpp

src/prime/CMakeFiles/prime.dir/eratosthenes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prime.dir/eratosthenes.cpp.i"
	cd /home/zzy0/workspace_vscode/data_structure/build/src/prime && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zzy0/workspace_vscode/data_structure/src/prime/eratosthenes.cpp > CMakeFiles/prime.dir/eratosthenes.cpp.i

src/prime/CMakeFiles/prime.dir/eratosthenes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prime.dir/eratosthenes.cpp.s"
	cd /home/zzy0/workspace_vscode/data_structure/build/src/prime && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zzy0/workspace_vscode/data_structure/src/prime/eratosthenes.cpp -o CMakeFiles/prime.dir/eratosthenes.cpp.s

src/prime/CMakeFiles/prime.dir/prime_nlt.cpp.o: src/prime/CMakeFiles/prime.dir/flags.make
src/prime/CMakeFiles/prime.dir/prime_nlt.cpp.o: ../src/prime/prime_nlt.cpp
src/prime/CMakeFiles/prime.dir/prime_nlt.cpp.o: src/prime/CMakeFiles/prime.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zzy0/workspace_vscode/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/prime/CMakeFiles/prime.dir/prime_nlt.cpp.o"
	cd /home/zzy0/workspace_vscode/data_structure/build/src/prime && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/prime/CMakeFiles/prime.dir/prime_nlt.cpp.o -MF CMakeFiles/prime.dir/prime_nlt.cpp.o.d -o CMakeFiles/prime.dir/prime_nlt.cpp.o -c /home/zzy0/workspace_vscode/data_structure/src/prime/prime_nlt.cpp

src/prime/CMakeFiles/prime.dir/prime_nlt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prime.dir/prime_nlt.cpp.i"
	cd /home/zzy0/workspace_vscode/data_structure/build/src/prime && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zzy0/workspace_vscode/data_structure/src/prime/prime_nlt.cpp > CMakeFiles/prime.dir/prime_nlt.cpp.i

src/prime/CMakeFiles/prime.dir/prime_nlt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prime.dir/prime_nlt.cpp.s"
	cd /home/zzy0/workspace_vscode/data_structure/build/src/prime && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zzy0/workspace_vscode/data_structure/src/prime/prime_nlt.cpp -o CMakeFiles/prime.dir/prime_nlt.cpp.s

# Object files for target prime
prime_OBJECTS = \
"CMakeFiles/prime.dir/eratosthenes.cpp.o" \
"CMakeFiles/prime.dir/prime_nlt.cpp.o"

# External object files for target prime
prime_EXTERNAL_OBJECTS =

../lib/libprime.a: src/prime/CMakeFiles/prime.dir/eratosthenes.cpp.o
../lib/libprime.a: src/prime/CMakeFiles/prime.dir/prime_nlt.cpp.o
../lib/libprime.a: src/prime/CMakeFiles/prime.dir/build.make
../lib/libprime.a: src/prime/CMakeFiles/prime.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zzy0/workspace_vscode/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library ../../../lib/libprime.a"
	cd /home/zzy0/workspace_vscode/data_structure/build/src/prime && $(CMAKE_COMMAND) -P CMakeFiles/prime.dir/cmake_clean_target.cmake
	cd /home/zzy0/workspace_vscode/data_structure/build/src/prime && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prime.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/prime/CMakeFiles/prime.dir/build: ../lib/libprime.a
.PHONY : src/prime/CMakeFiles/prime.dir/build

src/prime/CMakeFiles/prime.dir/clean:
	cd /home/zzy0/workspace_vscode/data_structure/build/src/prime && $(CMAKE_COMMAND) -P CMakeFiles/prime.dir/cmake_clean.cmake
.PHONY : src/prime/CMakeFiles/prime.dir/clean

src/prime/CMakeFiles/prime.dir/depend:
	cd /home/zzy0/workspace_vscode/data_structure/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zzy0/workspace_vscode/data_structure /home/zzy0/workspace_vscode/data_structure/src/prime /home/zzy0/workspace_vscode/data_structure/build /home/zzy0/workspace_vscode/data_structure/build/src/prime /home/zzy0/workspace_vscode/data_structure/build/src/prime/CMakeFiles/prime.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/prime/CMakeFiles/prime.dir/depend

