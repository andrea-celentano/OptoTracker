#define TOptoSelectorRaw_cxx


#include "TOptoSelectorRaw.hh"


TOptoSelectorRaw::TOptoSelectorRaw(TTree* t) :
TOptoSelector(t)
{
	Info("TOptoSelectorRaw","TOptoSelectorRaw constructor");

}



Bool_t TOptoSelectorRaw::Process(Long64_t entry)
{

	Info("Process","Processing entry %li",entry);
	//local variables
	int Nhit,iface,idetector,ipixel,Nphe,Ntot;
	int qtot=0;
	double xp,yp,t,theta,phi;
	TVector3  COG,rReconIN,rReconOUT,rRecon;
	TVector3 ux,uy,uz;
	//clear some variables
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<mm_detector->getNdet(ii);jj++){
			for (int ipid=0;ipid<mm_detector->getNPixels(ii,jj);ipid++){
				N[ii][jj][ipid]=0;
				q[ii][jj][ipid]=0;
				tFirst[ii][jj][ipid]=9999;
			}
		}
	}
	//load the entry, it "goes" in: raw. For the "raw" branch, there is 1 entry per "detector" (i.e. scintillator size)
	GetEntry(entry);
	Nhit=raw->size();

	//start processing

	//load the data
	for (int ihit=0;ihit<Nhit;ihit++){
		iface=raw->at(ihit)->GetFaceNumber();
		idetector=raw->at(ihit)->GetDetectorNumber();
		if (mm_detector->isDetPresent(iface,idetector)==0){
			cout<<"Error! The detector "<<idetector<<"on face "<<iface<<"is not supposed to be here but we have a hit"<<endl;
			exit(1);
		}
		Nphe=raw->at(ihit)->GetPheCount(); //1 "phe" is 1 detected photon (QE already included) on the detector
		for (int iphe=0;iphe<Nphe;iphe++){

			xp=raw->at(ihit)->GetX(iphe);
			yp=raw->at(ihit)->GetY(iphe);
			t=raw->at(ihit)->GetT(iphe);
			ipixel=raw->at(ihit)->GetPixel(iphe);

			//cout<<iPMT<<" "<<xp<<" "<<yp<<" "<<pid<<" "<<raw->at(ihit)->GetPixel(iphe)<<endl;

			//Time resolution effects
			if (mm_detector->getDetTimeRes(iface,idetector)>0) t=t+mm_rand->Gaus(0,mm_detector->getDetTimeRes(iface,idetector));
			if (t<tFirst[iface][idetector][ipixel]) tFirst[iface][idetector][ipixel]=t;


			qtot++;
			N[iface][idetector][ipixel]++;

			hPixel0[iface][idetector]->Fill(xp,yp);

		}//end loop on phe
	}//end loop on hits (1 hit == 1 face)


	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<mm_detector->getNdet(ii);jj++){
			if (mm_detector->isDetPresent(ii,jj)==0) continue;
			for (int id=0;id<mm_detector->getNPixels(ii,jj);id++){
				hCharge[ii+jj*6]->at(id)->Fill(N[ii][jj][id]);
				hTime[ii+jj*6]->at(id)->Fill(tFirst[ii][jj][id]);
				hTimeVsCharge[ii+jj*6]->at(id)->Fill(N[ii][jj][id],tFirst[ii][jj][id]);
			}
		}
	}


	//fill the reconstruction class with data
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<mm_detector->getNdet(ii);jj++){
			if (mm_detector->isDetPresent(ii,jj)==0) continue;
			mm_recon->setNaddress(ii,jj,N[ii][jj]);
			mm_recon->setTaddress(ii,jj,tFirst[ii][jj]);
		}
	}
	//compute COG
	COG=mm_recon->computeCOG();


	//Try the likelihood fit


	Ntot=qtot/0.2;

	mm_recon->getMinimizer()->Clear();



	mm_recon->initFit();
	mm_recon->getMinimizer()->SetStrategy(2);
	mm_recon->setPrintLevel(2);
	mm_recon->doFit();




	mm_recon->getMinimizer()->PrintResults();
	Info("Process","Fit was done");
	cout<<mm_recon->getMinimizer()->X()[0]<<" "<<mm_recon->getMinimizer()->X()[1]<<" "<<mm_recon->getMinimizer()->X()[2]<<endl;
	cout<<mm_recon->getMinimizer()->X()[3]<<" "<<mm_recon->getMinimizer()->X()[4]<<" "<<mm_recon->getMinimizer()->X()[5]<<endl;
	cout<<mm_recon->getMinimizer()->X()[6]<<" "<<mm_recon->getMinimizer()->X()[7]<<" "<<mm_recon->getMinimizer()->X()[8]<<" "<<mm_recon->getMinimizer()->X()[9]<<endl;


/*
	if ((m_recon->getFitObject()==k_track)&&(m_recon->getMinimizer()->X()[6]*mm_detector->getRindex()<1)){
		cout<<"In this fit, nb<1: do again point-like"<<endl;
		m_recon->getMinimizer()->Clear();
		m_recon->initParameters();
		fitObject=k_point;
		m_recon->setFitObject(fitObject);
		m_recon->setFitLikelihoodMode(fitMode);

		m_recon->getMinimizer()->SetLimitedVariable(0,"X0",COG.X(),.1,-mm_detector->getScintSizeX()*.5,mm_detector->getScintSizeX()*.5);
		m_recon->getMinimizer()->SetLimitedVariable(1,"Y0",COG.Y(),.1,-mm_detector->getScintSizeY()*.5,mm_detector->getScintSizeY()*.5);
		m_recon->getMinimizer()->SetLimitedVariable(2,"Z0",COG.Z(),.1,-mm_detector->getScintSizeZ()*.5,mm_detector->getScintSizeZ()*.5);
		m_recon->getMinimizer()->SetVariable(9,"tau",1.5,0.1);m_recon->getMinimizer()->FixVariable(9);


		m_recon->doFit();

		cout<<m_recon->getMinimizer()->X()[0]<<" "<<m_recon->getMinimizer()->X()[1]<<" "<<m_recon->getMinimizer()->X()[2];
		cout<<m_recon->getMinimizer()->X()[3]<<" "<<m_recon->getMinimizer()->X()[4]<<" "<<m_recon->getMinimizer()->X()[5];
		cout<<m_recon->getMinimizer()->X()[6]<<" "<<m_recon->getMinimizer()->X()[7]<<" "<<m_recon->getMinimizer()->X()[8]<<" "<<m_recon->getMinimizer()->X()[9]<<endl;


	}*/

	rReconIN.SetXYZ(mm_recon->getMinimizer()->X()[0],mm_recon->getMinimizer()->X()[1],mm_recon->getMinimizer()->X()[2]);
	rReconOUT.SetXYZ(mm_recon->getMinimizer()->X()[3],mm_recon->getMinimizer()->X()[4],mm_recon->getMinimizer()->X()[5]);



	rRecon=rReconOUT-rReconIN; //full trajectory

	Ntot=mm_recon->getMinimizer()->X()[4];

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



	hT0->Fill(mm_recon->getMinimizer()->X()[7]);
	hNPhotons->Fill(mm_recon->getMinimizer()->X()[8]);
	hTau->Fill( mm_recon->getMinimizer()->X()[9]);



	return kTRUE;
}
