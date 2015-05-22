#include "TRecon.hh"
#include "TOpNoviceDetectorLight.hh"

#include "Minuit2/FCNBase.h"
#include "TFitterMinuit.h"
#include "TVector3.h"
#include "TMath.h"

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
/*This is the part for the TRACK fit*/
/*We write the general likelihood function as

Li=p(Q)*p(t),

i.e. a piece containing the charge probability, and a part containing the time probability

L = product_over_pixels Li
Then, we take the product over all the pixels. To simplify the computation, intestead of maximizing the likelihood, I minimize the inverse of the logarithm,

L = - sum_over_pixels ln(Li) = - sum_over_pixels [ ln(p(q)) + ln (p(t)) ]

*/
double TRecon::TrackLikelihood(const double *x) const{
	double ret=0;
	double pQ=0;
	double pT=0;
	int Nphotons;
	for (int iface=0;iface<6;iface++){
		for (int idetector=0;idetector<m_detector->getNdet(iface);idetector++){
			if (m_detector->isDetPresent(iface,idetector)==0) continue;
			for (int id=0;id<m_detector->getNPixels(iface,idetector);id++){
				switch (m_fitLikelihoodMode){
				case(k_onlyCharge):
						pQ=TrackLikelihoodCharge(iface,idetector,id,x);/*This already returns the log of the charge probability*/
				break;
				case (k_onlyTime):
						Nphotons=m_N[iface][idetector][id]; //measured number of photons in this pixel
						if (Nphotons==0){
							pT=0;
						}
						else pT=TrackLikelihoodTime(iface,idetector,id,x);   /*This already returns the log of the time probability*/
						break;
				case (k_both):
						Nphotons=m_N[iface][idetector][id]; //measured number of photons in this pixel
						pQ=TrackLikelihoodCharge(iface,idetector,id,x); /*This already returns the log of the charge probability*/
						if (Nphotons==0){
							pT=0;
						}
						else pT=TrackLikelihoodTime(iface,idetector,id,x);   /*This already returns the log of the time probability*/
						break;
				}
				ret+=(-pT-pQ);
			}
		}
	}
	/*
	cout<<"********"<<endl; 
	cout.precision(10);
	cout<<ret<<" "<<pT<<" "<<pQ<<endl;
	cout<<" "<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
	cout<<" "<<x[3]<<" "<<x[4]<<" "<<x[5]<<endl;
	cout<<" "<<x[6]<<" "<<x[7]<<" "<<x[8]<<" "<<x[9]<<endl;
	 */
	return ret;
}










/*This already returns the log of the time probability*/
/*The time distribution probability is:

p(t)=N*p1(t)*(1-F(t))^(N-1),

log(p)=log(N)+log(p1)+(N-1)*log(1-F)    Since N is a constant term, I neglect the first logN piece


F(t)=int(-inf..t) p1(q)dq
1-F(t)=(t..+inf) p1(q)dq


where p1 is the single photon probability, and F(t) is the single photon integrated probability.
This accounts for the fact that I measure the FIRST photon, over N
*/

double TRecon::TrackLikelihoodTime(int iface,int idetector,int id,const double *para) const{
	
	/*for (int ii=0;ii<10;ii++)cout<<para[ii]<<" "<<m_minimizer->GetParName(ii)<<" "<<m_minimizer->GetParameter(ii)<<endl;
	cout<<endl;cin.get();*/
	//Function variables are the parameters we minimize the likelihood wrt
	TVector3 x0(para[0],para[1],para[2]); //starting point 
	TVector3 x1(para[3],para[4],para[5]); //ending point
	double b=para[6];
	double t0=para[7];
	double N0=para[8];  
	double tau=para[9]; 
	
	TVector3 xp=m_detector->getPosPixel(iface,idetector,id); //pixel position
	TVector3 x=(x1-x0); double xMag=x.Mag();
	TVector3 k=(xp-x0); double kMag=k.Mag();
	
	
	int Nphe=m_N[iface][idetector][id]; //hit number of photo-electrons
	double tmeas=m_t[iface][idetector][id];     //hit time
	double p1,F1,ret;
	double lambda,cosTheta,sin2Theta;
	double t,tmin;
	
	double sigma,n;	
	sigma=m_detector->getDetTimeRes(iface,idetector);
	n=m_detector->getRindex();
	
	
	/*Correct the time due to the time-of-flight propagation*/
	/*This is a very complicate function: the "first photon time" is the time that minimizes
	the track propagation (at speed c*beta) and the light propagation (at speed c/n)
	*/
	if (n*b<1){ /*Very simple case, all first photons emitted from x0*/
		tmin=(n/clight)*kMag;		
	}
	else if(xMag<=0){ /*Point-like case*/
		tmin=(n/clight)*kMag;	
	}
	else if(kMag<=0){ /*Very special case, when the pixel position equals x0*/
		tmin=0.;
	}
	else{ /*Complex case, there are different possibilities*/
		cosTheta=(x*k)/(x.Mag()*k.Mag());
		sin2Theta=1.-cosTheta*cosTheta;
		lambda = ( kMag / xMag ) * (cosTheta - sqrt(sin2Theta)/(n*b*n*b-1));	
		if (lambda < 0){ /*photon emitted at the beginning of the particle track*/
			tmin=(n/clight)*kMag;			
		}
		else if (lambda > 1){ /*photon emitted at the end of the particle track*/
			tmin=(x1-xp).Mag()*(n/clight)+xMag/(b*clight);		
		}
		else{   /*This is the most interesting case, the first photon get emitted along the particle track*/
			tmin=(kMag/(b*clight)) * (cosTheta+sqrt(n*b*n*b-1)*sqrt(sin2Theta));		
		}		
	}
		
	/*Now correct the time*/
	t=tmeas-tmin-t0;	
	/*This is important to help the fit: it tmeasured-tmin-t0<0, there is something strange.
	We are minimizing the "-log(likelihood), i.e. maximizing the log(likelihood)".
	This function already returns the log of the time component: I can put it to a "very small number" 
	to force the minimizer to go away*/
	
	//	if (t<0){
	//	
	//		cout<<"Bad t, going to a large number"<<endl;
	//		cout<<t<<" "<<tmeas<<" "<<tmin<<" "<<t0<<endl;
	//		ret=-999;
	//	}
	//	else
	
	/*Compute p1 and F1*/
		p1=SinglePhotonTimeProb(t,tau,sigma); /*This is already the natural logarithm, log(p) */ 
		F1=SinglePhotonIntegratedTimeProb(t,tau,sigma); /*This is already the natural logarithm, log(1-F1)*/ 
		ret=p1+(Nphe-1)*F1;
	//}
	return ret;
}





/*This already returns the log of the charge probability

If I measure Ne photo-electrons, on a detector with qe eps, 
and, on average, mu0 PHOTONS hit the detector,
the probability function is:

P(Ne) = (eps*mu0)^Ne Exp(-eps*mu0) / Ne!      --> poissonian with mean value mu0*eps
log(P) = .. -eps *mu0 +Ne log(mu0) (no constant terms in the likelihood)

I did the full calculation, i.e. P(Ne) = (sum over n >= Ne)  [Prob of n photons hit the PMT * Prob (Ne photo-electrons, given n0)]

Prob of n photons hit the PMT           --> Poissonian
Prob (Ne photo-electrons, given n0)     --> Binomial

*/
double TRecon::TrackLikelihoodCharge(int iface,int idetector,int id,const double *para) const{
	
	
	//Function variables are the parameters we minimize the likelihood wrt
	TVector3 x0(para[0],para[1],para[2]); //starting point 
	TVector3 x1(para[3],para[4],para[5]); //ending point
	double b=para[6];
	double t0=para[7];
	double N0=para[8]; 
	double tau=para[9]; 
	
	TVector3 xp=m_detector->getPosPixel(iface,idetector,id); //pixel position
	TVector3 x=(x1-x0); double xMag=x.Mag();
	TVector3 k=(xp-x0); double kMag=k.Mag();
	
	
	int Nphe=m_N[iface][idetector][id]; //hit number of photo-electrons
	double t=m_t[iface][idetector][id];     //hit time
	
	double eps,mu0,ret;
	
	/*Compute mu, integrating along the trajectory*/
	eps=m_detector->getDetQE(iface,idetector);
	mu0=TrackAverageCharge(x0,x1,iface,idetector,id);
	mu0*=N0;
	
	

	ret=-eps*mu0+Nphe*log(mu0);
	
	
	
	return ret;
}



double TRecon::TrackAverageCharge(const TVector3 &x0,const TVector3 &x1,int iface,int idetector,int id) const{
	
	
	//TVector3 xp=m_detector->getPosPixel(iface,idetector,id); //pixel position
	double ret;
	/*Prepare the parameters*/
	m_TrackLikelihoodChargeKernel->SetRange(0.,1.);
	m_TrackLikelihoodChargeKernel->SetParameter(0,x0.X());
	m_TrackLikelihoodChargeKernel->SetParameter(1,x0.Y());
	m_TrackLikelihoodChargeKernel->SetParameter(2,x0.Z());
	
	m_TrackLikelihoodChargeKernel->SetParameter(3,x1.X());
	m_TrackLikelihoodChargeKernel->SetParameter(4,x1.Y());
	m_TrackLikelihoodChargeKernel->SetParameter(5,x1.Z());
	
	
	m_TrackLikelihoodChargeKernel->SetParameter(6,iface);
	m_TrackLikelihoodChargeKernel->SetParameter(7,idetector);
	m_TrackLikelihoodChargeKernel->SetParameter(8,id);
	
	m_TrackLikelihoodChargeKernel->SetNpx(1000);
	
	ret=m_TrackLikelihoodChargeKernel->Integral(0.,1.);


	return ret;
	
}

double TRecon::TrackLikelihoodChargeKernel(double *x,double *p){
	
	double lambda=x[0];
	TVector3 x0(p[0],p[1],p[2]);
	TVector3 x1(p[3],p[4],p[5]);
	
	int iface=(int)(p[6]);
	int idetector=(int)(p[7]);
	int id=(int)(p[8]);
	
	TVector3 xPos=x0+lambda*(x1-x0);
	double ret=SinglePixelAverageCharge(xPos,iface,idetector,id);

	return ret;	
}

