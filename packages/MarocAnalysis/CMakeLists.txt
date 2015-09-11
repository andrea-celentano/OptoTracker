#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(MarocAnalysis)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "$ENV{ROOTSYS}/cmake/")
#Rpath
SET(CMAKE_INSTALL_RPATH "$ENV{OPTO}/lib")
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
# Setup Geant4 include directories and compile definitions
#
include(${Geant4_USE_FILE})

#----------------------------------------------------------------------------
# Find ROOT (required package)
#
find_package(ROOT REQUIRED)

if(NOT GCCXML)
   message(FATAL_ERROR "OpNovice requires GCCXML")
endif() 

#----------------------------------------------------------------------------
# Locate sources and headers for this project
#
include_directories(${PROJECT_SOURCE_DIR}/include 
 					${Geant4_INCLUDE_DIR}
                    ${ROOT_INCLUDE_DIR}
		    $ENV{OPTO}/packages/Common/include
		    $ENV{OPTO}/packages/Simulation/include
		    $ENV{OPTO}/packages/Reconstruction/include
		    )
		    
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

#----------------------------------------------------------------------------
# add ROOT libraries properties
#
set(libsuffix .so)
set(ROOT_LIBRARIES ${ROOT_LIBRARIES} -lMinuit -lMinuit2 -lProof)
set(ROOT_LIBRARY_PROPERTIES ${ROOT_LIBRARY_PROPERTIES} SUFFIX ${libsuffix})

#set (MY_CXX_FLAGS "-Wl,-u,G__cpp_setupdict")
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_CXX_FLAGS}")

#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries
#

link_directories(${ROOT_LIBRARY_DIR} $ENV{OPTO}/lib)

add_executable(PrintMaroc printMaroc.cpp ${sources} ${headers})
target_link_libraries(PrintMaroc ReconstructionNewClassesDict OpNoviceClassesDict CommonClassesDict ${ROOT_LIBRARIES} Cintex ${Geant4_LIBRARIES})

add_executable(MarocAnalysis marocAnalysis.cpp ${sources} ${headers})
target_link_libraries(MarocAnalysis ReconstructionNewClassesDict OpNoviceClassesDict CommonClassesDict ${ROOT_LIBRARIES} Cintex ${Geant4_LIBRARIES})

add_executable(comparison comparison.cpp ${sources} ${headers})
target_link_libraries(comparison ReconstructionNewClassesDict OpNoviceClassesDict CommonClassesDict ${ROOT_LIBRARIES} Cintex ${Geant4_LIBRARIES})

#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS PrintMaroc DESTINATION $ENV{OPTO}/bin)
install(TARGETS MarocAnalysis DESTINATION $ENV{OPTO}/bin)
install(TARGETS comparison DESTINATION $ENV{OPTO}/bin)
