#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

#include "TVector3.h"
#include "TMath.h"
#include "TRandom3.h"

#include "TSystem.h"
#include "TROOT.h"

#include "../../packages/Common/include/TDetectorLight.hh"
#include "../../packages/Common/include/TDetectorUtils.hh"
//These are the dimensions of the scintillator, in cm. The center is at (0,0,0)cm. Use a dot at the end!
#define ScintX 6.
#define ScintY 6.
#define ScintZ 6.
//These are divisions along the 3 axis, to define the number of VOXELS
#define Nvx  5
#define Nvy  5
#define Nvz  5

//These are the sizes (cm) of each photo-detector, along the 2 directions of the plane of the face. Use a dot at the end!
#define PhotoX 4.8
#define PhotoY 4.8

//These are the number of PIXELS of each photo-detector. Here, Px and Py are the number of pixels along the 2 directions of the plane of the face.
#define NPx   16
#define NPy   16

//These numbers are used to define if, on a given face, there is (1) or not (0) a photo-detector
#define face0 1
#define face1 1
#define face2 1
#define face3 1
#define face4 0
#define face5 0

//the LY of the scintillator, and the QE of the detector
#define LY 9700
#define QE .3

using namespace std;
//This returns the absolute pixel center, given the faceID and the pixelID
TVector3 getPixelCenter(int faceID,int PixelID);

//these 3 functions returns: the pixel normal(exiting detector) and the pixel 2 tangents (along the detectors frame)
TVector3 getPixelNormal(int faceID,int PixelID);
TVector3 getPixelT1(int faceID,int PixelID);
TVector3 getPixelT2(int faceID,int PixelID);
//This returns the absolute voxel center, given the voxelID
TVector3 getVoxelCenter(int VoxelID);

//this function retuns the solid angle covered by the pixel pixelID on face faceID, from the voxel VoxelID
double getSolidAngle(int faceID,int pixelID,int voxelID); 

//this function returns the AVERAGE number of photo-electrons seen by the pixelID, on faceID, for a UNITARY energy deposition (1MeV)on the VoxelID(at the center)
double getResponse(int faceID,int pixelID,int voxelID);


void writeSingleVoxelSingleShot(int voxelID,string fname);
void writeSingleVoxelMultiShot(int voxelID,string fname);
void writeMultiVoxelSingleShot(int* index, int n_index ,string fname);
void writeMultiVoxelMultiShot(int* index, int n_index ,string fname);

//This function writes the matrix Hij, on file "fname", using the same format as in the previous MC
void writeMatrix(string fname);
void writeMatrix2(TDetector *det, string fname);

int main(){
  int lato=Nvx;
  int centro_lato=(int)((lato-1)/2);
  int indice=centro_lato*(1+lato+lato*lato);
  int index[5]={ indice-2*(lato),indice-lato,indice,indice+(lato), indice+2*(lato)};

  gSystem->Load("$OPTO/lib/libCommonClassesDict.so");

  writeMatrix("reconModelMatrix.txt");
  // writeMatrix2("analyticModelMatrix.txt");
  writeSingleVoxelMultiShot(indice,"data_size5_device4_pixel8x16.out");
  writeSingleVoxelSingleShot(indice,"data_single_size5_device4_pixel8x16.out");  
  writeMultiVoxelSingleShot(index,lato,"multi_single_size5_device4_pixel8x16.out");
  writeMultiVoxelMultiShot(index,lato,"multi_multi_size5_device4_pixel8x16.out");


}



TVector3 getPixelCenter(int faceID,int PixelID){
  TVector3 ret;
  double x,y;
  int px,py;
 
  px=PixelID%NPx;
  py=PixelID/NPx;

  x=(-PhotoX/2)+px*(PhotoX/NPx)+0.5*(PhotoX/NPx);
  y=(-PhotoY/2)+py*(PhotoY/NPy)+0.5*(PhotoY/NPy);

  switch (faceID){
  case 0://face 0: z=const(>0)
    ret.SetXYZ(-x,y,ScintZ/2);
    break;
  case 2://face 2: z=const(<0)
    ret.SetXYZ(x,y,-ScintZ/2);
    break;
  case 1://face1: x=const(>0)
    ret.SetXYZ(ScintX/2,y,x);
    break;
  case 3://face3: x=const(<0)
    ret.SetXYZ(-ScintX/2,y,-x);
    break;
  case 4://face4: TOP face, Y=const(>0)
    ret.SetXYZ(x,ScintY/2,y);
    break;
  case 5://face5: BOTTOM face, Y=const(<0)
    ret.SetXYZ(x,-ScintY/2,-y);
    break;
  default:
    cout<<"ERROR: "<<faceID<<endl;
    break;
  } 
  return ret;
}

TVector3 getPixelNormal(int faceID,int PixelID){
  TVector3 ret;
  switch (faceID){
  case 0:
    ret.SetXYZ(0,0,1.);
    break;
  case 2:
    ret.SetXYZ(0,0,-1.);
    break;
  case 1:
    ret.SetXYZ(1.,0,0);
    break;
  case 3:
    ret.SetXYZ(-1.,0,0);
    break;
  case 4:
    ret.SetXYZ(0,1.,0);
    break;
  case 5:
    ret.SetXYZ(0,-1.,0);
    break;
  }
  return ret;
}

TVector3 getPixelT1(int faceID,int PixelID){
 TVector3 ret;
  switch (faceID){
  case 0:
    ret.SetXYZ(-1.,0,0);
    break;
  case 2:
    ret.SetXYZ(1.,0,0);
    break;
  case 1:
    ret.SetXYZ(0,0,1.);
    break;
  case 3:
    ret.SetXYZ(0,0,-1.);
    break;
  case 4:
    ret.SetXYZ(1,0,0);
    break;
  case 5:
    ret.SetXYZ(-1,0,0);
    break;
  }
  return ret;
}

TVector3 getPixelT2(int faceID,int PixelID){
  TVector3 ret;
  switch (faceID){
  case 0:
    ret.SetXYZ(0,1.,0);
    break;
  case 2:
    ret.SetXYZ(0,1.,0);
    break;
  case 1:
    ret.SetXYZ(0,1.,0);
    break;
  case 3:
    ret.SetXYZ(0,1.,0);
    break;
  case 4:
    ret.SetXYZ(0,0,1);
    break;
  case 5:
    ret.SetXYZ(0,0,-1);
    break;
  }
  return ret;
}


TVector3 getVoxelCenter(int VoxelID){
  int vx,vy,vz;
  double x,y,z;
  double dx=ScintX/Nvx;
  double dy=ScintY/Nvy;
  double dz=ScintZ/Nvz;

  vz=VoxelID/(Nvx*Nvy);
  vy=(VoxelID-vz*Nvx*Nvy)/Nvx;
  //vy=(VoxelID-vz)/Nvx;
  vx=VoxelID-vz*Nvx*Nvy-vy*Nvx;
  
  x=-ScintX/2+vx*dx+dx/2;
  y=-ScintY/2+vy*dy+dy/2;
  z=-ScintZ/2+vz*dz+dz/2;
  
  TVector3 ret(x,y,z);
  return ret;
}


double getSolidAngle(int faceID,int pixelID,int voxelID){
  TVector3 rp=getPixelCenter(faceID,pixelID);
  TVector3 rv=getVoxelCenter(voxelID);

  TVector3 r=rv-rp;

  TVector3 n=getPixelNormal(faceID,pixelID);
  TVector3 t1=getPixelT1(faceID,pixelID);
  TVector3 t2=getPixelT2(faceID,pixelID);

  double Lx,Ly; //pixel size
  double ret;

  double a,b,c;
  double r2;

  c=fabs(r*n);
  a=r*t1;
  b=r*t2;
  
  Lx=PhotoX/NPx;
  Ly=PhotoY/NPy;

  r2=r.Mag2();
  ret = 0;	
  ret += atan( (Lx-2*a)*(Ly-2*b) / (2*c*sqrt(4*r2-4*a*Lx-4*b*Ly+Lx*Lx+Ly*Ly)));
  ret += atan( (Lx+2*a)*(Ly+2*b) / (2*c*sqrt(4*r2+4*a*Lx+4*b*Ly+Lx*Lx+Ly*Ly)));
  ret += atan( (Lx+2*a)*(Ly-2*b) / (2*c*sqrt(4*r2+4*a*Lx-4*b*Ly+Lx*Lx+Ly*Ly)));
  ret += atan( (Lx-2*a)*(Ly+2*b) / (2*c*sqrt(4*r2-4*a*Lx+4*b*Ly+Lx*Lx+Ly*Ly)));

  return ret;

}


double getResponse(int faceID,int pixelID,int voxelID){
  double ret;
  double Nphotons=1.*LY;
  double solidAngle=getSolidAngle(faceID,pixelID,voxelID);
  ret=Nphotons/(4*TMath::Pi());
  ret*=solidAngle;
  ret*=QE;
  return ret;
}

void writeSingleVoxelMultiShot(int ivoxel,string fname){
  int ipixel,iface;
 int data;
 TRandom3 rand(0);
  int isFace[6]={face0,face1,face2,face3,face4,face5};
  ofstream out(fname.c_str());
  double val;
  for (iface=0;iface<6;iface++){
      if(isFace[iface]==0) continue;
      for (ipixel=0;ipixel<(NPx*NPy);ipixel++){
	val=getResponse(iface,ipixel,ivoxel);
	data=rand.Poisson(val*1000);
	out<<data<<" ";
      }      
  }
  out<<endl;
}

void writeSingleVoxelSingleShot(int ivoxel,string fname){
  int ipixel,iface;
 
 int isFace[6]={face0,face1,face2,face3,face4,face5};
  ofstream out(fname.c_str());
  int data;
  double val;
  TRandom3 rand(0);
  for (iface=0;iface<6;iface++){
      if(isFace[iface]==0) continue;
      for (ipixel=0;ipixel<(NPx*NPy);ipixel++){
	val=getResponse(iface,ipixel,ivoxel);
	data=rand.Poisson(val);
	out<<data<<" ";
      }      
    }
  out<<endl;
}

void writeMultiVoxelSingleShot(int* index, int n_index ,string fname){
  int ipixel,iface,ivoxel;
 
 int isFace[6]={face0,face1,face2,face3,face4,face5};
  ofstream out(fname.c_str());
  int data;
  double val;
  TRandom3 rand(0);
  for (iface=0;iface<6;iface++){
      if(isFace[iface]==0) continue;
      for (ipixel=0;ipixel<(NPx*NPy);ipixel++){
	val=0;
	for (int i=0;i<n_index;i++){
	  ivoxel=index[i];
	val+=getResponse(iface,ipixel,ivoxel);
	}
	data=rand.Poisson(val);
	out<<data<<" ";
      }      
    }
  out<<endl;
}

void writeMultiVoxelMultiShot(int* index, int n_index ,string fname){
  int ipixel,iface,ivoxel;
 
 int isFace[6]={face0,face1,face2,face3,face4,face5};
  ofstream out(fname.c_str());
  int data;
  double val;
  TRandom3 rand(0);
  for (iface=0;iface<6;iface++){
      if(isFace[iface]==0) continue;
      for (ipixel=0;ipixel<(NPx*NPy);ipixel++){
	val=0;
	for (int i=0;i<n_index;i++){
	  ivoxel=index[i];
	val+=getResponse(iface,ipixel,ivoxel);
	}
	data=rand.Poisson(val*1000);
	out<<data<<" ";
      }      
    }
  out<<endl;
}

void writeMatrix(string fname){
  int ipixel,iface;
  int ivoxel;
  double val;

  int isFace[6]={face0,face1,face2,face3,face4,face5};
  ofstream out(fname.c_str());
  
  for (ivoxel=0;ivoxel<(Nvx*Nvy*Nvz);ivoxel++){
    for (iface=0;iface<6;iface++){
      if(isFace[iface]==0) continue;
      for (ipixel=0;ipixel<(NPx*NPy);ipixel++){
	val=getResponse(iface,ipixel,ivoxel);
	out<<val<<" ";
      }      
    }
    cout<<"Done voxel "<<ivoxel<<endl;
    out<<endl;
  }//end voxel
}
void writeMatrix2(TDetector *det,string fname){
  int ipixel,iface;
  int ivoxel;
  double val;
  TDetectorUtils *utils=new TDetectorUtils(det);
  ofstream out2(fname.c_str());
  for (int ivoxel=0;ivoxel<(Nvx*Nvy*Nvz);ivoxel++){
    for (int iface=0;iface<6;iface++){
      for (int idet=0;idet<det->getNdet(iface);idet++){
      	for (int ipixel=0;ipixel<(det->getNPixels(iface,idet));ipixel++){
	  TVector3 rv=getVoxelCenter(ivoxel);
	  val=utils->GetSolidAngle(rv,iface,idet,ipixel);
	  val/=(4*TMath::Pi());
	  val*=det->getLY();
	  val*=det->getDetQE(iface,idet);
	  out2<<val<<" ";
	}
      }
    }
    out2<<endl;
  }//end voxel
}
void writeMatrix3(TDetector *det,string fname){
  int ipixel,iface;
  int ivoxel;
  double val;
  TDetectorUtils *utils=new TDetectorUtils(det);
  ofstream out2(fname.c_str());
  for (int ivoxel=0;ivoxel<(Nvx*Nvy*Nvz);ivoxel++){
    for (int iface=0;iface<6;iface++){
      for (int idet=0;idet<det->getNdet(iface);idet++){
      	for (int ipixel=0;ipixel<(det->getNPixels(iface,idet));ipixel++){
	  TVector3 rv=getVoxelCenter(ivoxel);
	  val=utils->SinglePixelAverageCharge(rv,iface,idet,ipixel);
	  val*=det->getLY();
	  out2<<val<<" ";
	}
      } 
    }
    out2<<endl;
  }//end voxel
}

int macro(){
  gSystem->Load("$OPTO/lib/libCommonClassesDict.so");
  TDetector *det=new TDetector("PrototypeGeometry.dat");
  
  getPixelCenter(0,0).Print();
  det->getPosPixel(0,0,0).Print();

  writeMatrix("matrixReconModel.txt"); //simple recon model
  cout<<"written Matrix"<<endl;
  //  writeMatrix2(det,"analyticModelMatrixNoOptics.txt");
  //cout<<"written Matrix2"<<endl;
  writeMatrix3(det,"matrixAnnalyticModel.txt");
  cout<<"written Matrix2"<<endl;
}


