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
CMAKE_SOURCE_DIR = /home/filipe/Desktop/IC/Projeto2/opencv-example-src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/filipe/Desktop/IC/Projeto2/opencv-example-src/build

# Include any dependencies generated for this target.
include CMakeFiles/golomb.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/golomb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/golomb.dir/flags.make

CMakeFiles/golomb.dir/Golomb.cpp.o: CMakeFiles/golomb.dir/flags.make
CMakeFiles/golomb.dir/Golomb.cpp.o: ../Golomb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/filipe/Desktop/IC/Projeto2/opencv-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/golomb.dir/Golomb.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/golomb.dir/Golomb.cpp.o -c /home/filipe/Desktop/IC/Projeto2/opencv-example-src/Golomb.cpp

CMakeFiles/golomb.dir/Golomb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/golomb.dir/Golomb.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/filipe/Desktop/IC/Projeto2/opencv-example-src/Golomb.cpp > CMakeFiles/golomb.dir/Golomb.cpp.i

CMakeFiles/golomb.dir/Golomb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/golomb.dir/Golomb.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/filipe/Desktop/IC/Projeto2/opencv-example-src/Golomb.cpp -o CMakeFiles/golomb.dir/Golomb.cpp.s

# Object files for target golomb
golomb_OBJECTS = \
"CMakeFiles/golomb.dir/Golomb.cpp.o"

# External object files for target golomb
golomb_EXTERNAL_OBJECTS =

libgolomb.a: CMakeFiles/golomb.dir/Golomb.cpp.o
libgolomb.a: CMakeFiles/golomb.dir/build.make
libgolomb.a: CMakeFiles/golomb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/filipe/Desktop/IC/Projeto2/opencv-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgolomb.a"
	$(CMAKE_COMMAND) -P CMakeFiles/golomb.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/golomb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/golomb.dir/build: libgolomb.a

.PHONY : CMakeFiles/golomb.dir/build

CMakeFiles/golomb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/golomb.dir/cmake_clean.cmake
.PHONY : CMakeFiles/golomb.dir/clean

CMakeFiles/golomb.dir/depend:
	cd /home/filipe/Desktop/IC/Projeto2/opencv-example-src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/filipe/Desktop/IC/Projeto2/opencv-example-src /home/filipe/Desktop/IC/Projeto2/opencv-example-src /home/filipe/Desktop/IC/Projeto2/opencv-example-src/build /home/filipe/Desktop/IC/Projeto2/opencv-example-src/build /home/filipe/Desktop/IC/Projeto2/opencv-example-src/build/CMakeFiles/golomb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/golomb.dir/depend

