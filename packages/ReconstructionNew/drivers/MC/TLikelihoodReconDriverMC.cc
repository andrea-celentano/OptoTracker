/*
 * TLikelihoodReconDriver.cc
 *
 *  Created on: Sep 25, 2015
 *      Author: celentan
 */
#include "TLikelihoodReconDriverMC.hh"

#include <stdio.h>
#include "TLikelihoodReconDriverMC.hh"
#include "TEvent.hh"

#include "OpNoviceDigi.hh"


int TLikelihoodReconDriverMC::process(TEvent *event){
	TClonesArray *digiCollection;
	TIter		 *digiCollectionIter;
	OpNoviceDigi *digi;

	TVector3 rReconIN,rReconOUT,rRecon;
	TVector3 ux,uy,uz;
	double Ntot,theta,phi;
	int face,detector,pixel,nPhe,nX,nY,ID;

	/*First, check if the recon input was given from file or we expect it event by event from previous drivers*/
	if (m_reconInputMode==reconInputDriver){
		if (event->hasObject("reconInput")){
			m_reconInput=(TReconInput*)event->getObject("reconInput");
		}
		else{
			Error("process","Asked for recon input from driver, but no reconInput object present. Are you using the TMatrixReconDriver and the TMatrixInterpreterDriver?");
			return 1;
		}
	}
	else if (m_reconInput==0){
		Error("process","something went wrong, no reconInput");
		return 2;
	}

	/*Prepare the data*/
	for (face=0;face<6;face++){
		for (detector=0;detector<m_manager->getDetector()->getNdet(face);detector++){
			for (pixel=0;pixel<m_manager->getDetector()->getNPixels(face,detector);pixel++){
				m_N[face][detector][pixel]=-1;  /*I use a negative value, since it is possible that we do not have this data in this event. Therefore, the likelihood will ignore this pixel*/
				m_T[face][detector][pixel]=-1;
				m_Q[face][detector][pixel]=-1;
			}
		}
	}

	if (event->hasCollection(OpNoviceDigi::Class(),m_collectionName)){
		cout<<"!!!!!!OK!!!!!!!"<<endl;
		digiCollection=event->getCollection(OpNoviceDigi::Class(),m_collectionName);
		digiCollectionIter=new TIter(digiCollection);
		while (digi = (OpNoviceDigi*)digiCollectionIter->Next()){
			face=digi->GetFaceNumber();
			detector=digi->GetDetectorNumber();
			pixel=digi->GetPixelNumber();
			nPhe=digi->GetPheCount();
			m_N[face][detector][pixel]=nPhe;
			nX=m_manager->getDetector()->getNPixelsX(face,detector);
			nY=m_manager->getDetector()->getNPixelsY(face,detector);
			ID=m_manager->getDetector()->getPixelGlobalID(face,detector,pixel);
		}
	}


	m_minimizer->Clear();
	this->initParameters(); /*This defines the parameters*/
	this->initFit();

	this->doFit();

	if (m_manager->getVerboseLevel()>=TJobManager::normalVerbosity){
		this->getMinimizer()->PrintResults();
		Info("Process","Fit was done");
		cout<<m_minimizer->X()[0]<<" "<<m_minimizer->X()[1]<<" "<<m_minimizer->X()[2]<<endl;
		cout<<m_minimizer->X()[3]<<" "<<m_minimizer->X()[4]<<" "<<m_minimizer->X()[5]<<endl;
		cout<<m_minimizer->X()[6]<<" "<<m_minimizer->X()[7]<<" "<<m_minimizer->X()[8]<<" "<<m_minimizer->X()[9]<<endl;
	}



	rReconIN.SetXYZ(m_minimizer->X()[0],m_minimizer->X()[1],m_minimizer->X()[2]);
	rReconOUT.SetXYZ(m_minimizer->X()[3],m_minimizer->X()[4],m_minimizer->X()[5]);



	rRecon=rReconOUT-rReconIN; //full trajectory

	Ntot=m_minimizer->X()[4];

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



	hT0->Fill(m_minimizer->X()[7]);
	hNPhotons->Fill(m_minimizer->X()[8]);
	hTau->Fill( m_minimizer->X()[9]);




	return 0;
}

