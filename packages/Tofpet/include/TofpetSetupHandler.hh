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

	void processLine(std::string line);


	/*This is the SiPM matrix*/
	static const int nMPPCPixels=64;
	static const int nMPPCPixelsX=8;
	static const int nMPPCPixelsY=8;

	/*This is a TOFPET assembly, with 2 MPPCs.*/
	static const int nTofpetPixels=128;
	static const int nTofpetPixelsX=16;
	static const int nTofpetPixelsY=8;




	ClassDef(TofpetSetupHandler,1);
};

#endif
