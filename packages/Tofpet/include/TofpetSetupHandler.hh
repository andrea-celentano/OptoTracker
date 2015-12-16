#ifndef TOFPETSETUPHANDLER_HG
#define TOFPETSETUPHANDLER_HG

#include <string>
#include "TObject.h"

#include "TRealSetupHandler.hh"

class TofpetSetupHandler : public TRealSetupHandler{

private:

public:
	TofpetSetupHandler();
	TofpetSetupHandler(std::string fname);


	ClassDef(TofpetSetupHandler,1);
};





#endif
