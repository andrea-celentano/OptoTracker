compareTofpetRates(int n,int ch,string fname){

  ifstream file;
  file.open(fname.c_str());
  vector < string > fnames;
  string m_fname;
  for (int ifile=0;ifile<n;ifile++){
    file>>m_fname;
    fnames.push_back(m_fname);
  }
  file.close();
  
  TFile **f=new TFile*[n];
  TTree **t=new TTree*[n];
  TH1D **h=new TH1D*[n];

  int m_ch,m_asic;
  m_ch=ch%64;
  m_asic=ch/64;

  for (int ii=0;ii<n;ii++){
    f[ii]=new TFile(fnames.at(ii).c_str());
    t[ii]=(TTree*)f[ii]->Get("data");
    h[ii]=new TH1D(Form("h%i",ii),Form("h%i",ii),64,-0.5,63.5);
    
    t[ii]->Draw(Form("step2>>h%i",ii),Form("rate*((channel==%i)&&(asic==%i))",m_ch,m_asic),"goff");
    h[ii]->SetLineColor(ii+1);
  }

  

  TCanvas *c=new TCanvas();
  c->SetLogy();
  h[0]->Draw();
  for (int ii=1;ii<n;ii++){
    h[ii]->Draw("SAME");
  }
}
