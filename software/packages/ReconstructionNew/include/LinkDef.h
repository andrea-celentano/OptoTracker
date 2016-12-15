#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclasses;



#pragma link C++ class std::vector< TDriver * >+;
#pragma link C++ class TAnalysis+;
#pragma link C++ class TJobManager+;
#pragma link C++ class TDriver+;
#pragma link C++ class TReconInput+;
#pragma link C++ class TEventMarkerDriver+;
#pragma link C++ class TReconHit+;

#pragma link C++ class TRootSaveDriver+;
#pragma link C++ class TChargeAnalysisDriver+;


#pragma link C++ class TChargeAnalysisPoissonDriver+;

#pragma link C++ class TLikelihoodReconDriver+;
#pragma link C++ class TLikelihoodComputationDriver+;

#pragma link C++ class TMatrixWriterDriver+;
#pragma link C++ class TMatrixReconDriver+;
#pragma link C++ class TMatrixInterpreterDriver+;

#pragma link C++ class TMCDataReaderDriver+;

#pragma link C++ class TCitirocDataReaderDriver+;
#pragma link C++ class TCitirocBasicDriver+;
#pragma link C++ class TCitirocSetupHandlerDriver+;
#pragma link C++ class TCitirocChargeCalibrationDriver+;
#pragma link C++ class TCitirocReconHitAnaDriver+;

#pragma link C++ class TTofpetDummyAnalysisDriver+;
#pragma link C++ class TTofpetTimeAnalysisDriver+;
#pragma link C++ class TTofpetSetupHandlerDriver+;
#pragma link C++ class TTofpetThresholdCalibrationDriver+;

#pragma link C++ class TMarocSetupHandlerDriver+;
#pragma link C++ class TMarocBasicDriver+;
#pragma link C++ class TMarocDataReaderDriver+;


#pragma link C++ class TLikelihoodCalculator+;
#pragma link C++ class TLikelihoodCalculatorIdeal+;
#pragma link C++ class TLikelihoodCalculatorMaroc1+;

#endif
