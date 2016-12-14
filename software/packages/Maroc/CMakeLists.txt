#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(MarocAnalysis)
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
   message(FATAL_ERROR "Maroc requires GCCXML")
endif() 

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
# add ROOT libraries properties
#
set(libsuffix .so)
set(ROOT_LIBRARIES ${ROOT_LIBRARIES} -L${ROOT_LIBRARY_DIR} -lMinuit -lMinuit2 -lProof)
set(ROOT_LIBRARY_PROPERTIES ${ROOT_LIBRARY_PROPERTIES} SUFFIX ${libsuffix})


#----------------------------------------------------------------------------
# Generate dictionaries, add ROOT libraries properties
#
REFLEX_GENERATE_DICTIONARY(MarocClasses include/MarocClasses.hh SELECTION xml/selection.xml) # OPTIONS --gccxmlopt="--gccxml-compiler g++")


add_library(MarocClassesDict SHARED ${sources} ${driver_sources} MarocClasses.cxx)
set(libsuffix .so)
set(ROOT_LIBRARIES ${ROOT_LIBRARIES} -L${ROOT_LIBRARY_DIR} -lMinuit -lMinuit2 -lProof -lXMLIO)
set(ROOT_LIBRARY_PROPERTIES ${ROOT_LIBRARY_PROPERTIES} SUFFIX ${libsuffix})
set_target_properties(MarocClassesDict PROPERTIES ${ROOT_LIBRARY_PROPERTIES})
target_link_libraries(MarocClassesDict ${Geant4_LIBRARIES} ${ROOT_LIBRARIES})





#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries
#

link_directories(${ROOT_LIBRARY_DIR} $ENV{OPTO}/software/lib)

add_executable(PrintMaroc printMaroc.cpp ${sources} ${headers})
target_link_libraries(PrintMaroc MarocClassesDict OpNoviceClassesDict CommonClassesDict ${ROOT_LIBRARIES} ${Geant4_LIBRARIES})

add_executable(MarocAnalysis marocAnalysis.cpp ${sources} ${headers})
target_link_libraries(MarocAnalysis MarocClassesDict OpNoviceClassesDict CommonClassesDict ${ROOT_LIBRARIES} ${Geant4_LIBRARIES})

add_executable(MarocAnalysis2 marocAnalysis2.cpp ${sources} ${headers})
target_link_libraries(MarocAnalysis2 MarocClassesDict OpNoviceClassesDict CommonClassesDict ${ROOT_LIBRARIES} ${Geant4_LIBRARIES})



add_executable(comparison comparison.cpp ${sources} ${headers})
target_link_libraries(comparison MarocClassesDict OpNoviceClassesDict CommonClassesDict ${ROOT_LIBRARIES} ${Geant4_LIBRARIES})

add_executable(MarocConverter marocConverter.cpp ${sources} ${headers})
target_link_libraries(MarocConverter MarocClassesDict OpNoviceClassesDict CommonClassesDict ${ROOT_LIBRARIES} ${Geant4_LIBRARIES})

add_executable(MarocConverter2 marocConverter2.cpp ${sources} ${headers})
target_link_libraries(MarocConverter2 MarocClassesDict OpNoviceClassesDict CommonClassesDict ${ROOT_LIBRARIES} ${Geant4_LIBRARIES})

#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS MarocClassesDict DESTINATION $ENV{OPTO}/software/lib)
install(TARGETS PrintMaroc DESTINATION $ENV{OPTO}/software/bin)
install(TARGETS MarocAnalysis DESTINATION $ENV{OPTO}/software/bin)
install(TARGETS MarocAnalysis2 DESTINATION $ENV{OPTO}/software/bin)
install(TARGETS comparison DESTINATION $ENV{OPTO}/software/bin)
install(TARGETS MarocConverter DESTINATION $ENV{OPTO}/software/bin)
install(TARGETS MarocConverter2 DESTINATION $ENV{OPTO}/software/bin)
