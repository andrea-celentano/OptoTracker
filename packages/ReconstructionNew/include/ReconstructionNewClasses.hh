#include <vector>
#include "TAnalysis.hh"
#include "TJobManager.hh"
#include "TDriver.hh"
#include "TReconInput.hh"
#include "../drivers/common/TEventMarkerDriver.hh"
#include "../drivers/common/TRootSaveDriver.hh"

#include "../drivers/matrix/TMatrixWriterDriver.hh"
#include "../drivers/matrix/TMatrixReconDriver.hh"
#include "../drivers/matrix/TMatrixInterpreterDriver.hh"

#include "../drivers/tofpet/TTofpetDummyAnalysisDriver.hh"

#include "../drivers/TChargeAnalysisDriver.hh"
#include "../drivers/TChargeAnalysisPoissonDriver.hh"
#include "../drivers/TLikelihoodReconDriver.hh"


#ifdef __GCCXML__
TJobManager object1;
TDriver *object2;
std::vector <TDriver*> object3;
#endif
//#undef __G4String
