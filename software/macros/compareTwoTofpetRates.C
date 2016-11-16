compareTwoTofpetRates(int ch,string f1name,string f2name){
  TFile *f1=new TFile(f1name.c_str());
  TFile *f2=new TFile(f2name.c_str());

  TTree *t1=(TTree*)f1->Get("data");
  TTree *t2=(TTree*)f2->Get("data");

  int m_ch,m_asic;
  m_ch=ch%64;
  m_asic=ch/64;

  t1->Draw("step2>>h1(64,-0.5,63.5",Form("rate*((channel==%i)&&(asic==%i))",m_ch,m_asic),"goff");
  t2->Draw("step2>>h2(64,-0.5,63.5",Form("rate*((channel==%i)&&(asic==%i))",m_ch,m_asic),"goff");

  h1->SetLineColor(1);
  h2->SetLineColor(2);

  TCanvas *c=new TCanvas();
  c->SetLogy();
  h1->Draw();
  h2->Draw("SAME");

}
