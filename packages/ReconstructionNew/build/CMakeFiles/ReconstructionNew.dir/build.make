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
CMAKE_SOURCE_DIR = /work/OptoTracker/packages/ReconstructionNew

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /work/OptoTracker/packages/ReconstructionNew/build

# Include any dependencies generated for this target.
include CMakeFiles/ReconstructionNew.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ReconstructionNew.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ReconstructionNew.dir/flags.make

CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.o: CMakeFiles/ReconstructionNew.dir/flags.make
CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.o: ../Reconstruction.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /work/OptoTracker/packages/ReconstructionNew/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.o -c /work/OptoTracker/packages/ReconstructionNew/Reconstruction.cpp

CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /work/OptoTracker/packages/ReconstructionNew/Reconstruction.cpp > CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.i

CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /work/OptoTracker/packages/ReconstructionNew/Reconstruction.cpp -o CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.s

CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.o.requires:
.PHONY : CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.o.requires

CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.o.provides: CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReconstructionNew.dir/build.make CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.o.provides.build
.PHONY : CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.o.provides

CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.o.provides.build: CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.o

CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.o: CMakeFiles/ReconstructionNew.dir/flags.make
CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.o: ../src/TOptoJobManager.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /work/OptoTracker/packages/ReconstructionNew/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.o -c /work/OptoTracker/packages/ReconstructionNew/src/TOptoJobManager.cc

CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /work/OptoTracker/packages/ReconstructionNew/src/TOptoJobManager.cc > CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.i

CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /work/OptoTracker/packages/ReconstructionNew/src/TOptoJobManager.cc -o CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.s

CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.o.requires:
.PHONY : CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.o.requires

CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.o.provides: CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.o.requires
	$(MAKE) -f CMakeFiles/ReconstructionNew.dir/build.make CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.o.provides.build
.PHONY : CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.o.provides

CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.o.provides.build: CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.o

CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.o: CMakeFiles/ReconstructionNew.dir/flags.make
CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.o: ../src/TDriver.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /work/OptoTracker/packages/ReconstructionNew/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.o -c /work/OptoTracker/packages/ReconstructionNew/src/TDriver.cc

CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /work/OptoTracker/packages/ReconstructionNew/src/TDriver.cc > CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.i

CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /work/OptoTracker/packages/ReconstructionNew/src/TDriver.cc -o CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.s

CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.o.requires:
.PHONY : CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.o.requires

CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.o.provides: CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.o.requires
	$(MAKE) -f CMakeFiles/ReconstructionNew.dir/build.make CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.o.provides.build
.PHONY : CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.o.provides

CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.o.provides.build: CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.o

# Object files for target ReconstructionNew
ReconstructionNew_OBJECTS = \
"CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.o" \
"CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.o" \
"CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.o"

# External object files for target ReconstructionNew
ReconstructionNew_EXTERNAL_OBJECTS =

ReconstructionNew: CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.o
ReconstructionNew: CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.o
ReconstructionNew: CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.o
ReconstructionNew: CMakeFiles/ReconstructionNew.dir/build.make
ReconstructionNew: libReconstructionNewClassesDict.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4Tree.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4FR.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4GMocren.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4visHepRep.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4RayTracer.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4VRML.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4OpenGL.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4gl2ps.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4vis_management.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4modeling.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4interfaces.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4persistency.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4analysis.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4error_propagation.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4readout.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4physicslists.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4run.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4event.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4tracking.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4parmodels.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4processes.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4digits_hits.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4track.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4particles.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4geometry.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4materials.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4graphics_reps.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4intercoms.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4global.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4clhep.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4zlib.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4geomUSolids.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4FR.so
ReconstructionNew: /usr/lib64/libXmu.so
ReconstructionNew: /work/jlab_software/1.2/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.3.2/5.3/gcc_64/lib/libQt5OpenGL.so.5.3.2
ReconstructionNew: /usr/lib64/libGLU.so
ReconstructionNew: /usr/lib64/libGL.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4vis_management.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4modeling.so
ReconstructionNew: /usr/lib64/libXm.so
ReconstructionNew: /usr/lib64/libSM.so
ReconstructionNew: /usr/lib64/libICE.so
ReconstructionNew: /usr/lib64/libX11.so
ReconstructionNew: /usr/lib64/libXext.so
ReconstructionNew: /work/jlab_software/1.2/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.3.2/5.3/gcc_64/lib/libQt5PrintSupport.so.5.3.2
ReconstructionNew: /work/jlab_software/1.2/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.3.2/5.3/gcc_64/lib/libQt5Widgets.so.5.3.2
ReconstructionNew: /work/jlab_software/1.2/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.3.2/5.3/gcc_64/lib/libQt5Gui.so.5.3.2
ReconstructionNew: /work/jlab_software/1.2/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.3.2/5.3/gcc_64/lib/libQt5Core.so.5.3.2
ReconstructionNew: /work/jlab_software/1.2/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib/libxerces-c.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4run.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4event.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4tracking.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4processes.so
ReconstructionNew: /usr/lib64/libexpat.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4digits_hits.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4track.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4particles.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4geometry.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4materials.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4graphics_reps.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4intercoms.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4global.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4clhep.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4zlib.so
ReconstructionNew: /work/geant4/4.10.01/SL6/no_multithread/lib64/libG4geomUSolids.so
ReconstructionNew: CMakeFiles/ReconstructionNew.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ReconstructionNew"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ReconstructionNew.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ReconstructionNew.dir/build: ReconstructionNew
.PHONY : CMakeFiles/ReconstructionNew.dir/build

CMakeFiles/ReconstructionNew.dir/requires: CMakeFiles/ReconstructionNew.dir/Reconstruction.cpp.o.requires
CMakeFiles/ReconstructionNew.dir/requires: CMakeFiles/ReconstructionNew.dir/src/TOptoJobManager.cc.o.requires
CMakeFiles/ReconstructionNew.dir/requires: CMakeFiles/ReconstructionNew.dir/src/TDriver.cc.o.requires
.PHONY : CMakeFiles/ReconstructionNew.dir/requires

CMakeFiles/ReconstructionNew.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ReconstructionNew.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ReconstructionNew.dir/clean

CMakeFiles/ReconstructionNew.dir/depend:
	cd /work/OptoTracker/packages/ReconstructionNew/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/OptoTracker/packages/ReconstructionNew /work/OptoTracker/packages/ReconstructionNew /work/OptoTracker/packages/ReconstructionNew/build /work/OptoTracker/packages/ReconstructionNew/build /work/OptoTracker/packages/ReconstructionNew/build/CMakeFiles/ReconstructionNew.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ReconstructionNew.dir/depend

