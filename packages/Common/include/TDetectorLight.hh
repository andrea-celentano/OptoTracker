#ifndef TDetectorLight_HG
#define TDetectorLight_HG

#include "TObject.h"
#include "TVector3.h"
#include "TMath.h"

#include <string>
#include <vector>
#include <fstream>

#define MAX_DETECTORS 256
using namespace std;
class TDetectorLight : public TObject
{
private:

	double LY,fastScintTime,rIndex;
	double scintSizeX,scintSizeY,scintSizeZ;

	int Ndet[6];int detPresent[6][MAX_DETECTORS];

	string detName[6][MAX_DETECTORS];
	double detSizeX[6][MAX_DETECTORS],detSizeY[6][MAX_DETECTORS];
	double detPixelSizeX[6][MAX_DETECTORS],detPixelSizeY[6][MAX_DETECTORS];
	int detNpixelsX[6][MAX_DETECTORS],detNpixelsY[6][MAX_DETECTORS];


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




	vector < double > posPixelX[6][MAX_DETECTORS];
	vector < double > posPixelY[6][MAX_DETECTORS];
	vector < double > posPixelZ[6][MAX_DETECTORS];

	std::string m_name;

	int m_totPixels,m_totDetectors;

public:
	TDetectorLight(string fname="");
	virtual ~TDetectorLight(){};
	/*Scintillator*/
	void setScintSizeX(double s){scintSizeX=s;}
	void setScintSizeY(double s){scintSizeY=s;}
	void setScintSizeZ(double s){scintSizeZ=s;}
	double getScintSizeX() const{return scintSizeX;}
	double getScintSizeY() const{return scintSizeY;}
	double getScintSizeZ() const{return scintSizeZ;}


	void setLY(double l){LY=l;}
	double getLY() const{return LY;}
	void setFastScintTime(double t){fastScintTime=t;}
	double getFastScintTime()  const{return fastScintTime;}
	double getRindex() const{return rIndex;}
	void setRindex(double n){rIndex=n;}

	/*Face*/
	double getFaceReflectivity(int ii) const{return faceReflectivity[ii];}
	void   setFaceReflectivity(int ii,double val){faceReflectivity[ii]=val;}

	/*Detector*/
	void setNdet(int iface, int N){Ndet[iface]=N;}
	int getNdet(int iface) const{return Ndet[iface];}

	int getDetGlobalID(int iface,int idetector) const;
	void getFaceDetIDfromGlobal(int global,int &iface,int &idetector) const;
	int getPixelGlobalID(int iface,int idetector,int ipixel) const;
	void getFaceDetPixelIDfromGlobal(int global,int &iface,int &idetector,int &ipixel) const;

	int getTotDetectors();
	int getTotPixels();

	void setDetSizeX(int iface,int idetector,double s){detSizeX[iface][idetector]=s;}
	void setDetSizeY(int iface,int idetector,double s){detSizeY[iface][idetector]=s;}
	double getDetSizeX(int iface,int idetector) const{return detSizeX[iface][idetector];}
	double getDetSizeY(int iface,int idetector) const{return detSizeY[iface][idetector];}

	double getDetCenterX(int iface,int idetector)  const{return detCenterX[iface][idetector];}
	double getDetCenterY(int iface,int idetector)  const{return detCenterY[iface][idetector];}
	double getDetRotation(int iface,int idetector) const{return detRotation[iface][idetector];}

	void setDetCenterX(int iface,int idetector,double val){detCenterX[iface][idetector]=val;}
	void setDetCenterY(int iface,int idetector,double val){detCenterY[iface][idetector]=val;}
	void setDetRotation(int iface,int idetector,double val){detRotation[iface][idetector]=val;}

	void setDetName(int iface,int idetector,string val){detName[iface][idetector]=val;}
	string getDetName(int iface, int idetector){return detName[iface][idetector];}

	void setNPixelsX(int iface,int idetector,int N){detNpixelsX[iface][idetector]=N;}
	void setNPixelsY(int iface,int idetector,int N){detNpixelsY[iface][idetector]=N;}
	int getNPixelsX(int iface,int idetector) const{return detNpixelsX[iface][idetector];}
	int getNPixelsY(int iface,int idetector) const{return detNpixelsY[iface][idetector];}
	int getNPixels(int iface,int idetector) const{return ((this->getNPixelsX(iface,idetector))*(this->getNPixelsY(iface,idetector)));}
	double getPixelSizeX(int iface,int idetector) const{return detPixelSizeX[iface][idetector];}
	double getPixelSizeY(int iface,int idetector) const{return detPixelSizeY[iface][idetector];}

	double getCouplingThickness(int iface, int idetector) const{return detCouplingThickness[iface][idetector];}
	double getCouplingRIndex(int iface, int idetector) const{return detCouplingRIndex[iface][idetector];}

	void setDetTimeRes(int iface,int idetector,double t){detTimeRes[iface][idetector]=t;}
	double getDetTimeRes(int iface,int idetector) const{return detTimeRes[iface][idetector];}
	double getDetQE(int iface,int idetector) const{return detQE[iface][idetector];}
	void setDetQE(int iface,int idetector,double QE){detQE[iface][idetector]=QE;}
	double getDetReflectivity(int iface,int idetector) const{return detReflectivity[iface][idetector];}
	void setDetReflectivity(int iface,int idetector,double val){detReflectivity[iface][idetector]=val;}





	int isDetPresent(int iface,int idetector) const{return detPresent[iface][idetector];}


	void setName(std::string name){m_name=name;}
	std::string getName(){return m_name;}

	TVector3 getPosPixel(int iface,int idetector,int ipixel) const;

	TVector3 getFaceNormal(int iface) const;
	TVector3 getFaceT1(int iface) const;
	TVector3 getFaceT2(int iface) const;

	TVector3 getDetectorNormal(int iface,int idetector) const{return this->getFaceNormal(iface);}
	TVector3 getDetectorT1(int iface,int idetector) const;
	TVector3 getDetectorT2(int iface,int idetector) const;
	/*
			int getPixelIDx(int iface,double x);
		int getPixelIDy(int iface,double y);
		int getPixelID(int iface,double x,double y);*/


	void init();

	void PrintPixels(Option_t* option = "") const;
	virtual void Print(Option_t* option = "") const;






	ClassDef(TDetectorLight,1);
};
#endif
