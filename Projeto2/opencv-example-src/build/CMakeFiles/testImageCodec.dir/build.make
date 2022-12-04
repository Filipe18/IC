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
CMAKE_SOURCE_DIR = /home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-src/build

# Include any dependencies generated for this target.
include CMakeFiles/testImageCodec.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/testImageCodec.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/testImageCodec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testImageCodec.dir/flags.make

CMakeFiles/testImageCodec.dir/tests/testImageCodec.cpp.o: CMakeFiles/testImageCodec.dir/flags.make
CMakeFiles/testImageCodec.dir/tests/testImageCodec.cpp.o: ../tests/testImageCodec.cpp
CMakeFiles/testImageCodec.dir/tests/testImageCodec.cpp.o: CMakeFiles/testImageCodec.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testImageCodec.dir/tests/testImageCodec.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testImageCodec.dir/tests/testImageCodec.cpp.o -MF CMakeFiles/testImageCodec.dir/tests/testImageCodec.cpp.o.d -o CMakeFiles/testImageCodec.dir/tests/testImageCodec.cpp.o -c /home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-src/tests/testImageCodec.cpp

CMakeFiles/testImageCodec.dir/tests/testImageCodec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testImageCodec.dir/tests/testImageCodec.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-src/tests/testImageCodec.cpp > CMakeFiles/testImageCodec.dir/tests/testImageCodec.cpp.i

CMakeFiles/testImageCodec.dir/tests/testImageCodec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testImageCodec.dir/tests/testImageCodec.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-src/tests/testImageCodec.cpp -o CMakeFiles/testImageCodec.dir/tests/testImageCodec.cpp.s

# Object files for target testImageCodec
testImageCodec_OBJECTS = \
"CMakeFiles/testImageCodec.dir/tests/testImageCodec.cpp.o"

# External object files for target testImageCodec
testImageCodec_EXTERNAL_OBJECTS =

/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: CMakeFiles/testImageCodec.dir/tests/testImageCodec.cpp.o
/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: CMakeFiles/testImageCodec.dir/build.make
/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: /usr/local/lib/libopencv_gapi.so.4.6.0
/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: /usr/local/lib/libopencv_highgui.so.4.6.0
/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: /usr/local/lib/libopencv_ml.so.4.6.0
/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: /usr/local/lib/libopencv_objdetect.so.4.6.0
/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: /usr/local/lib/libopencv_photo.so.4.6.0
/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: /usr/local/lib/libopencv_stitching.so.4.6.0
/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: /usr/local/lib/libopencv_video.so.4.6.0
/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: /usr/local/lib/libopencv_videoio.so.4.6.0
/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: /usr/local/lib/libopencv_imgcodecs.so.4.6.0
/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: /usr/local/lib/libopencv_dnn.so.4.6.0
/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: /usr/local/lib/libopencv_calib3d.so.4.6.0
/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: /usr/local/lib/libopencv_features2d.so.4.6.0
/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: /usr/local/lib/libopencv_flann.so.4.6.0
/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: /usr/local/lib/libopencv_imgproc.so.4.6.0
/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: /usr/local/lib/libopencv_core.so.4.6.0
/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec: CMakeFiles/testImageCodec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testImageCodec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testImageCodec.dir/build: /home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-bin/testImageCodec
.PHONY : CMakeFiles/testImageCodec.dir/build

CMakeFiles/testImageCodec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testImageCodec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testImageCodec.dir/clean

CMakeFiles/testImageCodec.dir/depend:
	cd /home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-src /home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-src /home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-src/build /home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-src/build /home/fastmiguel099/Documents/Universidade/IC/Projeto2/opencv-example-src/build/CMakeFiles/testImageCodec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testImageCodec.dir/depend
