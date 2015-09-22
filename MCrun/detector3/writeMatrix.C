#include <string>

using namespace std;

writeMatrix(string base_dir){
  gSystem->Load("$OPTO/lib/libCommonClassesDict.so");

  TFile *fVoxels=new TFile("matrix.root","update");
  TH3D *hVoxels=0;
  
  hVoxels=(TH3D*)fVoxels->Get("hVoxels");
  if (!hVoxels){
    Error("writeMatrix","no hVoxels histogram in file matrix.root");
    exit(1);
  }
  int Nx,Ny,Nz,Nv;
  int Np,Npprev;
  ifstream dataf;
  double data;
  Nx=hVoxels->GetXaxis()->GetNbins();
  Ny=hVoxels->GetYaxis()->GetNbins();
  Nz=hVoxels->GetZaxis()->GetNbins();
  Nv=Nx*Ny*Nz;
  
  /*First do a basic check over Np*/
   for (int iV=0;iV<Nv;iV++){
    dataf.open(Form("%s/voxel_%i.dat",base_dir.c_str(),iV));
    if (!dataf){
      Error("writeMatrix","error, voxel %i no file",iV);
    }
    dataf>>Np;
    if ((iV>0)&&(Np!=Npprev)){
      Error("writeMatrix","error on pixels number %i",iV);
    }
    Npprev=Np;
    dataf.close();
  }
  
  Np=256;
  TMatrixD m_matrix(Np,Nv);
  for (int iV=0;iV<Nv;iV++){
    dataf.open(Form("%s/voxel_%i.dat",base_dir.c_str(),iV));
    dataf>>Np;
    for (int iP=0;iP<Np;iP++){
      dataf>>data;
      m_matrix(iP,iV)=data;
    }
    dataf.close();
  }
  
  m_matrix.Write();
  fVoxels->Close();
}
