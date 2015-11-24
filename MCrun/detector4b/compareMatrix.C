int Np=512;
int Nv=125;
compareMatrix(int iv){

  TH1D *hReconModel=new TH1D("hReconModel","hReconModel",Np*Nv,-0.5,Np*Nv-0.5);
  TH1D *hReconModel2=new TH1D("hReconModel2","hReconModel2",Np,-0.5,Np-0.5);
  ifstream fReconModel("reconModelMatrix.txt");

  TH1D *hAnalyticModelNoOptics=new TH1D("hAnalyticModelNoOptics","hAnalyticModelNoOptics",Np*Nv,-0.5,Np*Nv-0.5);
  TH1D *hAnalyticModelNoOptics2=new TH1D("hAnalyticModelNoOptics2","hAnalyticModelNoOptics2",Np,-0.5,Np-0.5);
  ifstream fAnalyticModelNoOptics("analyticModelMatrixNoOptics.txt");

  TH1D *hAnalyticModelOptics=new TH1D("hAnalyticModelOptics","hAnalyticModelOptics",Np*Nv,-0.5,Np*Nv-0.5);
  TH1D *hAnalyticModelOptics2=new TH1D("hAnalyticModelOptics2","hAnalyticModelOptics2",Np,-0.5,Np-0.5);
  ifstream fAnalyticModelOptics("analyticModelMatrixOptics.txt");

  TH1D *hMCpoint=new TH1D("hMCpoint2","hMCpoint2",Np*Nv,-0.5,Np*Nv-0.5);
  TH1D *hMCpoint2=new TH1D("hMCpoint2","hMCpoint2",Np,-0.5,Np-0.5);
  ifstream fMCpoint("matrixMCpoint.txt");

  double val;
  double totval,totval2,totval3;
  
  totval=0;
  totval2=0;
 
  for (int ivoxel=0;ivoxel<Nv;ivoxel++){
    for (int ipixel=0;ipixel<Np;ipixel++){
      fReconModel>>val;
      totval+=val;
      hReconModel->SetBinContent(ivoxel+Nv*ipixel+1,val);
      if (ivoxel==iv){
	hReconModel2->SetBinContent(ipixel+1,val);
	totval2+=val;
      }
    }
  }
  //hReconModel2->Scale(1./totval2);


  totval=0;
  totval2=0;
  for (int ivoxel=0;ivoxel<Nv;ivoxel++){
    for (int ipixel=0;ipixel<Np;ipixel++){
      fAnalyticModelNoOptics>>val;
      totval+=val;
      hAnalyticModelNoOptics->SetBinContent(ivoxel+Nv*ipixel+1,val);
      if (ivoxel==iv){
	hAnalyticModelNoOptics2->SetBinContent(ipixel+1,val);
	totval2+=val;
      }
    }
  }
  //hAnalyticModelNoOptics2->Scale(1./totval2);

  totval=0;
  totval2=0;
  for (int ivoxel=0;ivoxel<Nv;ivoxel++){
    for (int ipixel=0;ipixel<Np;ipixel++){
      fAnalyticModelOptics>>val;
      totval+=val;
      hAnalyticModelOptics->SetBinContent(ivoxel+Nv*ipixel+1,val);
      if (ivoxel==iv){
	hAnalyticModelOptics2->SetBinContent(ipixel+1,val);
	totval2+=val;
      }
    }
  }
  //  hAnalyticModelOptics2->Scale(1./totval2);



  totval=0;
  totval2=0;
  for (int ivoxel=0;ivoxel<Nv;ivoxel++){
    for (int ipixel=0;ipixel<Np;ipixel++){
      fMCpoint>>val;
      totval+=val;
      hMCpoint->SetBinContent(ivoxel+Nv*ipixel+1,val);
      if (ivoxel==iv){
	hMCpoint2->SetBinContent(ipixel+1,val);
	totval2+=val;
      }
    }
  }
  //hMCpoint2->Scale(1./totval2);


  TCanvas *c1=new TCanvas();
  hReconModel->SetLineColor(1);
  hReconModel->Draw();

  hAnalyticModelNoOptics->SetLineColor(2);
  hAnalyticModelNoOptics->Draw("SAME");
 
  hAnalyticModelOptics->SetLineColor(3);
  hAnalyticModelOptics->Draw("SAME");

  hMCpoint->SetLineColor(4);
  hMCpoint->Draw("SAME");

  TCanvas *c2=new TCanvas();

  hReconModel2->SetLineColor(1);
  hReconModel2->Draw();

  hAnalyticModelNoOptics2->SetLineColor(2);
  hAnalyticModelNoOptics2->Draw("SAME");
 
  hAnalyticModelOptics2->SetLineColor(3);
  hAnalyticModelOptics2->Draw("SAME");


  hMCpoint2->SetLineColor(4);
  hMCpoint2->Draw("SAME");
}
