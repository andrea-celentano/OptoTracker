#ifndef COMMONMACROS_HG
#define COMMONMACROS_HG

#define LOADLIBS ROOT::Cintex::Cintex::Enable();\
				 gSystem->Load("${OPTO}/lib/libCommonClassesDict.so");\
			     gSystem->Load("${OPTO}/lib/libReconstructionNewClassesDict.so");\
				 gSystem->Load("${OPTO}/lib/libOpNoviceClassesDict.so");\
				 gSystem->Load("${OPTO}/lib/libTofpetAnalysisClassesDict.so");

#endif
