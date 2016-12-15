#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(ReconstructionNew)

#Rpath
SET(CMAKE_INSTALL_RPATH "$ENV{OPTO}/software/lib")
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
#
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()


#----------------------------------------------------------------------------
# Find ROOT (required package)
#
find_package(ROOT REQUIRED)
find_package(GCCXML REQUIRED)
include(${ROOT_USE_FILE})

if(NOT GCCXML)
   message(FATAL_ERROR "Requires GCCXML")
endif() 

#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
#
include(${Geant4_USE_FILE})
#----------------------------------------------------------------------------
# Locate sources and headers for this project
#
include_directories(${PROJECT_SOURCE_DIR}/include
                    ${PROJECT_SOURCE_DIR}/drivers
                     ${PROJECT_SOURCE_DIR}/drivers/common
		  			${PROJECT_SOURCE_DIR}/likelihoodCalculators
                    ${Geant4_INCLUDE_DIR}
		   			 ${ROOT_INCLUDE_DIR}
		    $ENV{OPTO}/software/packages/Common/include
		    $ENV{OPTO}/software/packages/Simulation/include
		     $ENV{OPTO}/software/packages/Citiroc/include
   	       	    $ENV{OPTO}/software/packages/Tofpet/include
   	            $ENV{OPTO}/software/packages/Maroc/include)
   	        
#file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc ${PROJECT_SOURCE_DIR}/drivers/*.cc)
#file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh ${PROJECT_SOURCE_DIR}/drivers/*.hh)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)


file(GLOB_RECURSE driver_sources ${PROJECT_SOURCE_DIR}/drivers/*.cc)
file(GLOB_RECURSE driver_headers ${PROJECT_SOURCE_DIR}/drivers/*.hh)

file(GLOB likelihood_sources ${PROJECT_SOURCE_DIR}/likelihoodCalculators/*.cc)
file(GLOB likelihood_headers ${PROJECT_SOURCE_DIR}/likelihoodCalculators/*.hh)

#----------------------------------------------------------------------------
# Generate dictionaries, add ROOT libraries properties
#

#REFLEX_GENERATE_DICTIONARY(ReconstructionNewClasses include/ReconstructionNewClasses.hh SELECTION xml/selection.xml)
#REFLEX_GENERATE_DICTIONARY(ReconstructionNewClasses ${headers} ${driver_headers} ${likelihood_headers} SELECTION xml/selection.xml) # OPTIONS --gccxmlopt="--gccxml-compiler g++")
ROOT_GENERATE_DICTIONARY(ReconstructionNewClasses include/ReconstructionNewClasses.hh LINKDEF include/LinkDef.h)


add_library(ReconstructionNewClassesDict SHARED ${sources} ${driver_sources} ${likelihood_sources} ReconstructionNewClasses.cxx)
set(libsuffix .so)
set(ROOT_LIBRARIES ${ROOT_LIBRARIES} -L${ROOT_LIBRARY_DIR} -lMinuit -lMinuit2 -lProof -lXMLIO)
set(ROOT_LIBRARY_PROPERTIES ${ROOT_LIBRARY_PROPERTIES} SUFFIX ${libsuffix})
set_target_properties(ReconstructionNewClassesDict PROPERTIES ${ROOT_LIBRARY_PROPERTIES})
target_link_libraries(ReconstructionNewClassesDict ${Geant4_LIBRARIES} ${ROOT_LIBRARIES})





#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries
#

link_directories(${ROOT_LIBRARY_DIR} $ENV{OPTO}/software/lib)

add_executable(ReconstructionNew Reconstruction.cpp ${headers} ${driver_headers} ${likelihood_headers})
target_link_libraries(ReconstructionNew ReconstructionNewClassesDict MarocClassesDict TofpetClassesDict CitirocClassesDict OpNoviceClassesDict CommonClassesDict ${ROOT_LIBRARIES} ${Geant4_LIBRARIES})


#

#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS ReconstructionNewClassesDict DESTINATION $ENV{OPTO}/software/lib)
install(FILES build/libReconstructionNewClasses_rdict.pcm DESTINATION $ENV{OPTO}/software/lib)
install(TARGETS ReconstructionNew DESTINATION $ENV{OPTO}/software/bin)
