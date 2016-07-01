/*
 * TTofpetDummyAnalysis.cc
 *
 *  Created on: Dec 4, 2015
 *      Author: celentan
 */

#include "TH1D.h"
#include "TH2D.h"


#include "TTofpetDummyAnalysisDriver.hh"
#include "TTofpetRun.hh"

#include "TEvent.hh"
#include "TTofpetEventHeader.hh"
#include "TTofpetHit.hh"
#include "TJobManager.hh"
#include "TTofpetSetupHandler.hh"

TTofpetDummyAnalysisDriver::TTofpetDummyAnalysisDriver() {
	// TODO Auto-generated constructor stub
	m_TofpetRun=0;
	hMultiplicity0=0;
	hMultiplicity1=0;
	hMultiplicity2=0;
	hMultiplicityAverage=0;
	hToT0=0;
	hToT1=0;

	hToTCh=0;
}

TTofpetDummyAnalysisDriver::~TTofpetDummyAnalysisDriver() {
	// TODO Auto-generated destructor stub
}

int TTofpetDummyAnalysisDriver::process(TEvent *event){
	TClonesArray *TTofpetHitCollection;
	TIter		 *TTofpetHitCollectionIter;
	TTofpetHit   *hit;
	TTofpetEventHeader *header=0;

	int N,step1,step2,id,id1,ch,ix,iy;



	header=(TTofpetEventHeader*)event->getEventHeader();
	if (header==0){
		Error("process","no event header!");
	}

	step1=header->getStep1();
	step2=header->getStep2();

	id=m_TofpetRun->getStepID(step1,step2);
	id1=m_TofpetRun->getStep1ID(step1);

	if (event->hasCollection(TTofpetHit::Class(),m_collectionRawName)){
		TTofpetHitCollection=event->getCollection(TTofpetHit::Class(),m_collectionRawName);

		N=TTofpetHitCollection->GetEntries();
		TTofpetHitCollectionIter=new TIter(TTofpetHitCollection);

		hMultiplicity0[id]->Fill(N);
		cout<<"THIS EVNT: "<<N<<" ::: ";
		while (hit = (TTofpetHit*)TTofpetHitCollectionIter->Next()){

			ch=hit->getChannel();
			ix=hit->getXi();
			iy=hit->getYi();
			cout<<ch<<" ";
			hToT0[id]->Fill(ix,iy,hit->getToT());
			hToT1[id]->Fill(ix,iy,hit->getToT());
			hToTCh[id1*128+ch]->Fill(hit->getToT(),step2);

			hMultiplicity1[id]->Fill(ix,iy);
			hMultiplicity2[id]->Fill(ch);

			//cout<<hit->getChannel()<<" "<<hit->getToT()<<endl;
		}
		cout<<endl;
		delete 	TTofpetHitCollectionIter;
	}
	else{
		Error("process","no collection with class TTofpetHit and name %s was found",m_collectionRawName.c_str());
	}

	return 0;
}

int TTofpetDummyAnalysisDriver::startOfData(){
	Info("startOfData","start");

	int step1,step2,N;

	hMultiplicityAverage=new TH2D("hMultiplicityAverage","hMultiplicityAverage",64,-0.5,63.5,64,-0.5,63.5);
	m_manager->GetOutputList()->Add(hMultiplicityAverage);

	if (m_manager->hasObject(TTofpetRun::Class())){
		m_TofpetRun=(TTofpetRun*)(m_manager->getObject(TTofpetRun::Class()));
		m_Nsteps=m_TofpetRun->getNsteps();
		if (m_manager->getVerboseLevel()>TJobManager::normalVerbosity)	Info("startOfData","Got TTofpetSetup. Number of steps: %i",m_Nsteps);

		hToT0=new TH2D*[m_Nsteps];
		hToT1=new TH2D*[m_Nsteps];
		hToTCh=new TH2D*[m_Nch*m_TofpetRun->getNsteps1()];

		hMultiplicity0=new TH1D*[m_Nsteps];
		hMultiplicity1=new TH2D*[m_Nsteps];
		hMultiplicity2=new TH1D*[m_Nsteps];

		for (int ii=0;ii<m_Nsteps;ii++){
			step1=m_TofpetRun->getStep1(ii);
			step2=m_TofpetRun->getStep2(ii);

			hMultiplicity0[ii]=new TH1D(Form("hMultiplicity0_%i_%i",step1,step2),Form("hMultiplicity0_%i_%i",step1,step2),m_Nch,-0.5,255.5);
			m_manager->GetOutputList()->Add(hMultiplicity0[ii]);

			hMultiplicity1[ii]=new TH2D(Form("hMultiplicity1_%i_%i",step1,step2),Form("hMultiplicity1_%i_%i",step1,step2),TTofpetSetupHandler::nTofpetPixelsX,-0.5,TTofpetSetupHandler::nTofpetPixelsX-0.5,TTofpetSetupHandler::nTofpetPixelsY,-.5,TTofpetSetupHandler::nTofpetPixelsY-.5);
			m_manager->GetOutputList()->Add(hMultiplicity1[ii]);

			hMultiplicity2[ii]=new TH1D(Form("hMultiplicity2_%i_%i",step1,step2),Form("hMultiplicity2_%i_%i",step1,step2),m_Nch,-0.5,255.5);
			m_manager->GetOutputList()->Add(hMultiplicity2[ii]);

		}


		for (int ii=0;ii<m_Nsteps;ii++){
			step1=m_TofpetRun->getStep1(ii);
			step2=m_TofpetRun->getStep2(ii);

			hToT0[ii]=new TH2D(Form("hTot0_%i_%i",step1,step2),Form("hTot0_%i_%i",step1,step2),TTofpetSetupHandler::nTofpetPixelsX,-0.5,TTofpetSetupHandler::nTofpetPixelsX-0.5,TTofpetSetupHandler::nTofpetPixelsY,-.5,TTofpetSetupHandler::nTofpetPixelsY-.5);
			hToT1[ii]=new TH2D(Form("hTot1_%i_%i",step1,step2),Form("hTot1_%i_%i",step1,step2),TTofpetSetupHandler::nTofpetPixelsX,-0.5,TTofpetSetupHandler::nTofpetPixelsX-0.5,TTofpetSetupHandler::nTofpetPixelsY,-.5,TTofpetSetupHandler::nTofpetPixelsY-.5);
			m_manager->GetOutputList()->Add(hToT0[ii]);
			m_manager->GetOutputList()->Add(hToT1[ii]);
		}

		for (int ii=0;ii<m_TofpetRun->getNsteps1();ii++){
			for (int jj=0;jj<m_Nch;jj++){
				hToTCh[ii*m_Nch+jj]=new TH2D(Form("hToTCh_%i_%i",ii,jj),Form("hToTCh_%i_%i",ii,jj),1000,-50,200,64,-0.5,63.5);
				m_manager->GetOutputList()->Add(hToTCh[ii*m_Nch+jj]);
			}
		}
	}
	else{
		Error("startOfData","No TTofpetRun object in the file, should be there!");
		return -1;
	}


	return 0;
}

int TTofpetDummyAnalysisDriver::end(){
	Info("end","end starts now");
	int step1,step2;
	double N;

	m_TofpetRun=0;
	hMultiplicityAverage=0;

	hMultiplicityAverage=(TH2D*)m_manager->GetOutputList()->FindObject("hMultiplicityAverage");

	/*m_TofpetRun is in the INPUT list!*/
	m_TofpetRun=(TTofpetRun*)m_manager->getObject(TTofpetRun::Class());
	if (m_TofpetRun==0){
		Error("end","No TTofpetRun!");
		return -1;
	}

	m_Nsteps=m_TofpetRun->getNsteps();
	Info("end","There are %i steps",m_Nsteps);

	hMultiplicity0=new TH1D*[m_Nsteps];
	hMultiplicity1=new TH2D*[m_Nsteps];
	hToT0=new TH2D*[m_Nsteps];
	hToT1=new TH2D*[m_Nsteps];
	hToTCh=new TH2D*[m_Nch*m_TofpetRun->getNsteps1()];




	for (int ii=0;ii<m_Nsteps;ii++){
		step1=m_TofpetRun->getStep1(ii);
		step2=m_TofpetRun->getStep2(ii);
		Info("end","getting histos for: %i %i",step1,step2);

		/*These are histograms in the output list!*/
		hMultiplicity0[ii]=(TH1D*)m_manager->GetOutputList()->FindObject(Form("hMultiplicity0_%i_%i",step1,step2));
		hMultiplicity1[ii]=(TH2D*)m_manager->GetOutputList()->FindObject(Form("hMultiplicity1_%i_%i",step1,step2));

		hToT0[ii]=(TH2D*)m_manager->GetOutputList()->FindObject(Form("hTot0_%i_%i",step1,step2));
		hToT0[ii]->Scale(1./m_TofpetRun->getStepNevents(step1,step2));

		hToT1[ii]=(TH2D*)m_manager->GetOutputList()->FindObject(Form("hTot1_%i_%i",step1,step2));
		hToT1[ii]->Divide(hMultiplicity1[ii]);




	//	hMultiplicity1[ii]->Scale(1./m_TofpetRun->getStepNevents(step1,step2));
		Info("end","hMultiplicity1 scaled: %s",hMultiplicity1[ii]->GetName());



		N=hMultiplicity0[ii]->GetMean();
		hMultiplicityAverage->Fill(step1,step2,N);
	}
	return 0;


}
