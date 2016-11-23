#include <vector>
#include "TAnalysis.hh"
#include "TJobManager.hh"
#include "TDriver.hh"
#include "TReconInput.hh"
#include "TReconHit.hh"

#include "../drivers/common/TEventMarkerDriver.hh"
#include "../drivers/common/TRootSaveDriver.hh"

#include "../drivers/matrix/TMatrixWriterDriver.hh"
#include "../drivers/matrix/TMatrixReconDriver.hh"
#include "../drivers/matrix/TMatrixInterpreterDriver.hh"


#include "../drivers/common/TChargeAnalysisDriver.hh"
#include "../drivers/common/TChargeAnalysisPoissonDriver.hh"
#include "../drivers/common/TLikelihoodReconDriver.hh"
#include "../drivers/common/TLikelihoodComputationDriver.hh"


#include "../drivers/tofpet/TTofpetDummyAnalysisDriver.hh"
#include "../drivers/tofpet/TTofpetTimeAnalysisDriver.hh"
#include "../drivers/tofpet/TTofpetSetupHandlerDriver.hh"
#include "../drivers/tofpet/TTofpetThresholdCalibrationDriver.hh"


#include "../drivers/maroc/TMarocSetupHandlerDriver.hh"
#include "../drivers/maroc/TMarocBasicDriver.hh"
#include "../drivers/maroc/TMarocDataReaderDriver.hh"

#include "../drivers/citiroc/TCitirocBasicDriver.hh"
#include "../drivers/citiroc/TCitirocDataReaderDriver.hh"
#include "../drivers/citiroc/TCitirocSetupHandlerDriver.hh"
#include "../drivers/citiroc/TCitirocChargeCalibrationDriver.hh"
#include "../drivers/citiroc/TCitirocReconHitAnaDriver.hh"

#include "../drivers/MC/TMCDataReaderDriver.hh"

#include "../likelihoodCalculators/TLikelihoodCalculator.hh"
#include "../likelihoodCalculators/TLikelihoodCalculatorIdeal.hh"
#include "../likelihoodCalculators/TLikelihoodCalculatorMaroc1.hh"

#ifdef __GCCXML__
TJobManager object1;
TDriver *object2;
std::vector <TDriver*> object3;
#endif
//#undef __G4String
