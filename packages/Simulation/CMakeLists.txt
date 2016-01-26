#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(OpNovice)

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
		    		$ENV{OPTO}/packages/Common/include)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh {PROJECT_SOURCE_DIR}/build/OpNoviceDict.h)

#----------------------------------------------------------------------------
# Generate dictionaries, add ROOT libraries properties
#
REFLEX_GENERATE_DICTIONARY(OpNoviceClasses include/OpNoviceClasses.hh SELECTION xml/selection.xml) # OPTIONS --gccxmlopt="--gccxml-compiler g++")
add_library(OpNoviceClassesDict SHARED ${sources} OpNoviceClasses.cpp)
set(libsuffix .so)
set(ROOT_LIBRARIES ${ROOT_LIBRARIES} -L${ROOT_LIBRARY_DIR} -lMinuit -lMinuit2 -lProof)
set(ROOT_LIBRARY_PROPERTIES ${ROOT_LIBRARY_PROPERTIES} SUFFIX ${libsuffix})
set_target_properties(OpNoviceClassesDict PROPERTIES ${ROOT_LIBRARY_PROPERTIES})
target_link_libraries(OpNoviceClassesDict  ${Geant4_LIBRARIES} ${ROOT_LIBRARIES} Cintex Reflex)



#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries
#

link_directories(${ROOT_LIBRARY_DIR} $ENV{OPTO}/lib)

add_executable(OpNoviceExe OpNovice.cc ${sources} ${headers})
target_link_libraries(OpNoviceExe OpNoviceClassesDict CommonClassesDict ${Geant4_LIBRARIES} ${ROOT_LIBRARIES} Cintex)
 



#----------------------------------------------------------------------------
# Copy all scripts to the build directory, i.e. the directory in which we
# build OpNovice. This is so that we can run the executable directly because it
# relies on these scripts being in the current working directory.
#
set(OpNovice_SCRIPTS
    gui.mac
    icons.mac
    run.png
    vis.mac
    run1.mac
    run2.mac
    run3.mac
    detector.mac
  )

foreach(_script ${OpNovice_SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY
    )
endforeach()


add_custom_target(OpNovice DEPENDS OpNoviceExe)

#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS OpNoviceClassesDict DESTINATION $ENV{OPTO}/lib)
install(TARGETS OpNoviceExe DESTINATION $ENV{OPTO}/bin)


