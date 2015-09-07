# Install script for directory: /project/Gruppo3/fiber5/celentano/OptoTracker/packages/ReconstructionNew

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "0")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/lib/libReconstructionNewClassesDict.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/lib/libReconstructionNewClassesDict.so")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/lib/libReconstructionNewClassesDict.so"
         RPATH "/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.3.2/5.3/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.3/lib")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/project/Gruppo3/fiber5/celentano/OptoTracker/lib/libReconstructionNewClassesDict.so")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/project/Gruppo3/fiber5/celentano/OptoTracker/lib" TYPE SHARED_LIBRARY FILES "/project/Gruppo3/fiber5/celentano/OptoTracker/packages/ReconstructionNew/build/libReconstructionNewClassesDict.so")
  IF(EXISTS "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/lib/libReconstructionNewClassesDict.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/lib/libReconstructionNewClassesDict.so")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/lib/libReconstructionNewClassesDict.so"
         OLD_RPATH "/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.3.2/5.3/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.3/lib::::::::::::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.3.2/5.3/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.3/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/lib/libReconstructionNewClassesDict.so")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew"
         RPATH "/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.21/root/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.3.2/5.3/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.3/lib")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/project/Gruppo3/fiber5/celentano/OptoTracker/bin" TYPE EXECUTABLE FILES "/project/Gruppo3/fiber5/celentano/OptoTracker/packages/ReconstructionNew/build/ReconstructionNew")
  IF(EXISTS "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew"
         OLD_RPATH "/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.21/root/lib:/project/Gruppo3/fiber5/celentano/OptoTracker/packages/ReconstructionNew/build:/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.3.2/5.3/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.3/lib:"
         NEW_RPATH "/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.21/root/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.00.p03/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.3.2/5.3/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20150427/1.2/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.3/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/project/Gruppo3/fiber5/celentano/OptoTracker/packages/ReconstructionNew/build/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/project/Gruppo3/fiber5/celentano/OptoTracker/packages/ReconstructionNew/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
