# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /media/SharedFiles/Lab3/Lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/SharedFiles/Lab3/Lab3/build

# Include any dependencies generated for this target.
include CMakeFiles/memory_simulation.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/memory_simulation.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/memory_simulation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/memory_simulation.dir/flags.make

CMakeFiles/memory_simulation.dir/src/main.cpp.o: CMakeFiles/memory_simulation.dir/flags.make
CMakeFiles/memory_simulation.dir/src/main.cpp.o: /media/SharedFiles/Lab3/Lab3/src/main.cpp
CMakeFiles/memory_simulation.dir/src/main.cpp.o: CMakeFiles/memory_simulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/media/SharedFiles/Lab3/Lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/memory_simulation.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/memory_simulation.dir/src/main.cpp.o -MF CMakeFiles/memory_simulation.dir/src/main.cpp.o.d -o CMakeFiles/memory_simulation.dir/src/main.cpp.o -c /media/SharedFiles/Lab3/Lab3/src/main.cpp

CMakeFiles/memory_simulation.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/memory_simulation.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/SharedFiles/Lab3/Lab3/src/main.cpp > CMakeFiles/memory_simulation.dir/src/main.cpp.i

CMakeFiles/memory_simulation.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/memory_simulation.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/SharedFiles/Lab3/Lab3/src/main.cpp -o CMakeFiles/memory_simulation.dir/src/main.cpp.s

CMakeFiles/memory_simulation.dir/src/MemoryAllocator.cpp.o: CMakeFiles/memory_simulation.dir/flags.make
CMakeFiles/memory_simulation.dir/src/MemoryAllocator.cpp.o: /media/SharedFiles/Lab3/Lab3/src/MemoryAllocator.cpp
CMakeFiles/memory_simulation.dir/src/MemoryAllocator.cpp.o: CMakeFiles/memory_simulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/media/SharedFiles/Lab3/Lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/memory_simulation.dir/src/MemoryAllocator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/memory_simulation.dir/src/MemoryAllocator.cpp.o -MF CMakeFiles/memory_simulation.dir/src/MemoryAllocator.cpp.o.d -o CMakeFiles/memory_simulation.dir/src/MemoryAllocator.cpp.o -c /media/SharedFiles/Lab3/Lab3/src/MemoryAllocator.cpp

CMakeFiles/memory_simulation.dir/src/MemoryAllocator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/memory_simulation.dir/src/MemoryAllocator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/SharedFiles/Lab3/Lab3/src/MemoryAllocator.cpp > CMakeFiles/memory_simulation.dir/src/MemoryAllocator.cpp.i

CMakeFiles/memory_simulation.dir/src/MemoryAllocator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/memory_simulation.dir/src/MemoryAllocator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/SharedFiles/Lab3/Lab3/src/MemoryAllocator.cpp -o CMakeFiles/memory_simulation.dir/src/MemoryAllocator.cpp.s

CMakeFiles/memory_simulation.dir/src/Process.cpp.o: CMakeFiles/memory_simulation.dir/flags.make
CMakeFiles/memory_simulation.dir/src/Process.cpp.o: /media/SharedFiles/Lab3/Lab3/src/Process.cpp
CMakeFiles/memory_simulation.dir/src/Process.cpp.o: CMakeFiles/memory_simulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/media/SharedFiles/Lab3/Lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/memory_simulation.dir/src/Process.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/memory_simulation.dir/src/Process.cpp.o -MF CMakeFiles/memory_simulation.dir/src/Process.cpp.o.d -o CMakeFiles/memory_simulation.dir/src/Process.cpp.o -c /media/SharedFiles/Lab3/Lab3/src/Process.cpp

CMakeFiles/memory_simulation.dir/src/Process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/memory_simulation.dir/src/Process.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/SharedFiles/Lab3/Lab3/src/Process.cpp > CMakeFiles/memory_simulation.dir/src/Process.cpp.i

CMakeFiles/memory_simulation.dir/src/Process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/memory_simulation.dir/src/Process.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/SharedFiles/Lab3/Lab3/src/Process.cpp -o CMakeFiles/memory_simulation.dir/src/Process.cpp.s

# Object files for target memory_simulation
memory_simulation_OBJECTS = \
"CMakeFiles/memory_simulation.dir/src/main.cpp.o" \
"CMakeFiles/memory_simulation.dir/src/MemoryAllocator.cpp.o" \
"CMakeFiles/memory_simulation.dir/src/Process.cpp.o"

# External object files for target memory_simulation
memory_simulation_EXTERNAL_OBJECTS =

memory_simulation: CMakeFiles/memory_simulation.dir/src/main.cpp.o
memory_simulation: CMakeFiles/memory_simulation.dir/src/MemoryAllocator.cpp.o
memory_simulation: CMakeFiles/memory_simulation.dir/src/Process.cpp.o
memory_simulation: CMakeFiles/memory_simulation.dir/build.make
memory_simulation: CMakeFiles/memory_simulation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/media/SharedFiles/Lab3/Lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable memory_simulation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/memory_simulation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/memory_simulation.dir/build: memory_simulation
.PHONY : CMakeFiles/memory_simulation.dir/build

CMakeFiles/memory_simulation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/memory_simulation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/memory_simulation.dir/clean

CMakeFiles/memory_simulation.dir/depend:
	cd /media/SharedFiles/Lab3/Lab3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/SharedFiles/Lab3/Lab3 /media/SharedFiles/Lab3/Lab3 /media/SharedFiles/Lab3/Lab3/build /media/SharedFiles/Lab3/Lab3/build /media/SharedFiles/Lab3/Lab3/build/CMakeFiles/memory_simulation.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/memory_simulation.dir/depend
