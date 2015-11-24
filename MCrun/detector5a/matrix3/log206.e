
-------- EEEE ------- G4Exception-START -------- EEEE -------
*** G4Exception : OpNovice
      issued by : OpNoviceSteppingAction::UserSteppingAction()
OpNoviceSteppingAction::UserSteppingAction(): No reallocation step after reflection!
Something is wrong with the surface normal or geometry

*** Fatal Exception *** core dump ***
-------- EEEE -------- G4Exception-END --------- EEEE -------


*** G4Exception: Aborting execution ***
Info in <TJobManager::TOptoJobManager>: Done
Info in <TAnalysis::ParseCommandLine>: steering file: /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrixMCcalculation.xml
Info in <TJobManager::setVariable>: Setting variable voxelID at value 206
Info in <TAnalysis::ParseCommandLine>: add file to chain: root/run_206_0.root
Info in <TJobManager::ConfigControl>: Done
Info in <TJobManager::ConfigDrivers>: Configure driver EventMarker class TEventMarkerDriver
Info in <TJobManager::ConfigDrivers>: Try to call method name setInterval with param 100 on class TEventMarkerDriver
Info in <TJobManager::ConfigDrivers>: Method setInterval called
Info in <TJobManager::ConfigDrivers>: Configure driver Matrix class TMatrixWriterDriver
Info in <TJobManager::ConfigDrivers>: Try to call method name setVoxelID with param 206 on class TMatrixWriterDriver
Info in <TJobManager::ConfigDrivers>: Method setVoxelID called
Info in <TJobManager::ConfigDrivers>: Done
Info in <TJobManager::Config>: Done
Warning in <TFile::Init>: file root/run_206_0.root probably not closed, trying to recover
Info in <TFile::Recover>: root/run_206_0.root, recovered key TTree:Event at address 1828202713
Warning in <TFile::Init>: successfully recovered 1 keys
Error in <TAnalysis::configure>: No detector found in any file, and no txt file passed with -det option
mv: cannot stat `voxel_206.dat': No such file or directory
