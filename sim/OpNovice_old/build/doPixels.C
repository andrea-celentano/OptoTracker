#include "TFile.h"
#include "TTree.h"
#include "TSystem.h"

const int Nvx=5,Nvy=5,Nvz=5;
const int Npx=8,Npy=8,Npz=8,Npmt=5;
double Lx=49,Ly=49,Lz=49;

doPixels(int iv){
	int ix,iy,iz;

	iz=iv/(Nvx*Nvy);
	iy=(iv/Nvx)-iz*Nvy;
	ix=(iv-Nvx*iy-Nvx*Nvy*iz);
	
	doPixels(ix,iy,iz);
}

doPixels(int ix,int iy,int iz){
	int iv;
	double xv,yv,zv;




	iv=ix+iy*Nvx+iz*Nvx*Nvy; //voxel ID
  

	xv=-Lx/2+ix*(Lx/(Nvx))+Lx/(2*Nvx);
	yv=-Ly/2+iy*(Ly/(Nvy))+Ly/(2*Nvy);
	zv=-Lz/2+iz*(Lz/(Nvz))+Lz/(2*Nvz);
	cout<<"Voxel: "<<iv<<"( "<<ix<<" "<<iy<<" "<<iz<<" )"<<endl;
	cout<<"Coord: "<<xv<<" "<<yv<<" "<<zv<<endl;
	
	string fname=Form("root/run_%i_0.root",iv);
	doPixels(fname,iv);

}
	


doPixels(string fname,int iv=-1){

	gSystem->Load("libOpNoviceClassesDict.so");

 

	TFile *f=new TFile(fname.c_str()); 
	TTree *t=f->Get("raw");
	
	vector <OpNovicePMTHit*> *PMTHit=NULL;
	t->SetBranchAddress("raw",&PMTHit);

	int Nevents=t->GetEntries(); //1 entry=1 event


	int n,PMT,pixel,photons,bin;
	int pxid,pyid,pid;
	double xp,yp,T;
	
	double q[Npx*Npy*Npmt]={0.};




	TH2D *h1=new TH2D("h1","h1;-x;y",Npx,-Lx/2,Lx/2.,Npy,-Ly/2.,Ly/2.);
	TH2D *h2=new TH2D("h2","h2;+z;+y",Npz,-Lz/2,Lz/2.,Npy,-Ly/2.,Ly/2.);
	TH2D *h3=new TH2D("h3","h3;+x;y",Npx,-Lx/2,Lx/2.,Npy,-Ly/2.,Ly/2.);
	TH2D *h4=new TH2D("h4","h4;-z;+y",Npz,-Lz/2,Lz/2.,Npy,-Ly/2.,Ly/2.);
	TH2D *h5=new TH2D("h5","h5;+x;+z",Npx,-Lx/2,Lx/2.,Npz,-Lz/2.,Lz/2.);
	TH2D *h6=new TH2D("h6","h6;+x;-z",Npx,-Lx/2,Lx/2.,Npz,-Lz/2.,Lz/2.);
	
	TH2D *h1t=new TH2D("h1t","h1t;+x;y",Npx,-Lx/2,Lx/2.,Npy,-Ly/2.,Ly/2.);
	TH2D *h2t=new TH2D("h2t","h2t;+z;+y",Npz,-Lz/2,Lz/2.,Npy,-Ly/2.,Ly/2.);
	TH2D *h3t=new TH2D("h3t","h3t;-x;y",Npx,-Lx/2,Lx/2.,Npy,-Ly/2.,Ly/2.);
	TH2D *h4t=new TH2D("h4t","h4t;-z;+y",Npz,-Lz/2,Lz/2.,Npy,-Ly/2.,Ly/2.);
   	TH2D *h5t=new TH2D("h5t","h5t;+x;+z",Npx,-Lx/2,Lx/2.,Npz,-Lz/2.,Lz/2.);
	TH2D *h6t=new TH2D("h6t","h6t;+z;-z",Npz,-Lz/2,Lz/2.,Npz,-Lz/2.,Lz/2.);

	TH2D *h1t_event=new TH2D("h1t_event","h1t;+x;y",Npx,-Lx/2,Lx/2.,Npy,-Ly/2.,Ly/2.);
	TH2D *h2t_event=new TH2D("h2t_event","h2t;+z;+y",Npz,-Lz/2,Lz/2.,Npy,-Ly/2.,Ly/2.);
	TH2D *h3t_event=new TH2D("h3t_event","h3t;-x;y",Npx,-Lx/2,Lx/2.,Npy,-Ly/2.,Ly/2.);
	TH2D *h4t_event=new TH2D("h4t_event","h4t;-z;+y",Npz,-Lz/2,Lz/2.,Npy,-Ly/2.,Ly/2.);
	TH2D *h5t_event=new TH2D("h5t_event","h5t;+x;+z",Npx,-Lx/2,Lx/2.,Npz,-Lz/2.,Lz/2.);
	TH2D *h6t_event=new TH2D("h6t_event","h6t;+x;-z",Npx,-Lx/2,Lx/2.,Npz,-Lz/2.,Lz/2.);

	for (int ii=0;ii<Nevents;ii++){
		t->GetEntry(ii);  
		n=PMTHit->size();
		
		h1t_event->Reset();
		h2t_event->Reset();
		h3t_event->Reset();
		h4t_event->Reset();
		h5t_event->Reset();
		h6t_event->Reset();
		for (int jj=0;jj<n;jj++){
			PMT=PMTHit->at(jj)->GetPMTNumber();
			if (PMT>=6) continue;
			if (PMT==5) PMT=4;
			photons=PMTHit->at(jj)->GetPhotonCount();
      
			//	cout<<PMT<<" "<<photons<<endl;
			
			for (int qq=0;qq<photons;qq++){

				xp=PMTHit->at(jj)->GetX(qq);
				yp=PMTHit->at(jj)->GetY(qq);
				
				if (fabs(xp)>Lx/2) continue;
				if (fabs(yp)>Ly/2) continue;
				
				T=PMTHit->at(jj)->GetT(qq);
				//	cout<<xp<<" "<<yp<<endl;
			
					
				switch (PMT){
				case 0:
					h1->Fill(xp,yp);
					pxid=(xp+Lx/2)/(Lx/Npx);
					pyid=(yp+Ly/2)/(Ly/Npy);				
					if (h1t_event->GetBinContent(h1t_event->FindBin(xp,yp))==0) h1t_event->SetBinContent(h1t_event->FindBin(xp,yp),T);
					else if (T<h1t_event->GetBinContent(h1t_event->FindBin(xp,yp)))  h1t_event->SetBinContent(h1t_event->FindBin(xp,yp),T);
					break;
					
				case 1:
					h2->Fill(xp,yp);
					pxid=(xp+Lz/2)/(Lz/Npz);
					pyid=(yp+Ly/2)/(Ly/Npy);
					if (h2t_event->GetBinContent(h2t_event->FindBin(xp,yp))==0) h2t_event->SetBinContent(h2t_event->FindBin(xp,yp),T);
					else if (T<h2t_event->GetBinContent(h2t_event->FindBin(xp,yp)))  h2t_event->SetBinContent(h2t_event->FindBin(xp,yp),T);	
					break;
					
				case 2:
					h3->Fill(xp,yp);
					pxid=(xp+Lx/2)/(Lx/Npx);
					pyid=(yp+Ly/2)/(Ly/Npy);
					if (h3t_event->GetBinContent(h3t_event->FindBin(xp,yp))==0) h3t_event->SetBinContent(h3t_event->FindBin(xp,yp),T);
					else if (T<h3t_event->GetBinContent(h3t_event->FindBin(xp,yp)))  h3t_event->SetBinContent(h3t_event->FindBin(xp,yp),T);
					break;
					
				case 3:
					h4->Fill(xp,yp);
					pxid=(xp+Lx/2)/(Lz/Npz);
					pyid=(yp+Ly/2)/(Ly/Npy);
					if (h4t_event->GetBinContent(h4t_event->FindBin(xp,yp))==0) h4t_event->SetBinContent(h4t_event->FindBin(xp,yp),T);
					else if (T<h4t_event->GetBinContent(h4t_event->FindBin(xp,yp)))  h4t_event->SetBinContent(h4t_event->FindBin(xp,yp),T);
					break;
				case 4:
					h5->Fill(xp,yp);
					pxid=(xp+Lx/2)/(Lz/Npz);
					pyid=(yp+Ly/2)/(Ly/Npy);
					if (h5t_event->GetBinContent(h5t_event->FindBin(xp,yp))==0) h5t_event->SetBinContent(h5t_event->FindBin(xp,yp),T);
					else if (T<h5t_event->GetBinContent(h5t_event->FindBin(xp,yp)))  h5t_event->SetBinContent(h5t_event->FindBin(xp,yp),T);
					break;
				case 5:
					h6->Fill(xp,yp);
					pxid=(xp+Lx/2)/(Lx/Npx);
					pyid=(yp+Ly/2)/(Lz/Npz);
					if (h6t_event->GetBinContent(h6t_event->FindBin(xp,yp))==0) h6t_event->SetBinContent(h6t_event->FindBin(xp,yp),T);
					else if (T<h6t_event->GetBinContent(h6t_event->FindBin(xp,yp)))  h6t_event->SetBinContent(h6t_event->FindBin(xp,yp),T);
					break;
	
				default:
					break;
				}	
				//if (PMT==5) PMT=4;
				pid=pxid+Npx*pyid+Npx*Npy*PMT;
				q[pid]++;
			}//end loop on photons      
		}//end loop on pmts
		h1t->Add(h1t_event);
		h2t->Add(h2t_event);
		h3t->Add(h3t_event);
		h4t->Add(h4t_event);
		h5t->Add(h5t_event);
		h6t->Add(h6t_event);
		
	}//end loop on events
	h1->Scale(1./Nevents);
	h2->Scale(1./Nevents);
	h3->Scale(1./Nevents);
	h4->Scale(1./Nevents);
	h5->Scale(1./Nevents);
	h6->Scale(1./Nevents);

	h1t->Scale(1./Nevents);
	h2t->Scale(1./Nevents);
	h3t->Scale(1./Nevents);
	h4t->Scale(1./Nevents);
	h5t->Scale(1./Nevents);
	h6t->Scale(1./Nevents);
		




	TCanvas *c0=new TCanvas("c0","c0");
	c0->Divide(5,1);
	
	

	c0->cd(1);h1->Draw("colz");
	c0->cd(2);h2->Draw("colz");
	c0->cd(3);h3->Draw("colz");
	c0->cd(4);h4->Draw("colz");
	c0->cd(5);h5->Draw("colz");










	TCanvas *c=new TCanvas("c","c");
	c->Divide(6,3);
	
	
	c->cd(1);h1->ProjectionY()->Draw();
	c->cd(2);h2->ProjectionY()->Draw();
	c->cd(3);h3->ProjectionY()->Draw();
	c->cd(4);h4->ProjectionY()->Draw();
	c->cd(5);h5->ProjectionY()->Draw();
	c->cd(6);h6->ProjectionY()->Draw();

	c->cd(7);h1->Draw("colz");
	c->cd(8);h2->Draw("colz");
	c->cd(9);h3->Draw("colz");
	c->cd(10);h4->Draw("colz");
	c->cd(11);h5->Draw("colz");
	c->cd(12);h6->Draw("colz");

	c->cd(13);h1->ProjectionX()->Draw();
	c->cd(14);h2->ProjectionX()->Draw();
	c->cd(15);h3->ProjectionX()->Draw();
	c->cd(16);h4->ProjectionX()->Draw();
	c->cd(17);h5->ProjectionX()->Draw();
	c->cd(18);h6->ProjectionX()->Draw();


	TCanvas *c1=new TCanvas("c1","c1");
	c1->Divide(6,3);
	c1->cd(7);h1t->Draw("colz");
	c1->cd(8);h2t->Draw("colz");
	c1->cd(9);h3t->Draw("colz");
	c1->cd(10);h4t->Draw("colz");
	c1->cd(11);h5t->Draw("colz");
	c1->cd(12);h6t->Draw("colz");
	
	if (iv>=0){
		c->Print(Form("run%i.ps(",iv));
		c1->Print(Form("run%i.ps)",iv));
	}
  
	ofstream ofile;
	if (iv>=0) ofile.open(Form("run%i.out",iv));
	else ofile.open((fname+".out").c_str());
	for (pid=0;pid<(Npx*Npy*Npmt);pid++){
		q[pid]=1.*q[pid]/Nevents;
		//    cout<<q[pid]<<" ";
		ofile<<q[pid]<<" ";
	}
	ofile.close();
}
