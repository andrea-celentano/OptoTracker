Double_t
poissonf(Double_t*x,Double_t*par)                                         
{                                                                              
  return par[0]*TMath::Poisson(x[0],par[1]);
}      


test(){
  TFile *f=new TFile("alpha_0.root.recon.root");
  TH1D *h=f->Get("hCharge_2_53");
  
  TF1 *ff=new TF1("ff",poissonf,0,20,2);
  ff->SetParameter(0,h->GetEntries());
  ff->SetParameter(1,h->GetMean());
  h->Draw();
  h->Fit("ff");

}
