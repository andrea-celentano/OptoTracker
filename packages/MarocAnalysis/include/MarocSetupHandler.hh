#ifndef MarocSetupHandler_HG
#define MarocSetupHandler_HG

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "TRealSetupHandler.hh"

using namespace std;

class MarocSetupHandler:public TRealSetupHandler{

private:

	void processLine(string line);

	map < int , int > m_MarocToH8500; /*Key: the MAROC id (0..63). Out: the H8500 Id (0..63)*/
	map < int , int > m_H8500ToMaroc; /*Key: the H8500id (0..63).  Out: the MarocId (0..63)*/
	void fillMaps();
public:

	static const int nH8500Pixels=64;
	static const int nH8500PixelsX=8;
	static const int nH8500PixelsY=8;

	static const int nMarocChannels=4096;


	MarocSetupHandler();
	MarocSetupHandler(string fname);


	int getMarocCard(int globalID);  /*This methods returns the MAROC CARD, from 0 to 63, given the globalID*/ /*The MAROC CARD (0..31) is the number to identify the "REAL" detector*/
	int getMarocChannelFromGlobal(int globalID);  /*This methods returns the MAROC CHANNEL, from 0 to 63, given the globalID*/
	int getMarocChannelFromH8500(int H8500ID);   /*This methods returns the MAROC CHANNEL, from 0 to 63, given the H8500ID*/


	int getH8500IdFromGlobal(int globalID);  /*This methods returns the pixel id, in H8500 arrangement, from 0 to 63, given the globalID (from 0 to 4095)*/
	int getH8500IdFromMaroc(int globalID);   /*This methods returns the pixel id, in H8500 arrangement, from 0 to 63, given the MAROCId (from 0 to 63)*/


	int getPixelReconId(int globalID);                /*This method is specific to this setup. Given the globalID, returns the pixelID, in the recon system coordinates*/
	int getPixelReconId(int iRealDet,int iRealPixel); /*This method is specific to this setup. Given the realDetID (i.e. the maroc card) and the pixel Id (i.e. the H8500 channel), returns the pixelID, in the recon system coordinates*/

	
	double getPixelGainFromGlobal(int globalID,int igain=0); /*Given the globalID (0..4095) it retuns the pixel gain*/
	
	


};
#endif 

