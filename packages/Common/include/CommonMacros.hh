#ifndef COMMONMACROS_HG
#define COMMONMACROS_HG

#define LOADLIBS ROOT::Cintex::Cintex::Enable();\
				 gSystem->Load("libCommonClassesDict.so");\
				 gSystem->Load("libTofpetAnalysisClassesDict.so");\
				 gSystem->Load("libOpNoviceClassesDict.so");\
			     gSystem->Load("libReconstructionNewClassesDict.so");

#endif
