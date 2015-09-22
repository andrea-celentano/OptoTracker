#include <vector>
#include "TAnalysis.hh"
#include "TJobManager.hh"
#include "TDriver.hh"
#include "../drivers/TEventMarkerDriver.hh"
#include "../drivers/TRootSaveDriver.hh"
#include "../drivers/TChargeAnalysisDriver.hh"
#include "../drivers/TMatrixWriterDriver.hh"
#include "../drivers/TMatrixReconDriver.hh"

#ifdef __GCCXML__
TJobManager object1;
TDriver *object2;
std::vector <TDriver*> object3;
#endif
//#undef __G4String
