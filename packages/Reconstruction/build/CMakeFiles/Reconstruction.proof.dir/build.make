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
CMAKE_SOURCE_DIR = /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/build

# Include any dependencies generated for this target.
include CMakeFiles/Reconstruction.proof.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Reconstruction.proof.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Reconstruction.proof.dir/flags.make

CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.o: CMakeFiles/Reconstruction.proof.dir/flags.make
CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.o: ../Reconstruction.proof.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.o -c /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/Reconstruction.proof.cpp

CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/Reconstruction.proof.cpp > CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.i

CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/Reconstruction.proof.cpp -o CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.s

CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.o.requires:
.PHONY : CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.o.requires

CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.o.provides: CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.o.requires
	$(MAKE) -f CMakeFiles/Reconstruction.proof.dir/build.make CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.o.provides.build
.PHONY : CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.o.provides

CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.o.provides.build: CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.o

CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.o: CMakeFiles/Reconstruction.proof.dir/flags.make
CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.o: ../src/TReconPoint.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.o -c /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/src/TReconPoint.cc

CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/src/TReconPoint.cc > CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.i

CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/src/TReconPoint.cc -o CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.s

CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.o.requires:
.PHONY : CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.o.requires

CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.o.provides: CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.o.requires
	$(MAKE) -f CMakeFiles/Reconstruction.proof.dir/build.make CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.o.provides.build
.PHONY : CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.o.provides

CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.o.provides.build: CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.o

CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.o: CMakeFiles/Reconstruction.proof.dir/flags.make
CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.o: ../src/TReconTrack.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.o -c /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/src/TReconTrack.cc

CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/src/TReconTrack.cc > CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.i

CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/src/TReconTrack.cc -o CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.s

CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.o.requires:
.PHONY : CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.o.requires

CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.o.provides: CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.o.requires
	$(MAKE) -f CMakeFiles/Reconstruction.proof.dir/build.make CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.o.provides.build
.PHONY : CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.o.provides

CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.o.provides.build: CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.o

CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.o: CMakeFiles/Reconstruction.proof.dir/flags.make
CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.o: ../src/TRecon.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.o -c /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/src/TRecon.cc

CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/src/TRecon.cc > CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.i

CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/src/TRecon.cc -o CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.s

CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.o.requires:
.PHONY : CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.o.requires

CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.o.provides: CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.o.requires
	$(MAKE) -f CMakeFiles/Reconstruction.proof.dir/build.make CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.o.provides.build
.PHONY : CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.o.provides

CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.o.provides.build: CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.o

CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.o: CMakeFiles/Reconstruction.proof.dir/flags.make
CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.o: ../src/TOpNoviceSelectorRaw.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.o -c /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/src/TOpNoviceSelectorRaw.cc

CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/src/TOpNoviceSelectorRaw.cc > CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.i

CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/src/TOpNoviceSelectorRaw.cc -o CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.s

CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.o.requires:
.PHONY : CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.o.requires

CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.o.provides: CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.o.requires
	$(MAKE) -f CMakeFiles/Reconstruction.proof.dir/build.make CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.o.provides.build
.PHONY : CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.o.provides

CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.o.provides.build: CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.o

# Object files for target Reconstruction.proof
Reconstruction_proof_OBJECTS = \
"CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.o" \
"CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.o" \
"CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.o" \
"CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.o" \
"CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.o"

# External object files for target Reconstruction.proof
Reconstruction_proof_EXTERNAL_OBJECTS =

Reconstruction.proof: CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.o
Reconstruction.proof: CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.o
Reconstruction.proof: CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.o
Reconstruction.proof: CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.o
Reconstruction.proof: CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.o
Reconstruction.proof: CMakeFiles/Reconstruction.proof.dir/build.make
Reconstruction.proof: libReconstructionClassesDict.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4Tree.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4FR.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4GMocren.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4visHepRep.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4RayTracer.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4VRML.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4OpenGL.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4gl2ps.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4vis_management.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4modeling.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4interfaces.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4persistency.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4analysis.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4error_propagation.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4readout.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4physicslists.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4run.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4event.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4tracking.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4parmodels.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4processes.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4digits_hits.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4track.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4particles.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4geometry.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4materials.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4graphics_reps.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4intercoms.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4global.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4zlib.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4FR.so
Reconstruction.proof: /usr/lib64/libXmu.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.3.2/5.3/gcc_64/lib/libQt5OpenGL.so.5.3.2
Reconstruction.proof: /usr/lib64/libGLU.so
Reconstruction.proof: /usr/lib64/libGL.so
Reconstruction.proof: /usr/lib64/libSM.so
Reconstruction.proof: /usr/lib64/libICE.so
Reconstruction.proof: /usr/lib64/libX11.so
Reconstruction.proof: /usr/lib64/libXext.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4vis_management.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4modeling.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.3.2/5.3/gcc_64/lib/libQt5PrintSupport.so.5.3.2
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.3.2/5.3/gcc_64/lib/libQt5Widgets.so.5.3.2
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.3.2/5.3/gcc_64/lib/libQt5Gui.so.5.3.2
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.3.2/5.3/gcc_64/lib/libQt5Core.so.5.3.2
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib/libxerces-c.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4run.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4event.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4tracking.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4processes.so
Reconstruction.proof: /usr/lib64/libexpat.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4digits_hits.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4track.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4particles.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4geometry.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4materials.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4graphics_reps.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4intercoms.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4global.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.3/lib/libCLHEP.so
Reconstruction.proof: /project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64/libG4zlib.so
Reconstruction.proof: CMakeFiles/Reconstruction.proof.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Reconstruction.proof"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Reconstruction.proof.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Reconstruction.proof.dir/build: Reconstruction.proof
.PHONY : CMakeFiles/Reconstruction.proof.dir/build

CMakeFiles/Reconstruction.proof.dir/requires: CMakeFiles/Reconstruction.proof.dir/Reconstruction.proof.cpp.o.requires
CMakeFiles/Reconstruction.proof.dir/requires: CMakeFiles/Reconstruction.proof.dir/src/TReconPoint.cc.o.requires
CMakeFiles/Reconstruction.proof.dir/requires: CMakeFiles/Reconstruction.proof.dir/src/TReconTrack.cc.o.requires
CMakeFiles/Reconstruction.proof.dir/requires: CMakeFiles/Reconstruction.proof.dir/src/TRecon.cc.o.requires
CMakeFiles/Reconstruction.proof.dir/requires: CMakeFiles/Reconstruction.proof.dir/src/TOpNoviceSelectorRaw.cc.o.requires
.PHONY : CMakeFiles/Reconstruction.proof.dir/requires

CMakeFiles/Reconstruction.proof.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Reconstruction.proof.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Reconstruction.proof.dir/clean

CMakeFiles/Reconstruction.proof.dir/depend:
	cd /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/build /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/build /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Reconstruction/build/CMakeFiles/Reconstruction.proof.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Reconstruction.proof.dir/depend

