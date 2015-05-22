#ifndef TOpNoviceDetectorLight_HG
#define TOpNoviceDetectorLight_HG

#include "TObject.h"
#include "TVector3.h"
#include "TMath.h"

#include <string>
#include <vector>
#include <fstream>

#define MAX_DETECTORS 256
using namespace std;
class TOpNoviceDetectorLight : public TObject
{
private:

	double LY,fastScintTime,rIndex;
	double scintSizeX,scintSizeY,scintSizeZ;

	int Ndet[6];
	double detSizeX[6][MAX_DETECTORS],detSizeY[6][MAX_DETECTORS];
	double detPixelSizeX[6][MAX_DETECTORS],detPixelSizeY[6][MAX_DETECTORS];
	int detNpixelsX[6][MAX_DETECTORS],detNpixelsY[6][MAX_DETECTORS];
	int detPresent[6][MAX_DETECTORS];

	/*Overall detector propeties*/
	double detQE[6][MAX_DETECTORS];
	double detReflectivity[6][MAX_DETECTORS];
	double detTimeRes[6][MAX_DETECTORS];

	/*Detector placement*/
	double detCenterX[6][MAX_DETECTORS];
	double detCenterY[6][MAX_DETECTORS];
	double detRotation[6][MAX_DETECTORS];

	/*Detector coupling*/
	double detCouplingRIndex[6][MAX_DETECTORS];
	double detCouplingThickness[6][MAX_DETECTORS];

	/*Wrapping*/
	double faceReflectivity[6];




	std::vector < double > posPixelX[6][MAX_DETECTORS];
	std::vector < double > posPixelY[6][MAX_DETECTORS];
	std::vector < double > posPixelZ[6][MAX_DETECTORS];



public:
	TOpNoviceDetectorLight(string fname);

	/*Scintillator*/
	void setScintSizeX(double s){scintSizeX=s;}
	void setScintSizeY(double s){scintSizeY=s;}
	void setScintSizeZ(double s){scintSizeZ=s;}
	double getScintSizeX(){return scintSizeX;}
	double getScintSizeY(){return scintSizeY;}
	double getScintSizeZ(){return scintSizeZ;}


	void setLY(double l){LY=l;}
	double getLY(){return LY;}
	void setFastScintTime(double t){fastScintTime=t;}
	double getFastScintTime(){return fastScintTime;}
	double getRindex(){return rIndex;}
	void setRindex(double n){rIndex=n;}

	/*Face*/
	double getFaceReflectivity(int ii){return faceReflectivity[ii];}
	void   setFaceReflectivity(int ii,double val){faceReflectivity[ii]=val;}

	/*Detector*/
	void setNdet(int iface, int N){Ndet[iface]=N;}
	int getNdet(int iface){return Ndet[iface];}

	void setDetSizeX(int iface,int idetector,double s){detSizeX[iface][idetector]=s;}
	void setDetSizeY(int iface,int idetector,double s){detSizeY[iface][idetector]=s;}
	double getDetSizeX(int iface,int idetector){return detSizeX[iface][idetector];}
	double getDetSizeY(int iface,int idetector){return detSizeY[iface][idetector];}

	double getDetCenterX(int iface,int idetector){return detCenterX[iface][idetector];}
	double getDetCenterY(int iface,int idetector){return detCenterY[iface][idetector];}
	double getDetRotation(int iface,int idetector){return detRotation[iface][idetector];}

	void setDetCenterX(int iface,int idetector,double val){detCenterX[iface][idetector]=val;}
	void setDetCenterY(int iface,int idetector,double val){detCenterY[iface][idetector]=val;}
	void setDetRotation(int iface,int idetector,double val){detRotation[iface][idetector]=val;}

	void setNPixelsX(int iface,int idetector,int N){detNpixelsX[iface][idetector]=N;}
	void setNPixelsY(int iface,int idetector,int N){detNpixelsY[iface][idetector]=N;}
	int getNPixelsX(int iface,int idetector){return detNpixelsX[iface][idetector];}
	int getNPixelsY(int iface,int idetector){return detNpixelsY[iface][idetector];}
	int getNPixels(int iface,int idetector){return ((this->getNPixelsX(iface,idetector))*(this->getNPixelsY(iface,idetector)));}
	double getPixelSizeX(int iface,int idetector){return detPixelSizeX[iface][idetector];}
	double getPixelSizeY(int iface,int idetector){return detPixelSizeY[iface][idetector];}

	double getCouplingThickness(int iface, int idetector){return detCouplingThickness[iface][idetector];}
	double getCouplingRIndex(int iface, int idetector){return detCouplingRIndex[iface][idetector];}

	void setDetTimeRes(int iface,int idetector,double t){detTimeRes[iface][idetector]=t;}
	double getDetTimeRes(int iface,int idetector){return detTimeRes[iface][idetector];}
	double getDetQE(int iface,int idetector){return detQE[iface][idetector];}
	void setDetQE(int iface,int idetector,double QE){detQE[iface][idetector]=QE;}
	double getDetReflectivity(int iface,int ipixel){return detReflectivity[iface][ipixel];}
	void setDetReflectivity(int iface,int ipixel,double val){detReflectivity[iface][ipixel]=val;}





	int isDetPresent(int iface,int idetector){return detPresent[iface][idetector];}



	std::string getName(){return "detector";}

	TVector3 getPosPixel(int iface,int idetector,int ipixel){return  TVector3(posPixelX[iface][idetector].at(ipixel),posPixelY[iface][idetector].at(ipixel),posPixelZ[iface][idetector].at(ipixel));}


	TVector3 getFaceNormal(int iface);
	TVector3 getFaceT1(int iface);
	TVector3 getFaceT2(int iface);

	TVector3 getDetectorT1(int iface,int idetector);
	TVector3 getDetectorT2(int iface,int idetector);
	/*
			int getPixelIDx(int iface,double x);
		int getPixelIDy(int iface,double y);
		int getPixelID(int iface,double x,double y);*/


	void init();

	void printPixels();
	void printDet();




	//static TOpNoviceDetectorLight* getInstance();
	//	virtual ~TOpNoviceDetectorLight();

	ClassDef(TOpNoviceDetectorLight,1);
};
#endif
