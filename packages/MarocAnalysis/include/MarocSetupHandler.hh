#ifndef MarocSetupHandler_HG
#define MarocSetupHandler_HG

#include <iostream>
#include <fstream>

#include "RealSetupHandler.hh"

using namespace std;

class MarocSetupHandler:public RealSetupHandler{
  
  public:
    MarocSetupHandler();
    MarocSetupHandler(string fname);
    
    int GetMarocId(int globalId);
    int GetH8500Id(int globalId);
    double H8500Gain(int H8500Id,int PmtID);

    double MarocGain(int MarocId);
    int GetSetupId(int MarocId,int faceID);


};
#endif 

