# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\project\clion\communitysystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\project\clion\communitysystem\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/communitysystem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/communitysystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/communitysystem.dir/flags.make

CMakeFiles/communitysystem.dir/main.c.obj: CMakeFiles/communitysystem.dir/flags.make
CMakeFiles/communitysystem.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\project\clion\communitysystem\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/communitysystem.dir/main.c.obj"
	D:\tool\MinGw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\communitysystem.dir\main.c.obj   -c D:\project\clion\communitysystem\main.c

CMakeFiles/communitysystem.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/communitysystem.dir/main.c.i"
	D:\tool\MinGw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\project\clion\communitysystem\main.c > CMakeFiles\communitysystem.dir\main.c.i

CMakeFiles/communitysystem.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/communitysystem.dir/main.c.s"
	D:\tool\MinGw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\project\clion\communitysystem\main.c -o CMakeFiles\communitysystem.dir\main.c.s

# Object files for target communitysystem
communitysystem_OBJECTS = \
"CMakeFiles/communitysystem.dir/main.c.obj"

# External object files for target communitysystem
communitysystem_EXTERNAL_OBJECTS =

communitysystem.exe: CMakeFiles/communitysystem.dir/main.c.obj
communitysystem.exe: CMakeFiles/communitysystem.dir/build.make
communitysystem.exe: CMakeFiles/communitysystem.dir/linklibs.rsp
communitysystem.exe: CMakeFiles/communitysystem.dir/objects1.rsp
communitysystem.exe: CMakeFiles/communitysystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\project\clion\communitysystem\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable communitysystem.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\communitysystem.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/communitysystem.dir/build: communitysystem.exe

.PHONY : CMakeFiles/communitysystem.dir/build

CMakeFiles/communitysystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\communitysystem.dir\cmake_clean.cmake
.PHONY : CMakeFiles/communitysystem.dir/clean

CMakeFiles/communitysystem.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\project\clion\communitysystem D:\project\clion\communitysystem D:\project\clion\communitysystem\cmake-build-debug D:\project\clion\communitysystem\cmake-build-debug D:\project\clion\communitysystem\cmake-build-debug\CMakeFiles\communitysystem.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/communitysystem.dir/depend

