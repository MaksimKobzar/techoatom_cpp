# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /cygdrive/c/Users/kobzar/.CLion2016.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/kobzar/.CLion2016.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/git/techoatom_cpp/exercises/Stack_win

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/git/techoatom_cpp/exercises/Stack_win/cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/runStackTestLib.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/runStackTestLib.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/runStackTestLib.dir/flags.make

test/CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.o: test/CMakeFiles/runStackTestLib.dir/flags.make
test/CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.o: ../test/StackTestLib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/git/techoatom_cpp/exercises/Stack_win/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.o"
	cd /cygdrive/d/git/techoatom_cpp/exercises/Stack_win/cmake-build-debug/test && /usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.o -c /cygdrive/d/git/techoatom_cpp/exercises/Stack_win/test/StackTestLib.cpp

test/CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.i"
	cd /cygdrive/d/git/techoatom_cpp/exercises/Stack_win/cmake-build-debug/test && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/git/techoatom_cpp/exercises/Stack_win/test/StackTestLib.cpp > CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.i

test/CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.s"
	cd /cygdrive/d/git/techoatom_cpp/exercises/Stack_win/cmake-build-debug/test && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/git/techoatom_cpp/exercises/Stack_win/test/StackTestLib.cpp -o CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.s

test/CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.o.requires:

.PHONY : test/CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.o.requires

test/CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.o.provides: test/CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/runStackTestLib.dir/build.make test/CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.o.provides.build
.PHONY : test/CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.o.provides

test/CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.o.provides.build: test/CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.o


# Object files for target runStackTestLib
runStackTestLib_OBJECTS = \
"CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.o"

# External object files for target runStackTestLib
runStackTestLib_EXTERNAL_OBJECTS =

test/runStackTestLib.exe: test/CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.o
test/runStackTestLib.exe: test/CMakeFiles/runStackTestLib.dir/build.make
test/runStackTestLib.exe: test/gtest/googlemock/gtest/libgtest.a
test/runStackTestLib.exe: test/gtest/googlemock/gtest/libgtest_main.a
test/runStackTestLib.exe: test/gtest/googlemock/gtest/libgtest.a
test/runStackTestLib.exe: test/CMakeFiles/runStackTestLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/git/techoatom_cpp/exercises/Stack_win/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable runStackTestLib.exe"
	cd /cygdrive/d/git/techoatom_cpp/exercises/Stack_win/cmake-build-debug/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runStackTestLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/runStackTestLib.dir/build: test/runStackTestLib.exe

.PHONY : test/CMakeFiles/runStackTestLib.dir/build

test/CMakeFiles/runStackTestLib.dir/requires: test/CMakeFiles/runStackTestLib.dir/StackTestLib.cpp.o.requires

.PHONY : test/CMakeFiles/runStackTestLib.dir/requires

test/CMakeFiles/runStackTestLib.dir/clean:
	cd /cygdrive/d/git/techoatom_cpp/exercises/Stack_win/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/runStackTestLib.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/runStackTestLib.dir/clean

test/CMakeFiles/runStackTestLib.dir/depend:
	cd /cygdrive/d/git/techoatom_cpp/exercises/Stack_win/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/git/techoatom_cpp/exercises/Stack_win /cygdrive/d/git/techoatom_cpp/exercises/Stack_win/test /cygdrive/d/git/techoatom_cpp/exercises/Stack_win/cmake-build-debug /cygdrive/d/git/techoatom_cpp/exercises/Stack_win/cmake-build-debug/test /cygdrive/d/git/techoatom_cpp/exercises/Stack_win/cmake-build-debug/test/CMakeFiles/runStackTestLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/runStackTestLib.dir/depend

