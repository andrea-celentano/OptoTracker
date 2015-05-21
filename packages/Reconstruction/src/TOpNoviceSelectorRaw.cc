#define TOpNoviceSelectorRaw_cxx
// The class definition in OpNoviceSelectorRaw.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("OpNoviceSelectorRaw.C")
// Root > T->Process("OpNoviceSelectorRaw.C","some options")
// Root > T->Process("OpNoviceSelectorRaw.C+")
//

#include "TOpNoviceSelectorRaw.hh"

TOpNoviceSelectorRaw::TOpNoviceSelectorRaw(TTree* /*tree*/) : 
fChain(0),m_recon(0),m_detector(0)
{ 
  hPixel0Title[0]="hPixel0_0;-x;y";
  hPixel0Title[1]="hPixel0_0;+z;+y";
  hPixel0Title[2]="hPixel0_0;+x;+y";
  hPixel0Title[3]="hPixel0_0;-z;+y";
  hPixel0Title[4]="hPixel0_0;+x;+z";
  hPixel0Title[5]="hPixel0_0;+x;-z";
  for (int ii=0;ii<6;ii++) hPixel0[ii]=0;
}

void TOpNoviceSelectorRaw::Begin(TTree * /*tree*/)
{
  // The Begin() function is called at the start of the query.
  // When running with PROOF Begin() is only called on the client.
  // The tree argument is deprecated (on PROOF 0 is passed).
  
  TString option = GetOption();
  Info("Begin","Master Begin");
  
  if (m_detector==0){
    m_detector=dynamic_cast<TOpNoviceDetectorLight *>(fInput->FindObject("TOpNoviceDetectorLight"));
    Info("Begin","We are on Proof, load detector on master");
    if (m_detector==NULL){
      Error("Begin","Detector not on the master");
      exit(1);
    } 	
  }
}

void TOpNoviceSelectorRaw::SlaveBegin(TTree * /*tree*/)
{
  // The SlaveBegin() function is called after the Begin() function.
  // When running with PROOF SlaveBegin() is called on each slave server.
  // The tree argument is deprecated (on PROOF 0 is passed).
  
  TString option = GetOption();
  //Random number generator
  m_rand=new TRandom3(m_seed);
  Info("SlaveBegin","Slave begin");
 
  //Get the detector object from the input list
   if (m_detector==0){
      m_detector=dynamic_cast<TOpNoviceDetectorLight *>(fInput->FindObject("TOpNoviceDetectorLight"));
      Info("Begin","We are on Proof, load detector on master");
   }
  
  if (m_detector==NULL){
   Error("SlaveBegin","Detector not on a slave");
    exit(1);
  }
  //I need to create the "reconstruction" class in EVERY slave
  m_recon=new TRecon(m_detector);
  
  
  //Init the variables used in the Process
  N=new int*[6];
  tFirst=new double*[6];
  q=new double*[6];
  for (int ii=0;ii<6;ii++){
    q[ii]=new double[m_detector->getNPixels(ii)]();
    N[ii]=new int[m_detector->getNPixels(ii)]();
    tFirst[ii]=new double[m_detector->getNPixels(ii)]();	
  }
  
  
  //Histograms
  for (int ii=0;ii<6;ii++){
    if (m_detector->isDetPresent(ii)){
      hPixel0[ii]=new TH2D(Form("hPixel0_%i",ii+1),Form("hPixel0_%i",ii+1),m_detector->getNPixelsX(ii),-m_detector->getDetSizeX(ii)/2,m_detector->getDetSizeX(ii)/2,m_detector->getNPixelsY(ii),-m_detector->getDetSizeY(ii)/2,m_detector->getDetSizeY(ii)/2);
      hPixel0[ii]->SetTitle(hPixel0Title[ii].c_str());
      fOutput->Add(hPixel0[ii]); //VERY IMPORTANT: fill output list
      
      
      int Nx=m_detector->getNPixelsX(ii);
      int Ny=m_detector->getNPixelsY(ii);
      for (int id=0;id<Nx*Ny;id++){
	hCharge[ii].push_back(new TH1D(Form("hCharge_%i_%i",ii,id),Form("hCharge_%i_%i",ii,id),100,-0.5,99.5));fOutput->Add(hCharge[ii].at(id));	    
	hTime[ii].push_back(new TH1D(Form("hTime_%i_%i",ii,id),Form("hTime_%i_%i",ii,id),400,-2.5,17.5));fOutput->Add(hTime[ii].at(id));	    
	hTimeVsCharge[ii].push_back(new TH2D(Form("hTimeVsCharge_%i_%i",ii,id),Form("hTimeVsCharge_%i_%i",ii,id),100,-0.5,99.5,400,-2.5,17.5));fOutput->Add(hTimeVsCharge[ii].at(id));	    
      }  
    }      
  }
  
  
  hX=new TH1D("hX","hX;x",200,-m_detector->getScintSizeX()/2-1,m_detector->getScintSizeX()/2+1);fOutput->Add(hX);	
  hY=new TH1D("hY","hY;y",200,-m_detector->getScintSizeY()/2-1,m_detector->getScintSizeY()/2+1);fOutput->Add(hY);
  hZ=new TH1D("hZ","hZ;z",200,-m_detector->getScintSizeZ()/2-1,m_detector->getScintSizeZ()/2+1);fOutput->Add(hZ);
  hXY=new TH2D("hXY","hXY;x;y",100,-m_detector->getScintSizeX()/2-1,m_detector->getScintSizeX()/2+1,100,-m_detector->getScintSizeY()/2-1,m_detector->getScintSizeY()/2+1);fOutput->Add(hXY);
  hXZ=new TH2D("hXZ","hXZ;x;z",100,-m_detector->getScintSizeX()/2-1,m_detector->getScintSizeX()/2+1,100,-m_detector->getScintSizeZ()/2-1,m_detector->getScintSizeZ()/2+1);fOutput->Add(hXZ);
  hYZ=new TH2D("hYZ","hYZ;y;z",100,-m_detector->getScintSizeY()/2-1,m_detector->getScintSizeY()/2+1,100,-m_detector->getScintSizeZ()/2-1,m_detector->getScintSizeZ()/2+1);fOutput->Add(hYZ);
  
  
  hX_1=new TH1D("hX_1","hX;x",200,-m_detector->getScintSizeX()/2-1,m_detector->getScintSizeX()/2+1);fOutput->Add(hX_1);
  hY_1=new TH1D("hY_1","hY;y",200,-m_detector->getScintSizeY()/2-1,m_detector->getScintSizeY()/2+1);fOutput->Add(hY_1);
  hZ_1=new TH1D("hZ_1","hZ;z",200,-m_detector->getScintSizeZ()/2-1,m_detector->getScintSizeZ()/2+1);fOutput->Add(hZ_1);
  hXY_1=new TH2D("hXY_1","hXY;x;y",100,-m_detector->getScintSizeX()/2-1,m_detector->getScintSizeX()/2+1,100,-m_detector->getScintSizeY()/2-1,m_detector->getScintSizeY()/2+1);fOutput->Add(hXY_1);
  hXZ_1=new TH2D("hXZ_1","hXZ;x;z",100,-m_detector->getScintSizeX()/2-1,m_detector->getScintSizeX()/2+1,100,-m_detector->getScintSizeZ()/2-1,m_detector->getScintSizeZ()/2+1);fOutput->Add(hXZ_1);
  hYZ_1=new TH2D("hYZ_1","hYZ;y;z",100,-m_detector->getScintSizeY()/2-1,m_detector->getScintSizeY()/2+1,100,-m_detector->getScintSizeZ()/2-1,m_detector->getScintSizeZ()/2+1);fOutput->Add(hYZ_1);
  
  hX_2=new TH1D("hX_2","hX;x",200,-m_detector->getScintSizeX()/2-1,m_detector->getScintSizeX()/2+1);fOutput->Add(hX_2);
  hY_2=new TH1D("hY_2","hY;y",200,-m_detector->getScintSizeY()/2-1,m_detector->getScintSizeY()/2+1);fOutput->Add(hY_2);
  hZ_2=new TH1D("hZ_2","hZ;z",200,-m_detector->getScintSizeZ()/2-1,m_detector->getScintSizeZ()/2+1);fOutput->Add(hZ_2);
  hXY_2=new TH2D("hXY_2","hXY;x;y",100,-m_detector->getScintSizeX()/2-1,m_detector->getScintSizeX()/2+1,100,-m_detector->getScintSizeY()/2-1,m_detector->getScintSizeY()/2+1);fOutput->Add(hXY_2);
  hXZ_2=new TH2D("hXZ_2","hXZ;x;z",100,-m_detector->getScintSizeX()/2-1,m_detector->getScintSizeX()/2+1,100,-m_detector->getScintSizeZ()/2-1,m_detector->getScintSizeZ()/2+1);fOutput->Add(hXZ_2);
  hYZ_2=new TH2D("hYZ_2","hYZ;y;z",100,-m_detector->getScintSizeY()/2-1,m_detector->getScintSizeY()/2+1,100,-m_detector->getScintSizeZ()/2-1,m_detector->getScintSizeZ()/2+1);fOutput->Add(hYZ_2);
  
  
   
  hTheta=new TH1D("hTheta","hTheta",150,-120,120);fOutput->Add(hTheta);
  hPhi=new TH1D("hPhi","hPhi",150,-250,250);fOutput->Add(hPhi);
 
  hNPhotons=new TH1D("hNPhotons","hNPhotons",1000,0,4E5);fOutput->Add(hNPhotons);
  hT0=new TH1D("hT0","hT0",100,-.1,.1);fOutput->Add(hT0);
  hTau=new TH1D("hTau","hTau",100,-.1,5);fOutput->Add(hTau);
    
 
  
  
}

Bool_t TOpNoviceSelectorRaw::Process(Long64_t entry)
{
  // The Process() function is called for each entry in the tree (or possibly
  // keyed object in the case of PROOF) to be processed. The entry argument
  // specifies which entry in the currently loaded tree is to be processed.
  // It can be passed to either OpNoviceSelectorRaw::GetEntry() or TBranch::GetEntry()
  // to read either all or the required parts of the data. When processing
  // keyed objects with PROOF, the object is already loaded and is available
  // via the fObject pointer.
  //
  // This function should contain the "body" of the analysis. It can contain
  // simple or elaborate selection criteria, run algorithms on the data
  // of the event and typically fill histograms.
  //
  // The processing can be stopped by calling Abort().
  //
  // Use fStatus to set the return value of TTree::Process().
  //
  // The return value is currently not used.
  
  Info("Process","Processing entry %li",entry);
  //local variables
  int Nhit,iPMT,Nphe,pid,Ntot;
  int qtot=0;
  double xp,yp,t,theta,phi;
  TVector3  COG,rReconIN,rReconOUT,rRecon;
  TVector3 ux,uy,uz;
  //clear some variables 
  for (int ii=0;ii<6;ii++){
    for (int ipid=0;ipid<m_detector->getNPixels(ii);ipid++){
      N[ii][ipid]=0;
      q[ii][ipid]=0;
      tFirst[ii][ipid]=9999; 
    }
  }
  
  //load the entry, it "goes" in: raw. For the "raw" branch, there is 1 entry per "detector" (i.e. scintillator size)
  GetEntry(entry);
  Nhit=raw->size();
  
  //start processing
  
  //load the data    
  for (int ihit=0;ihit<Nhit;ihit++){			
    iPMT=raw->at(ihit)->GetPMTNumber();
    if (m_detector->isDetPresent(iPMT)==0){
      cout<<"Error! The detector on face "<<iPMT+1<<"is not supposed to be here but we have a hit"<<endl;
      exit(1);
    }
    Nphe=raw->at(ihit)->GetPheCount(); //1 "phe" is 1 detected photon (QE already included) on the detector
    for (int iphe=0;iphe<Nphe;iphe++){
      
      xp=raw->at(ihit)->GetX(iphe);
      yp=raw->at(ihit)->GetY(iphe);
      t=raw->at(ihit)->GetT(iphe);      
      pid=m_detector->getPixelID(iPMT,xp,yp);
      
      //cout<<iPMT<<" "<<xp<<" "<<yp<<" "<<pid<<" "<<raw->at(ihit)->GetPixel(iphe)<<endl;
      
      //Time resolution effects
      if (m_detector->getTimeRes(iPMT)>0) t=t+m_rand->Gaus(0,m_detector->getTimeRes(iPMT)); 
      if (t<tFirst[iPMT][pid]) tFirst[iPMT][pid]=t;      
      
      
      qtot++;
      N[iPMT][pid]++;	
      
      hPixel0[iPMT]->Fill(xp,yp); 
      
    }//end loop on phe
  }//end loop on hits (1 hit == 1 face)
  

   for (int ii=0;ii<6;ii++){
       if (m_detector->isDetPresent(ii)==0) continue;
       for (int id=0;id<m_detector->getNPixels(ii);id++){
	 hCharge[ii].at(id)->Fill(N[ii][id]);
	 hTime[ii].at(id)->Fill(tFirst[ii][id]);
	 hTimeVsCharge[ii].at(id)->Fill(N[ii][id],tFirst[ii][id]);
       }
     }
  
  
  
  //fill the reconstruction class with data
  for (int ii=0;ii<6;ii++){
    if (m_detector->isDetPresent(ii)==0) continue;
    m_recon->setNaddress(ii,N[ii]);
    m_recon->setTaddress(ii,tFirst[ii]);  
  }
  
  //compute COG
  COG=m_recon->computeCOG();
  
  
  //Try the likelihood fit
  
  
  Ntot=qtot/0.2; 
  fitObject_t fitObject=k_track;             //k_point k_track
  fitLikelihoodMode_t fitMode=k_both;    //k_both  k_onlyTime k_onlyCharge
  m_recon->getMinimizer()->Clear();
  m_recon->initParameters();
  m_recon->setFitObject(fitObject);
  m_recon->setFitLikelihoodMode(fitMode);
  
  
  
  

  //m_recon->getMinimizer()->SetVariable(0,"X0",COG.X(),.1,-detector->getScintSizeX()*.5,detector->getScintSizeX()*.5);//m_recon->getMinimizer()->FixVariable(0);	  
 // m_recon->getMinimizer()->SetLimitedVariable(1,"Y0",m_detector->getScintSizeY()*.5,.1,-m_detector->getScintSizeY()*.5,m_detector->getScintSizeY()*.5); m_recon->getMinimizer()->FixVariable(1);
  m_recon->getMinimizer()->SetLimitedVariable(2,"Z0",m_detector->getScintSizeZ()*.5,.1,-m_detector->getScintSizeZ()*.5,m_detector->getScintSizeZ()*.5);m_recon->getMinimizer()->FixVariable(2);
  
  //m_recon->getMinimizer()->SetVariable(3,"X1",0.,.1,-m_detector->getScintSizeX()*.5,m_detector->getScintSizeX()*.5);//m_recon->getMinimizer()->FixVariable(0);	  
//  m_recon->getMinimizer()->SetLimitedVariable(4,"Y1",-m_detector->getScintSizeY()*.5,.1,-m_detector->getScintSizeY()*.5,m_detector->getScintSizeY()*.5); m_recon->getMinimizer()->FixVariable(4);	  
  //m_recon->getMinimizer()->SetVariable(5,"Z1",0.,.1,-m_detector->getScintSizeZ()*.5,m_detector->getScintSizeZ()*.5);//m_recon->getMinimizer()->FixVariable(2);
  
  //m_recon->getMinimizer()->SetLimitedVariable(6,"b",0.99999,0.1,0.,1.);
  m_recon->getMinimizer()->FixVariable(6);	
  //m_recon->getMinimizer()->SetLimitedVariable(7,"t",0.,0.1,0.,1.);
  //m_recon->getMinimizer()->FixVariable(7);	//t gets automatically fixed if using k_onlyCharge
  if (fitMode!=k_onlyTime){
    m_recon->getMinimizer()->SetLowerLimitedVariable(8,"N",Ntot,1.,0);
  }
  //m_recon->getMinimizer()->FixVariable(8);	 //N gets automatically fixed if we set k_onlyTime
  //m_recon->getMinimizer()->SetVariable(9,"tau",1.5,0.1,0,0);
  m_recon->getMinimizer()->FixVariable(9);
  m_recon->getMinimizer()->SetStrategy(2);
  
  m_recon->setPrintLevel(2);
  m_recon->doFit();
  
  m_recon->getMinimizer()->PrintResults();
  cout<<"FIT DONE"<<endl;
    cout<<m_recon->getMinimizer()->X()[0]<<" "<<m_recon->getMinimizer()->X()[1]<<" "<<m_recon->getMinimizer()->X()[2]<<endl;
    cout<<m_recon->getMinimizer()->X()[3]<<" "<<m_recon->getMinimizer()->X()[4]<<" "<<m_recon->getMinimizer()->X()[5]<<endl;
    cout<<m_recon->getMinimizer()->X()[6]<<" "<<m_recon->getMinimizer()->X()[7]<<" "<<m_recon->getMinimizer()->X()[8]<<" "<<m_recon->getMinimizer()->X()[9]<<endl;
    
  
  
  if ((m_recon->getFitObject()==k_track)&&(m_recon->getMinimizer()->X()[6]*m_detector->getRindex()<1)){
    cout<<"In this fit, nb<1: do again point-like"<<endl;
    m_recon->getMinimizer()->Clear();
    m_recon->initParameters();
    fitObject=k_point;
    m_recon->setFitObject(fitObject);		
    m_recon->setFitLikelihoodMode(fitMode);
    
    m_recon->getMinimizer()->SetLimitedVariable(0,"X0",COG.X(),.1,-m_detector->getScintSizeX()*.5,m_detector->getScintSizeX()*.5); 
    m_recon->getMinimizer()->SetLimitedVariable(1,"Y0",COG.Y(),.1,-m_detector->getScintSizeY()*.5,m_detector->getScintSizeY()*.5);
    m_recon->getMinimizer()->SetLimitedVariable(2,"Z0",COG.Z(),.1,-m_detector->getScintSizeZ()*.5,m_detector->getScintSizeZ()*.5);
    m_recon->getMinimizer()->SetVariable(9,"tau",1.5,0.1);m_recon->getMinimizer()->FixVariable(9);
    
    
    m_recon->doFit();

    cout<<m_recon->getMinimizer()->X()[0]<<" "<<m_recon->getMinimizer()->X()[1]<<" "<<m_recon->getMinimizer()->X()[2];
    cout<<m_recon->getMinimizer()->X()[3]<<" "<<m_recon->getMinimizer()->X()[4]<<" "<<m_recon->getMinimizer()->X()[5];
    cout<<m_recon->getMinimizer()->X()[6]<<" "<<m_recon->getMinimizer()->X()[7]<<" "<<m_recon->getMinimizer()->X()[8]<<" "<<m_recon->getMinimizer()->X()[9]<<endl;
    
    
  }
  
  rReconIN.SetXYZ(m_recon->getMinimizer()->X()[0],m_recon->getMinimizer()->X()[1],m_recon->getMinimizer()->X()[2]);
  rReconOUT.SetXYZ(m_recon->getMinimizer()->X()[3],m_recon->getMinimizer()->X()[4],m_recon->getMinimizer()->X()[5]);
  
  
  
  rRecon=rReconOUT-rReconIN; //full trajectory
  
  Ntot=m_recon->getMinimizer()->X()[4];  
  
  hX_1->Fill( rReconIN.X());
  hY_1->Fill( rReconIN.Y());
  hZ_1->Fill( rReconIN.Z());
  hXY_1->Fill( rReconIN.X(), rReconIN.Y());
  hXZ_1->Fill( rReconIN.X(), rReconIN.Z());
  hYZ_1->Fill( rReconIN.Y(), rReconIN.Z());
  
  hX_2->Fill( rReconOUT.X());
  hY_2->Fill( rReconOUT.Y());
  hZ_2->Fill( rReconOUT.Z());
  hXY_2->Fill( rReconOUT.X(), rReconOUT.Y());
  hXZ_2->Fill( rReconOUT.X(), rReconOUT.Z());
  hYZ_2->Fill( rReconOUT.Y(), rReconOUT.Z());
  
  
  
  /*Define the angles wrt the VERTICAL direction, that is -y. Phi is in the xz plane, wrt to X*/ 
  ux.SetXYZ(1.,0.,0.);uy.SetXYZ(0.,1.,0.),uz.SetXYZ(0.,0.,1.); //since we have down-going muons..
  theta=rRecon.Angle(-1.*uy); //since we have down-going muons..
  
  double yTMP=rRecon.Y();
  
  rRecon.SetY(0.); //project on XZ
  phi=rRecon.Angle(ux);
  rRecon.SetY(yTMP);
  
  hTheta->Fill(theta*TMath::RadToDeg());
  hPhi->Fill(phi*TMath::RadToDeg());
     
  
  
  hT0->Fill(m_recon->getMinimizer()->X()[7]);
  hNPhotons->Fill(m_recon->getMinimizer()->X()[8]);
  hTau->Fill(  m_recon->getMinimizer()->X()[9]);
  
  
  
  return kTRUE;
}

void TOpNoviceSelectorRaw::SlaveTerminate()
{
  // The SlaveTerminate() function is called after all entries or objects
  // have been processed. When running with PROOF SlaveTerminate() is called
  // on each slave server.
  
  cout<<"SlaveTerminate start"<<endl;
  //   if (m_recon) delete m_recon;
  cout<<"SlaveTerminate end"<<endl;
  
}

void TOpNoviceSelectorRaw::Terminate()
{
  // The Terminate() function is the last function to be called during
  // a query. It always runs on the client, it can be used to present
  // the results graphically or save the results to file.
  cout<<"Terminate start"<<endl; 
  /*Get back all the histograms*/
  
   for (int ii=0;ii<6;ii++){
    if (m_detector->isDetPresent(ii)){
      hPixel0[ii]=  dynamic_cast<TH2D *>(fOutput->FindObject(Form("hPixel0_%i",ii+1)));
    }
   }
  
  hX =  dynamic_cast<TH1D *>(fOutput->FindObject("hX"));
  hY =  dynamic_cast<TH1D *>(fOutput->FindObject("hY"));
  hZ =  dynamic_cast<TH1D *>(fOutput->FindObject("hZ"));
  hXY =  dynamic_cast<TH2D *>(fOutput->FindObject("hXY"));
  hXZ =  dynamic_cast<TH2D *>(fOutput->FindObject("hXZ"));
  hYZ =  dynamic_cast<TH2D *>(fOutput->FindObject("hYZ"));
  
  hX_1 =  dynamic_cast<TH1D *>(fOutput->FindObject("hX_1"));
  hY_1 =  dynamic_cast<TH1D *>(fOutput->FindObject("hY_1"));
  hZ_1 =  dynamic_cast<TH1D *>(fOutput->FindObject("hZ_1"));
  hXY_1 =  dynamic_cast<TH2D *>(fOutput->FindObject("hXY_1"));
  hXZ_1 =  dynamic_cast<TH2D *>(fOutput->FindObject("hXZ_1"));
  hYZ_1 =  dynamic_cast<TH2D *>(fOutput->FindObject("hYZ_1"));
  
  hX_2 =  dynamic_cast<TH1D *>(fOutput->FindObject("hX_2"));
  hY_2 =  dynamic_cast<TH1D *>(fOutput->FindObject("hY_2"));
  hZ_2 =  dynamic_cast<TH1D *>(fOutput->FindObject("hZ_2"));
  hXY_2 =  dynamic_cast<TH2D *>(fOutput->FindObject("hXY_2"));
  hXZ_2 =  dynamic_cast<TH2D *>(fOutput->FindObject("hXZ_2"));
  hYZ_2 =  dynamic_cast<TH2D *>(fOutput->FindObject("hYZ_2"));
  
  hTheta =  dynamic_cast<TH1D *>(fOutput->FindObject("hTheta"));
  hPhi =  dynamic_cast<TH1D *>(fOutput->FindObject("hPhi"));
  
  hNPhotons= dynamic_cast<TH1D *>(fOutput->FindObject("hNPhotons"));
  hT0= dynamic_cast<TH1D *>(fOutput->FindObject("hT0"));;
  hTau= dynamic_cast<TH1D *>(fOutput->FindObject("hTau"));;
  
  
  TCanvas *c1=new TCanvas("c1","c1");
  c1->Divide(4,3);
  for (int ii=0;ii<4;ii++){if (m_detector->isDetPresent(ii)){c1->cd(ii+5);hPixel0[ii]->Draw("colz");}}
  if (m_detector->isDetPresent(4)){c1->cd(2);hPixel0[4]->Draw("colz");}
  if (m_detector->isDetPresent(5)){c1->cd(10);hPixel0[5]->Draw("colz");}
  fOutput->Add(c1);
  
  /*TCanvas *c2=new TCanvas("c2","c2");
  c2->Divide(3,3);
  c2->cd(4);hXY->Draw("colz");c2->cd(1);hX->Draw();c2->cd(7);hY->Draw();
  c2->cd(5);hYZ->Draw("colz");c2->cd(2);hY->Draw();c2->cd(8);hZ->Draw();
  c2->cd(6);hXZ->Draw("colz");c2->cd(3);hZ->Draw();c2->cd(9);hX->Draw();
  fOutput->Add(c2); */
  
  TCanvas *c2in=new TCanvas("c2In","c2_likelihoodReconstructionIN");
  c2in->Divide(3,3);
  c2in->cd(4);hXY_1->Draw("colz");c2in->cd(1);hX_1->Draw();c2in->cd(7);hY_1->Draw();
  c2in->cd(5);hYZ_1->Draw("colz");c2in->cd(2);hY_1->Draw();c2in->cd(8);hZ_1->Draw();
  c2in->cd(6);hXZ_1->Draw("colz");c2in->cd(3);hZ_1->Draw();c2in->cd(9);hX_1->Draw();
  fOutput->Add(c2in);
  
  TCanvas *c2out=new TCanvas("c2Out","c2_likelihoodReconstructionOUT");
  c2out->Divide(3,3);
  c2out->cd(4);hXY_2->Draw("colz");c2out->cd(1);hX_2->Draw();c2out->cd(7);hY_2->Draw();
  c2out->cd(5);hYZ_2->Draw("colz");c2out->cd(2);hY_2->Draw();c2out->cd(8);hZ_2->Draw();
  c2out->cd(6);hXZ_2->Draw("colz");c2out->cd(3);hZ_2->Draw();c2out->cd(9);hX_2->Draw();
  fOutput->Add(c2out);
  
  TCanvas *c2ang=new TCanvas("c2Angle","c2_likelihoodReconstructionAngles");
  c2ang->Divide(2,2);
  c2ang->cd(1);hTheta->Draw();
  c2ang->cd(2);hPhi->Draw();
  fOutput->Add(c2ang);
  
   
  TCanvas *c3=new TCanvas("c3","Other");
  c3->Divide(2,2);
  c3->cd(1);hNPhotons->Draw();
  c3->cd(2);hT0->Draw();
  c3->cd(3);hTau->Draw();
  fOutput->Add(c3);

  cout<<"Terminate end"<<endl;
}
