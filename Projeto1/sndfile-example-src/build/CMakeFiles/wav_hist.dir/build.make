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
CMAKE_SOURCE_DIR = /home/filipe/Desktop/IC/Projeto1/sndfile-example-src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/filipe/Desktop/IC/Projeto1/sndfile-example-src/build

# Include any dependencies generated for this target.
include CMakeFiles/wav_hist.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wav_hist.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wav_hist.dir/flags.make

CMakeFiles/wav_hist.dir/wav_hist.cpp.o: CMakeFiles/wav_hist.dir/flags.make
CMakeFiles/wav_hist.dir/wav_hist.cpp.o: ../wav_hist.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/filipe/Desktop/IC/Projeto1/sndfile-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wav_hist.dir/wav_hist.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wav_hist.dir/wav_hist.cpp.o -c /home/filipe/Desktop/IC/Projeto1/sndfile-example-src/wav_hist.cpp

CMakeFiles/wav_hist.dir/wav_hist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wav_hist.dir/wav_hist.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/filipe/Desktop/IC/Projeto1/sndfile-example-src/wav_hist.cpp > CMakeFiles/wav_hist.dir/wav_hist.cpp.i

CMakeFiles/wav_hist.dir/wav_hist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wav_hist.dir/wav_hist.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/filipe/Desktop/IC/Projeto1/sndfile-example-src/wav_hist.cpp -o CMakeFiles/wav_hist.dir/wav_hist.cpp.s

# Object files for target wav_hist
wav_hist_OBJECTS = \
"CMakeFiles/wav_hist.dir/wav_hist.cpp.o"

# External object files for target wav_hist
wav_hist_EXTERNAL_OBJECTS =

/home/filipe/Desktop/IC/Projeto1/sndfile-example-bin/wav_hist: CMakeFiles/wav_hist.dir/wav_hist.cpp.o
/home/filipe/Desktop/IC/Projeto1/sndfile-example-bin/wav_hist: CMakeFiles/wav_hist.dir/build.make
/home/filipe/Desktop/IC/Projeto1/sndfile-example-bin/wav_hist: CMakeFiles/wav_hist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/filipe/Desktop/IC/Projeto1/sndfile-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/filipe/Desktop/IC/Projeto1/sndfile-example-bin/wav_hist"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wav_hist.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wav_hist.dir/build: /home/filipe/Desktop/IC/Projeto1/sndfile-example-bin/wav_hist

.PHONY : CMakeFiles/wav_hist.dir/build

CMakeFiles/wav_hist.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wav_hist.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wav_hist.dir/clean

CMakeFiles/wav_hist.dir/depend:
	cd /home/filipe/Desktop/IC/Projeto1/sndfile-example-src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/filipe/Desktop/IC/Projeto1/sndfile-example-src /home/filipe/Desktop/IC/Projeto1/sndfile-example-src /home/filipe/Desktop/IC/Projeto1/sndfile-example-src/build /home/filipe/Desktop/IC/Projeto1/sndfile-example-src/build /home/filipe/Desktop/IC/Projeto1/sndfile-example-src/build/CMakeFiles/wav_hist.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wav_hist.dir/depend

