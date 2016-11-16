#ifndef COMMONMACROS_HG
#define COMMONMACROS_HG

#define LOADLIBS ROOT::Cintex::Cintex::Enable();\
				 gSystem->Load("${OPTO}/lib/libCommonClassesDict.so");\
		 		 gSystem->Load("${OPTO}/lib/libTofpetClassesDict.so");\
				 gSystem->Load("${OPTO}/lib/libOpNoviceClassesDict.so");\
				 gSystem->Load("${OPTO}/lib/libMarocClassesDict.so");\
  			     gSystem->Load("${OPTO}/lib/libReconstructionNewClassesDict.so");
#endif
