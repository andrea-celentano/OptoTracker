#ifndef MarocSetupHandler_HG
#define MarocSetupHandler_HG

#include <iostream>
#include <fstream>

#include "RealSetupHandler.hh"

using namespace std;

class MarocSetupHandler:public RealSetupHandler{
  
  private:
     static const int nH8500pixels=64;
  public:
    MarocSetupHandler();
    MarocSetupHandler(string fname);
    
    int getMarocId(int globalID);  /*This methods returns the MAROC card, from 0 to 31, given the globalID*/
    int getH8500Id(int globalID);  /*This methods returns the pixel id, in H8500 arrangement, from 0 to 63, given the globalID*/
    //int getPixelReconId
   // double H8500Gain(int H8500Id,int PmtID);

    //double MarocGain(int MarocId);
    //int GetGeometryId(int MarocId,int faceID);


};
#endif 

