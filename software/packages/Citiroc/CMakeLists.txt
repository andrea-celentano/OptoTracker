#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(Citiroc)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "$ENV{ROOTSYS}/cmake/")
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
   message(FATAL_ERROR "Citiroc requires GCCXML")
endif() 

#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
#
include(${Geant4_USE_FILE})


#----------------------------------------------------------------------------
# Locate sources and headers for this project
#
include_directories(${PROJECT_SOURCE_DIR}/include 
 					${Geant4_INCLUDE_DIR}
                    ${ROOT_INCLUDE_DIR}
		    		$ENV{OPTO}/software/packages/Common/include
		    		$ENV{OPTO}/software/packages/Simulation/include
		  			)
		  			
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)



#----------------------------------------------------------------------------
# Generate dictionaries, add ROOT libraries properties
# 
REFLEX_GENERATE_DICTIONARY(CitirocClasses include/CitirocClasses.hh SELECTION xml/selection.xml) # OPTIONS --gccxmlopt="--gccxml-compiler g++")


add_library(CitirocClassesDict SHARED ${sources} ${driver_sources} CitirocClasses.cxx)
set(libsuffix .so)
set(ROOT_LIBRARIES ${ROOT_LIBRARIES} -L${ROOT_LIBRARY_DIR} -lMinuit -lMinuit2 -lProof -lXMLIO -lSpectrum -lGui )
set(ROOT_LIBRARY_PROPERTIES ${ROOT_LIBRARY_PROPERTIES} SUFFIX ${libsuffix})
set_target_properties(CitirocClassesDict PROPERTIES ${ROOT_LIBRARY_PROPERTIES})
target_link_libraries(CitirocClassesDict ${Geant4_LIBRARIES} ${ROOT_LIBRARIES})

link_directories(${ROOT_LIBRARY_DIR} $ENV{OPTO}/software/lib)


add_executable(CitirocEventBuilder CitirocEventBuilder.cpp ${sources} ${headers})
target_link_libraries(CitirocEventBuilder CitirocClassesDict CommonClassesDict ${ROOT_LIBRARIES})




#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS CitirocClassesDict DESTINATION $ENV{OPTO}/software/lib)
install(TARGETS CitirocEventBuilder DESTINATION $ENV{OPTO}/software/bin)
