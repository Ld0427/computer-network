# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lei/computer-network/day2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lei/computer-network/day2/build

# Include any dependencies generated for this target.
include CMakeFiles/erroif.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/erroif.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/erroif.dir/flags.make

CMakeFiles/erroif.dir/src/erroif.cpp.o: CMakeFiles/erroif.dir/flags.make
CMakeFiles/erroif.dir/src/erroif.cpp.o: ../src/erroif.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lei/computer-network/day2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/erroif.dir/src/erroif.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/erroif.dir/src/erroif.cpp.o -c /home/lei/computer-network/day2/src/erroif.cpp

CMakeFiles/erroif.dir/src/erroif.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/erroif.dir/src/erroif.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lei/computer-network/day2/src/erroif.cpp > CMakeFiles/erroif.dir/src/erroif.cpp.i

CMakeFiles/erroif.dir/src/erroif.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/erroif.dir/src/erroif.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lei/computer-network/day2/src/erroif.cpp -o CMakeFiles/erroif.dir/src/erroif.cpp.s

# Object files for target erroif
erroif_OBJECTS = \
"CMakeFiles/erroif.dir/src/erroif.cpp.o"

# External object files for target erroif
erroif_EXTERNAL_OBJECTS =

liberroif.so: CMakeFiles/erroif.dir/src/erroif.cpp.o
liberroif.so: CMakeFiles/erroif.dir/build.make
liberroif.so: CMakeFiles/erroif.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lei/computer-network/day2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library liberroif.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/erroif.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/erroif.dir/build: liberroif.so

.PHONY : CMakeFiles/erroif.dir/build

CMakeFiles/erroif.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/erroif.dir/cmake_clean.cmake
.PHONY : CMakeFiles/erroif.dir/clean

CMakeFiles/erroif.dir/depend:
	cd /home/lei/computer-network/day2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lei/computer-network/day2 /home/lei/computer-network/day2 /home/lei/computer-network/day2/build /home/lei/computer-network/day2/build /home/lei/computer-network/day2/build/CMakeFiles/erroif.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/erroif.dir/depend

