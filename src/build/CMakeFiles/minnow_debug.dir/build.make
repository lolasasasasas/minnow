# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lfynb/桌面/pjt/minnow/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lfynb/桌面/pjt/minnow/src/build

# Include any dependencies generated for this target.
include CMakeFiles/minnow_debug.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/minnow_debug.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/minnow_debug.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minnow_debug.dir/flags.make

CMakeFiles/minnow_debug.dir/byte_stream.o: CMakeFiles/minnow_debug.dir/flags.make
CMakeFiles/minnow_debug.dir/byte_stream.o: /home/lfynb/桌面/pjt/minnow/src/byte_stream.cc
CMakeFiles/minnow_debug.dir/byte_stream.o: CMakeFiles/minnow_debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/lfynb/桌面/pjt/minnow/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/minnow_debug.dir/byte_stream.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/minnow_debug.dir/byte_stream.o -MF CMakeFiles/minnow_debug.dir/byte_stream.o.d -o CMakeFiles/minnow_debug.dir/byte_stream.o -c /home/lfynb/桌面/pjt/minnow/src/byte_stream.cc

CMakeFiles/minnow_debug.dir/byte_stream.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/minnow_debug.dir/byte_stream.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lfynb/桌面/pjt/minnow/src/byte_stream.cc > CMakeFiles/minnow_debug.dir/byte_stream.i

CMakeFiles/minnow_debug.dir/byte_stream.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/minnow_debug.dir/byte_stream.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lfynb/桌面/pjt/minnow/src/byte_stream.cc -o CMakeFiles/minnow_debug.dir/byte_stream.s

CMakeFiles/minnow_debug.dir/byte_stream_helpers.o: CMakeFiles/minnow_debug.dir/flags.make
CMakeFiles/minnow_debug.dir/byte_stream_helpers.o: /home/lfynb/桌面/pjt/minnow/src/byte_stream_helpers.cc
CMakeFiles/minnow_debug.dir/byte_stream_helpers.o: CMakeFiles/minnow_debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/lfynb/桌面/pjt/minnow/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/minnow_debug.dir/byte_stream_helpers.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/minnow_debug.dir/byte_stream_helpers.o -MF CMakeFiles/minnow_debug.dir/byte_stream_helpers.o.d -o CMakeFiles/minnow_debug.dir/byte_stream_helpers.o -c /home/lfynb/桌面/pjt/minnow/src/byte_stream_helpers.cc

CMakeFiles/minnow_debug.dir/byte_stream_helpers.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/minnow_debug.dir/byte_stream_helpers.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lfynb/桌面/pjt/minnow/src/byte_stream_helpers.cc > CMakeFiles/minnow_debug.dir/byte_stream_helpers.i

CMakeFiles/minnow_debug.dir/byte_stream_helpers.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/minnow_debug.dir/byte_stream_helpers.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lfynb/桌面/pjt/minnow/src/byte_stream_helpers.cc -o CMakeFiles/minnow_debug.dir/byte_stream_helpers.s

CMakeFiles/minnow_debug.dir/reassembler.o: CMakeFiles/minnow_debug.dir/flags.make
CMakeFiles/minnow_debug.dir/reassembler.o: /home/lfynb/桌面/pjt/minnow/src/reassembler.cc
CMakeFiles/minnow_debug.dir/reassembler.o: CMakeFiles/minnow_debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/lfynb/桌面/pjt/minnow/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/minnow_debug.dir/reassembler.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/minnow_debug.dir/reassembler.o -MF CMakeFiles/minnow_debug.dir/reassembler.o.d -o CMakeFiles/minnow_debug.dir/reassembler.o -c /home/lfynb/桌面/pjt/minnow/src/reassembler.cc

CMakeFiles/minnow_debug.dir/reassembler.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/minnow_debug.dir/reassembler.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lfynb/桌面/pjt/minnow/src/reassembler.cc > CMakeFiles/minnow_debug.dir/reassembler.i

CMakeFiles/minnow_debug.dir/reassembler.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/minnow_debug.dir/reassembler.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lfynb/桌面/pjt/minnow/src/reassembler.cc -o CMakeFiles/minnow_debug.dir/reassembler.s

# Object files for target minnow_debug
minnow_debug_OBJECTS = \
"CMakeFiles/minnow_debug.dir/byte_stream.o" \
"CMakeFiles/minnow_debug.dir/byte_stream_helpers.o" \
"CMakeFiles/minnow_debug.dir/reassembler.o"

# External object files for target minnow_debug
minnow_debug_EXTERNAL_OBJECTS =

libminnow_debug.a: CMakeFiles/minnow_debug.dir/byte_stream.o
libminnow_debug.a: CMakeFiles/minnow_debug.dir/byte_stream_helpers.o
libminnow_debug.a: CMakeFiles/minnow_debug.dir/reassembler.o
libminnow_debug.a: CMakeFiles/minnow_debug.dir/build.make
libminnow_debug.a: CMakeFiles/minnow_debug.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/lfynb/桌面/pjt/minnow/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libminnow_debug.a"
	$(CMAKE_COMMAND) -P CMakeFiles/minnow_debug.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minnow_debug.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minnow_debug.dir/build: libminnow_debug.a
.PHONY : CMakeFiles/minnow_debug.dir/build

CMakeFiles/minnow_debug.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minnow_debug.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minnow_debug.dir/clean

CMakeFiles/minnow_debug.dir/depend:
	cd /home/lfynb/桌面/pjt/minnow/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lfynb/桌面/pjt/minnow/src /home/lfynb/桌面/pjt/minnow/src /home/lfynb/桌面/pjt/minnow/src/build /home/lfynb/桌面/pjt/minnow/src/build /home/lfynb/桌面/pjt/minnow/src/build/CMakeFiles/minnow_debug.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/minnow_debug.dir/depend

