# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = D:\software\Qt\Tools\CMake_64\bin\cmake.exe

# The command to remove a file.
RM = D:\software\Qt\Tools\CMake_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\workspace\Computer-Graphics\learn\qt\chap02\samp2_4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\workspace\Computer-Graphics\learn\qt\chap02\build-samp2_4-Desktop_Qt_6_5_0_MinGW_64_bit-Debug

# Utility rule file for samp2_4_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/samp2_4_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/samp2_4_autogen.dir/progress.make

CMakeFiles/samp2_4_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=D:\workspace\Computer-Graphics\learn\qt\chap02\build-samp2_4-Desktop_Qt_6_5_0_MinGW_64_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target samp2_4"
	D:\software\Qt\Tools\CMake_64\bin\cmake.exe -E cmake_autogen D:/workspace/Computer-Graphics/learn/qt/chap02/build-samp2_4-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/CMakeFiles/samp2_4_autogen.dir/AutogenInfo.json Debug

samp2_4_autogen: CMakeFiles/samp2_4_autogen
samp2_4_autogen: CMakeFiles/samp2_4_autogen.dir/build.make
.PHONY : samp2_4_autogen

# Rule to build all files generated by this target.
CMakeFiles/samp2_4_autogen.dir/build: samp2_4_autogen
.PHONY : CMakeFiles/samp2_4_autogen.dir/build

CMakeFiles/samp2_4_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\samp2_4_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/samp2_4_autogen.dir/clean

CMakeFiles/samp2_4_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\workspace\Computer-Graphics\learn\qt\chap02\samp2_4 D:\workspace\Computer-Graphics\learn\qt\chap02\samp2_4 D:\workspace\Computer-Graphics\learn\qt\chap02\build-samp2_4-Desktop_Qt_6_5_0_MinGW_64_bit-Debug D:\workspace\Computer-Graphics\learn\qt\chap02\build-samp2_4-Desktop_Qt_6_5_0_MinGW_64_bit-Debug D:\workspace\Computer-Graphics\learn\qt\chap02\build-samp2_4-Desktop_Qt_6_5_0_MinGW_64_bit-Debug\CMakeFiles\samp2_4_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/samp2_4_autogen.dir/depend

