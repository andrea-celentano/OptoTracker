#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(MarocAnalysis)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "$ENV{ROOTSYS}/cmake/")
#Rpath
SET(CMAKE_INSTALL_RPATH "$ENV{OPTO}/lib")




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
                    ${ROOT_INCLUDE_DIR}
		    $ENV{OPTO}/packages/Geometry/include
		    $ENV{OPTO}/packages/Simulation/include)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

#----------------------------------------------------------------------------
# add ROOT libraries properties
#
set(libsuffix .so)
set(ROOT_LIBRARIES ${ROOT_LIBRARIES} -lMinuit -lMinuit2 -lProof)
set(ROOT_LIBRARY_PROPERTIES ${ROOT_LIBRARY_PROPERTIES} SUFFIX ${libsuffix})


#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries
#

link_directories(${ROOT_LIBRARY_DIR} $ENV{OPTO}/lib)

add_executable(MarocAnalysis marocAnalysis.cpp ${sources} ${headers})
target_link_libraries(MarocAnalysis ReconstructionClassesDict GeometryClassesDict ${ROOT_LIBRARIES} Cintex)



#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#

install(TARGETS MarocAnalysis DESTINATION $ENV{OPTO}/bin)

