# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = A:\EEEE2046\calc_cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = A:\EEEE2046\calc_cmake\mingw_static

# Include any dependencies generated for this target.
include CMakeFiles/maths.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/maths.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/maths.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/maths.dir/flags.make

CMakeFiles/maths.dir/adder.cpp.obj: CMakeFiles/maths.dir/flags.make
CMakeFiles/maths.dir/adder.cpp.obj: ../adder.cpp
CMakeFiles/maths.dir/adder.cpp.obj: CMakeFiles/maths.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=A:\EEEE2046\calc_cmake\mingw_static\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/maths.dir/adder.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/maths.dir/adder.cpp.obj -MF CMakeFiles\maths.dir\adder.cpp.obj.d -o CMakeFiles\maths.dir\adder.cpp.obj -c A:\EEEE2046\calc_cmake\adder.cpp

CMakeFiles/maths.dir/adder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/maths.dir/adder.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E A:\EEEE2046\calc_cmake\adder.cpp > CMakeFiles\maths.dir\adder.cpp.i

CMakeFiles/maths.dir/adder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/maths.dir/adder.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S A:\EEEE2046\calc_cmake\adder.cpp -o CMakeFiles\maths.dir\adder.cpp.s

# Object files for target maths
maths_OBJECTS = \
"CMakeFiles/maths.dir/adder.cpp.obj"

# External object files for target maths
maths_EXTERNAL_OBJECTS =

libmaths.a: CMakeFiles/maths.dir/adder.cpp.obj
libmaths.a: CMakeFiles/maths.dir/build.make
libmaths.a: CMakeFiles/maths.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=A:\EEEE2046\calc_cmake\mingw_static\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmaths.a"
	$(CMAKE_COMMAND) -P CMakeFiles\maths.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\maths.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/maths.dir/build: libmaths.a
.PHONY : CMakeFiles/maths.dir/build

CMakeFiles/maths.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\maths.dir\cmake_clean.cmake
.PHONY : CMakeFiles/maths.dir/clean

CMakeFiles/maths.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" A:\EEEE2046\calc_cmake A:\EEEE2046\calc_cmake A:\EEEE2046\calc_cmake\mingw_static A:\EEEE2046\calc_cmake\mingw_static A:\EEEE2046\calc_cmake\mingw_static\CMakeFiles\maths.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/maths.dir/depend

