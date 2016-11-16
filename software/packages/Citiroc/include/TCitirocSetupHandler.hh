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

	map < int , int > m_CitirocToH8500; /*Key: the Citiroc id (0..63). Out: the H8500 Id (0..63)*/
	map < int , int > m_H8500ToCitiroc; /*Key: the H8500id (0..63).  Out: the CitirocId (0..63)*/
	void fillMaps();
public:


	static const int nCitirocChannelsPerBoard=32;



	TCitirocSetupHandler();
	//TCitirocSetupHandler(string fname);

	virtual ~TCitirocSetupHandler(){};

	
	
	

	ClassDef(TCitirocSetupHandler,1);
};
#endif 

