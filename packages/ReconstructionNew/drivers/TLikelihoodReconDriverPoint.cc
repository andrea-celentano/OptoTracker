#include "TLikelihoodReconDriver.hh"


/*This is the part for the POINT fit*/
/*We write the general likelihood function as

Li=p(Q)*p(t),

i.e. a piece containing the charge probability, and a part containing the time probability

L = product_over_pixels Li
Then, we take the product over all the pixels. To simplify the computation, intestead of maximizing the likelihood, I minimize the inverse of the logarithm,

L = - sum_over_pixels ln(Li) = - sum_over_pixels [ ln(p(q)) + ln (p(t)) ]

 */
double TLikelihoodReconDriver::PointLikelihood(const double *x) const{
	double ret=0;
	double pQ=0;
	double pT=0;
	int Nphotons;
	for (int iface=0;iface<6;iface++){
		for (int idetector=0;idetector<m_manager->getDetector()->getNdet(iface);idetector++){
			if (m_manager->getDetector()->isDetPresent(iface,idetector)==0) continue;
			for (int id=0;id<m_manager->getDetector()->getNPixels(iface,idetector);id++){
				if (m_N[iface][idetector][id]<0){
					pT=pQ=0;
				}
				else{
					switch (m_fitLikelihoodMode){

					case(k_onlyCharge):
						pQ=PointLikelihoodCharge(iface,idetector,id,x);/*This already returns the log of the charge probability*/
					break;

					case (k_onlyTime):
						Nphotons=m_N[iface][idetector][id]; //measured number of phe in this pixel
						if (Nphotons==0){
							pT=0;
						}
						else pT=PointLikelihoodTime(iface,idetector,id,x);   /*This already returns the log of the time probability*/
					break;

					case (k_both):
						Nphotons=m_N[iface][idetector][id]; //measured number of phe in this pixel
						pQ=PointLikelihoodCharge(iface,idetector,id,x); /*This already returns the log of the charge probability*/
						if (Nphotons==0){
							pT=0;
						}
						else pT=PointLikelihoodTime(iface,idetector,id,x);   /*This already returns the log of the time probability*/
					break;
					}
				}
				ret+=(-pT-pQ);
			}
		}
	}
/*
	cout<<"********"<<endl;
	cout.precision(10);
	cout<<ret<<" "<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
*/
	return ret;
}



/*This already returns the log of the time probability*/
/*The time distribution probability is:

p(t)=N*p1(t)*(1-F(t))^(N-1),

log(p)=log(N)+log(p1)+(N-1)*log(1-F)

F(t)=int(-inf..t) p1(q)dq
1-F(t)=(t..+inf) p1(q)dq

Since N is a constant term, I neglect the first logN piece

where p1 is the single photon probability, and F(t) is the single photon integrated probability.
This accounts for the fact that I measure the FIRST photon, over N
 */

double TLikelihoodReconDriver::PointLikelihoodTime(int iface,int idetector,int id,const double *para) const{

	//Function variables are the parameters we minimize the likelihood wrt
	/*IT IS UP TO THE USER TO FIX x1 and b for this case*/
	TVector3 x0(para[0],para[1],para[2]); //starting point
	TVector3 x1(para[3],para[4],para[5]); //ending point
	double b=para[6];
	double t0=para[7];
	double N0=para[8];
	double tau=para[9];

	double sigma,n,t;


	int Nphe=m_N[iface][idetector][id]; //hit number of photo-electrons
	double tmeas=m_t[iface][idetector][id];     //hit time
	double dist,p1,F1,ret;
	TVector3 xp=m_manager->getDetector()->getPosPixel(iface,idetector,id); //pixel position




	sigma=m_manager->getDetector()->getDetTimeRes(iface,idetector);
	n=m_manager->getDetector()->getRindex();


	/*Correct the time due to the time-of-flight propagation*/
	dist=(x0-xp).Mag();
	t=tmeas-n*dist/clight-t0;

	/*Compute p1 and F1*/
	p1=m_manager->getDetectorUtils()->SinglePhotonTimeProb(t,tau,sigma); /*This is already the natural logarithm, log(p) */
	F1=m_manager->getDetectorUtils()->SinglePhotonIntegratedTimeProb(t,tau,sigma); /*This is already the natural logarithm, log(1-F1)*/
	ret=p1+(Nphe-1)*F1;


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
double TLikelihoodReconDriver::PointLikelihoodCharge(int iface,int idetector,int id,const double *para) const{

	//Function variables are the parameters we minimize the likelihood wrt
	/*IT IS UP TO THE USER TO FIX x1 and b for this case*/
	TVector3 x0(para[0],para[1],para[2]); //starting point
	TVector3 x1(para[3],para[4],para[5]); //ending point
	double b=para[6];
	double t0=para[7];
	double N0=para[8];
	double tau=para[9];


	int Nphe=m_N[iface][idetector][id];     //hit number of photo-electrons
	double t=m_t[iface][idetector][id];     //hit time, useless here
	double mu0,ret,eps;
	TVector3 xp=m_manager->getDetector()->getPosPixel(iface,idetector,id); //pixel position


	/*Compute mu*/
	eps=m_manager->getDetector()->getDetQE(iface,idetector);
	mu0=m_manager->getDetectorUtils()->SinglePixelAverageCharge(x0,iface,idetector,id);
	mu0*=N0;
	//cout<<mu0<<endl;
	//cin.get();
	ret=-eps*mu0+Nphe*log(mu0);
	return ret;
}







