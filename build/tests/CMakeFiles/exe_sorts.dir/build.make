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
include tests/CMakeFiles/exe_sorts.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/exe_sorts.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/exe_sorts.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/exe_sorts.dir/flags.make

tests/CMakeFiles/exe_sorts.dir/main.cpp.o: tests/CMakeFiles/exe_sorts.dir/flags.make
tests/CMakeFiles/exe_sorts.dir/main.cpp.o: ../tests/main.cpp
tests/CMakeFiles/exe_sorts.dir/main.cpp.o: tests/CMakeFiles/exe_sorts.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zzy0/workspace_vscode/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/exe_sorts.dir/main.cpp.o"
	cd /home/zzy0/workspace_vscode/data_structure/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/exe_sorts.dir/main.cpp.o -MF CMakeFiles/exe_sorts.dir/main.cpp.o.d -o CMakeFiles/exe_sorts.dir/main.cpp.o -c /home/zzy0/workspace_vscode/data_structure/tests/main.cpp

tests/CMakeFiles/exe_sorts.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exe_sorts.dir/main.cpp.i"
	cd /home/zzy0/workspace_vscode/data_structure/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zzy0/workspace_vscode/data_structure/tests/main.cpp > CMakeFiles/exe_sorts.dir/main.cpp.i

tests/CMakeFiles/exe_sorts.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exe_sorts.dir/main.cpp.s"
	cd /home/zzy0/workspace_vscode/data_structure/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zzy0/workspace_vscode/data_structure/tests/main.cpp -o CMakeFiles/exe_sorts.dir/main.cpp.s

# Object files for target exe_sorts
exe_sorts_OBJECTS = \
"CMakeFiles/exe_sorts.dir/main.cpp.o"

# External object files for target exe_sorts
exe_sorts_EXTERNAL_OBJECTS =

../bin/exe_sorts: tests/CMakeFiles/exe_sorts.dir/main.cpp.o
../bin/exe_sorts: tests/CMakeFiles/exe_sorts.dir/build.make
../bin/exe_sorts: ../lib/libstring_pm.a
../bin/exe_sorts: tests/CMakeFiles/exe_sorts.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zzy0/workspace_vscode/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/exe_sorts"
	cd /home/zzy0/workspace_vscode/data_structure/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exe_sorts.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/exe_sorts.dir/build: ../bin/exe_sorts
.PHONY : tests/CMakeFiles/exe_sorts.dir/build

tests/CMakeFiles/exe_sorts.dir/clean:
	cd /home/zzy0/workspace_vscode/data_structure/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/exe_sorts.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/exe_sorts.dir/clean

tests/CMakeFiles/exe_sorts.dir/depend:
	cd /home/zzy0/workspace_vscode/data_structure/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zzy0/workspace_vscode/data_structure /home/zzy0/workspace_vscode/data_structure/tests /home/zzy0/workspace_vscode/data_structure/build /home/zzy0/workspace_vscode/data_structure/build/tests /home/zzy0/workspace_vscode/data_structure/build/tests/CMakeFiles/exe_sorts.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/exe_sorts.dir/depend

