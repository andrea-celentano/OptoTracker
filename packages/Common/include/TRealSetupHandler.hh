#ifndef REAL_GEOMETRY_HANDLER_HG
#define REAL_GEOMETRY_HANDLER_HG

#include <iostream>
#include <iomanip>

#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <string>
#include <utility>
#include "TDetector.hh"

#include "TObject.h"

using namespace std;

/*
 * This is the base class for all the "real" geometries, i.e. it provides the matching between
a real configuration, with detectors handled in a "certain" way, 
and the reconstruction configuration, that is defined in a "universal" way.
 To do this, one specifies:  RealDetectorID --> reconstruction detector face / reconstruction detector ID (in the face)
In the "real" analysis, one will derive a concrete instance of this base class
 */

class TRealSetupHandler : public TObject{
protected:
	/*
    These are the 2 maps that provide, given the RealDetectorId (key), 
    the detector face (0..5) and the detectorID (in the face)
	 */
	map < int , int > m_reconstructionDetFace;
	map < int , int > m_reconstructionDetID;

	/*The inverse map. Note that only (face/id) --> RealID has meaning*/
	map <  pair < int , int > , int >  m_reconstructionRealDet;

	/*These maps will hold the pixels gain, for the reconstruction detector face and detectorID*/
	map < int , double > m_PixelGain1[6][MAX_DETECTORS];
	map < int , double > m_PixelGain2[6][MAX_DETECTORS];
	map < int , double > m_PixelGain3[6][MAX_DETECTORS];


	int nRealDet;
	int m_thisReconFace;
	int m_thisReconDetID;
	int m_thisRealDetID;
	int m_thisPixel;
	int m_thisPixelFirst;
	int m_thisPixelLast;

	int m_thisGainEntry;
	double m_thisGainVal;

	void processLine(string line);

public:
	TRealSetupHandler(string fname);
	TRealSetupHandler();


	int    getReconstructionDetectorFace(int idet);
	int    getReconstructionDetectorID(int idet);
	int    getRealDetectorID(int iface,int idet);

	/*These are 2 functions to set and get a pixel gain.
     There are 3 gains per pixel, for convenience: 
     If igain==0 (default), return the product of the 3
     If a gain is not set, use "1" instead
	 */

	double getPixelGain(int iface,int idetector, int ipixel,int igain=0);
	void   setPixelGain(int iface,int idetector, int ipixel,int igain,double val);
	void   Print(int printPixels=0);
	void   PrintPixels(int iface,int idetector);


	ClassDef(TRealSetupHandler,1);
};





#endif
