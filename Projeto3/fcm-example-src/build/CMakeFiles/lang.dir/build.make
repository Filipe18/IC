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
include CMakeFiles/lang.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lang.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lang.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lang.dir/flags.make

CMakeFiles/lang.dir/lang.cpp.o: CMakeFiles/lang.dir/flags.make
CMakeFiles/lang.dir/lang.cpp.o: ../lang.cpp
CMakeFiles/lang.dir/lang.cpp.o: CMakeFiles/lang.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lang.dir/lang.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lang.dir/lang.cpp.o -MF CMakeFiles/lang.dir/lang.cpp.o.d -o CMakeFiles/lang.dir/lang.cpp.o -c /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/lang.cpp

CMakeFiles/lang.dir/lang.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang.dir/lang.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/lang.cpp > CMakeFiles/lang.dir/lang.cpp.i

CMakeFiles/lang.dir/lang.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang.dir/lang.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/lang.cpp -o CMakeFiles/lang.dir/lang.cpp.s

# Object files for target lang
lang_OBJECTS = \
"CMakeFiles/lang.dir/lang.cpp.o"

# External object files for target lang
lang_EXTERNAL_OBJECTS =

/home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-bin/lang: CMakeFiles/lang.dir/lang.cpp.o
/home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-bin/lang: CMakeFiles/lang.dir/build.make
/home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-bin/lang: CMakeFiles/lang.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-bin/lang"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lang.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lang.dir/build: /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-bin/lang
.PHONY : CMakeFiles/lang.dir/build

CMakeFiles/lang.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lang.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lang.dir/clean

CMakeFiles/lang.dir/depend:
	cd /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build /home/fastmiguel099/Documents/Universidade/IC/Projeto3/fcm-example-src/build/CMakeFiles/lang.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lang.dir/depend

