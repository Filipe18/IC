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
include CMakeFiles/locatelang.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/locatelang.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/locatelang.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/locatelang.dir/flags.make

CMakeFiles/locatelang.dir/locatelang.cpp.o: CMakeFiles/locatelang.dir/flags.make
CMakeFiles/locatelang.dir/locatelang.cpp.o: ../locatelang.cpp
CMakeFiles/locatelang.dir/locatelang.cpp.o: CMakeFiles/locatelang.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/locatelang.dir/locatelang.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/locatelang.dir/locatelang.cpp.o -MF CMakeFiles/locatelang.dir/locatelang.cpp.o.d -o CMakeFiles/locatelang.dir/locatelang.cpp.o -c /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/locatelang.cpp

CMakeFiles/locatelang.dir/locatelang.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/locatelang.dir/locatelang.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/locatelang.cpp > CMakeFiles/locatelang.dir/locatelang.cpp.i

CMakeFiles/locatelang.dir/locatelang.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/locatelang.dir/locatelang.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/locatelang.cpp -o CMakeFiles/locatelang.dir/locatelang.cpp.s

# Object files for target locatelang
locatelang_OBJECTS = \
"CMakeFiles/locatelang.dir/locatelang.cpp.o"

# External object files for target locatelang
locatelang_EXTERNAL_OBJECTS =

/home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-bin/locatelang: CMakeFiles/locatelang.dir/locatelang.cpp.o
/home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-bin/locatelang: CMakeFiles/locatelang.dir/build.make
/home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-bin/locatelang: CMakeFiles/locatelang.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-bin/locatelang"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/locatelang.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/locatelang.dir/build: /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-bin/locatelang
.PHONY : CMakeFiles/locatelang.dir/build

CMakeFiles/locatelang.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/locatelang.dir/cmake_clean.cmake
.PHONY : CMakeFiles/locatelang.dir/clean

CMakeFiles/locatelang.dir/depend:
	cd /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build/CMakeFiles/locatelang.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/locatelang.dir/depend

