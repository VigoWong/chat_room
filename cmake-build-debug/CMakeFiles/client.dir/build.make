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
include CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.dir/flags.make

CMakeFiles/client.dir/src/usr/admin.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/usr/admin.cpp.o: ../src/usr/admin.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client.dir/src/usr/admin.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/usr/admin.cpp.o -c /Users/huhawel/Documents/todo_list/wechat_room/src/usr/admin.cpp

CMakeFiles/client.dir/src/usr/admin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/usr/admin.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/huhawel/Documents/todo_list/wechat_room/src/usr/admin.cpp > CMakeFiles/client.dir/src/usr/admin.cpp.i

CMakeFiles/client.dir/src/usr/admin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/usr/admin.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/huhawel/Documents/todo_list/wechat_room/src/usr/admin.cpp -o CMakeFiles/client.dir/src/usr/admin.cpp.s

CMakeFiles/client.dir/src/usr/user.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/usr/user.cpp.o: ../src/usr/user.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/client.dir/src/usr/user.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/usr/user.cpp.o -c /Users/huhawel/Documents/todo_list/wechat_room/src/usr/user.cpp

CMakeFiles/client.dir/src/usr/user.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/usr/user.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/huhawel/Documents/todo_list/wechat_room/src/usr/user.cpp > CMakeFiles/client.dir/src/usr/user.cpp.i

CMakeFiles/client.dir/src/usr/user.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/usr/user.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/huhawel/Documents/todo_list/wechat_room/src/usr/user.cpp -o CMakeFiles/client.dir/src/usr/user.cpp.s

CMakeFiles/client.dir/src/client.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/client.cpp.o: ../src/client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/client.dir/src/client.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/client.cpp.o -c /Users/huhawel/Documents/todo_list/wechat_room/src/client.cpp

CMakeFiles/client.dir/src/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/client.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/huhawel/Documents/todo_list/wechat_room/src/client.cpp > CMakeFiles/client.dir/src/client.cpp.i

CMakeFiles/client.dir/src/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/client.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/huhawel/Documents/todo_list/wechat_room/src/client.cpp -o CMakeFiles/client.dir/src/client.cpp.s

CMakeFiles/client.dir/util/util.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/util/util.cpp.o: ../util/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/client.dir/util/util.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/util/util.cpp.o -c /Users/huhawel/Documents/todo_list/wechat_room/util/util.cpp

CMakeFiles/client.dir/util/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/util/util.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/huhawel/Documents/todo_list/wechat_room/util/util.cpp > CMakeFiles/client.dir/util/util.cpp.i

CMakeFiles/client.dir/util/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/util/util.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/huhawel/Documents/todo_list/wechat_room/util/util.cpp -o CMakeFiles/client.dir/util/util.cpp.s

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/src/usr/admin.cpp.o" \
"CMakeFiles/client.dir/src/usr/user.cpp.o" \
"CMakeFiles/client.dir/src/client.cpp.o" \
"CMakeFiles/client.dir/util/util.cpp.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

../built/client: CMakeFiles/client.dir/src/usr/admin.cpp.o
../built/client: CMakeFiles/client.dir/src/usr/user.cpp.o
../built/client: CMakeFiles/client.dir/src/client.cpp.o
../built/client: CMakeFiles/client.dir/util/util.cpp.o
../built/client: CMakeFiles/client.dir/build.make
../built/client: /usr/local/lib/libglog.0.4.0.dylib
../built/client: /usr/local/lib/libgflags.2.2.2.dylib
../built/client: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ../built/client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.dir/build: ../built/client

.PHONY : CMakeFiles/client.dir/build

CMakeFiles/client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client.dir/clean

CMakeFiles/client.dir/depend:
	cd /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/huhawel/Documents/todo_list/wechat_room /Users/huhawel/Documents/todo_list/wechat_room /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug /Users/huhawel/Documents/todo_list/wechat_room/cmake-build-debug/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client.dir/depend

