# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog/cmake-build-debug

# Include any dependencies generated for this target.
include ../libs/lib_map/CMakeFiles/map_Lib.dir/depend.make

# Include the progress variables for this target.
include ../libs/lib_map/CMakeFiles/map_Lib.dir/progress.make

# Include the compile flags for this target's objects.
include ../libs/lib_map/CMakeFiles/map_Lib.dir/flags.make

../libs/lib_map/CMakeFiles/map_Lib.dir/map.cpp.o: ../libs/lib_map/CMakeFiles/map_Lib.dir/flags.make
../libs/lib_map/CMakeFiles/map_Lib.dir/map.cpp.o: ../map/map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ../libs/lib_map/CMakeFiles/map_Lib.dir/map.cpp.o"
	cd /Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog/libs/lib_map && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/map_Lib.dir/map.cpp.o -c /Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog/map/map.cpp

../libs/lib_map/CMakeFiles/map_Lib.dir/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/map_Lib.dir/map.cpp.i"
	cd /Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog/libs/lib_map && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog/map/map.cpp > CMakeFiles/map_Lib.dir/map.cpp.i

../libs/lib_map/CMakeFiles/map_Lib.dir/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/map_Lib.dir/map.cpp.s"
	cd /Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog/libs/lib_map && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog/map/map.cpp -o CMakeFiles/map_Lib.dir/map.cpp.s

# Object files for target map_Lib
map_Lib_OBJECTS = \
"CMakeFiles/map_Lib.dir/map.cpp.o"

# External object files for target map_Lib
map_Lib_EXTERNAL_OBJECTS =

../libs/lib_map/libmap_Lib.a: ../libs/lib_map/CMakeFiles/map_Lib.dir/map.cpp.o
../libs/lib_map/libmap_Lib.a: ../libs/lib_map/CMakeFiles/map_Lib.dir/build.make
../libs/lib_map/libmap_Lib.a: ../libs/lib_map/CMakeFiles/map_Lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmap_Lib.a"
	cd /Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog/libs/lib_map && $(CMAKE_COMMAND) -P CMakeFiles/map_Lib.dir/cmake_clean_target.cmake
	cd /Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog/libs/lib_map && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/map_Lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
../libs/lib_map/CMakeFiles/map_Lib.dir/build: ../libs/lib_map/libmap_Lib.a

.PHONY : ../libs/lib_map/CMakeFiles/map_Lib.dir/build

../libs/lib_map/CMakeFiles/map_Lib.dir/clean:
	cd /Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog/libs/lib_map && $(CMAKE_COMMAND) -P CMakeFiles/map_Lib.dir/cmake_clean.cmake
.PHONY : ../libs/lib_map/CMakeFiles/map_Lib.dir/clean

../libs/lib_map/CMakeFiles/map_Lib.dir/depend:
	cd /Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog /Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog/map /Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog/cmake-build-debug /Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog/libs/lib_map /Users/andrew_borovets/Desktop/proga/TECHPROG/TechProg-2020/game_techprog/libs/lib_map/CMakeFiles/map_Lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ../libs/lib_map/CMakeFiles/map_Lib.dir/depend
