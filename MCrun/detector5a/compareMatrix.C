int Np=1024;
int Nv=3*3*3;

void compareMatrix(int iv){

	TH1D *hAnalyticModelOptics=new TH1D("hAnalyticModelOptics","hAnalyticModelOptics",Np*Nv,-0.5,Np*Nv-0.5);
	TH1D *hAnalyticModelOptics2=new TH1D("hAnalyticModelOptics2","hAnalyticModelOptics2",Np,-0.5,Np-0.5);
	ifstream fAnalyticModelOptics("/home/celentan/Dropbox/OptoTracker/risultati/test9/nominal/voxels3_3_3/matrix3-3-3.Analytic.txt");


	TH1D *hMCpoint=new TH1D("hMCpoint","hMCpoint",Np*Nv,-0.5,Np*Nv-0.5);
	TH1D *hMCpoint2=new TH1D("hMCpoint2","hMCpoint2",Np,-0.5,Np-0.5);
	ifstream fMCpoint("/home/celentan/Dropbox/OptoTracker/risultati/test9/nominal/voxels4_4_4/matrix4-4-4.Analytic.txt");

	TH1D *hMCvolume=new TH1D("hMCvolume","hMCvolume",Np*Nv,-0.5,Np*Nv-0.5);
	TH1D *hMCvolume2=new TH1D("hMCvolume2","hMCvolume2",Np,-0.5,Np-0.5);
	ifstream fMCvolume("/home/celentan/Dropbox/OptoTracker/risultati/test9/nominal/voxels5_5_5/matrix5-5-5.Analytic.txt");
	double val;
	double totval,totval2,totval3;



	totval=0;
	totval2=0;
	for (int ivoxel=0;ivoxel<Nv;ivoxel++){
		for (int ipixel=0;ipixel<Np;ipixel++){
			fAnalyticModelOptics>>val;
			totval+=val;
			hAnalyticModelOptics->SetBinContent(ivoxel+Nv*ipixel+1,val);
			if (ivoxel==iv){
				hAnalyticModelOptics2->SetBinContent(ipixel+1,val);
				totval2+=val;
			}
		}
	}
	//  hAnalyticModelOptics2->Scale(1./totval2);



	totval=0;
	totval2=0;
	for (int ivoxel=0;ivoxel<Nv;ivoxel++){
		for (int ipixel=0;ipixel<Np;ipixel++){
			fMCpoint>>val;
			totval+=val;
			hMCpoint->SetBinContent(ivoxel+Nv*ipixel+1,val);
			if (ivoxel==iv){
				hMCpoint2->SetBinContent(ipixel+1,val);
				totval2+=val;
			}
		}
	}

	totval=0;
	totval2=0;
	for (int ivoxel=0;ivoxel<Nv;ivoxel++){
		for (int ipixel=0;ipixel<Np;ipixel++){
			fMCvolume>>val;
			totval+=val;
			hMCvolume->SetBinContent(ivoxel+Nv*ipixel+1,val);
			if (ivoxel==iv){
				hMCvolume2->SetBinContent(ipixel+1,val);
				totval2+=val;
			}
		}
	}
	
	//hMCpoint2->Scale(1./totval2);


	TCanvas *c1=new TCanvas();


	hAnalyticModelOptics->SetLineColor(1);
	hAnalyticModelOptics->Draw();

	hMCpoint->SetLineColor(2);
	hMCpoint->Draw("SAME");

	hMCvolume->SetLineColor(3);
	hMCvolume->Draw("SAME");

	TCanvas *c2=new TCanvas();

	hAnalyticModelOptics2->SetLineColor(1);
	hAnalyticModelOptics2->Draw();

	hMCpoint2->SetLineColor(2);
	hMCpoint2->Draw("SAME");

	hMCvolume2->SetLineColor(3);
	hMCvolume2->Draw("SAME");


}
