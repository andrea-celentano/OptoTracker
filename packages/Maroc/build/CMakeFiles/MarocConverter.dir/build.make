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
CMAKE_SOURCE_DIR = /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build

# Include any dependencies generated for this target.
include CMakeFiles/MarocConverter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MarocConverter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MarocConverter.dir/flags.make

CMakeFiles/MarocConverter.dir/marocConverter.cpp.o: CMakeFiles/MarocConverter.dir/flags.make
CMakeFiles/MarocConverter.dir/marocConverter.cpp.o: ../marocConverter.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MarocConverter.dir/marocConverter.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MarocConverter.dir/marocConverter.cpp.o -c /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/marocConverter.cpp

CMakeFiles/MarocConverter.dir/marocConverter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MarocConverter.dir/marocConverter.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/marocConverter.cpp > CMakeFiles/MarocConverter.dir/marocConverter.cpp.i

CMakeFiles/MarocConverter.dir/marocConverter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MarocConverter.dir/marocConverter.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/marocConverter.cpp -o CMakeFiles/MarocConverter.dir/marocConverter.cpp.s

CMakeFiles/MarocConverter.dir/marocConverter.cpp.o.requires:
.PHONY : CMakeFiles/MarocConverter.dir/marocConverter.cpp.o.requires

CMakeFiles/MarocConverter.dir/marocConverter.cpp.o.provides: CMakeFiles/MarocConverter.dir/marocConverter.cpp.o.requires
	$(MAKE) -f CMakeFiles/MarocConverter.dir/build.make CMakeFiles/MarocConverter.dir/marocConverter.cpp.o.provides.build
.PHONY : CMakeFiles/MarocConverter.dir/marocConverter.cpp.o.provides

CMakeFiles/MarocConverter.dir/marocConverter.cpp.o.provides.build: CMakeFiles/MarocConverter.dir/marocConverter.cpp.o

CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.o: CMakeFiles/MarocConverter.dir/flags.make
CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.o: ../src/TMarocSetupHandler.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.o -c /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/src/TMarocSetupHandler.cc

CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/src/TMarocSetupHandler.cc > CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.i

CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/src/TMarocSetupHandler.cc -o CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.s

CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.o.requires:
.PHONY : CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.o.requires

CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.o.provides: CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.o.requires
	$(MAKE) -f CMakeFiles/MarocConverter.dir/build.make CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.o.provides.build
.PHONY : CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.o.provides

CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.o.provides.build: CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.o

# Object files for target MarocConverter
MarocConverter_OBJECTS = \
"CMakeFiles/MarocConverter.dir/marocConverter.cpp.o" \
"CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.o"

# External object files for target MarocConverter
MarocConverter_EXTERNAL_OBJECTS =

MarocConverter: CMakeFiles/MarocConverter.dir/marocConverter.cpp.o
MarocConverter: CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.o
MarocConverter: CMakeFiles/MarocConverter.dir/build.make
MarocConverter: libMarocClassesDict.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libCore.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libCint.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libRIO.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libNet.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libHist.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libGraf.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libGraf3d.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libGpad.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libTree.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libRint.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libPostscript.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libMatrix.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libPhysics.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libMathCore.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root/libThread.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4Tree.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4FR.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4GMocren.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4visHepRep.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4RayTracer.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4VRML.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4OpenGL.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4gl2ps.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4vis_management.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4modeling.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4interfaces.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4persistency.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4analysis.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4error_propagation.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4readout.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4physicslists.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4run.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4event.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4tracking.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4parmodels.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4processes.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4digits_hits.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4track.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4particles.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4geometry.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4materials.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4graphics_reps.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4intercoms.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4global.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4zlib.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4geomUSolids.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4FR.so
MarocConverter: /usr/lib64/libXmu.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib/libQt5OpenGL.so.5.4.0
MarocConverter: /usr/lib64/libGLU.so
MarocConverter: /usr/lib64/libGL.so
MarocConverter: /usr/lib64/libSM.so
MarocConverter: /usr/lib64/libICE.so
MarocConverter: /usr/lib64/libX11.so
MarocConverter: /usr/lib64/libXext.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4vis_management.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4modeling.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib/libQt5PrintSupport.so.5.4.0
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib/libQt5Widgets.so.5.4.0
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib/libQt5Gui.so.5.4.0
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib/libQt5Core.so.5.4.0
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib/libxerces-c.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4run.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4event.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4tracking.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4processes.so
MarocConverter: /usr/lib64/libexpat.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4digits_hits.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4track.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4particles.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4geometry.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4materials.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4graphics_reps.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4intercoms.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4global.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib/libCLHEP.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4zlib.so
MarocConverter: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64/libG4geomUSolids.so
MarocConverter: CMakeFiles/MarocConverter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable MarocConverter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MarocConverter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MarocConverter.dir/build: MarocConverter
.PHONY : CMakeFiles/MarocConverter.dir/build

CMakeFiles/MarocConverter.dir/requires: CMakeFiles/MarocConverter.dir/marocConverter.cpp.o.requires
CMakeFiles/MarocConverter.dir/requires: CMakeFiles/MarocConverter.dir/src/TMarocSetupHandler.cc.o.requires
.PHONY : CMakeFiles/MarocConverter.dir/requires

CMakeFiles/MarocConverter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MarocConverter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MarocConverter.dir/clean

CMakeFiles/MarocConverter.dir/depend:
	cd /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build/CMakeFiles/MarocConverter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MarocConverter.dir/depend
