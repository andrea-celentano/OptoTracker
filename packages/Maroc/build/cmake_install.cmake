# Install script for directory: /work/OptoTracker/packages/Maroc

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
  IF(EXISTS "$ENV{DESTDIR}/work/OptoTracker/lib/libMarocClassesDict.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/work/OptoTracker/lib/libMarocClassesDict.so")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/work/OptoTracker/lib/libMarocClassesDict.so"
         RPATH "/work/OptoTracker/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/work/OptoTracker/lib/libMarocClassesDict.so")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/work/OptoTracker/lib" TYPE SHARED_LIBRARY FILES "/work/OptoTracker/packages/Maroc/build/libMarocClassesDict.so")
  IF(EXISTS "$ENV{DESTDIR}/work/OptoTracker/lib/libMarocClassesDict.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/work/OptoTracker/lib/libMarocClassesDict.so")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/work/OptoTracker/lib/libMarocClassesDict.so"
         OLD_RPATH "/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib::::::::::::::::::::::"
         NEW_RPATH "/work/OptoTracker/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/work/OptoTracker/lib/libMarocClassesDict.so")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/work/OptoTracker/bin/PrintMaroc" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/work/OptoTracker/bin/PrintMaroc")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/work/OptoTracker/bin/PrintMaroc"
         RPATH "/work/OptoTracker/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/work/OptoTracker/bin/PrintMaroc")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/work/OptoTracker/bin" TYPE EXECUTABLE FILES "/work/OptoTracker/packages/Maroc/build/PrintMaroc")
  IF(EXISTS "$ENV{DESTDIR}/work/OptoTracker/bin/PrintMaroc" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/work/OptoTracker/bin/PrintMaroc")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/work/OptoTracker/bin/PrintMaroc"
         OLD_RPATH "/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/work/OptoTracker/packages/Maroc/build:/work/OptoTracker/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib:"
         NEW_RPATH "/work/OptoTracker/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/work/OptoTracker/bin/PrintMaroc")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/work/OptoTracker/bin/MarocAnalysis" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/work/OptoTracker/bin/MarocAnalysis")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/work/OptoTracker/bin/MarocAnalysis"
         RPATH "/work/OptoTracker/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/work/OptoTracker/bin/MarocAnalysis")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/work/OptoTracker/bin" TYPE EXECUTABLE FILES "/work/OptoTracker/packages/Maroc/build/MarocAnalysis")
  IF(EXISTS "$ENV{DESTDIR}/work/OptoTracker/bin/MarocAnalysis" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/work/OptoTracker/bin/MarocAnalysis")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/work/OptoTracker/bin/MarocAnalysis"
         OLD_RPATH "/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/work/OptoTracker/packages/Maroc/build:/work/OptoTracker/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib:"
         NEW_RPATH "/work/OptoTracker/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/work/OptoTracker/bin/MarocAnalysis")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/work/OptoTracker/bin/comparison" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/work/OptoTracker/bin/comparison")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/work/OptoTracker/bin/comparison"
         RPATH "/work/OptoTracker/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/work/OptoTracker/bin/comparison")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/work/OptoTracker/bin" TYPE EXECUTABLE FILES "/work/OptoTracker/packages/Maroc/build/comparison")
  IF(EXISTS "$ENV{DESTDIR}/work/OptoTracker/bin/comparison" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/work/OptoTracker/bin/comparison")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/work/OptoTracker/bin/comparison"
         OLD_RPATH "/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/work/OptoTracker/packages/Maroc/build:/work/OptoTracker/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib:"
         NEW_RPATH "/work/OptoTracker/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/work/OptoTracker/bin/comparison")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/work/OptoTracker/bin/MarocConverter" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/work/OptoTracker/bin/MarocConverter")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/work/OptoTracker/bin/MarocConverter"
         RPATH "/work/OptoTracker/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/work/OptoTracker/bin/MarocConverter")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/work/OptoTracker/bin" TYPE EXECUTABLE FILES "/work/OptoTracker/packages/Maroc/build/MarocConverter")
  IF(EXISTS "$ENV{DESTDIR}/work/OptoTracker/bin/MarocConverter" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/work/OptoTracker/bin/MarocConverter")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/work/OptoTracker/bin/MarocConverter"
         OLD_RPATH "/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/work/OptoTracker/packages/Maroc/build:/work/OptoTracker/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib:"
         NEW_RPATH "/work/OptoTracker/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/lib/root:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/geant4/4.10.01.p02/lib64:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/qt/5.4.0/5.4/gcc_64/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/xercesc/3.1.1/lib:/work/jlab_software/1.3/Linux_Scientific6-x86_64-gcc4.4.7/clhep/2.2.0.8/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/work/OptoTracker/bin/MarocConverter")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/work/OptoTracker/packages/Maroc/build/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/work/OptoTracker/packages/Maroc/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
