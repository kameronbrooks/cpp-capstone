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

CMakeFiles/chess.dir/src/ai.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/ai.cpp.o: ../src/ai.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chess.dir/src/ai.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/ai.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/ai.cpp"

CMakeFiles/chess.dir/src/ai.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/ai.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/ai.cpp" > CMakeFiles/chess.dir/src/ai.cpp.i

CMakeFiles/chess.dir/src/ai.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/ai.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/ai.cpp" -o CMakeFiles/chess.dir/src/ai.cpp.s

CMakeFiles/chess.dir/src/board.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/board.cpp.o: ../src/board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/chess.dir/src/board.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/board.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/board.cpp"

CMakeFiles/chess.dir/src/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/board.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/board.cpp" > CMakeFiles/chess.dir/src/board.cpp.i

CMakeFiles/chess.dir/src/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/board.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/board.cpp" -o CMakeFiles/chess.dir/src/board.cpp.s

CMakeFiles/chess.dir/src/cell.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/cell.cpp.o: ../src/cell.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/chess.dir/src/cell.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/cell.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/cell.cpp"

CMakeFiles/chess.dir/src/cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/cell.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/cell.cpp" > CMakeFiles/chess.dir/src/cell.cpp.i

CMakeFiles/chess.dir/src/cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/cell.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/cell.cpp" -o CMakeFiles/chess.dir/src/cell.cpp.s

CMakeFiles/chess.dir/src/color.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/color.cpp.o: ../src/color.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/chess.dir/src/color.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/color.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/color.cpp"

CMakeFiles/chess.dir/src/color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/color.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/color.cpp" > CMakeFiles/chess.dir/src/color.cpp.i

CMakeFiles/chess.dir/src/color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/color.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/color.cpp" -o CMakeFiles/chess.dir/src/color.cpp.s

CMakeFiles/chess.dir/src/game.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/chess.dir/src/game.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/game.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/game.cpp"

CMakeFiles/chess.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/game.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/game.cpp" > CMakeFiles/chess.dir/src/game.cpp.i

CMakeFiles/chess.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/game.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/game.cpp" -o CMakeFiles/chess.dir/src/game.cpp.s

CMakeFiles/chess.dir/src/game_state.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/game_state.cpp.o: ../src/game_state.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/chess.dir/src/game_state.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/game_state.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/game_state.cpp"

CMakeFiles/chess.dir/src/game_state.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/game_state.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/game_state.cpp" > CMakeFiles/chess.dir/src/game_state.cpp.i

CMakeFiles/chess.dir/src/game_state.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/game_state.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/game_state.cpp" -o CMakeFiles/chess.dir/src/game_state.cpp.s

CMakeFiles/chess.dir/src/input_controller.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/input_controller.cpp.o: ../src/input_controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/chess.dir/src/input_controller.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/input_controller.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/input_controller.cpp"

CMakeFiles/chess.dir/src/input_controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/input_controller.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/input_controller.cpp" > CMakeFiles/chess.dir/src/input_controller.cpp.i

CMakeFiles/chess.dir/src/input_controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/input_controller.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/input_controller.cpp" -o CMakeFiles/chess.dir/src/input_controller.cpp.s

CMakeFiles/chess.dir/src/main.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/chess.dir/src/main.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/main.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/main.cpp"

CMakeFiles/chess.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/main.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/main.cpp" > CMakeFiles/chess.dir/src/main.cpp.i

CMakeFiles/chess.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/main.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/main.cpp" -o CMakeFiles/chess.dir/src/main.cpp.s

CMakeFiles/chess.dir/src/piece.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/piece.cpp.o: ../src/piece.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/chess.dir/src/piece.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/piece.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece.cpp"

CMakeFiles/chess.dir/src/piece.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/piece.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece.cpp" > CMakeFiles/chess.dir/src/piece.cpp.i

CMakeFiles/chess.dir/src/piece.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/piece.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece.cpp" -o CMakeFiles/chess.dir/src/piece.cpp.s

CMakeFiles/chess.dir/src/piece_bishop.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/piece_bishop.cpp.o: ../src/piece_bishop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/chess.dir/src/piece_bishop.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/piece_bishop.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_bishop.cpp"

CMakeFiles/chess.dir/src/piece_bishop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/piece_bishop.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_bishop.cpp" > CMakeFiles/chess.dir/src/piece_bishop.cpp.i

CMakeFiles/chess.dir/src/piece_bishop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/piece_bishop.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_bishop.cpp" -o CMakeFiles/chess.dir/src/piece_bishop.cpp.s

CMakeFiles/chess.dir/src/piece_knight.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/piece_knight.cpp.o: ../src/piece_knight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/chess.dir/src/piece_knight.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/piece_knight.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_knight.cpp"

CMakeFiles/chess.dir/src/piece_knight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/piece_knight.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_knight.cpp" > CMakeFiles/chess.dir/src/piece_knight.cpp.i

CMakeFiles/chess.dir/src/piece_knight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/piece_knight.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_knight.cpp" -o CMakeFiles/chess.dir/src/piece_knight.cpp.s

CMakeFiles/chess.dir/src/piece_pawn.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/piece_pawn.cpp.o: ../src/piece_pawn.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/chess.dir/src/piece_pawn.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/piece_pawn.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_pawn.cpp"

CMakeFiles/chess.dir/src/piece_pawn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/piece_pawn.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_pawn.cpp" > CMakeFiles/chess.dir/src/piece_pawn.cpp.i

CMakeFiles/chess.dir/src/piece_pawn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/piece_pawn.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_pawn.cpp" -o CMakeFiles/chess.dir/src/piece_pawn.cpp.s

CMakeFiles/chess.dir/src/piece_queen.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/piece_queen.cpp.o: ../src/piece_queen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/chess.dir/src/piece_queen.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/piece_queen.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_queen.cpp"

CMakeFiles/chess.dir/src/piece_queen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/piece_queen.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_queen.cpp" > CMakeFiles/chess.dir/src/piece_queen.cpp.i

CMakeFiles/chess.dir/src/piece_queen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/piece_queen.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_queen.cpp" -o CMakeFiles/chess.dir/src/piece_queen.cpp.s

CMakeFiles/chess.dir/src/piece_rook.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/piece_rook.cpp.o: ../src/piece_rook.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/chess.dir/src/piece_rook.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/piece_rook.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_rook.cpp"

CMakeFiles/chess.dir/src/piece_rook.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/piece_rook.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_rook.cpp" > CMakeFiles/chess.dir/src/piece_rook.cpp.i

CMakeFiles/chess.dir/src/piece_rook.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/piece_rook.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_rook.cpp" -o CMakeFiles/chess.dir/src/piece_rook.cpp.s

CMakeFiles/chess.dir/src/piece_type.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/piece_type.cpp.o: ../src/piece_type.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/chess.dir/src/piece_type.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/piece_type.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_type.cpp"

CMakeFiles/chess.dir/src/piece_type.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/piece_type.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_type.cpp" > CMakeFiles/chess.dir/src/piece_type.cpp.i

CMakeFiles/chess.dir/src/piece_type.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/piece_type.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/piece_type.cpp" -o CMakeFiles/chess.dir/src/piece_type.cpp.s

CMakeFiles/chess.dir/src/renderer.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/renderer.cpp.o: ../src/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/chess.dir/src/renderer.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/renderer.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/renderer.cpp"

CMakeFiles/chess.dir/src/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/renderer.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/renderer.cpp" > CMakeFiles/chess.dir/src/renderer.cpp.i

CMakeFiles/chess.dir/src/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/renderer.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/renderer.cpp" -o CMakeFiles/chess.dir/src/renderer.cpp.s

CMakeFiles/chess.dir/src/sprite.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/sprite.cpp.o: ../src/sprite.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/chess.dir/src/sprite.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/sprite.cpp.o -c "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/sprite.cpp"

CMakeFiles/chess.dir/src/sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/sprite.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/sprite.cpp" > CMakeFiles/chess.dir/src/sprite.cpp.i

CMakeFiles/chess.dir/src/sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/sprite.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kameron/Documents/code/cpp capstone/cpp-capstone/src/sprite.cpp" -o CMakeFiles/chess.dir/src/sprite.cpp.s

# Object files for target chess
chess_OBJECTS = \
"CMakeFiles/chess.dir/src/ai.cpp.o" \
"CMakeFiles/chess.dir/src/board.cpp.o" \
"CMakeFiles/chess.dir/src/cell.cpp.o" \
"CMakeFiles/chess.dir/src/color.cpp.o" \
"CMakeFiles/chess.dir/src/game.cpp.o" \
"CMakeFiles/chess.dir/src/game_state.cpp.o" \
"CMakeFiles/chess.dir/src/input_controller.cpp.o" \
"CMakeFiles/chess.dir/src/main.cpp.o" \
"CMakeFiles/chess.dir/src/piece.cpp.o" \
"CMakeFiles/chess.dir/src/piece_bishop.cpp.o" \
"CMakeFiles/chess.dir/src/piece_knight.cpp.o" \
"CMakeFiles/chess.dir/src/piece_pawn.cpp.o" \
"CMakeFiles/chess.dir/src/piece_queen.cpp.o" \
"CMakeFiles/chess.dir/src/piece_rook.cpp.o" \
"CMakeFiles/chess.dir/src/piece_type.cpp.o" \
"CMakeFiles/chess.dir/src/renderer.cpp.o" \
"CMakeFiles/chess.dir/src/sprite.cpp.o"

# External object files for target chess
chess_EXTERNAL_OBJECTS =

chess: CMakeFiles/chess.dir/src/ai.cpp.o
chess: CMakeFiles/chess.dir/src/board.cpp.o
chess: CMakeFiles/chess.dir/src/cell.cpp.o
chess: CMakeFiles/chess.dir/src/color.cpp.o
chess: CMakeFiles/chess.dir/src/game.cpp.o
chess: CMakeFiles/chess.dir/src/game_state.cpp.o
chess: CMakeFiles/chess.dir/src/input_controller.cpp.o
chess: CMakeFiles/chess.dir/src/main.cpp.o
chess: CMakeFiles/chess.dir/src/piece.cpp.o
chess: CMakeFiles/chess.dir/src/piece_bishop.cpp.o
chess: CMakeFiles/chess.dir/src/piece_knight.cpp.o
chess: CMakeFiles/chess.dir/src/piece_pawn.cpp.o
chess: CMakeFiles/chess.dir/src/piece_queen.cpp.o
chess: CMakeFiles/chess.dir/src/piece_rook.cpp.o
chess: CMakeFiles/chess.dir/src/piece_type.cpp.o
chess: CMakeFiles/chess.dir/src/renderer.cpp.o
chess: CMakeFiles/chess.dir/src/sprite.cpp.o
chess: CMakeFiles/chess.dir/build.make
chess: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
chess: CMakeFiles/chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/kameron/Documents/code/cpp capstone/cpp-capstone/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX executable chess"
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

