
#include "TEvent.hh"

#include "TFile.h"
#include "TTree.h"
#include "TObject.h"
#include "TH1D.h"
#include "TApplication.h"
#include "TVectorT.h"
#include "Cintex/Cintex.h"


#include <iostream>



using namespace std;
TApplication gui("gui",0,NULL);

int main(){
	//Load Cintex
	ROOT::Cintex::Cintex::Enable();
	TEvent *ev=new TEvent();
	TClonesArray *array1=new TClonesArray("TVectorT<float>");
	array1->SetName("StiCazzi");
	TClonesArray *array2=new TClonesArray("TVectorT<double>");
	array2->SetName("StiCazzia");


	ev->addCollection(array1);
	ev->addCollection(array2,1);
	cout<<ev->getNcollections()<<endl;
	ev->printCollectionsName();

	cout<<ev->getCollectionByName("StiCazzia")->GetClass()->GetName()<<endl;

	TFile *f=new TFile("out.root","recreate");
	TTree *t=new TTree("out","out");
	t->Branch("event",&ev);

	TVectorT<float> *v;
	for (int ii=0;ii<100;ii++){
//		ev->Clear("C");
		for (int jj=0;jj<ii;jj++){
			v=(TVectorT<float>*)(ev->getCollection(0)->ConstructedAt(jj));
			v->ResizeTo(10);
		}
		t->Fill();
	}
	t->Write();
	f->Close();

	cin.get();


	TFile *f2=new TFile("out.root");
	TTree *t2=(TTree*)f2->Get("out");

	TEvent *ev2=NULL;

	t2->SetBranchAddress("event",&ev2);
	for (int ii=0;ii<t2->GetEntries();ii++){
		if (ev2) ev2->Clear("C");
		t2->GetEntry(ii);
		int nC1=ev2->getCollection(0)->GetEntriesFast();
		cout<<"Qui: "<<nC1<<endl;
		for (int jj=0;jj<nC1;jj++){
			cout<<ev2->getCollection(0)->At(jj)->GetName()<<" ";
			cout<<((TVectorT<float>*)(ev2->getCollection(0)->At(jj)))->GetName()<<endl;
			cout<<((TVectorT<float>*)(ev2->getCollection(0)->At(jj)))->GetNrows()<<endl;
			//	gui.Run(1);
		}

	}
}
