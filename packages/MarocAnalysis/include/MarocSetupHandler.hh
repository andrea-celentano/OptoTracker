#ifndef MarocSetupHandler_HG
#define MarocSetupHandler_HG

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "RealSetupHandler.hh"

using namespace std;

class MarocSetupHandler:public RealSetupHandler{

private:

	void processLine(string line);

	map < int , int > m_MarocToH8500; /*Key: the MAROC id (0..63). Out: the H8500 Id (0..63)*/
	map < int , int > m_H8500ToMaroc; /*Key: the MAROC id (0..63). Out: the H8500 Id (0..63)*/
	void fillMaps();
public:

	static const int nH8500Pixels=64;
	static const int nH8500PixelsX=8;
	static const int nH8500PixelsY=8;


	MarocSetupHandler();
	MarocSetupHandler(string fname);


	int getMarocCard(int globalID);  /*This methods returns the MAROC CARD, from 0 to 63, given the globalID*/
	int getMarocChannelFromGlobal(int globalID);  /*This methods returns the MAROC CHANNEL, from 0 to 63, given the globalID*/
	int getMarocChannelFromH8500(int H8500ID);   /*This methods returns the MAROC CHANNEL, from 0 to 63, given the H8500ID*/


	int getH8500IdFromGlobal(int globalID);  /*This methods returns the pixel id, in H8500 arrangement, from 0 to 63, given the globalID*/
	int getH8500IdFromMaroc(int globalID);  /*This methods returns the pixel id, in H8500 arrangement, from 0 to 63, given the MAROCId*/


	int getPixelReconId(int globalID); /*This method is specific to this setup. Given the globalID, returns the pixelID, in the recon system coordinates*/
	int getPixelReconId(int iRealDet,int iRealPixel); /*This method is specific to this setup. Given the globalID, returns the pixelID, in the recon system coordinates*/

	/*#ifndef MarocAnalysisDef_HG
#define MarocAnalysisDef_HG
#define N0 2048
#define Ncards 2
#define NperCard 64
#define Ntot (Ncards*NperCard)
*/





	//int getPixelReconId
	// double H8500Gain(int H8500Id,int PmtID);

	//double MarocGain(int MarocId);
	//int GetGeometryId(int MarocId,int faceID);


};
#endif 

