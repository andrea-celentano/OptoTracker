#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(Tofpet)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "$ENV{ROOTSYS}/cmake/")
#Rpath
SET(CMAKE_INSTALL_RPATH "$ENV{OPTO}/software/lib")
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

#----------------------------------------------------------------------------
# Find ROOT (required package)
#
find_package(ROOT REQUIRED)
find_package(GCCXML REQUIRED)
include(${ROOT_USE_FILE})
if(NOT GCCXML)
   message(FATAL_ERROR "Common requires GCCXML")
endif() 

#----------------------------------------------------------------------------
# Locate sources and headers for this project
#
include_directories(${PROJECT_SOURCE_DIR}/include 
		    ${ROOT_INCLUDE_DIR}
		    $ENV{OPTO}/software/packages/Common/include
		    )
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

#----------------------------------------------------------------------------
# Generate dictionaries, add ROOT libraries properties
# 
#REFLEX_GENERATE_DICTIONARY(TofpetClasses include/TofpetClasses.hh SELECTION xml/selection.xml) # OPTIONS --gccxmlopt="--gccxml-compiler g++")
ROOT_GENERATE_DICTIONARY(TofpetClasses include/TofpetClasses.hh LINKDEF include/LinkDef.h)

add_library(TofpetClassesDict SHARED ${sources} TofpetClasses.cxx)
set(libsuffix .so)
set(ROOT_LIBRARIES ${ROOT_LIBRARIES} -lMinuit -lProof -lXMLIO -lGui)
set(ROOT_LIBRARY_PROPERTIES ${ROOT_LIBRARY_PROPERTIES} SUFFIX ${libsuffix})
set_target_properties(TofpetClassesDict PROPERTIES ${ROOT_LIBRARY_PROPERTIES})


target_link_libraries(TofpetClassesDict ${ROOT_LIBRARIES} -L${ROOT_LIBRARY_DIR})

#----------------------------------------------------------------------------
# Add the executable
#

link_directories(${ROOT_LIBRARY_DIR} $ENV{OPTO}/software/lib)

add_executable(DarkScan DarkScan.cpp)
target_link_libraries(DarkScan TofpetClassesDict CommonClassesDict ${ROOT_LIBRARIES})



#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS TofpetClassesDict DESTINATION $ENV{OPTO}/software/lib)
install(FILES build/libTofpetClasses_rdict.pcm DESTINATION $ENV{OPTO}/software/lib)
install(TARGETS DarkScan DESTINATION $ENV{OPTO}/software/bin)

