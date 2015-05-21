### setup GEANT4 ENVIRONMENT #######################################

setenv APPS /project/Gruppo3/fiber6/apps
setenv GEANT4_VERSION       4.10.01
setenv G4SYSTEM             Linux-g++
setenv G4ROOT               ${APPS}/geant4/4.10.01/SL6/no_multithread
setenv G4INSTALL            ${APPS}/geant4/4.10.01/SL6/no_multithread
setenv G4INCLUDE            ${G4INSTALL}/include/Geant4
setenv G4LIB                ${G4INSTALL}/lib64
setenv G4WORKDIR            ${G4INSTALL}
setenv G4UI_USE_TERMINAL    1
setenv G4UI_USE_TCSH        1
setenv G4VIS_USE_DAWN       1
setenv G4VIS_USE_VRML       1
setenv G4VIS_USE_DAWNFILE   1
setenv G4VIS_USE_OPENGLX    1
setenv G4VIS_USE_OPENGLXM   1
setenv G4VIS_USE_RAYTRACER  1
setenv G4VIS_USE_RAYTRACERX 1
setenv G4DATA		    ${APPS}/geant4/4.10.01/data
setenv G4LEVELGAMMADATA     ${G4DATA}/PhotonEvaporation3.1
setenv G4RADIOACTIVEDATA    ${G4DATA}/RadioactiveDecay4.2
setenv G4LEDATA             ${G4DATA}/G4EMLOW6.41
setenv G4NEUTRONHPDATA      ${G4DATA}/G4NDL4.5
setenv G4ABLADATA           ${G4DATA}/G4ABLA3.0
setenv G4REALSURFACEDATA    ${G4DATA}/RealSurface1.0
setenv G4SAIDXSDATA         ${G4DATA}/G4SAIDDATA1.1
#setenv CLHEP_BASE_DIR       ${APPS}/clhep/$OS_NAME
#setenv LD_LIBRARY_PATH      ${LD_LIBRARY_PATH}:${CLHEP_BASE_DIR}/lib

