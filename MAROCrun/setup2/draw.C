draw(string filename){
  TFile *f=new TFile(filename.c_str());
  TCanvas *c1=new TCanvas("c1","c1",400,400);
  hChargeExp0_0->Draw();
  hChargeTeo0_0->Draw("SAME");
  hChargeMC0_0->Draw("SAME");
  c1->SaveAs((filename+"PMT1.png").c_str());
  TCanvas *c2=new TCanvas("c2","c2",400,400);
  hChargeExp1_0->Draw();
  hChargeTeo1_0->Draw("SAME");
  hChargeMC1_0->Draw("SAME");
  c2->SaveAs((filename+"PMT2.png").c_str());
}
