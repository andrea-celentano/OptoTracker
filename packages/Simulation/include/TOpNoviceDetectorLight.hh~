#ifndef TOpNoviceDetectorLight_HG
#define TOpNoviceDetectorLight_HG

#include "TObject.h"
#include "TVector3.h"


#include <string>
#include <vector>
class TOpNoviceDetectorLight : public TObject
{
	private:
		double scintSizeX,scintSizeY,scintSizeZ;
		double detSizeX[6],detSizeY[6];
		double detPixelSizeX[6],detPixelSizeY[6];
		double detTimeRes[6];
		int detNpixelsX[6],detNpixelsY[6];
		int detPresent[6];
		double LY,fastScintTime,rIndex;
		
	
		std::vector < double > posPixelX[6];
		std::vector < double > posPixelY[6];
		std::vector < double > posPixelZ[6];
	
		std::vector < double > posPixelScaledX[6];
		std::vector < double > posPixelScaledY[6];
		std::vector < double > posPixelScaledZ[6];
		
		std::vector < double > QE[6];
		int QEinit;
	public:
		void setScintSizeX(double s){scintSizeX=s;}
		void setScintSizeY(double s){scintSizeY=s;}
		void setScintSizeZ(double s){scintSizeZ=s;}
		double getScintSizeX(){return scintSizeX;}
		double getScintSizeY(){return scintSizeY;}
		double getScintSizeZ(){return scintSizeZ;}
		
	
		void setDetSizeX(int i,double s){detSizeX[i]=s;}
		void setDetSizeY(int i,double s){detSizeY[i]=s;}
		double getDetSizeX(int i){return detSizeX[i];}
		double getDetSizeY(int i){return detSizeY[i];}
		
	
		void setNPixelsX(int i,int N){detNpixelsX[i]=N;}
		void setNPixelsY(int i,int N){detNpixelsY[i]=N;}
		int getNPixelsX(int i){return detNpixelsX[i];}
		int getNPixelsY(int i){return detNpixelsY[i];}
		int getNPixels(int i){return ((this->getNPixelsX(i))*(this->getNPixelsY(i)));}
	
		void setTimeRes(int iface,double t){detTimeRes[iface]=t;}
		double getTimeRes(int iface){return detTimeRes[iface];}
	
		void setLY(double l){LY=l;}
		double getLY(){return LY;}
		
		void setFastScintTime(double t){fastScintTime=t;}
		double getFastScintTime(){return fastScintTime;}
		
		double getRindex(){return rIndex;}
		void setRindex(double n){rIndex=n;}
	
		double getQE(int iface,int ipixel);
		void setQE(int iface,int ipixel,double QE);
		
		double getQEmean(int iface);
		void setQEmean(int iface,double QE);
		
	
		double getPixelSizeX(int iface){return detPixelSizeX[iface];}
		double getPixelSizeY(int iface){return detPixelSizeY[iface];}
		int isDetPresent(int iface){return detPresent[iface];}
		int getPixelIDx(int iface,double x);
		int getPixelIDy(int iface,double y);
		int getPixelID(int iface,double x,double y);
	
		std::string getName(){return "detector";}
	
		TVector3 getPosPixel(int iface,int ipixel){return  TVector3(posPixelX[iface].at(ipixel),posPixelY[iface].at(ipixel),posPixelZ[iface].at(ipixel));}
		TVector3 getPosPixelScaled(int iface,int ipixel){return  TVector3(posPixelScaledX[iface].at(ipixel),posPixelScaledY[iface].at(ipixel),posPixelScaledZ[iface].at(ipixel));}
	
		TVector3 getPixelNormal(int iface,int ipixel);
		TVector3 getPixelT1(int iface,int ipixel);
		TVector3 getPixelT2(int iface,int ipixel);
	
		/*Attention. This method has to be called only when the following have been set:
		- scintillatorSize
		- detectorSize
		- number of pixels
		*/
		void init();
		
		void printPixels();
		void printDet();
	
		TOpNoviceDetectorLight();
	
		static TOpNoviceDetectorLight* getInstance();
	//	virtual ~TOpNoviceDetectorLight();
	
	ClassDef(TOpNoviceDetectorLight,1);
};
#endif