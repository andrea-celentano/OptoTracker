#define TOptoSelector_cxx


#include "TOptoSelector.hh"

TOptoSelector::TOptoSelector(TTree* /*tree*/) :
fChain(0),mm_recon(0),mm_detector(0),mm_reconInput(0),mm_rand(0)
{ 
	Info("TOptoSelector","TOptoSelector constructor");
	hPixel0Title=new string[6];
	
	hPixel0Title[0]="hPixel0_0;-x;y";
	hPixel0Title[1]="hPixel0_0;+z;+y";
	hPixel0Title[2]="hPixel0_0;+x;+y";
	hPixel0Title[3]="hPixel0_0;-z;+y";
	hPixel0Title[4]="hPixel0_0;+x;+z";
	hPixel0Title[5]="hPixel0_0;+x;-z";
	
	hX=hY=hZ=hX_1=hY_1=hZ_1=hX_2=hY_2=hZ_2=0;
	hXY=hXZ=hYZ=hXY_1=hXZ_1=hYZ_1=hXY_2=hXZ_2=hYZ_2=0;
	hTheta=hPhi=0;
	hNPhotons=hT0=hTau=0;
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<MAX_DETECTORS;jj++){
			hPixel0[ii][jj]=0;
		}
	}
}
void TOptoSelector::Begin(TTree * /*tree*/)
{
	// The Begin() function is called at the start of the query.
	// When running with PROOF Begin() is only called on the client.
	// The tree argument is deprecated (on PROOF 0 is passed).

	TString option = GetOption();
	Info("Begin","Master Begin");

	if (mm_detector==0){
		mm_detector=dynamic_cast<TDetectorLight *>(fInput->FindObject("TDetectorLight"));
		Info("Begin","We are on Proof, load detector on master");
		if (mm_detector==NULL){
			Error("Begin","Detector not on the master");
			exit(1);
		}
	}
	if (mm_reconInput==0){
		mm_reconInput=dynamic_cast<TReconInput *>(fInput->FindObject("TReconInput"));
		Info("Begin","We are on Proof, load recon input on master");
		if (mm_reconInput==NULL){
			Error("Begin","Recon Input not on the master");
			exit(1);
		}
	}
}

void TOptoSelector::SlaveBegin(TTree * /*tree*/)
{
	// The SlaveBegin() function is called after the Begin() function.
	// When running with PROOF SlaveBegin() is called on each slave server.
	// The tree argument is deprecated (on PROOF 0 is passed).

	TString option = GetOption();
	//Random number generator
	mm_rand=new TRandom3(mm_seed);
	Info("SlaveBegin","Slave begin");

	//Get the detector object from the input list
	if (mm_detector==0){
		mm_detector=dynamic_cast<TDetectorLight *>(fInput->FindObject("TDetectorLight"));
		Info("Begin","We are on Proof, loaded detector on slave");
	}
	if (mm_detector==NULL){
		Error("SlaveBegin","Detector not on a slave");
		exit(1);
	}
	
	if (mm_reconInput==0){
		mm_reconInput=dynamic_cast<TReconInput *>(fInput->FindObject("TReconInput"));
		Info("Begin","We are on Proof, loaded recon input on slave");
		
	}
	if (mm_reconInput==NULL){
		Error("Begin","Recon Input not on the slave");
		exit(1);
	}
	
	
	mm_detector->Print();
	mm_reconInput->Print();
	//I need to create the "reconstruction" class in EVERY slave
	mm_recon=new TRecon(mm_detector,mm_reconInput);

	//Init the variables used in the Process
	N=new int**[6];
	tFirst=new double**[6];
	q=new double**[6];


	for (int ii=0;ii<6;ii++){
		q[ii]=new double*[MAX_DETECTORS];
		N[ii]=new int*[MAX_DETECTORS];
		tFirst[ii]=new double*[MAX_DETECTORS];

		for (int jj=0;jj<mm_detector->getNdet(ii);jj++){
			q[ii][jj]=new double[mm_detector->getNPixels(ii,jj)]();
			N[ii][jj]=new int[mm_detector->getNPixels(ii,jj)]();
			tFirst[ii][jj]=new double[mm_detector->getNPixels(ii,jj)]();
		}
	}

	//Histograms
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<mm_detector->getNdet(ii);jj++){
			if (mm_detector->isDetPresent(ii,jj)){
				hPixel0[ii][jj]=new TH2D(Form("hPixel0_%i_%i",ii,jj),Form("hPixel0_%i_%i",ii,jj),mm_detector->getNPixelsX(ii,jj),-mm_detector->getDetSizeX(ii,jj)/2,mm_detector->getDetSizeX(ii,jj)/2,mm_detector->getNPixelsY(ii,jj),-mm_detector->getDetSizeY(ii,jj)/2,mm_detector->getDetSizeY(ii,jj)/2);
				hPixel0[ii][jj]->SetTitle(hPixel0Title[ii].c_str());
				fOutput->Add(hPixel0[ii][jj]); //VERY IMPORTANT: fill output list


				int Nx=mm_detector->getNPixelsX(ii,jj);
				int Ny=mm_detector->getNPixelsY(ii,jj);
				
				hCharge[ii+jj*6]=new vector <TH1D*>;
				hTime[ii+jj*6]=new vector <TH1D*>;
				hTimeVsCharge[ii+jj*6]=new vector <TH2D*>;
				
				for (int id=0;id<Nx*Ny;id++){ /*indexed in this way: ID=6*idetector + iface*/
					hCharge[ii+jj*6]->push_back(new TH1D(Form("hCharge_%i_%i_%i",ii,jj,id),Form("hCharge_%i_%i_%i",ii,jj,id),1000,-0.5,999.5));fOutput->Add(hCharge[ii+jj*6]->at(id));
					hTime[ii+jj*6]->push_back(new TH1D(Form("hTime_%i_%i_%i",ii,jj,id),Form("hTime_%i_%i_%i",ii,jj,id),400,-2.5,17.5));fOutput->Add(hTime[ii+jj*6]->at(id));
					hTimeVsCharge[ii+jj*6]->push_back(new TH2D(Form("hTimeVsCharge_%i_%i_%i",ii,jj,id),Form("hTimeVsCharge_%i_%i_%i",ii,jj,id),1000,-0.5,999.5,400,-2.5,17.5));fOutput->Add(hTimeVsCharge[ii+jj*6]->at(id));
				}
			}
		}
	}


	hX=new TH1D("hX","hX;x (cm)",200,-mm_detector->getScintSizeX()/2-1,mm_detector->getScintSizeX()/2+1);fOutput->Add(hX);
	hY=new TH1D("hY","hY;y (cm)",200,-mm_detector->getScintSizeY()/2-1,mm_detector->getScintSizeY()/2+1);fOutput->Add(hY);
	hZ=new TH1D("hZ","hZ;z (cm)",200,-mm_detector->getScintSizeZ()/2-1,mm_detector->getScintSizeZ()/2+1);fOutput->Add(hZ);
	hXY=new TH2D("hXY","hXY;x (cm);y (cm)",100,-mm_detector->getScintSizeX()/2-1,mm_detector->getScintSizeX()/2+1,100,-mm_detector->getScintSizeY()/2-1,mm_detector->getScintSizeY()/2+1);fOutput->Add(hXY);
	hXZ=new TH2D("hXZ","hXZ;x (cm);z (cm)",100,-mm_detector->getScintSizeX()/2-1,mm_detector->getScintSizeX()/2+1,100,-mm_detector->getScintSizeZ()/2-1,mm_detector->getScintSizeZ()/2+1);fOutput->Add(hXZ);
	hYZ=new TH2D("hYZ","hYZ;y (cm);z (cm)",100,-mm_detector->getScintSizeY()/2-1,mm_detector->getScintSizeY()/2+1,100,-mm_detector->getScintSizeZ()/2-1,mm_detector->getScintSizeZ()/2+1);fOutput->Add(hYZ);


	hX_1=new TH1D("hX_1","hX;x (cm)",200,-mm_detector->getScintSizeX()/2-1,mm_detector->getScintSizeX()/2+1);fOutput->Add(hX_1);
	hY_1=new TH1D("hY_1","hY;y (cm)",200,-mm_detector->getScintSizeY()/2-1,mm_detector->getScintSizeY()/2+1);fOutput->Add(hY_1);
	hZ_1=new TH1D("hZ_1","hZ;z (cm)",200,-mm_detector->getScintSizeZ()/2-1,mm_detector->getScintSizeZ()/2+1);fOutput->Add(hZ_1);
	hXY_1=new TH2D("hXY_1","hXY;x (cm);y (cm)",100,-mm_detector->getScintSizeX()/2-1,mm_detector->getScintSizeX()/2+1,100,-mm_detector->getScintSizeY()/2-1,mm_detector->getScintSizeY()/2+1);fOutput->Add(hXY_1);
	hXZ_1=new TH2D("hXZ_1","hXZ;x (cm);z (cm)",100,-mm_detector->getScintSizeX()/2-1,mm_detector->getScintSizeX()/2+1,100,-mm_detector->getScintSizeZ()/2-1,mm_detector->getScintSizeZ()/2+1);fOutput->Add(hXZ_1);
	hYZ_1=new TH2D("hYZ_1","hYZ;y (cm);z (cm)",100,-mm_detector->getScintSizeY()/2-1,mm_detector->getScintSizeY()/2+1,100,-mm_detector->getScintSizeZ()/2-1,mm_detector->getScintSizeZ()/2+1);fOutput->Add(hYZ_1);

	hX_2=new TH1D("hX_2","hX;x (cm)",200,-mm_detector->getScintSizeX()/2-1,mm_detector->getScintSizeX()/2+1);fOutput->Add(hX_2);
	hY_2=new TH1D("hY_2","hY;y (cm)",200,-mm_detector->getScintSizeY()/2-1,mm_detector->getScintSizeY()/2+1);fOutput->Add(hY_2);
	hZ_2=new TH1D("hZ_2","hZ;z (cm)",200,-mm_detector->getScintSizeZ()/2-1,mm_detector->getScintSizeZ()/2+1);fOutput->Add(hZ_2);
	hXY_2=new TH2D("hXY_2","hXY;x (cm);y (cm)",100,-mm_detector->getScintSizeX()/2-1,mm_detector->getScintSizeX()/2+1,100,-mm_detector->getScintSizeY()/2-1,mm_detector->getScintSizeY()/2+1);fOutput->Add(hXY_2);
	hXZ_2=new TH2D("hXZ_2","hXZ;x (cm);z (cm)",100,-mm_detector->getScintSizeX()/2-1,mm_detector->getScintSizeX()/2+1,100,-mm_detector->getScintSizeZ()/2-1,mm_detector->getScintSizeZ()/2+1);fOutput->Add(hXZ_2);
	hYZ_2=new TH2D("hYZ_2","hYZ;y (cm);z (cm)",100,-mm_detector->getScintSizeY()/2-1,mm_detector->getScintSizeY()/2+1,100,-mm_detector->getScintSizeZ()/2-1,mm_detector->getScintSizeZ()/2+1);fOutput->Add(hYZ_2);



	hTheta=new TH1D("hTheta","hTheta",150,-120,120);fOutput->Add(hTheta);
	hPhi=new TH1D("hPhi","hPhi",150,-250,250);fOutput->Add(hPhi);

	hNPhotons=new TH1D("hNPhotons","hNPhotons",1000,0,4E5);fOutput->Add(hNPhotons);
	hT0=new TH1D("hT0","hT0",100,-.1,.1);fOutput->Add(hT0);
	hTau=new TH1D("hTau","hTau",100,-.1,5);fOutput->Add(hTau);




}

void TOptoSelector::SlaveTerminate()
{
	// The SlaveTerminate() function is called after all entries or objects
	// have been processed. When running with PROOF SlaveTerminate() is called
	// on each slave server.

	cout<<"SlaveTerminate start"<<endl;
	//   if (m_recon) delete m_recon;
	cout<<"SlaveTerminate end"<<endl;

}

void TOptoSelector::Terminate()
{
	// The Terminate() function is the last function to be called during
	// a query. It always runs on the client, it can be used to present
	// the results graphically or save the results to file.
	cout<<"Terminate start"<<endl;
	/*Get back all the histograms*/

	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<mm_detector->getNdet(ii);jj++){
			if (mm_detector->isDetPresent(ii,jj)){
				hPixel0[ii][jj]=  dynamic_cast<TH2D *>(fOutput->FindObject(Form("hPixel0_%i_%i",ii,jj)));
			}
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


	/*TCanvas *c1=new TCanvas("c1","c1");
	c1->Divide(4,3);
	for (int ii=0;ii<4;ii++){if (mm_detector->isDetPresent(ii)){c1->cd(ii+5);hPixel0[ii]->Draw("colz");}}
	if (mm_detector->isDetPresent(4)){c1->cd(2);hPixel0[4]->Draw("colz");}
	if (mm_detector->isDetPresent(5)){c1->cd(10);hPixel0[5]->Draw("colz");}
	fOutput->Add(c1);
	 */

	/*TCanvas *c2=new TCanvas("c2","c2");
  c2->Divide(3,3);
  c2->cd(4);hXY->Draw("colz");c2->cd(1);hX->Draw();c2->cd(7);hY->Draw();
  c2->cd(5);hYZ->Draw("colz");c2->cd(2);hY->Draw();c2->cd(8);hZ->Draw();
  c2->cd(6);hXZ->Draw("colz");c2->cd(3);hZ->Draw();c2->cd(9);hX->Draw();
  fOutput->Add(c2); */

	TCanvas *c2in=new TCanvas("c2In","x0");
	c2in->Divide(3,2);
	c2in->cd(4);hXY_1->Draw("colz");c2in->cd(1);hX_1->Draw();
	c2in->cd(5);hYZ_1->Draw("colz");c2in->cd(2);hY_1->Draw();
	c2in->cd(6);hXZ_1->Draw("colz");c2in->cd(3);hZ_1->Draw();
	fOutput->Add(c2in);

	TCanvas *c2out=new TCanvas("c2Out","x1");
	c2out->Divide(3,3);
	c2out->cd(4);hXY_2->Draw("colz");c2out->cd(1);hX_2->Draw();
	c2out->cd(5);hYZ_2->Draw("colz");c2out->cd(2);hY_2->Draw();
	c2out->cd(6);hXZ_2->Draw("colz");c2out->cd(3);hZ_2->Draw();
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
