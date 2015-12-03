#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(TofpetAnalysis)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "$ENV{ROOTSYS}/cmake/")
#Rpath
SET(CMAKE_INSTALL_RPATH "$ENV{OPTO}/lib")
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

#----------------------------------------------------------------------------
# Find ROOT (required package)
#
find_package(ROOT REQUIRED)

if(NOT GCCXML)
   message(FATAL_ERROR "Common requires GCCXML")
endif() 

#----------------------------------------------------------------------------
# Locate sources and headers for this project
#
include_directories(${PROJECT_SOURCE_DIR}/include 
		    ${ROOT_INCLUDE_DIR}
		    $ENV{OPTO}/packages/Common/include)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

#----------------------------------------------------------------------------
# Generate dictionaries, add ROOT libraries properties
# 
REFLEX_GENERATE_DICTIONARY(TofpetAnalysisClasses include/TofpetAnalysisClasses.hh SELECTION xml/selection.xml) # OPTIONS --gccxmlopt="--gccxml-compiler g++")
add_library(TofpetAnalysisClassesDict SHARED ${sources} TofpetAnalysisClasses.cpp)
set(libsuffix .so)
set(ROOT_LIBRARIES ${ROOT_LIBRARIES} -lMinuit -lMinuit2 -lProof -lXMLIO)
set(ROOT_LIBRARY_PROPERTIES ${ROOT_LIBRARY_PROPERTIES} SUFFIX ${libsuffix})
set_target_properties(TofpetAnalysisClassesDict PROPERTIES ${ROOT_LIBRARY_PROPERTIES})


target_link_libraries(TofpetAnalysisClassesDict ${ROOT_LIBRARIES} Cintex Reflex)

 

#add_executable(PrintDetector PrintDetector.cpp ${sources} ${headers})
#target_link_libraries(PrintDetector CommonClassesDict ${ROOT_LIBRARIES} Cintex)

#add_executable(TestCommon TestCommon.cpp ${sources} ${headers})
#target_link_libraries(TestCommon CommonClassesDict ${ROOT_LIBRARIES} Cintex)




#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS TofpetAnalysisClassesDict DESTINATION $ENV{OPTO}/lib)
#install(TARGETS PrintDetector DESTINATION $ENV{OPTO}/bin)
#install(TARGETS TestCommon DESTINATION $ENV{OPTO}/bin)
