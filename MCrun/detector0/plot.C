

plot(){

  string dirname="simulation1";
  double timeRes[6]={20,50,100,150,200,400};
  string letter[6]={"a","b","c","d","e","f"};

  double meanTheta0,sigmaTheta0,meanPhi0,sigmaPhi0;
  double emeanTheta0,esigmaTheta0,emeanPhi0,esigmaPhi0;
  TGraphErrors *gmeanTheta0=new TGraphErrors();
  TGraphErrors *gsigmaTheta0=new TGraphErrors();
  TGraphErrors *gmeanPhi0=new TGraphErrors();
  TGraphErrors *gsigmaPhi0=new TGraphErrors();
  


  double meanTheta1[6];double emeanTheta1[6];
  double sigmaTheta1[6];  double esigmaTheta1[6];
  double meanPhi1[6]; double emeanPhi1[6];
  double sigmaPhi1[6]; double esigmaPhi1[6];
  TGraphErrors *gmeanTheta1=new TGraphErrors();
  TGraphErrors *gsigmaTheta1=new TGraphErrors();
  TGraphErrors *gmeanPhi1=new TGraphErrors();
  TGraphErrors *gsigmaPhi1=new TGraphErrors();

  double meanTheta2[6];double emeanTheta2[6];
  double sigmaTheta2[6];  double esigmaTheta2[6];
  double meanPhi2[6]; double emeanPhi2[6];
  double sigmaPhi2[6]; double esigmaPhi2[6];
  TGraphErrors *gmeanTheta2=new TGraphErrors();
  TGraphErrors *gsigmaTheta2=new TGraphErrors();
  TGraphErrors *gmeanPhi2=new TGraphErrors();
  TGraphErrors *gsigmaPhi2=new TGraphErrors();

  double meanTheta3[6];double emeanTheta3[6];
  double sigmaTheta3[6];  double esigmaTheta3[6];
  double meanPhi3[6]; double emeanPhi3[6];
  double sigmaPhi3[6]; double esigmaPhi3[6];
  TGraphErrors *gmeanTheta3=new TGraphErrors();
  TGraphErrors *gsigmaTheta3=new TGraphErrors();
  TGraphErrors *gmeanPhi3=new TGraphErrors();
  TGraphErrors *gsigmaPhi3=new TGraphErrors();
  
  double meanTheta4[6];double emeanTheta4[6];
  double sigmaTheta4[6];  double esigmaTheta4[6];
  double meanPhi4[6]; double emeanPhi4[6];
  double sigmaPhi4[6]; double esigmaPhi4[6];
  TGraphErrors *gmeanTheta4=new TGraphErrors();
  TGraphErrors *gsigmaTheta4=new TGraphErrors();
  TGraphErrors *gmeanPhi4=new TGraphErrors();
  TGraphErrors *gsigmaPhi4=new TGraphErrors();
 



  double meanTheta5[6];double emeanTheta5[6];
  double sigmaTheta5[6];  double esigmaTheta5[6];
  double meanPhi5[6]; double emeanPhi5[6];
  double sigmaPhi5[6]; double esigmaPhi5[6];
  TGraphErrors *gmeanTheta5=new TGraphErrors();
  TGraphErrors *gsigmaTheta5=new TGraphErrors();
  TGraphErrors *gmeanPhi5=new TGraphErrors();
  TGraphErrors *gsigmaPhi5=new TGraphErrors();


  TFile *f;
  TCanvas *c;
  TH1D *hTheta,*Phi;

  /*Case0: the no-charge case*/
  f=new TFile(Form("%s/case0.root",dirname.c_str()));
  c=new TCanvas("c","c");
  c->Divide(2,2);

  
  hTheta=(TH1D*)f->Get("hTheta");
  hPhi=(TH1D*)f->Get("hPhi");
  c->cd(1);
  hTheta->Fit("gaus");
  hTheta->SetTitle("hThetaCase0");
  meanTheta0=hTheta->GetFunction("gaus")->GetParameter(1);
  sigmaTheta0=hTheta->GetFunction("gaus")->GetParameter(2);
  emeanTheta0=hTheta->GetFunction("gaus")->GetParError(1);
  esigmaTheta0=hTheta->GetFunction("gaus")->GetParError(2);
  gmeanTheta0->SetPoint(0,0,meanTheta0);
  gmeanTheta0->SetPointError(0,0,emeanTheta0);
  gsigmaTheta0->SetPoint(0,0,sigmaTheta0);
  gsigmaTheta0->SetPointError(0,0,esigmaTheta0);

  c->cd(2);
  hPhi->Fit("gaus");
  hPhi->SetTitle("hPhiCase0");
  meanPhi0=hPhi->GetFunction("gaus")->GetParameter(1);
  sigmaPhi0=hPhi->GetFunction("gaus")->GetParameter(2);
  emeanPhi0=hPhi->GetFunction("gaus")->GetParError(1);
  esigmaPhi0=hPhi->GetFunction("gaus")->GetParError(2);
  gmeanPhi0->SetPoint(0,0,meanTheta0);
  gmeanPhi0->SetPointError(0,0,emeanTheta0);
  gsigmaPhi0->SetPoint(0,0,sigmaPhi0);
  gsigmaPhi0->SetPointError(0,0.,esigmaPhi0);

  c->Draw();
  c->Print("out.ps(");
  c=(TCanvas*)f->Get("c2In");
  c->Print("out.ps");
  c=(TCanvas*)f->Get("c2Out");
  c->Print("out.ps");


  f->Close();

  /*Case1: time AND charge, free t0*/
  for (int ii=0;ii<6;ii++){
    f=new TFile(Form("%s/case1%s.root",dirname.c_str(),letter[ii].c_str()));
    hTheta=(TH1D*)f->Get("hTheta");
    hPhi=(TH1D*)f->Get("hPhi");
    c=new TCanvas("c","c");
    c->Divide(2,2);
 
    
    c->cd(1); 
    hTheta->SetTitle(Form("hThetaCase1%s",letter[ii].c_str()));
    hTheta->Fit("gaus");hTheta->Draw();
    meanTheta1[ii]=hTheta->GetFunction("gaus")->GetParameter(1);
    sigmaTheta1[ii]=hTheta->GetFunction("gaus")->GetParameter(2);
    emeanTheta1[ii]=hTheta->GetFunction("gaus")->GetParError(1);
    esigmaTheta1[ii]=hTheta->GetFunction("gaus")->GetParError(2);
    gmeanTheta1->SetPoint(ii,timeRes[ii],meanTheta1[ii]);
    gmeanTheta1->SetPointError(ii,0.,emeanTheta1[ii]);
    gsigmaTheta1->SetPoint(ii,timeRes[ii],sigmaTheta1[ii]);
    gsigmaTheta1->SetPointError(ii,0.,esigmaTheta1[ii]);

    c->cd(2);
    hPhi->SetTitle(Form("hPhiCase1%s",letter[ii].c_str()));
    hPhi->Fit("gaus");hPhi->Draw();
    meanPhi1[ii]=hPhi->GetFunction("gaus")->GetParameter(1);
    sigmaPhi1[ii]=hPhi->GetFunction("gaus")->GetParameter(2);
    emeanPhi1[ii]=hPhi->GetFunction("gaus")->GetParError(1);
    esigmaPhi1[ii]=hPhi->GetFunction("gaus")->GetParError(2);
    gmeanPhi1->SetPoint(ii,timeRes[ii],meanPhi1[ii]);
    gmeanPhi1->SetPointError(ii,0.,emeanPhi1[ii]);
    gsigmaPhi1->SetPoint(ii,timeRes[ii],sigmaPhi1[ii]);
    gsigmaPhi1->SetPointError(ii,0.,esigmaPhi1[ii]);

    c->Print("out.ps");
    
    c=(TCanvas*)f->Get("c2In");
    c->Print("out.ps");
    c=(TCanvas*)f->Get("c2Out");
    c->Print("out.ps");

        f->Close();
	
  }


  /*Case2: time AND charge, fixed t0*/
  for (int ii=0;ii<6;ii++){
    f=new TFile(Form("%s/case2%s.root",dirname.c_str(),letter[ii].c_str()));
    hTheta=(TH1D*)f->Get("hTheta");
    hPhi=(TH1D*)f->Get("hPhi");
    c=new TCanvas("c","c");
    c->Divide(2,2);
 
    
    c->cd(1);
    hTheta->SetTitle(Form("hThetaCase2%s",letter[ii].c_str()));
    hTheta->Fit("gaus");hTheta->Draw();
    meanTheta2[ii]=hTheta->GetFunction("gaus")->GetParameter(1);
    sigmaTheta2[ii]=hTheta->GetFunction("gaus")->GetParameter(2);
    emeanTheta2[ii]=hTheta->GetFunction("gaus")->GetParError(1);
    esigmaTheta2[ii]=hTheta->GetFunction("gaus")->GetParError(2);
    gmeanTheta2->SetPoint(ii,timeRes[ii],meanTheta2[ii]);
    gmeanTheta2->SetPointError(ii,0.,emeanTheta2[ii]);
    gsigmaTheta2->SetPoint(ii,timeRes[ii],sigmaTheta2[ii]);
    gsigmaTheta2->SetPointError(ii,0.,esigmaTheta2[ii]);

    c->cd(2);
    hPhi->SetTitle(Form("hPhiCase2%s",letter[ii].c_str()));
    hPhi->Fit("gaus");hPhi->Draw();
    meanPhi2[ii]=hPhi->GetFunction("gaus")->GetParameter(1);
    sigmaPhi2[ii]=hPhi->GetFunction("gaus")->GetParameter(2);
    emeanPhi2[ii]=hPhi->GetFunction("gaus")->GetParError(1);
    esigmaPhi2[ii]=hPhi->GetFunction("gaus")->GetParError(2);
    gmeanPhi2->SetPoint(ii,timeRes[ii],meanPhi2[ii]);
    gmeanPhi2->SetPointError(ii,0.,emeanPhi2[ii]);
    gsigmaPhi2->SetPoint(ii,timeRes[ii],sigmaPhi2[ii]);
    gsigmaPhi2->SetPointError(ii,0.,esigmaPhi2[ii]);

    c->Print("out.ps");
    c=(TCanvas*)f->Get("c2In");
    c->Print("out.ps");
    c=(TCanvas*)f->Get("c2Out");
    c->Print("out.ps");
    
    f->Close();

  }






  /*Case3: time only, free t0*/
  for (int ii=0;ii<6;ii++){
    f=new TFile(Form("%s/case3%s.root",dirname.c_str(),letter[ii].c_str()));
    hTheta=(TH1D*)f->Get("hTheta");
    hPhi=(TH1D*)f->Get("hPhi");
    c=new TCanvas("c","c");
    c->Divide(2,2);
 
    
    c->cd(1);
    hTheta->SetTitle(Form("hThetaCase3%s",letter[ii].c_str()));
    hTheta->Fit("gaus");hTheta->Draw();
    meanTheta3[ii]=hTheta->GetFunction("gaus")->GetParameter(1);
    sigmaTheta3[ii]=hTheta->GetFunction("gaus")->GetParameter(2);
    emeanTheta3[ii]=hTheta->GetFunction("gaus")->GetParError(1);
    esigmaTheta3[ii]=hTheta->GetFunction("gaus")->GetParError(2);
    gmeanTheta3->SetPoint(ii,timeRes[ii],meanTheta3[ii]);
    gmeanTheta3->SetPointError(ii,0.,emeanTheta3[ii]);
    gsigmaTheta3->SetPoint(ii,timeRes[ii],sigmaTheta3[ii]);
    gsigmaTheta3->SetPointError(ii,0.,esigmaTheta3[ii]);

    c->cd(2);
    hPhi->Fit("gaus");hPhi->Draw();
    meanPhi3[ii]=hPhi->GetFunction("gaus")->GetParameter(1);
    sigmaPhi3[ii]=hPhi->GetFunction("gaus")->GetParameter(2);
    emeanPhi3[ii]=hPhi->GetFunction("gaus")->GetParError(1);
    esigmaPhi3[ii]=hPhi->GetFunction("gaus")->GetParError(2);
    gmeanPhi3->SetPoint(ii,timeRes[ii],meanPhi3[ii]);
    gmeanPhi3->SetPointError(ii,0.,emeanPhi3[ii]);
    gsigmaPhi3->SetPoint(ii,timeRes[ii],sigmaPhi3[ii]);
    gsigmaPhi3->SetPointError(ii,0.,esigmaPhi3[ii]);

    c->Print("out.ps");
 c=(TCanvas*)f->Get("c2In");
    c->Print("out.ps");
    c=(TCanvas*)f->Get("c2Out");
    c->Print("out.ps");
   


    f->Close();

  }

  /*Case4: time only, fixed t0*/
  for (int ii=0;ii<6;ii++){
    f=new TFile(Form("%s/case4%s.root",dirname.c_str(),letter[ii].c_str()));
    hTheta=(TH1D*)f->Get("hTheta");
    hPhi=(TH1D*)f->Get("hPhi");
    c=new TCanvas("c","c");
    c->Divide(2,2);
 
    
    c->cd(1);
    hTheta->SetTitle(Form("hThetaCase4%s",letter[ii].c_str()));
    hTheta->Fit("gaus");hTheta->Draw();
    meanTheta4[ii]=hTheta->GetFunction("gaus")->GetParameter(1);
    sigmaTheta4[ii]=hTheta->GetFunction("gaus")->GetParameter(2);
    emeanTheta4[ii]=hTheta->GetFunction("gaus")->GetParError(1);
    esigmaTheta4[ii]=hTheta->GetFunction("gaus")->GetParError(2);
    gmeanTheta4->SetPoint(ii,timeRes[ii],meanTheta4[ii]);
    gmeanTheta4->SetPointError(ii,0.,emeanTheta4[ii]);
    gsigmaTheta4->SetPoint(ii,timeRes[ii],sigmaTheta4[ii]);
    gsigmaTheta4->SetPointError(ii,0.,esigmaTheta4[ii]);

    c->cd(2);
    hPhi->Fit("gaus");hPhi->Draw();
    hPhi->SetTitle(Form("hPhiCase4%s",letter[ii].c_str()));
    meanPhi4[ii]=hPhi->GetFunction("gaus")->GetParameter(1);
    sigmaPhi4[ii]=hPhi->GetFunction("gaus")->GetParameter(2);
    emeanPhi4[ii]=hPhi->GetFunction("gaus")->GetParError(1);
    esigmaPhi4[ii]=hPhi->GetFunction("gaus")->GetParError(2);
    gmeanPhi4->SetPoint(ii,timeRes[ii],meanPhi4[ii]);
    gmeanPhi4->SetPointError(ii,0.,emeanPhi4[ii]);
    gsigmaPhi4->SetPoint(ii,timeRes[ii],sigmaPhi4[ii]);
    gsigmaPhi4->SetPointError(ii,0.,esigmaPhi4[ii]);

    c->Print("out.ps");
    c=(TCanvas*)f->Get("c2In");
    c->Print("out.ps");
    c=(TCanvas*)f->Get("c2Out");
    c->Print("out.ps");



    f->Close();

  }


  /*Case5: time AND charge, free T0, free Y1*/
  for (int ii=0;ii<6;ii++){
    f=new TFile(Form("%s/case5%s.root",dirname.c_str(),letter[ii].c_str()));
    hTheta=(TH1D*)f->Get("hTheta");
    hPhi=(TH1D*)f->Get("hPhi");
    c=new TCanvas("c","c");
    c->Divide(2,2);
 
    
    c->cd(1);
    hTheta->SetTitle(Form("hThetaCase5%s",letter[ii].c_str()));
    hTheta->Fit("gaus");hTheta->Draw();
    meanTheta5[ii]=hTheta->GetFunction("gaus")->GetParameter(1);
    sigmaTheta5[ii]=hTheta->GetFunction("gaus")->GetParameter(2);
    emeanTheta5[ii]=hTheta->GetFunction("gaus")->GetParError(1);
    esigmaTheta5[ii]=hTheta->GetFunction("gaus")->GetParError(2);
    gmeanTheta5->SetPoint(ii,timeRes[ii],meanTheta5[ii]);
    gmeanTheta5->SetPointError(ii,0.,emeanTheta5[ii]);
    gsigmaTheta5->SetPoint(ii,timeRes[ii],sigmaTheta5[ii]);
    gsigmaTheta5->SetPointError(ii,0.,esigmaTheta5[ii]);

    c->cd(2);
    hPhi->SetTitle(Form("hPhiCase5%s",letter[ii].c_str()));
    hPhi->Fit("gaus");hPhi->Draw();
    meanPhi5[ii]=hPhi->GetFunction("gaus")->GetParameter(1);
    sigmaPhi5[ii]=hPhi->GetFunction("gaus")->GetParameter(2);
    emeanPhi5[ii]=hPhi->GetFunction("gaus")->GetParError(1);
    esigmaPhi5[ii]=hPhi->GetFunction("gaus")->GetParError(2);
    gmeanPhi5->SetPoint(ii,timeRes[ii],meanPhi5[ii]);
    gmeanPhi5->SetPointError(ii,0.,emeanPhi5[ii]);
    gsigmaPhi5->SetPoint(ii,timeRes[ii],sigmaPhi5[ii]);
    gsigmaPhi5->SetPointError(ii,0.,esigmaPhi5[ii]);

    c->Print("out.ps");
    c=(TCanvas*)f->Get("c2In");
    c->Print("out.ps");
    c=(TCanvas*)f->Get("c2Out");
    c->Print("out.ps");



    f->Close();

  }






  TCanvas *c1=new TCanvas("c1","c1");
  c1->Divide(2,2);

  c1->cd(1);
  TMultiGraph *gmeanTheta=new TMultiGraph();
  gmeanTheta0->SetMarkerStyle(7);gmeanTheta0->SetMarkerColor(1);gmeanTheta->Add(gmeanTheta0,"P");
  gmeanTheta1->SetMarkerStyle(7);gmeanTheta1->SetMarkerColor(2);gmeanTheta->Add(gmeanTheta1,"P");
  gmeanTheta2->SetMarkerStyle(7);gmeanTheta2->SetMarkerColor(3);gmeanTheta->Add(gmeanTheta2,"P");
  gmeanTheta3->SetMarkerStyle(7);gmeanTheta3->SetMarkerColor(4);gmeanTheta->Add(gmeanTheta3,"P");
  gmeanTheta4->SetMarkerStyle(7);gmeanTheta4->SetMarkerColor(5);gmeanTheta->Add(gmeanTheta4,"P");
  gmeanTheta5->SetMarkerStyle(7);gmeanTheta5->SetMarkerColor(6);gmeanTheta->Add(gmeanTheta5,"P");
  gmeanTheta->Draw("A");

  c1->cd(2);
  TMultiGraph *gmeanPhi=new TMultiGraph();
  gmeanPhi0->SetMarkerStyle(7);gmeanPhi0->SetMarkerColor(1);gmeanPhi->Add(gmeanPhi0,"P");
  gmeanPhi1->SetMarkerStyle(7);gmeanPhi1->SetMarkerColor(2);gmeanPhi->Add(gmeanPhi1,"P");
  gmeanPhi2->SetMarkerStyle(7);gmeanPhi2->SetMarkerColor(3);gmeanPhi->Add(gmeanPhi2,"P");
  gmeanPhi3->SetMarkerStyle(7);gmeanPhi3->SetMarkerColor(4);gmeanPhi->Add(gmeanPhi3,"P");
  gmeanPhi4->SetMarkerStyle(7);gmeanPhi4->SetMarkerColor(5);gmeanPhi->Add(gmeanPhi4,"P");
  gmeanPhi5->SetMarkerStyle(7);gmeanPhi5->SetMarkerColor(5);gmeanPhi->Add(gmeanPhi5,"P");
  gmeanPhi->Draw("A");

  
  c1->cd(3);
  TMultiGraph *gsigmaTheta=new TMultiGraph();
  gsigmaTheta0->SetMarkerStyle(7);gsigmaTheta0->SetMarkerColor(1);gsigmaTheta->Add(gsigmaTheta0,"P");
  gsigmaTheta1->SetMarkerStyle(7);gsigmaTheta1->SetMarkerColor(2);gsigmaTheta->Add(gsigmaTheta1,"P");
  gsigmaTheta2->SetMarkerStyle(7);gsigmaTheta2->SetMarkerColor(3);gsigmaTheta->Add(gsigmaTheta2,"P");
  gsigmaTheta3->SetMarkerStyle(7);gsigmaTheta3->SetMarkerColor(4);gsigmaTheta->Add(gsigmaTheta3,"P");
  gsigmaTheta4->SetMarkerStyle(7);gsigmaTheta4->SetMarkerColor(5);gsigmaTheta->Add(gsigmaTheta4,"P");
  gsigmaTheta5->SetMarkerStyle(7);gsigmaTheta5->SetMarkerColor(6);gsigmaTheta->Add(gsigmaTheta5,"P");
  gsigmaTheta->Draw("A");
 
  c1->cd(4);
  TMultiGraph *gsigmaPhi=new TMultiGraph();
  gsigmaPhi0->SetMarkerStyle(7);gsigmaPhi0->SetMarkerColor(1);gsigmaPhi->Add(gsigmaPhi0,"P");
  gsigmaPhi1->SetMarkerStyle(7);gsigmaPhi1->SetMarkerColor(2);gsigmaPhi->Add(gsigmaPhi1,"P");
  gsigmaPhi2->SetMarkerStyle(7);gsigmaPhi2->SetMarkerColor(3);gsigmaPhi->Add(gsigmaPhi2,"P");
  gsigmaPhi3->SetMarkerStyle(7);gsigmaPhi3->SetMarkerColor(4);gsigmaPhi->Add(gsigmaPhi3,"P");
  gsigmaPhi4->SetMarkerStyle(7);gsigmaPhi4->SetMarkerColor(5);gsigmaPhi->Add(gsigmaPhi4,"P");
  gsigmaPhi5->SetMarkerStyle(7);gsigmaPhi5->SetMarkerColor(6);gsigmaPhi->Add(gsigmaPhi5,"P");


  gsigmaPhi->Draw("A");








  c1->Print("out.ps)");
}
