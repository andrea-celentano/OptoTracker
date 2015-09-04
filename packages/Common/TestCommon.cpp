
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
	array1->SetName("Coll1");
	TClonesArray *array2=new TClonesArray("TVectorT<double>");
	array2->SetName("Coll2");
	TClonesArray *array3=new TClonesArray("TH1D");
	array3->SetName("Coll3");
	TClonesArray *array4=new TClonesArray("TH1F");
	array4->SetName("Coll4");

	TH1D *h=new TH1D("h","h",100,0,1);


	cout<< h->IsA()->InheritsFrom("TH1")<<endl;
	cout<< h->IsA()->InheritsFrom("TH1")<<endl;
	cout<< h->IsA()->InheritsFrom("TLorentzVector")<<endl;
	cout<< h->IsA()->InheritsFrom(TH1F::Class())<<endl;
	cout<<dynamic_cast<TH1*>(h)<<endl;
	cout<<dynamic_cast<TH1F*>(h)<<endl;
	cin.get();






	ev->addCollection(array1);
	ev->addCollection(array2,1);
	ev->addCollection(array3,1);
	ev->addCollection(array4,1);
	cout<<ev->getNcollections()<<endl;
	ev->printCollections();
	cout<<ev->hasCollection(array4)<<endl;
	TClonesArray *test=ev->getCollection(TObject::Class(),"Coll3");

	cout<<test->GetClass()->GetName()<<endl;

	cout<<"Creating new"<<endl;
	TH1 *hh=(TH1*)TClass::GetClass("TH1D")->New();
	cout<<hh->IsA()->GetName()<<endl;


	TFile *f=new TFile("out.root","recreate");
	TTree *t=new TTree("out","out");
	t->Branch("event",&ev);

	TVectorT<float> *v;
	for (int ii=0;ii<100;ii++){
//		ev->Clear("C");
		for (int jj=0;jj<ii;jj++){
			//v=(TVectorT<float>*)(ev->getCollection(0)->ConstructedAt(jj));
		//	v->ResizeTo(10);
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
	//	int nC1=ev2->getCollection(0)->GetEntriesFast();
	//	cout<<"Qui: "<<nC1<<endl;
		//for (int jj=0;jj<nC1;jj++){
		//	cout<<ev2->getCollection(0)->At(jj)->GetName()<<" ";
			//cout<<((TVectorT<float>*)(ev2->getCollection(0)->At(jj)))->GetName()<<endl;
		//	//cout<<((TVectorT<float>*)(ev2->getCollection(0)->At(jj)))->GetNrows()<<endl;
			//	gui.Run(1);
		//}

	}
}
