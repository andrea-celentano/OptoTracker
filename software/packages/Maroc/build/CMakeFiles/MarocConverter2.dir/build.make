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
CMAKE_SOURCE_DIR = /work/OptoTracker/software/packages/Maroc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /work/OptoTracker/software/packages/Maroc/build

# Include any dependencies generated for this target.
include CMakeFiles/MarocConverter2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MarocConverter2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MarocConverter2.dir/flags.make

CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.o: CMakeFiles/MarocConverter2.dir/flags.make
CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.o: ../marocConverter2.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /work/OptoTracker/software/packages/Maroc/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.o -c /work/OptoTracker/software/packages/Maroc/marocConverter2.cpp

CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /work/OptoTracker/software/packages/Maroc/marocConverter2.cpp > CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.i

CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /work/OptoTracker/software/packages/Maroc/marocConverter2.cpp -o CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.s

CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.o.requires:
.PHONY : CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.o.requires

CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.o.provides: CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.o.requires
	$(MAKE) -f CMakeFiles/MarocConverter2.dir/build.make CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.o.provides.build
.PHONY : CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.o.provides

CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.o.provides.build: CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.o

CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.o: CMakeFiles/MarocConverter2.dir/flags.make
CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.o: ../src/TMarocSetupHandler.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /work/OptoTracker/software/packages/Maroc/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.o -c /work/OptoTracker/software/packages/Maroc/src/TMarocSetupHandler.cc

CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /work/OptoTracker/software/packages/Maroc/src/TMarocSetupHandler.cc > CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.i

CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /work/OptoTracker/software/packages/Maroc/src/TMarocSetupHandler.cc -o CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.s

CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.o.requires:
.PHONY : CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.o.requires

CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.o.provides: CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.o.requires
	$(MAKE) -f CMakeFiles/MarocConverter2.dir/build.make CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.o.provides.build
.PHONY : CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.o.provides

CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.o.provides.build: CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.o

# Object files for target MarocConverter2
MarocConverter2_OBJECTS = \
"CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.o" \
"CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.o"

# External object files for target MarocConverter2
MarocConverter2_EXTERNAL_OBJECTS =

MarocConverter2: CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.o
MarocConverter2: CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.o
MarocConverter2: CMakeFiles/MarocConverter2.dir/build.make
MarocConverter2: libMarocClassesDict.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libCore.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libCint.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libRIO.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libNet.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libHist.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libGraf.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libGraf3d.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libGpad.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libTree.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libRint.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libPostscript.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libMatrix.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libPhysics.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libMathCore.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libThread.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4Tree.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4FR.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4GMocren.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4visHepRep.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4RayTracer.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4VRML.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4OpenGL.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4gl2ps.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4vis_management.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4modeling.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4interfaces.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4persistency.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4analysis.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4error_propagation.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4readout.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4physicslists.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4run.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4event.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4tracking.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4parmodels.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4processes.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4digits_hits.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4track.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4particles.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4geometry.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4materials.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4graphics_reps.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4intercoms.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4global.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4zlib.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4geomUSolids.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4FR.so
MarocConverter2: /usr/lib64/libXmu.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib/libQt5OpenGL.so.5.4.0
MarocConverter2: /usr/lib64/libGLU.so
MarocConverter2: /usr/lib64/libGL.so
MarocConverter2: /usr/lib64/libSM.so
MarocConverter2: /usr/lib64/libICE.so
MarocConverter2: /usr/lib64/libX11.so
MarocConverter2: /usr/lib64/libXext.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4vis_management.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4modeling.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib/libQt5PrintSupport.so.5.4.0
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib/libQt5Widgets.so.5.4.0
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib/libQt5Gui.so.5.4.0
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib/libQt5Core.so.5.4.0
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib/libxerces-c.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4run.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4event.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4tracking.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4processes.so
MarocConverter2: /usr/lib64/libexpat.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4digits_hits.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4track.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4particles.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4geometry.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4materials.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4graphics_reps.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4intercoms.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4global.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib/libCLHEP.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4zlib.so
MarocConverter2: /work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4geomUSolids.so
MarocConverter2: CMakeFiles/MarocConverter2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable MarocConverter2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MarocConverter2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MarocConverter2.dir/build: MarocConverter2
.PHONY : CMakeFiles/MarocConverter2.dir/build

CMakeFiles/MarocConverter2.dir/requires: CMakeFiles/MarocConverter2.dir/marocConverter2.cpp.o.requires
CMakeFiles/MarocConverter2.dir/requires: CMakeFiles/MarocConverter2.dir/src/TMarocSetupHandler.cc.o.requires
.PHONY : CMakeFiles/MarocConverter2.dir/requires

CMakeFiles/MarocConverter2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MarocConverter2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MarocConverter2.dir/clean

CMakeFiles/MarocConverter2.dir/depend:
	cd /work/OptoTracker/software/packages/Maroc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/OptoTracker/software/packages/Maroc /work/OptoTracker/software/packages/Maroc /work/OptoTracker/software/packages/Maroc/build /work/OptoTracker/software/packages/Maroc/build /work/OptoTracker/software/packages/Maroc/build/CMakeFiles/MarocConverter2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MarocConverter2.dir/depend

