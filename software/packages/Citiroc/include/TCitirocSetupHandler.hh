#ifndef CITIROCSetupHandler_HG
#define CITIROCSetupHandler_HG

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "TRealSetupHandler.hh"

using namespace std;

class TCitirocSetupHandler:public TRealSetupHandler{

private:

	void processLine(string line);

	/*First two maps are not so fundamental*/
	map < std::pair<int,int>, int > m_reconstructionDetFacefromCitirocIDChannel;
	map < std::pair<int,int>, int > m_reconstructionDetIDfromCitirocIDChannel;
	map < std::pair<int,int>, int > m_reconstructionDetPixelfromCitirocIDChannel;




public:


	static const int nCitirocChannelsPerBoard=32;

	int getReconstructionDetectorPixel(int ID,int ch);

	TCitirocSetupHandler();
	TCitirocSetupHandler(string fname);

	virtual ~TCitirocSetupHandler(){};

	
	
	

	ClassDef(TCitirocSetupHandler,1);
};
#endif 

