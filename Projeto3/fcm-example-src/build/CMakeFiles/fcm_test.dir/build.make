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
CMAKE_SOURCE_DIR = /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build

# Include any dependencies generated for this target.
include CMakeFiles/fcm_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/fcm_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/fcm_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fcm_test.dir/flags.make

CMakeFiles/fcm_test.dir/fcm_test.cpp.o: CMakeFiles/fcm_test.dir/flags.make
CMakeFiles/fcm_test.dir/fcm_test.cpp.o: ../fcm_test.cpp
CMakeFiles/fcm_test.dir/fcm_test.cpp.o: CMakeFiles/fcm_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fcm_test.dir/fcm_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fcm_test.dir/fcm_test.cpp.o -MF CMakeFiles/fcm_test.dir/fcm_test.cpp.o.d -o CMakeFiles/fcm_test.dir/fcm_test.cpp.o -c /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/fcm_test.cpp

CMakeFiles/fcm_test.dir/fcm_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fcm_test.dir/fcm_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/fcm_test.cpp > CMakeFiles/fcm_test.dir/fcm_test.cpp.i

CMakeFiles/fcm_test.dir/fcm_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fcm_test.dir/fcm_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/fcm_test.cpp -o CMakeFiles/fcm_test.dir/fcm_test.cpp.s

# Object files for target fcm_test
fcm_test_OBJECTS = \
"CMakeFiles/fcm_test.dir/fcm_test.cpp.o"

# External object files for target fcm_test
fcm_test_EXTERNAL_OBJECTS =

/home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-bin/fcm_test: CMakeFiles/fcm_test.dir/fcm_test.cpp.o
/home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-bin/fcm_test: CMakeFiles/fcm_test.dir/build.make
/home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-bin/fcm_test: CMakeFiles/fcm_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-bin/fcm_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fcm_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fcm_test.dir/build: /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-bin/fcm_test
.PHONY : CMakeFiles/fcm_test.dir/build

CMakeFiles/fcm_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fcm_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fcm_test.dir/clean

CMakeFiles/fcm_test.dir/depend:
	cd /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build/CMakeFiles/fcm_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fcm_test.dir/depend

