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
CMAKE_SOURCE_DIR = /home/siren/tf2-onsteroids

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/siren/tf2-onsteroids/build

# Include any dependencies generated for this target.
include CMakeFiles/libcheat.so.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libcheat.so.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libcheat.so.dir/flags.make

CMakeFiles/libcheat.so.dir/src/main.cpp.o: CMakeFiles/libcheat.so.dir/flags.make
CMakeFiles/libcheat.so.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siren/tf2-onsteroids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libcheat.so.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libcheat.so.dir/src/main.cpp.o -c /home/siren/tf2-onsteroids/src/main.cpp

CMakeFiles/libcheat.so.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libcheat.so.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/siren/tf2-onsteroids/src/main.cpp > CMakeFiles/libcheat.so.dir/src/main.cpp.i

CMakeFiles/libcheat.so.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libcheat.so.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/siren/tf2-onsteroids/src/main.cpp -o CMakeFiles/libcheat.so.dir/src/main.cpp.s

CMakeFiles/libcheat.so.dir/src/mem/mem.cpp.o: CMakeFiles/libcheat.so.dir/flags.make
CMakeFiles/libcheat.so.dir/src/mem/mem.cpp.o: ../src/mem/mem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siren/tf2-onsteroids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libcheat.so.dir/src/mem/mem.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libcheat.so.dir/src/mem/mem.cpp.o -c /home/siren/tf2-onsteroids/src/mem/mem.cpp

CMakeFiles/libcheat.so.dir/src/mem/mem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libcheat.so.dir/src/mem/mem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/siren/tf2-onsteroids/src/mem/mem.cpp > CMakeFiles/libcheat.so.dir/src/mem/mem.cpp.i

CMakeFiles/libcheat.so.dir/src/mem/mem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libcheat.so.dir/src/mem/mem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/siren/tf2-onsteroids/src/mem/mem.cpp -o CMakeFiles/libcheat.so.dir/src/mem/mem.cpp.s

# Object files for target libcheat.so
libcheat_so_OBJECTS = \
"CMakeFiles/libcheat.so.dir/src/main.cpp.o" \
"CMakeFiles/libcheat.so.dir/src/mem/mem.cpp.o"

# External object files for target libcheat.so
libcheat_so_EXTERNAL_OBJECTS =

liblibcheat.so.so: CMakeFiles/libcheat.so.dir/src/main.cpp.o
liblibcheat.so.so: CMakeFiles/libcheat.so.dir/src/mem/mem.cpp.o
liblibcheat.so.so: CMakeFiles/libcheat.so.dir/build.make
liblibcheat.so.so: CMakeFiles/libcheat.so.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/siren/tf2-onsteroids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library liblibcheat.so.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libcheat.so.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libcheat.so.dir/build: liblibcheat.so.so

.PHONY : CMakeFiles/libcheat.so.dir/build

CMakeFiles/libcheat.so.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libcheat.so.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libcheat.so.dir/clean

CMakeFiles/libcheat.so.dir/depend:
	cd /home/siren/tf2-onsteroids/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/siren/tf2-onsteroids /home/siren/tf2-onsteroids /home/siren/tf2-onsteroids/build /home/siren/tf2-onsteroids/build /home/siren/tf2-onsteroids/build/CMakeFiles/libcheat.so.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libcheat.so.dir/depend

