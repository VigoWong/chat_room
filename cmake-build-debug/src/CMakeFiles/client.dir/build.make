# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/huhawel/Documents/todo_list/wechat_room

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/client.dir/flags.make

src/CMakeFiles/client.dir/util.cpp.o: src/CMakeFiles/client.dir/flags.make
src/CMakeFiles/client.dir/util.cpp.o: ../src/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/client.dir/util.cpp.o"
	cd /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/util.cpp.o -c /Users/huhawel/Documents/todo_list/wechat_room/src/util.cpp

src/CMakeFiles/client.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/util.cpp.i"
	cd /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/huhawel/Documents/todo_list/wechat_room/src/util.cpp > CMakeFiles/client.dir/util.cpp.i

src/CMakeFiles/client.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/util.cpp.s"
	cd /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/huhawel/Documents/todo_list/wechat_room/src/util.cpp -o CMakeFiles/client.dir/util.cpp.s

src/CMakeFiles/client.dir/usr/user.cpp.o: src/CMakeFiles/client.dir/flags.make
src/CMakeFiles/client.dir/usr/user.cpp.o: ../src/usr/user.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/client.dir/usr/user.cpp.o"
	cd /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/usr/user.cpp.o -c /Users/huhawel/Documents/todo_list/wechat_room/src/usr/user.cpp

src/CMakeFiles/client.dir/usr/user.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/usr/user.cpp.i"
	cd /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/huhawel/Documents/todo_list/wechat_room/src/usr/user.cpp > CMakeFiles/client.dir/usr/user.cpp.i

src/CMakeFiles/client.dir/usr/user.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/usr/user.cpp.s"
	cd /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/huhawel/Documents/todo_list/wechat_room/src/usr/user.cpp -o CMakeFiles/client.dir/usr/user.cpp.s

src/CMakeFiles/client.dir/client.cpp.o: src/CMakeFiles/client.dir/flags.make
src/CMakeFiles/client.dir/client.cpp.o: ../src/client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/client.dir/client.cpp.o"
	cd /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/client.cpp.o -c /Users/huhawel/Documents/todo_list/wechat_room/src/client.cpp

src/CMakeFiles/client.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/client.cpp.i"
	cd /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/huhawel/Documents/todo_list/wechat_room/src/client.cpp > CMakeFiles/client.dir/client.cpp.i

src/CMakeFiles/client.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/client.cpp.s"
	cd /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/huhawel/Documents/todo_list/wechat_room/src/client.cpp -o CMakeFiles/client.dir/client.cpp.s

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/util.cpp.o" \
"CMakeFiles/client.dir/usr/user.cpp.o" \
"CMakeFiles/client.dir/client.cpp.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

../built/client: src/CMakeFiles/client.dir/util.cpp.o
../built/client: src/CMakeFiles/client.dir/usr/user.cpp.o
../built/client: src/CMakeFiles/client.dir/client.cpp.o
../built/client: src/CMakeFiles/client.dir/build.make
../built/client: /usr/local/lib/libglog.0.4.0.dylib
../built/client: /usr/local/lib/libgflags.2.2.2.dylib
../built/client: src/CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../built/client"
	cd /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/client.dir/build: ../built/client

.PHONY : src/CMakeFiles/client.dir/build

src/CMakeFiles/client.dir/clean:
	cd /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/client.dir/clean

src/CMakeFiles/client.dir/depend:
	cd /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/huhawel/Documents/todo_list/wechat_room /Users/huhawel/Documents/todo_list/wechat_room/src /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/src /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/src/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/client.dir/depend

