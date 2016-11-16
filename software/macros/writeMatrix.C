#include <string>

using namespace std;

writeMatrix(string det_name,string base_dir){
  gSystem->Load("$OPTO/lib/libCommonClassesDict.so");
  
  TFile *fVoxels=new TFile("matrix.root","update");
  TH3D *hVoxels=0;
  TDetectorLight det(det_name);
  hVoxels=(TH3D*)fVoxels->Get("hVoxels");
  if (!hVoxels){
    Error("writeMatrix","no hVoxels histogram in file matrix.root");
    exit(1);
  }
  int Nx,Ny,Nz,Nv;
  int Np,Npprev;
  ifstream dataf;
  double data;
  TObject *obj;
  ofstream filetxt("matrix.txt");

  Nx=hVoxels->GetXaxis()->GetNbins();
  Ny=hVoxels->GetYaxis()->GetNbins();
  Nz=hVoxels->GetZaxis()->GetNbins();
  Nv=Nx*Ny*Nz;

  /*Clear previous matrixes if there*/
  while (obj=fVoxels->Get("TMatrixT<double>")){
    cout<<"Matrix deleted"<<endl;
    obj->Delete("TMatrixT<double>");
    fVoxels->Close();
    fVoxels->Open("matrix.root","update");
  }
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
   
   Np=det.getTotPixels();
   TMatrixD m_matrix(Np,Nv);
   for (int iV=0;iV<Nv;iV++){
    dataf.open(Form("%s/voxel_%i.dat",base_dir.c_str(),iV));
    dataf>>Np;
    for (int iP=0;iP<Np;iP++){
      dataf>>data;
      m_matrix(iP,iV)=data;
      filetxt<<data<<" ";
    }
    filetxt<<endl;
    dataf.close();
  }
  
  m_matrix.Write();
  fVoxels->Close();
  cout<<"DONE"<<endl;
}
