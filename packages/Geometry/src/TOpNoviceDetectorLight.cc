#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <stdlib.h>     /* atof */

#include "TVector3.h"
#include "TOpNoviceDetectorLight.hh"

using namespace std;
/*
static TOpNoviceDetectorLight* detectorLight = 0;

TOpNoviceDetectorLight* TOpNoviceDetectorLight::getInstance(){

 if (detectorLight==0){
 cout<<"TOpNoviceDetectorLight::getInstance() creates a new detectorLight"<<endl;
 detectorLight=new TOpNoviceDetectorLight();
 }
 return detectorLight;

 }
 */

TOpNoviceDetectorLight::TOpNoviceDetectorLight(string fname)
{	
	ifstream file(fname.c_str());
	string line,key,data;
	istringstream parser;

	int face,id;

	cout<<"TOpNoviceDetectorLight: init with file "<<fname<<endl;
	if (!file){
		cout<<"Error in TOpNoviceDetectorLight, file not found: "<<fname<<endl;
		exit(1);
	}
	while(!file.eof()){
		getline (file,line);
		if (line.size()==0) continue;

		parser.clear();
		parser.str(line);
		parser>>key;

		if (key[0]=='#') continue; //comment

		if (key=="DetectorSize"){
			parser>>data;scintSizeX=atof(data.c_str());
			parser>>data;scintSizeY=atof(data.c_str());
			parser>>data;scintSizeZ=atof(data.c_str());
		}
		else if (key=="ScintillatorLY"){
			parser>>data;LY=atof(data.c_str());
		}
		else if (key=="ScintillatorFastTau"){
			parser>>data;fastScintTime=atof(data.c_str());
		}
		else if (key=="ScintillatorRindex"){
			parser>>data;rIndex=atof(data.c_str());
		}


		else if (key=="Face"){
			parser>>data;face=atoi(data.c_str());
			Ndet[face]=0;
			parser>>data;Ndet[face]=atoi(data.c_str());
			if (Ndet[face]<=0){
				cout<<"Error in TOpNoviceDetectorLight, face "<<face+1<<"has <=0 detector"<<endl;
			}
		}
		else if (key=="FaceProperties"){
			parser>>data;faceReflectivity[face]=atof(data.c_str());
		}
		else if (key=="Detector"){
			parser>>data;id=atoi(data.c_str());

			parser>>data;detSizeX[face][id]=atof(data.c_str());
			parser>>data;detSizeY[face][id]=atof(data.c_str());
			parser>>data;detNpixelsX[face][id]=atoi(data.c_str());
			parser>>data;detNpixelsY[face][id]=atoi(data.c_str());

		}
		else if (key=="DetectorProperties"){

			parser>>data;detQE[face][id]=atof(data.c_str());
			parser>>data;detReflectivity[face][id]=atof(data.c_str());
			parser>>data;detTimeRes[face][id]=atof(data.c_str());

		}
		else if (key=="DetectorPlacement"){

			parser>>data;detCenterX[face][id]=atof(data.c_str());
			parser>>data;detCenterY[face][id]=atof(data.c_str());
			parser>>data;detRotation[face][id]=atof(data.c_str());
		}

		else if (key=="DetectorCoupling"){

			parser>>data;detCouplingRIndex[face][id]=atof(data.c_str());
			parser>>data;detCouplingThickness[face][id]=atof(data.c_str());
		}

	}
	init();

}















/*Attention. This method has to be called only when the following have been set:
  - scintillatorSize
  - detectorSize
  - number of pixels
 */
void TOpNoviceDetectorLight::init(){
	cout<<"TOpNoviceDetectorLight::init()"<<endl;
	double x,y,z,xd,yd,xf,yf;
	int ipixel;

	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<Ndet[ii];jj++)
			if ((detSizeX[ii][jj]<=0)||(detSizeY[ii][jj]<=0)) detPresent[ii][jj]=0;
			else {
				detPresent[ii][jj]=1;
				detPixelSizeX[ii][jj]=detSizeX[ii][jj]/detNpixelsX[ii][jj];
				detPixelSizeY[ii][jj]=detSizeY[ii][jj]/detNpixelsY[ii][jj];
			}
	}




	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<Ndet[ii];jj++){
			if (detPresent[ii][jj]==0) continue;

			posPixelX[ii][jj].clear();posPixelY[ii][jj].clear();posPixelZ[ii][jj].clear();


			for (int iy=0;iy<detNpixelsY[ii][jj];iy++){
				for (int ix=0;ix<detNpixelsX[ii][jj];ix++){

					xd=(-detSizeX[ii][jj]/2+ix*detPixelSizeX[ii][jj]+detPixelSizeX[ii][jj]/2);
					yd=(-detSizeY[ii][jj]/2+iy*detPixelSizeY[ii][jj]+detPixelSizeY[ii][jj]/2);

					xf=xd*cos(detRotation[ii][jj]*TMath::DegToRad())-yd*sin(detRotation[ii][jj]*TMath::DegToRad());
					yf=+xd*sin(detRotation[ii][jj]*TMath::DegToRad())+yd*cos(detRotation[ii][jj]*TMath::DegToRad());



					xf=xf+detCenterX[ii][jj];
					yf=yf+detCenterY[ii][jj];

					switch (ii){
					case 0: //faccia 1:yx, +z
					z=+scintSizeZ/2+detCouplingThickness[ii][jj];
					x=-xf;
					y=yf;
					break;
					case 2: //faccia 3: yx, -z
						z=-scintSizeZ/2-detCouplingThickness[ii][jj];
						x=xf;
						y=yf;
						break;
					case 1: //faccia 2: yz, +x
						x=+scintSizeX/2+detCouplingThickness[ii][jj];
						y=yf;
						z=xf;
						break;

					case 3: //faccia 4: yz, -x
						x=-scintSizeX/2-detCouplingThickness[ii][jj];
						y=yf;
						z=-xf;
						break;

					case 4: //faccia 5, xz, +y
						y=scintSizeY/2+detCouplingThickness[ii][jj];;
						x=xf;
						z=yf;
						break;
					case 5: //faccia 6, xz, -y
						y=-scintSizeY/2-detCouplingThickness[ii][jj];;
						x=xf;
						z=-yf;
						break;
					}
					posPixelX[ii][jj].push_back(x);posPixelY[ii][jj].push_back(y);posPixelZ[ii][jj].push_back(z);
				}
			}
		}
	}
	cout<<"TOpNoviceDetectorLight::init() done"<<endl;
}
/*
    int TOpNoviceDetectorLight::getPixelIDx(int iface,double x){
      int id;
      id=(int)((x+detSizeX[iface]/2)/(detPixelSizeX[iface]));
      if (id>=this->getNPixelsX(iface)) id=this->getNPixelsX(iface)-1;
      return id;	
    }
    int TOpNoviceDetectorLight::getPixelIDy(int iface,double y){
      int id;
      id=(int)((y+detSizeY[iface]/2)/(detPixelSizeY[iface]));
      if (id>=this->getNPixelsY(iface)) id=this->getNPixelsY(iface)-1;
      return id;	

    }
    int TOpNoviceDetectorLight::getPixelID(int iface,double x,double y){
      int idx,idy,id;
      idx=this->getPixelIDx(iface,x);
      idy=this->getPixelIDy(iface,y);

      id=idx+detNpixelsX[iface]*idy;

      return id;

    }


 */

void TOpNoviceDetectorLight::printPixels(){
	int id;

	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<Ndet[ii];jj++){
			if (this->isDetPresent(ii,jj)==0) continue;
			printf("face: %i, detector: %i \n",ii,jj);
			printf("id \t \t X \t \t Y \t \t Z \t \t t1X \t \t t1Y \t \t t1Z \t \t t2X \t \t t2Y \t \t t2Z \n");
			for (int iy=0;iy<detNpixelsY[ii][jj];iy++){
				for (int ix=0;ix<detNpixelsX[ii][jj];ix++){
					id=ix+detNpixelsX[ii][jj]*iy;
					printf("%i \t \t %f \t %f \t %f \t %f \t %f \t %f \t %f \t %f \t %f \n",id,posPixelX[ii][jj].at(id),posPixelY[ii][jj].at(id),posPixelZ[ii][jj].at(id),this->getDetectorT1(ii,jj).X(),this->getDetectorT1(ii,jj).Y(),this->getDetectorT1(ii,jj).Z(),this->getDetectorT2(ii,jj).X(),this->getDetectorT2(ii,jj).Y(),this->getDetectorT2(ii,jj).Z());
				}
			}
			printf("*********************\n\n");

		}
	}
}



void TOpNoviceDetectorLight::printDet(){
	printf("Scintillator size: \t %f \t %f \t %f \n",this->getScintSizeX(),this->getScintSizeY(),this->getScintSizeZ());
	printf("Decay time: \t %f \n",this->getFastScintTime());
	printf("LY: \t %f \n",this->getLY());
	printf("rIndex: \t %f \n",this->getRindex());
	printf("Face \t Detector \t SizeX \t \t SizeY \t \t PixelsX \t PixelsY \t TimeRes \t QE \n");
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<Ndet[ii];jj++){
			if (this->isDetPresent(ii,jj)) printf("%i \t %i \t \t  %f \t %f \t %i \t \t %i \t \t %f \t  %f\n",ii,jj,this->getDetSizeX(ii,jj),this->getDetSizeY(ii,jj),this->getNPixelsX(ii,jj),this->getNPixelsY(ii,jj),this->getDetTimeRes(ii,jj),this->getDetQE(ii,jj));
			else printf("%i \t \t Not present \n",ii+1);
		}
	}


}












/*Return the EXITING normal of a face*/
TVector3 TOpNoviceDetectorLight::getFaceNormal(int iface){
	switch (iface){
	case 0:
		return TVector3(0.,0.,1.);
		break;
	case 1:
		return TVector3(1.,0.,0.);
		break;
	case 2:
		return TVector3(0.,0.,-1.);
		break;
	case 3:
		return TVector3(-1.,0.,0.);
		break;
	case 4:
		return TVector3(0.,1.,0.);
		break;
	case 5:
		return TVector3(0.,-1.,0.);
		break;
	}
}

/*Return the first tangent vector*/
TVector3 TOpNoviceDetectorLight::getFaceT1(int iface){
	switch (iface){
	case 0:
		return TVector3(-1.,0.,0.);
		break;
	case 1:
		return TVector3(0.,0.,1.);
		break;
	case 2:
		return TVector3(1.,0.,0.);
		break;
	case 3:
		return TVector3(0.,0.,-1.);
		break;
	case 4:
		return TVector3(1.,0.,0.);
		break;
	case 5:
		return TVector3(1.,0.,0.);
		break;
	}
}

/*Return the second tangent vector*/
TVector3 TOpNoviceDetectorLight::getFaceT2(int iface){
	switch (iface){
	case 0:
		return TVector3(0.,1.,0.);
		break;
	case 1:
		return TVector3(0.,1.,0.);
		break;
	case 2:
		return TVector3(0.,1.,0.);
		break;
	case 3:
		return TVector3(0.,1.,0.);
		break;
	case 4:
		return TVector3(0.,0.,1.);
		break;
	case 5:
		return TVector3(0.,0.,1.);
		break;
	}
}



/*Return the first tangent vector*/
TVector3 TOpNoviceDetectorLight::getDetectorT1(int iface,int idetector){

	TVector3 n1(cos(detRotation[iface][idetector]*TMath::DegToRad()),sin(detRotation[iface][idetector]*TMath::DegToRad()),0);





	switch (iface){
	case 0:
		return TVector3(-n1.X(),n1.Y(),0.);
		break;
	case 1:
		return TVector3(0.,n1.Y(),n1.X());
		break;
	case 2:
		return TVector3(n1.X(),n1.Y(),0.);
		break;
	case 3:
		return TVector3(0.,n1.Y(),-n1.X());
		break;
	case 4:
		return TVector3(n1.X(),0.,n1.Y());
		break;
	case 5:
		return TVector3(n1.X(),0.,-n1.Y());
		break;
	}
}

/*Return the second tangent vector*/
TVector3 TOpNoviceDetectorLight::getDetectorT2(int iface,int idetector){
	TVector3 n2(-sin(detRotation[iface][idetector]*TMath::DegToRad()),cos(detRotation[iface][idetector]*TMath::DegToRad()),0);
	switch (iface){
	case 0:
		return TVector3(-n2.X(),n2.Y(),0.);
		break;
	case 1:
		return TVector3(0.,n2.Y(),n2.X());
		break;
	case 2:
		return TVector3(n2.X(),n2.Y(),0.);
		break;
	case 3:
		return TVector3(0.,n2.Y(),-n2.X());
		break;
	case 4:
		return TVector3(n2.X(),0.,n2.Y());
		break;
	case 5:
		return TVector3(n2.X(),0.,-n2.Y());
		break;
	}
}











