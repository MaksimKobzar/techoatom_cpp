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
CMAKE_SOURCE_DIR = /cygdrive/d/git/techoatom_cpp/Stack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/git/techoatom_cpp/Stack/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/StackDraft.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StackDraft.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StackDraft.dir/flags.make

CMakeFiles/StackDraft.dir/main.cpp.o: CMakeFiles/StackDraft.dir/flags.make
CMakeFiles/StackDraft.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/git/techoatom_cpp/Stack/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StackDraft.dir/main.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StackDraft.dir/main.cpp.o -c /cygdrive/d/git/techoatom_cpp/Stack/main.cpp

CMakeFiles/StackDraft.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StackDraft.dir/main.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/git/techoatom_cpp/Stack/main.cpp > CMakeFiles/StackDraft.dir/main.cpp.i

CMakeFiles/StackDraft.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StackDraft.dir/main.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/git/techoatom_cpp/Stack/main.cpp -o CMakeFiles/StackDraft.dir/main.cpp.s

CMakeFiles/StackDraft.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/StackDraft.dir/main.cpp.o.requires

CMakeFiles/StackDraft.dir/main.cpp.o.provides: CMakeFiles/StackDraft.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/StackDraft.dir/build.make CMakeFiles/StackDraft.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/StackDraft.dir/main.cpp.o.provides

CMakeFiles/StackDraft.dir/main.cpp.o.provides.build: CMakeFiles/StackDraft.dir/main.cpp.o


# Object files for target StackDraft
StackDraft_OBJECTS = \
"CMakeFiles/StackDraft.dir/main.cpp.o"

# External object files for target StackDraft
StackDraft_EXTERNAL_OBJECTS =

StackDraft.exe: CMakeFiles/StackDraft.dir/main.cpp.o
StackDraft.exe: CMakeFiles/StackDraft.dir/build.make
StackDraft.exe: CMakeFiles/StackDraft.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/git/techoatom_cpp/Stack/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable StackDraft.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StackDraft.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StackDraft.dir/build: StackDraft.exe

.PHONY : CMakeFiles/StackDraft.dir/build

CMakeFiles/StackDraft.dir/requires: CMakeFiles/StackDraft.dir/main.cpp.o.requires

.PHONY : CMakeFiles/StackDraft.dir/requires

CMakeFiles/StackDraft.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StackDraft.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StackDraft.dir/clean

CMakeFiles/StackDraft.dir/depend:
	cd /cygdrive/d/git/techoatom_cpp/Stack/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/git/techoatom_cpp/Stack /cygdrive/d/git/techoatom_cpp/Stack /cygdrive/d/git/techoatom_cpp/Stack/cmake-build-debug /cygdrive/d/git/techoatom_cpp/Stack/cmake-build-debug /cygdrive/d/git/techoatom_cpp/Stack/cmake-build-debug/CMakeFiles/StackDraft.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StackDraft.dir/depend

