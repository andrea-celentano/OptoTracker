# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/build

# Include any dependencies generated for this target.
include CMakeFiles/TestCommon.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestCommon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestCommon.dir/flags.make

CMakeFiles/TestCommon.dir/TestCommon.cpp.o: CMakeFiles/TestCommon.dir/flags.make
CMakeFiles/TestCommon.dir/TestCommon.cpp.o: ../TestCommon.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TestCommon.dir/TestCommon.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TestCommon.dir/TestCommon.cpp.o -c /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/TestCommon.cpp

CMakeFiles/TestCommon.dir/TestCommon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestCommon.dir/TestCommon.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/TestCommon.cpp > CMakeFiles/TestCommon.dir/TestCommon.cpp.i

CMakeFiles/TestCommon.dir/TestCommon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestCommon.dir/TestCommon.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/TestCommon.cpp -o CMakeFiles/TestCommon.dir/TestCommon.cpp.s

CMakeFiles/TestCommon.dir/TestCommon.cpp.o.requires:
.PHONY : CMakeFiles/TestCommon.dir/TestCommon.cpp.o.requires

CMakeFiles/TestCommon.dir/TestCommon.cpp.o.provides: CMakeFiles/TestCommon.dir/TestCommon.cpp.o.requires
	$(MAKE) -f CMakeFiles/TestCommon.dir/build.make CMakeFiles/TestCommon.dir/TestCommon.cpp.o.provides.build
.PHONY : CMakeFiles/TestCommon.dir/TestCommon.cpp.o.provides

CMakeFiles/TestCommon.dir/TestCommon.cpp.o.provides.build: CMakeFiles/TestCommon.dir/TestCommon.cpp.o

CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.o: CMakeFiles/TestCommon.dir/flags.make
CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.o: ../src/TDetectorUtils.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.o -c /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/TDetectorUtils.cc

CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/TDetectorUtils.cc > CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.i

CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/TDetectorUtils.cc -o CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.s

CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.o.requires:
.PHONY : CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.o.requires

CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.o.provides: CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.o.requires
	$(MAKE) -f CMakeFiles/TestCommon.dir/build.make CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.o.provides.build
.PHONY : CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.o.provides

CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.o.provides.build: CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.o

CMakeFiles/TestCommon.dir/src/TEvent.cc.o: CMakeFiles/TestCommon.dir/flags.make
CMakeFiles/TestCommon.dir/src/TEvent.cc.o: ../src/TEvent.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TestCommon.dir/src/TEvent.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TestCommon.dir/src/TEvent.cc.o -c /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/TEvent.cc

CMakeFiles/TestCommon.dir/src/TEvent.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestCommon.dir/src/TEvent.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/TEvent.cc > CMakeFiles/TestCommon.dir/src/TEvent.cc.i

CMakeFiles/TestCommon.dir/src/TEvent.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestCommon.dir/src/TEvent.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/TEvent.cc -o CMakeFiles/TestCommon.dir/src/TEvent.cc.s

CMakeFiles/TestCommon.dir/src/TEvent.cc.o.requires:
.PHONY : CMakeFiles/TestCommon.dir/src/TEvent.cc.o.requires

CMakeFiles/TestCommon.dir/src/TEvent.cc.o.provides: CMakeFiles/TestCommon.dir/src/TEvent.cc.o.requires
	$(MAKE) -f CMakeFiles/TestCommon.dir/build.make CMakeFiles/TestCommon.dir/src/TEvent.cc.o.provides.build
.PHONY : CMakeFiles/TestCommon.dir/src/TEvent.cc.o.provides

CMakeFiles/TestCommon.dir/src/TEvent.cc.o.provides.build: CMakeFiles/TestCommon.dir/src/TEvent.cc.o

CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.o: CMakeFiles/TestCommon.dir/flags.make
CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.o: ../src/TXMLHandler.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.o -c /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/TXMLHandler.cc

CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/TXMLHandler.cc > CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.i

CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/TXMLHandler.cc -o CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.s

CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.o.requires:
.PHONY : CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.o.requires

CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.o.provides: CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.o.requires
	$(MAKE) -f CMakeFiles/TestCommon.dir/build.make CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.o.provides.build
.PHONY : CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.o.provides

CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.o.provides.build: CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.o

CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.o: CMakeFiles/TestCommon.dir/flags.make
CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.o: ../src/RealSetupHandler.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.o -c /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/RealSetupHandler.cc

CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/RealSetupHandler.cc > CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.i

CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/RealSetupHandler.cc -o CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.s

CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.o.requires:
.PHONY : CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.o.requires

CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.o.provides: CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.o.requires
	$(MAKE) -f CMakeFiles/TestCommon.dir/build.make CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.o.provides.build
.PHONY : CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.o.provides

CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.o.provides.build: CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.o

CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.o: CMakeFiles/TestCommon.dir/flags.make
CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.o: ../src/TDetectorLight.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.o -c /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/TDetectorLight.cc

CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/TDetectorLight.cc > CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.i

CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/TDetectorLight.cc -o CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.s

CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.o.requires:
.PHONY : CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.o.requires

CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.o.provides: CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.o.requires
	$(MAKE) -f CMakeFiles/TestCommon.dir/build.make CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.o.provides.build
.PHONY : CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.o.provides

CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.o.provides.build: CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.o

CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.o: CMakeFiles/TestCommon.dir/flags.make
CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.o: ../src/TNamedContainer.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.o -c /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/TNamedContainer.cc

CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/TNamedContainer.cc > CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.i

CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/src/TNamedContainer.cc -o CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.s

CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.o.requires:
.PHONY : CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.o.requires

CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.o.provides: CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.o.requires
	$(MAKE) -f CMakeFiles/TestCommon.dir/build.make CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.o.provides.build
.PHONY : CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.o.provides

CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.o.provides.build: CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.o

# Object files for target TestCommon
TestCommon_OBJECTS = \
"CMakeFiles/TestCommon.dir/TestCommon.cpp.o" \
"CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.o" \
"CMakeFiles/TestCommon.dir/src/TEvent.cc.o" \
"CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.o" \
"CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.o" \
"CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.o" \
"CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.o"

# External object files for target TestCommon
TestCommon_EXTERNAL_OBJECTS =

TestCommon: CMakeFiles/TestCommon.dir/TestCommon.cpp.o
TestCommon: CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.o
TestCommon: CMakeFiles/TestCommon.dir/src/TEvent.cc.o
TestCommon: CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.o
TestCommon: CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.o
TestCommon: CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.o
TestCommon: CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.o
TestCommon: CMakeFiles/TestCommon.dir/build.make
TestCommon: libCommonClassesDict.so
TestCommon: CMakeFiles/TestCommon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable TestCommon"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestCommon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestCommon.dir/build: TestCommon
.PHONY : CMakeFiles/TestCommon.dir/build

CMakeFiles/TestCommon.dir/requires: CMakeFiles/TestCommon.dir/TestCommon.cpp.o.requires
CMakeFiles/TestCommon.dir/requires: CMakeFiles/TestCommon.dir/src/TDetectorUtils.cc.o.requires
CMakeFiles/TestCommon.dir/requires: CMakeFiles/TestCommon.dir/src/TEvent.cc.o.requires
CMakeFiles/TestCommon.dir/requires: CMakeFiles/TestCommon.dir/src/TXMLHandler.cc.o.requires
CMakeFiles/TestCommon.dir/requires: CMakeFiles/TestCommon.dir/src/RealSetupHandler.cc.o.requires
CMakeFiles/TestCommon.dir/requires: CMakeFiles/TestCommon.dir/src/TDetectorLight.cc.o.requires
CMakeFiles/TestCommon.dir/requires: CMakeFiles/TestCommon.dir/src/TNamedContainer.cc.o.requires
.PHONY : CMakeFiles/TestCommon.dir/requires

CMakeFiles/TestCommon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestCommon.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestCommon.dir/clean

CMakeFiles/TestCommon.dir/depend:
	cd /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/build /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/build /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Common/build/CMakeFiles/TestCommon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestCommon.dir/depend

