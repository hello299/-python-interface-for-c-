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
CMAKE_SOURCE_DIR = /home/zhaobojun/change_detection_ws/src/change_detection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhaobojun/change_detection_ws/src/change_detection/build

# Include any dependencies generated for this target.
include CMakeFiles/octree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/octree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/octree.dir/flags.make

CMakeFiles/octree.dir/src/octree_change_detection.cpp.o: CMakeFiles/octree.dir/flags.make
CMakeFiles/octree.dir/src/octree_change_detection.cpp.o: ../src/octree_change_detection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhaobojun/change_detection_ws/src/change_detection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/octree.dir/src/octree_change_detection.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/octree.dir/src/octree_change_detection.cpp.o -c /home/zhaobojun/change_detection_ws/src/change_detection/src/octree_change_detection.cpp

CMakeFiles/octree.dir/src/octree_change_detection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/octree.dir/src/octree_change_detection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhaobojun/change_detection_ws/src/change_detection/src/octree_change_detection.cpp > CMakeFiles/octree.dir/src/octree_change_detection.cpp.i

CMakeFiles/octree.dir/src/octree_change_detection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/octree.dir/src/octree_change_detection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhaobojun/change_detection_ws/src/change_detection/src/octree_change_detection.cpp -o CMakeFiles/octree.dir/src/octree_change_detection.cpp.s

# Object files for target octree
octree_OBJECTS = \
"CMakeFiles/octree.dir/src/octree_change_detection.cpp.o"

# External object files for target octree
octree_EXTERNAL_OBJECTS =

liboctree.so: CMakeFiles/octree.dir/src/octree_change_detection.cpp.o
liboctree.so: CMakeFiles/octree.dir/build.make
liboctree.so: CMakeFiles/octree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhaobojun/change_detection_ws/src/change_detection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library liboctree.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/octree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/octree.dir/build: liboctree.so

.PHONY : CMakeFiles/octree.dir/build

CMakeFiles/octree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/octree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/octree.dir/clean

CMakeFiles/octree.dir/depend:
	cd /home/zhaobojun/change_detection_ws/src/change_detection/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhaobojun/change_detection_ws/src/change_detection /home/zhaobojun/change_detection_ws/src/change_detection /home/zhaobojun/change_detection_ws/src/change_detection/build /home/zhaobojun/change_detection_ws/src/change_detection/build /home/zhaobojun/change_detection_ws/src/change_detection/build/CMakeFiles/octree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/octree.dir/depend

