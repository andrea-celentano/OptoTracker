#include <iostream>
#include <cmath>

#include "TVector3.h"
#include "TOpNoviceDetectorLight.hh"

using namespace std;

static TOpNoviceDetectorLight* detectorLight = 0;

TOpNoviceDetectorLight* TOpNoviceDetectorLight::getInstance(){
  
  if (detectorLight==0){
    cout<<"TOpNoviceDetectorLight::getInstance() creates a new detectorLight"<<endl;
    detectorLight=new TOpNoviceDetectorLight();
  }
  return detectorLight;
  
}

TOpNoviceDetectorLight::TOpNoviceDetectorLight():QEinit(0)
{	
  
}

/*Attention. This method has to be called only when the following have been set:
- scintillatorSize
- detectorSize
- number of pixels
*/
void TOpNoviceDetectorLight::init(){
  cout<<"TOpNoviceDetectorLight::init()"<<endl;
  double x,y,z,xs,ys,zs;
  int ipixel;
  
  for (int ii=0;ii<6;ii++){
    if ((detSizeX[ii]<=0)||(detSizeY[ii]<=0)) detPresent[ii]=0;
    else { 
      detPresent[ii]=1;
      detPixelSizeX[ii]=detSizeX[ii]/detNpixelsX[ii];
      detPixelSizeY[ii]=detSizeY[ii]/detNpixelsY[ii];
    }
  }
  
  
  
  
  for (int ii=0;ii<6;ii++){
    if (detPresent[ii]==0) continue;
    
    posPixelX[ii].clear();posPixelY[ii].clear();posPixelZ[ii].clear();
    posPixelScaledX[ii].clear();posPixelScaledY[ii].clear();posPixelScaledZ[ii].clear();
    
    for (int iy=0;iy<detNpixelsY[ii];iy++){
      for (int ix=0;ix<detNpixelsX[ii];ix++){
	ipixel=ix+detNpixelsY[ii]*iy;	  
	
	switch (ii){
	  case 0: //faccia 1:yx, +z
	    z=+scintSizeZ/2;
	    x=-(-detSizeX[ii]/2+ix*detPixelSizeX[ii]+detPixelSizeX[ii]/2);
	    y=(-detSizeY[ii]/2+iy*detPixelSizeY[ii]+detPixelSizeY[ii]/2); 
	    xs=x*scintSizeX/detSizeX[ii];
	    ys=y*scintSizeY/detSizeY[ii];
	    zs=z;
	    break;
	  case 2: //faccia 3: yx, -z
	    z=-scintSizeZ/2;
	    x=(-detSizeX[ii]/2+ix*detPixelSizeX[ii]+detPixelSizeX[ii]/2);
	    y=(-detSizeY[ii]/2+iy*detPixelSizeY[ii]+detPixelSizeY[ii]/2);
	    xs=x*scintSizeX/detSizeX[ii];
	    ys=y*scintSizeY/detSizeY[ii];
	    zs=z;
	    break;
	  case 1: //faccia 2: yz, +x
	    x=+scintSizeX/2;
	    y=(-detSizeY[ii]/2+iy*detPixelSizeY[ii]+detPixelSizeY[ii]/2);
	    z=(-detSizeX[ii]/2+ix*detPixelSizeX[ii]+detPixelSizeX[ii]/2);
	    xs=x;
	    ys=y*scintSizeY/detSizeY[ii];
	    zs=z*scintSizeZ/detSizeX[ii];
	    break;
	  case 3: //faccia 4: yz, -x
	    x=-scintSizeX/2;
	    y=(-detSizeY[ii]/2+iy*detPixelSizeY[ii]+detPixelSizeY[ii]/2);
	    z=-(-detSizeX[ii]/2+ix*detPixelSizeY[ii]+detPixelSizeX[ii]/2);
	    xs=x;
	    ys=y*scintSizeY/detSizeY[ii];
	    zs=z*scintSizeZ/detSizeX[ii];
	    break;
	  case 4: //faccia 5, xz, +y
	    y=scintSizeY/2;
	    x=(-detSizeX[ii]/2+ix*detPixelSizeX[ii]+detPixelSizeX[ii]/2);
	    z=(-detSizeY[ii]/2+iy*detPixelSizeY[ii]+detPixelSizeY[ii]/2);
	    ys=y;
	    xs=x*scintSizeX/detSizeX[ii];
	    zs=z*scintSizeZ/detSizeY[ii];
	    break;
	  case 5: //faccia 6, xz, -y
	    y=-scintSizeY/2;
	    x=(-detSizeX[ii]/2+ix*detPixelSizeX[ii]+detPixelSizeX[ii]/2);
	    z=-(-detSizeY[ii]/2+iy*detPixelSizeY[ii]+detPixelSizeY[ii]/2);
	    ys=y;
	    xs=x*scintSizeX/detSizeX[ii];
	    zs=z*scintSizeZ/detSizeY[ii];
	    break;
	} 	  
	posPixelX[ii].push_back(x);posPixelY[ii].push_back(y);posPixelZ[ii].push_back(z);
	posPixelScaledX[ii].push_back(xs);posPixelScaledY[ii].push_back(ys);posPixelScaledZ[ii].push_back(zs);
      }    
    }
  }
  cout<<"TOpNoviceDetectorLight::init() done"<<endl;
}

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




void TOpNoviceDetectorLight::printPixels(){
  int id;
  for (int ii=0;ii<6;ii++){
    if (this->isDetPresent(ii)==0) continue;
    printf("id \t \t X \t \t Y \t \t Z \t \t \n");
    for (int iy=0;iy<detNpixelsY[ii];iy++){
      for (int ix=0;ix<detNpixelsX[ii];ix++){
	id=ix+detNpixelsX[ii]*iy;
	printf("%i \t %f \t %f \t %f \t \n",id,posPixelX[ii].at(id),posPixelY[ii].at(id),posPixelZ[ii].at(id));
      }
    }
    printf("*********************\n");
    
  }
}



void TOpNoviceDetectorLight::printDet(){
  printf("Scintillator size: \t %f \t %f \t %f \n",this->getScintSizeX(),this->getScintSizeY(),this->getScintSizeZ());
  printf("Decay time: \t %f \n",this->getFastScintTime());
  printf("LY: \t %f \n",this->getLY());
  printf("rIndex: \t %f \n",this->getRindex());
  printf("Detectors \t SizeX \t \t SizeY \t \t PixelsX \t PixelsY \t TimeRes \t QE \n");
  for (int ii=0;ii<6;ii++){
    if (this->isDetPresent(ii)) printf("%i \t \t %f \t %f \t %i \t \t %i \t \t %f \t  %f\n",ii+1,this->getDetSizeX(ii),this->getDetSizeY(ii),this->getNPixelsX(ii),this->getNPixelsY(ii),this->getTimeRes(ii),this->getQEmean(ii));
    else printf("%i \t \t Not present \n",ii+1);
  }
  
  
}












/*Return the EXITING normal of a pixel*/
TVector3 TOpNoviceDetectorLight::getPixelNormal(int iface,int ipixel){
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
TVector3 TOpNoviceDetectorLight::getPixelT1(int iface,int ipixel){
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
TVector3 TOpNoviceDetectorLight::getPixelT2(int iface,int ipixel){
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






double TOpNoviceDetectorLight::getQE(int iface,int ipixel){
  double ret=0;
  if (this->isDetPresent(iface)==0) ret=0;
  else ret=QE[iface].at(ipixel);
  return ret;
}

void TOpNoviceDetectorLight::setQE(int iface,int ipixel,double mQE){
  if (QEinit==0){
    cout<<"QEinit"<<endl;
    
    for (int ii=0;ii<6;ii++){
      if (this->isDetPresent(ii)==0) continue;
      for (int iy=0;iy<detNpixelsY[ii];iy++){
	for (int ix=0;ix<detNpixelsX[ii];ix++){
	  QE[ii].push_back(0.);
	}
      }
    }
    QEinit=1; 
  }
  QE[iface].at(ipixel)=mQE;
}

double TOpNoviceDetectorLight::getQEmean(int iface){
  double ret=0;
  int ii=0;
  if (this->isDetPresent(iface)==0) ret=0;
  else{
    for (int iy=0;iy<detNpixelsY[iface];iy++){
      for (int ix=0;ix<detNpixelsX[iface];ix++){
	ret+=QE[iface].at(ii++);
      }
    }
  }
  
  ret/=(detNpixelsX[iface]*detNpixelsY[iface]);
  return ret;
}

void TOpNoviceDetectorLight::setQEmean(int iface,double mQE){ 
  int ii=0;
  cout<<"setQEmean called for face "<<iface<<endl;
  if (QEinit==0){
    cout<<"QEinit"<<endl;
    for (int id=0;id<6;id++){
      if (this->isDetPresent(id)==0) continue;
      for (int iy=0;iy<detNpixelsY[id];iy++){
	for (int ix=0;ix<detNpixelsX[id];ix++){
	  QE[id].push_back(0.);
	}
      }
    }
    QEinit=1; 
  }
  if (this->isDetPresent(iface)==0){
    cout<<"QEmean no det on face "<<iface<<endl;
    return;
  }
  else{   
    for (int iy=0;iy<detNpixelsY[iface];iy++){
      for (int ix=0;ix<detNpixelsX[iface];ix++){
	QE[iface].at(ii++)=mQE;
      }
    }
  }
}








