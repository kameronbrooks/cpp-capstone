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
CMAKE_SOURCE_DIR = "/home/kameron/Documents/code/cpp capstone/cpp-capstone"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/kameron/Documents/code/cpp capstone/cpp-capstone/build"

# Include any dependencies generated for this target.
include CMakeFiles/chess.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chess.dir/flags.make

CMakeFiles/chess.dir/src/main.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chess.dir/src/main.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/main.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/main.cpp"

CMakeFiles/chess.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/main.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/main.cpp" > CMakeFiles/chess.dir/src/main.cpp.i

CMakeFiles/chess.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/main.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/main.cpp" -o CMakeFiles/chess.dir/src/main.cpp.s

# Object files for target chess
chess_OBJECTS = \
"CMakeFiles/chess.dir/src/main.cpp.o"

# External object files for target chess
chess_EXTERNAL_OBJECTS =

chess: CMakeFiles/chess.dir/src/main.cpp.o
chess: CMakeFiles/chess.dir/build.make
chess: CMakeFiles/chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable chess"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chess.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chess.dir/build: chess

.PHONY : CMakeFiles/chess.dir/build

CMakeFiles/chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chess.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chess.dir/clean

CMakeFiles/chess.dir/depend:
	cd "/home/kameron/Documents/code/cpp capstone/cpp-capstone/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/kameron/Documents/code/cpp capstone/cpp-capstone" "/home/kameron/Documents/code/cpp capstone/cpp-capstone" "/home/kameron/Documents/code/cpp capstone/cpp-capstone/build" "/home/kameron/Documents/code/cpp capstone/cpp-capstone/build" "/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles/chess.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/chess.dir/depend

