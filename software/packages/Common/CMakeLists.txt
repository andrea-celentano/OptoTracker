#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(Common)
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
		    ${ROOT_INCLUDE_DIR})
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

#----------------------------------------------------------------------------
# Generate dictionaries, add ROOT libraries properties
# 
#REFLEX_GENERATE_DICTIONARY(CommonClasses include/CommonClasses.hh SELECTION xml/selection.xml) # OPTIONS --gccxmlopt="--gccxml-compiler g++")
ROOT_GENERATE_DICTIONARY(CommonClasses include/CommonClasses.hh LINKDEF include/LinkDef.h)

add_library(CommonClassesDict SHARED ${sources} CommonClasses.cxx)
set(libsuffix .so)
set(ROOT_LIBRARIES ${ROOT_LIBRARIES} -L${ROOT_LIBRARY_DIR} -lProof -lXMLIO)
set(ROOT_LIBRARY_PROPERTIES ${ROOT_LIBRARY_PROPERTIES} SUFFIX ${libsuffix})
set_target_properties(CommonClassesDict PROPERTIES ${ROOT_LIBRARY_PROPERTIES})

target_link_libraries(CommonClassesDict ${ROOT_LIBRARIES})

add_executable(PrintDetector PrintDetector.cpp ${headers})
target_link_libraries(PrintDetector CommonClassesDict ${ROOT_LIBRARIES})

add_executable(TestCommon TestCommon.cpp ${headers})
target_link_libraries(TestCommon CommonClassesDict ${ROOT_LIBRARIES})




#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS CommonClassesDict DESTINATION $ENV{OPTO}/software/lib)
install(FILES build/libCommonClasses_rdict.pcm DESTINATION $ENV{OPTO}/software/lib)
install(TARGETS PrintDetector DESTINATION $ENV{OPTO}/software/bin)
install(TARGETS TestCommon DESTINATION $ENV{OPTO}/software/bin)
