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
CMAKE_SOURCE_DIR = /home/zzy0/vscode_workspace/data_structure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zzy0/vscode_workspace/data_structure/build

# Include any dependencies generated for this target.
include src/string_pm/CMakeFiles/string_pm.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/string_pm/CMakeFiles/string_pm.dir/compiler_depend.make

# Include the progress variables for this target.
include src/string_pm/CMakeFiles/string_pm.dir/progress.make

# Include the compile flags for this target's objects.
include src/string_pm/CMakeFiles/string_pm.dir/flags.make

src/string_pm/CMakeFiles/string_pm.dir/pm_brute_1.cpp.o: src/string_pm/CMakeFiles/string_pm.dir/flags.make
src/string_pm/CMakeFiles/string_pm.dir/pm_brute_1.cpp.o: ../src/string_pm/pm_brute_1.cpp
src/string_pm/CMakeFiles/string_pm.dir/pm_brute_1.cpp.o: src/string_pm/CMakeFiles/string_pm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zzy0/vscode_workspace/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/string_pm/CMakeFiles/string_pm.dir/pm_brute_1.cpp.o"
	cd /home/zzy0/vscode_workspace/data_structure/build/src/string_pm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/string_pm/CMakeFiles/string_pm.dir/pm_brute_1.cpp.o -MF CMakeFiles/string_pm.dir/pm_brute_1.cpp.o.d -o CMakeFiles/string_pm.dir/pm_brute_1.cpp.o -c /home/zzy0/vscode_workspace/data_structure/src/string_pm/pm_brute_1.cpp

src/string_pm/CMakeFiles/string_pm.dir/pm_brute_1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/string_pm.dir/pm_brute_1.cpp.i"
	cd /home/zzy0/vscode_workspace/data_structure/build/src/string_pm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zzy0/vscode_workspace/data_structure/src/string_pm/pm_brute_1.cpp > CMakeFiles/string_pm.dir/pm_brute_1.cpp.i

src/string_pm/CMakeFiles/string_pm.dir/pm_brute_1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/string_pm.dir/pm_brute_1.cpp.s"
	cd /home/zzy0/vscode_workspace/data_structure/build/src/string_pm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zzy0/vscode_workspace/data_structure/src/string_pm/pm_brute_1.cpp -o CMakeFiles/string_pm.dir/pm_brute_1.cpp.s

src/string_pm/CMakeFiles/string_pm.dir/pm_brute_2.cpp.o: src/string_pm/CMakeFiles/string_pm.dir/flags.make
src/string_pm/CMakeFiles/string_pm.dir/pm_brute_2.cpp.o: ../src/string_pm/pm_brute_2.cpp
src/string_pm/CMakeFiles/string_pm.dir/pm_brute_2.cpp.o: src/string_pm/CMakeFiles/string_pm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zzy0/vscode_workspace/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/string_pm/CMakeFiles/string_pm.dir/pm_brute_2.cpp.o"
	cd /home/zzy0/vscode_workspace/data_structure/build/src/string_pm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/string_pm/CMakeFiles/string_pm.dir/pm_brute_2.cpp.o -MF CMakeFiles/string_pm.dir/pm_brute_2.cpp.o.d -o CMakeFiles/string_pm.dir/pm_brute_2.cpp.o -c /home/zzy0/vscode_workspace/data_structure/src/string_pm/pm_brute_2.cpp

src/string_pm/CMakeFiles/string_pm.dir/pm_brute_2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/string_pm.dir/pm_brute_2.cpp.i"
	cd /home/zzy0/vscode_workspace/data_structure/build/src/string_pm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zzy0/vscode_workspace/data_structure/src/string_pm/pm_brute_2.cpp > CMakeFiles/string_pm.dir/pm_brute_2.cpp.i

src/string_pm/CMakeFiles/string_pm.dir/pm_brute_2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/string_pm.dir/pm_brute_2.cpp.s"
	cd /home/zzy0/vscode_workspace/data_structure/build/src/string_pm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zzy0/vscode_workspace/data_structure/src/string_pm/pm_brute_2.cpp -o CMakeFiles/string_pm.dir/pm_brute_2.cpp.s

src/string_pm/CMakeFiles/string_pm.dir/pm_kmp.cpp.o: src/string_pm/CMakeFiles/string_pm.dir/flags.make
src/string_pm/CMakeFiles/string_pm.dir/pm_kmp.cpp.o: ../src/string_pm/pm_kmp.cpp
src/string_pm/CMakeFiles/string_pm.dir/pm_kmp.cpp.o: src/string_pm/CMakeFiles/string_pm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zzy0/vscode_workspace/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/string_pm/CMakeFiles/string_pm.dir/pm_kmp.cpp.o"
	cd /home/zzy0/vscode_workspace/data_structure/build/src/string_pm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/string_pm/CMakeFiles/string_pm.dir/pm_kmp.cpp.o -MF CMakeFiles/string_pm.dir/pm_kmp.cpp.o.d -o CMakeFiles/string_pm.dir/pm_kmp.cpp.o -c /home/zzy0/vscode_workspace/data_structure/src/string_pm/pm_kmp.cpp

src/string_pm/CMakeFiles/string_pm.dir/pm_kmp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/string_pm.dir/pm_kmp.cpp.i"
	cd /home/zzy0/vscode_workspace/data_structure/build/src/string_pm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zzy0/vscode_workspace/data_structure/src/string_pm/pm_kmp.cpp > CMakeFiles/string_pm.dir/pm_kmp.cpp.i

src/string_pm/CMakeFiles/string_pm.dir/pm_kmp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/string_pm.dir/pm_kmp.cpp.s"
	cd /home/zzy0/vscode_workspace/data_structure/build/src/string_pm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zzy0/vscode_workspace/data_structure/src/string_pm/pm_kmp.cpp -o CMakeFiles/string_pm.dir/pm_kmp.cpp.s

src/string_pm/CMakeFiles/string_pm.dir/string_pm.cpp.o: src/string_pm/CMakeFiles/string_pm.dir/flags.make
src/string_pm/CMakeFiles/string_pm.dir/string_pm.cpp.o: ../src/string_pm/string_pm.cpp
src/string_pm/CMakeFiles/string_pm.dir/string_pm.cpp.o: src/string_pm/CMakeFiles/string_pm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zzy0/vscode_workspace/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/string_pm/CMakeFiles/string_pm.dir/string_pm.cpp.o"
	cd /home/zzy0/vscode_workspace/data_structure/build/src/string_pm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/string_pm/CMakeFiles/string_pm.dir/string_pm.cpp.o -MF CMakeFiles/string_pm.dir/string_pm.cpp.o.d -o CMakeFiles/string_pm.dir/string_pm.cpp.o -c /home/zzy0/vscode_workspace/data_structure/src/string_pm/string_pm.cpp

src/string_pm/CMakeFiles/string_pm.dir/string_pm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/string_pm.dir/string_pm.cpp.i"
	cd /home/zzy0/vscode_workspace/data_structure/build/src/string_pm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zzy0/vscode_workspace/data_structure/src/string_pm/string_pm.cpp > CMakeFiles/string_pm.dir/string_pm.cpp.i

src/string_pm/CMakeFiles/string_pm.dir/string_pm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/string_pm.dir/string_pm.cpp.s"
	cd /home/zzy0/vscode_workspace/data_structure/build/src/string_pm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zzy0/vscode_workspace/data_structure/src/string_pm/string_pm.cpp -o CMakeFiles/string_pm.dir/string_pm.cpp.s

# Object files for target string_pm
string_pm_OBJECTS = \
"CMakeFiles/string_pm.dir/pm_brute_1.cpp.o" \
"CMakeFiles/string_pm.dir/pm_brute_2.cpp.o" \
"CMakeFiles/string_pm.dir/pm_kmp.cpp.o" \
"CMakeFiles/string_pm.dir/string_pm.cpp.o"

# External object files for target string_pm
string_pm_EXTERNAL_OBJECTS =

../lib/libstring_pm.a: src/string_pm/CMakeFiles/string_pm.dir/pm_brute_1.cpp.o
../lib/libstring_pm.a: src/string_pm/CMakeFiles/string_pm.dir/pm_brute_2.cpp.o
../lib/libstring_pm.a: src/string_pm/CMakeFiles/string_pm.dir/pm_kmp.cpp.o
../lib/libstring_pm.a: src/string_pm/CMakeFiles/string_pm.dir/string_pm.cpp.o
../lib/libstring_pm.a: src/string_pm/CMakeFiles/string_pm.dir/build.make
../lib/libstring_pm.a: src/string_pm/CMakeFiles/string_pm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zzy0/vscode_workspace/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library ../../../lib/libstring_pm.a"
	cd /home/zzy0/vscode_workspace/data_structure/build/src/string_pm && $(CMAKE_COMMAND) -P CMakeFiles/string_pm.dir/cmake_clean_target.cmake
	cd /home/zzy0/vscode_workspace/data_structure/build/src/string_pm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/string_pm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/string_pm/CMakeFiles/string_pm.dir/build: ../lib/libstring_pm.a
.PHONY : src/string_pm/CMakeFiles/string_pm.dir/build

src/string_pm/CMakeFiles/string_pm.dir/clean:
	cd /home/zzy0/vscode_workspace/data_structure/build/src/string_pm && $(CMAKE_COMMAND) -P CMakeFiles/string_pm.dir/cmake_clean.cmake
.PHONY : src/string_pm/CMakeFiles/string_pm.dir/clean

src/string_pm/CMakeFiles/string_pm.dir/depend:
	cd /home/zzy0/vscode_workspace/data_structure/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zzy0/vscode_workspace/data_structure /home/zzy0/vscode_workspace/data_structure/src/string_pm /home/zzy0/vscode_workspace/data_structure/build /home/zzy0/vscode_workspace/data_structure/build/src/string_pm /home/zzy0/vscode_workspace/data_structure/build/src/string_pm/CMakeFiles/string_pm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/string_pm/CMakeFiles/string_pm.dir/depend
