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
CMAKE_SOURCE_DIR = /mnt/c/Users/hxm/CLionProjects/proj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/hxm/CLionProjects/proj/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hospital.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hospital.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hospital.dir/flags.make

CMakeFiles/hospital.dir/Hospital.cpp.o: CMakeFiles/hospital.dir/flags.make
CMakeFiles/hospital.dir/Hospital.cpp.o: ../Hospital.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/hxm/CLionProjects/proj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hospital.dir/Hospital.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hospital.dir/Hospital.cpp.o -c /mnt/c/Users/hxm/CLionProjects/proj/Hospital.cpp

CMakeFiles/hospital.dir/Hospital.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hospital.dir/Hospital.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/hxm/CLionProjects/proj/Hospital.cpp > CMakeFiles/hospital.dir/Hospital.cpp.i

CMakeFiles/hospital.dir/Hospital.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hospital.dir/Hospital.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/hxm/CLionProjects/proj/Hospital.cpp -o CMakeFiles/hospital.dir/Hospital.cpp.s

# Object files for target hospital
hospital_OBJECTS = \
"CMakeFiles/hospital.dir/Hospital.cpp.o"

# External object files for target hospital
hospital_EXTERNAL_OBJECTS =

hospital: CMakeFiles/hospital.dir/Hospital.cpp.o
hospital: CMakeFiles/hospital.dir/build.make
hospital: CMakeFiles/hospital.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/hxm/CLionProjects/proj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hospital"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hospital.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hospital.dir/build: hospital

.PHONY : CMakeFiles/hospital.dir/build

CMakeFiles/hospital.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hospital.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hospital.dir/clean

CMakeFiles/hospital.dir/depend:
	cd /mnt/c/Users/hxm/CLionProjects/proj/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/hxm/CLionProjects/proj /mnt/c/Users/hxm/CLionProjects/proj /mnt/c/Users/hxm/CLionProjects/proj/cmake-build-debug /mnt/c/Users/hxm/CLionProjects/proj/cmake-build-debug /mnt/c/Users/hxm/CLionProjects/proj/cmake-build-debug/CMakeFiles/hospital.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hospital.dir/depend
