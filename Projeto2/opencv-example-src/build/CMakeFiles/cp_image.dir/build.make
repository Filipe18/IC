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
CMAKE_SOURCE_DIR = /home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-src/build

# Include any dependencies generated for this target.
include CMakeFiles/cp_image.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cp_image.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cp_image.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cp_image.dir/flags.make

CMakeFiles/cp_image.dir/cp_image.cpp.o: CMakeFiles/cp_image.dir/flags.make
CMakeFiles/cp_image.dir/cp_image.cpp.o: ../cp_image.cpp
CMakeFiles/cp_image.dir/cp_image.cpp.o: CMakeFiles/cp_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cp_image.dir/cp_image.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cp_image.dir/cp_image.cpp.o -MF CMakeFiles/cp_image.dir/cp_image.cpp.o.d -o CMakeFiles/cp_image.dir/cp_image.cpp.o -c /home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-src/cp_image.cpp

CMakeFiles/cp_image.dir/cp_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cp_image.dir/cp_image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-src/cp_image.cpp > CMakeFiles/cp_image.dir/cp_image.cpp.i

CMakeFiles/cp_image.dir/cp_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cp_image.dir/cp_image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-src/cp_image.cpp -o CMakeFiles/cp_image.dir/cp_image.cpp.s

# Object files for target cp_image
cp_image_OBJECTS = \
"CMakeFiles/cp_image.dir/cp_image.cpp.o"

# External object files for target cp_image
cp_image_EXTERNAL_OBJECTS =

/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: CMakeFiles/cp_image.dir/cp_image.cpp.o
/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: CMakeFiles/cp_image.dir/build.make
/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: /usr/local/lib/libopencv_gapi.so.4.6.0
/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: /usr/local/lib/libopencv_highgui.so.4.6.0
/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: /usr/local/lib/libopencv_ml.so.4.6.0
/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: /usr/local/lib/libopencv_objdetect.so.4.6.0
/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: /usr/local/lib/libopencv_photo.so.4.6.0
/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: /usr/local/lib/libopencv_stitching.so.4.6.0
/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: /usr/local/lib/libopencv_video.so.4.6.0
/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: /usr/local/lib/libopencv_videoio.so.4.6.0
/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: /usr/local/lib/libopencv_imgcodecs.so.4.6.0
/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: /usr/local/lib/libopencv_dnn.so.4.6.0
/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: /usr/local/lib/libopencv_calib3d.so.4.6.0
/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: /usr/local/lib/libopencv_features2d.so.4.6.0
/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: /usr/local/lib/libopencv_flann.so.4.6.0
/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: /usr/local/lib/libopencv_imgproc.so.4.6.0
/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: /usr/local/lib/libopencv_core.so.4.6.0
/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image: CMakeFiles/cp_image.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cp_image.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cp_image.dir/build: /home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-bin/cp_image
.PHONY : CMakeFiles/cp_image.dir/build

CMakeFiles/cp_image.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cp_image.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cp_image.dir/clean

CMakeFiles/cp_image.dir/depend:
	cd /home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-src /home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-src /home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-src/build /home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-src/build /home/antunes/Desktop/4ano/IC/Projeto2/opencv-example-src/build/CMakeFiles/cp_image.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cp_image.dir/depend

