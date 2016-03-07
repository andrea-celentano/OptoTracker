# Install script for directory: /project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc

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
  IF(EXISTS "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/lib/libMarocClassesDict.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/lib/libMarocClassesDict.so")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/lib/libMarocClassesDict.so"
         RPATH "/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/project/Gruppo3/fiber5/celentano/OptoTracker/lib/libMarocClassesDict.so")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/project/Gruppo3/fiber5/celentano/OptoTracker/lib" TYPE SHARED_LIBRARY FILES "/project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build/libMarocClassesDict.so")
  IF(EXISTS "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/lib/libMarocClassesDict.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/lib/libMarocClassesDict.so")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/lib/libMarocClassesDict.so"
         OLD_RPATH "/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib::::::::::::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/lib/libMarocClassesDict.so")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/PrintMaroc" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/PrintMaroc")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/PrintMaroc"
         RPATH "/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/project/Gruppo3/fiber5/celentano/OptoTracker/bin/PrintMaroc")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/project/Gruppo3/fiber5/celentano/OptoTracker/bin" TYPE EXECUTABLE FILES "/project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build/PrintMaroc")
  IF(EXISTS "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/PrintMaroc" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/PrintMaroc")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/PrintMaroc"
         OLD_RPATH "/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build:/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib:"
         NEW_RPATH "/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/PrintMaroc")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/MarocAnalysis" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/MarocAnalysis")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/MarocAnalysis"
         RPATH "/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/project/Gruppo3/fiber5/celentano/OptoTracker/bin/MarocAnalysis")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/project/Gruppo3/fiber5/celentano/OptoTracker/bin" TYPE EXECUTABLE FILES "/project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build/MarocAnalysis")
  IF(EXISTS "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/MarocAnalysis" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/MarocAnalysis")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/MarocAnalysis"
         OLD_RPATH "/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build:/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib:"
         NEW_RPATH "/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/MarocAnalysis")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/comparison" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/comparison")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/comparison"
         RPATH "/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/project/Gruppo3/fiber5/celentano/OptoTracker/bin/comparison")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/project/Gruppo3/fiber5/celentano/OptoTracker/bin" TYPE EXECUTABLE FILES "/project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build/comparison")
  IF(EXISTS "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/comparison" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/comparison")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/comparison"
         OLD_RPATH "/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build:/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib:"
         NEW_RPATH "/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/comparison")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/MarocConverter" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/MarocConverter")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/MarocConverter"
         RPATH "/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/project/Gruppo3/fiber5/celentano/OptoTracker/bin/MarocConverter")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/project/Gruppo3/fiber5/celentano/OptoTracker/bin" TYPE EXECUTABLE FILES "/project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build/MarocConverter")
  IF(EXISTS "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/MarocConverter" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/MarocConverter")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/MarocConverter"
         OLD_RPATH "/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build:/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib:"
         NEW_RPATH "/project/Gruppo3/fiber5/celentano/OptoTracker/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/project/Gruppo3/fiber5/celentano/OptoTracker/bin/MarocConverter")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/project/Gruppo3/fiber5/celentano/OptoTracker/packages/Maroc/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
