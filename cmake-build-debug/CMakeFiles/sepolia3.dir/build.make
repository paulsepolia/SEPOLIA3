# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/clion/2018_16/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion/2018_16/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pgg/pgg/git_projects/not_finished/sepolia3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pgg/pgg/git_projects/not_finished/sepolia3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sepolia3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sepolia3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sepolia3.dir/flags.make

CMakeFiles/sepolia3.dir/fake_main.cpp.o: CMakeFiles/sepolia3.dir/flags.make
CMakeFiles/sepolia3.dir/fake_main.cpp.o: ../fake_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pgg/pgg/git_projects/not_finished/sepolia3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sepolia3.dir/fake_main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sepolia3.dir/fake_main.cpp.o -c /home/pgg/pgg/git_projects/not_finished/sepolia3/fake_main.cpp

CMakeFiles/sepolia3.dir/fake_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sepolia3.dir/fake_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pgg/pgg/git_projects/not_finished/sepolia3/fake_main.cpp > CMakeFiles/sepolia3.dir/fake_main.cpp.i

CMakeFiles/sepolia3.dir/fake_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sepolia3.dir/fake_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pgg/pgg/git_projects/not_finished/sepolia3/fake_main.cpp -o CMakeFiles/sepolia3.dir/fake_main.cpp.s

CMakeFiles/sepolia3.dir/unit_tests/vector_dense/test_unit_algebra.cpp.o: CMakeFiles/sepolia3.dir/flags.make
CMakeFiles/sepolia3.dir/unit_tests/vector_dense/test_unit_algebra.cpp.o: ../unit_tests/vector_dense/test_unit_algebra.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pgg/pgg/git_projects/not_finished/sepolia3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sepolia3.dir/unit_tests/vector_dense/test_unit_algebra.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sepolia3.dir/unit_tests/vector_dense/test_unit_algebra.cpp.o -c /home/pgg/pgg/git_projects/not_finished/sepolia3/unit_tests/vector_dense/test_unit_algebra.cpp

CMakeFiles/sepolia3.dir/unit_tests/vector_dense/test_unit_algebra.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sepolia3.dir/unit_tests/vector_dense/test_unit_algebra.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pgg/pgg/git_projects/not_finished/sepolia3/unit_tests/vector_dense/test_unit_algebra.cpp > CMakeFiles/sepolia3.dir/unit_tests/vector_dense/test_unit_algebra.cpp.i

CMakeFiles/sepolia3.dir/unit_tests/vector_dense/test_unit_algebra.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sepolia3.dir/unit_tests/vector_dense/test_unit_algebra.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pgg/pgg/git_projects/not_finished/sepolia3/unit_tests/vector_dense/test_unit_algebra.cpp -o CMakeFiles/sepolia3.dir/unit_tests/vector_dense/test_unit_algebra.cpp.s

# Object files for target sepolia3
sepolia3_OBJECTS = \
"CMakeFiles/sepolia3.dir/fake_main.cpp.o" \
"CMakeFiles/sepolia3.dir/unit_tests/vector_dense/test_unit_algebra.cpp.o"

# External object files for target sepolia3
sepolia3_EXTERNAL_OBJECTS =

sepolia3: CMakeFiles/sepolia3.dir/fake_main.cpp.o
sepolia3: CMakeFiles/sepolia3.dir/unit_tests/vector_dense/test_unit_algebra.cpp.o
sepolia3: CMakeFiles/sepolia3.dir/build.make
sepolia3: CMakeFiles/sepolia3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pgg/pgg/git_projects/not_finished/sepolia3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable sepolia3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sepolia3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sepolia3.dir/build: sepolia3

.PHONY : CMakeFiles/sepolia3.dir/build

CMakeFiles/sepolia3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sepolia3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sepolia3.dir/clean

CMakeFiles/sepolia3.dir/depend:
	cd /home/pgg/pgg/git_projects/not_finished/sepolia3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pgg/pgg/git_projects/not_finished/sepolia3 /home/pgg/pgg/git_projects/not_finished/sepolia3 /home/pgg/pgg/git_projects/not_finished/sepolia3/cmake-build-debug /home/pgg/pgg/git_projects/not_finished/sepolia3/cmake-build-debug /home/pgg/pgg/git_projects/not_finished/sepolia3/cmake-build-debug/CMakeFiles/sepolia3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sepolia3.dir/depend

