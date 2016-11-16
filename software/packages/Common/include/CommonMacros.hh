#ifndef COMMONMACROS_HG
#define COMMONMACROS_HG

#define LOADLIBS ROOT::Cintex::Cintex::Enable();\
				 gSystem->Load("${OPTO}/software/lib/libCommonClassesDict.so");\
		 		 gSystem->Load("${OPTO}/software/lib/libTofpetClassesDict.so");\
				 gSystem->Load("${OPTO}/software/lib/libOpNoviceClassesDict.so");\
				 gSystem->Load("${OPTO}/software/lib/libMarocClassesDict.so");\
				  gSystem->Load("${OPTO}/software/lib/libCitirocClassesDict.so");\
  			     gSystem->Load("${OPTO}/software/lib/libReconstructionNewClassesDict.so");
#endif
