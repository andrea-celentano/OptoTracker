#include "TDetectorUtils.hh"
#include "TDetectorLight.hh"

#include "TMath.h"
#include "TF1.h"
TDetectorUtils::TDetectorUtils(TDetectorLight *detector):
m_detector(detector),
m_SinglePhotonTimeProbKernel(NULL){

	if (m_detector){
		double tau=m_detector->getFastScintTime();
		m_SinglePhotonTimeProbKernel=new TF1("SinglePhotonTimeProbIntegral",this,&TDetectorUtils::SinglePhotonTimeProbKernel,-3*tau,10*tau,2);
	}
}

TDetectorUtils::~TDetectorUtils() {
	if (m_SinglePhotonTimeProbKernel) delete m_SinglePhotonTimeProbKernel;
}


double TDetectorUtils::GaussianCDF(const double& t, const double& mean,const double& sigma) const {

    double ret;
    ret=0.5*(1+TMath::Erf((t-mean)/(sqrt(2.)*sigma)));
    return ret;
}



/*This returns already the logarithm. The single photon time prob is the convolution between an exponential (tau) and a gaussian (sigma),
that is

p(t)=1/(2tau) * exp(sigma*sigma/(2*tau*tau)) * exp(-t/tau) * ERFC[ (sigma*sigma)/tau - t)/(sqrt(2)*sigma)]

log(p) --> -t/tau + log (ERFC[...])

Here I already compute the natural logarithm and exclude constant terms.
*/
double TDetectorUtils::SinglePhotonTimeProb(double t, double tau, double sigma) const {
	double ret=0;
		double arg,arg1;
		ret=-t/tau;

		if (sigma<=0){ //in this case, p=(1/tau)exp(-t/tau)theta(t), ln(p)=-t/tau-ln(tau)+ln(theta(t))---> -t/tau
			if (t<0) ret=0; //very bad work-around (would be log(0), but in this way I have continuity)
		}
		else{
		  arg=((sigma*sigma)/tau - t)/(sqrt(2.)*sigma);
		  arg1=TMath::Erfc(arg);
		  if (arg1>0)  ret+=log(arg1);
		  else ret+=0;
		}

		//cout<<"QUI: "<<arg<<" "<<TMath::Erfc(arg)<<" "<<t<<" "<<ret<<" "<<sigma<<endl;

		return ret;
}






/*This already returns log(1-F), where F=int(-inf .. t) p(q)dq
Note that 1-F = int(t...+inf) p(q)dq
*/
double TDetectorUtils::SinglePhotonIntegratedTimeProb(double t, double tau, double sigma) const {
	double ret=0;
	double ret1=0;
	double uu,vv;
	/*analytic case.
	p(t)=theta(t)*exp(-t/tau)*1/tau.
	F(t)=(1-exp(-t/tau) if t>0, 0 otherwise
	1-F=exp(-t/tau) if t>0, 1 otherwise
	log(1-F) = -t/tau if t>0, 0 otherwise
	*/

	if (sigma<=0){
		if (t<0) ret=0;
		else ret=-t/tau;
		return ret;
	}

	uu=t/tau;
	vv=sigma/tau;

	/*Analytical expression for the integral distribution of a gaussian modified exponential*/
	ret=GaussianCDF(uu,0.,vv);
	ret=ret-exp(-uu)*exp((vv*vv)/2)*GaussianCDF(uu,vv*vv,vv);
	ret=1-ret;




	ret=log(ret);



	return ret;

}


double TDetectorUtils::SinglePhotonTimeProbKernel(double* x, double* p) {
	double ret=0;
		double t=x[0];
		double tau=p[0];
		double sigma=p[1];
		double arg=((sigma*sigma)/tau - t)/(sqrt(2)*sigma);

		ret=1;
		/*These two factors are constant, so it is irrelevant to include them in the integration Kernel*/
		ret*=(1/(2*tau));
		ret*=exp((sigma*sigma)/(2*tau*tau));

		ret*=exp(-t/tau);
		ret*=TMath::Erfc(arg);


		return ret;
}


/*This is a function that, given the source point x0,
returns the average number of photons on the pixel iPMT, id,
assuming a unitary excitation at the source.
*/
double TDetectorUtils::SinglePixelAverageCharge(const TVector3& x0, int iface, int idetector, int id) const {
		double ret;
		double solidAngle;
		TVector3 xp=m_detector->getPosPixel(iface,idetector,id);

		/*First account for the solid angle*/
		solidAngle=this->GetSolidAngle(x0,iface,idetector,id);
		solidAngle /= ( 4 * TMath::Pi() );

		/*Then, at large angles there may be other effects.
		 *  Add Fresnel transmission between scintillator and coupling*/

		ret = solidAngle;


		return ret;
}
	/*This is the method that returns the solid angle of a given face/detector/pixel
	from the point x0*/
double TDetectorUtils::GetSolidAngle(const TVector3& x0, int iface, int idetector, int id) const {

	TVector3 xp=m_detector->getPosPixel(iface,idetector,id);
	TVector3 r=(x0-xp);

	double a,b,c,Lx,Ly,r2,ret;

	c=fabs(r*m_detector->getDetectorNormal(iface,idetector));
	a=r*m_detector->getDetectorT1(iface,idetector);
	b=r*m_detector->getDetectorT2(iface,idetector);


	Lx=m_detector->getPixelSizeX(iface,idetector);
	Ly=m_detector->getPixelSizeY(iface,idetector);


	r2=r.Mag2();
	ret = 0;

	ret += atan( (Lx-2*a)*(Ly-2*b) / (2*c*sqrt(4*r2-4*a*Lx-4*b*Ly+Lx*Lx+Ly*Ly)));
	ret += atan( (Lx+2*a)*(Ly+2*b) / (2*c*sqrt(4*r2+4*a*Lx+4*b*Ly+Lx*Lx+Ly*Ly)));
	ret += atan( (Lx+2*a)*(Ly-2*b) / (2*c*sqrt(4*r2+4*a*Lx-4*b*Ly+Lx*Lx+Ly*Ly)));
	ret += atan( (Lx-2*a)*(Ly+2*b) / (2*c*sqrt(4*r2-4*a*Lx+4*b*Ly+Lx*Lx+Ly*Ly)));


	return ret;
}


/*This function returns the minimal propagation time for a track between x0 and x1, moving with speed beta
 *
 */
double TDetectorUtils::GetMinimalDelay(const TVector3& x0, const TVector3& x1,double beta, int iface, int idetector, int id) const {

	TVector3 xp=m_detector->getPosPixel(iface,idetector,id); //pixel position
		TVector3 x=(x1-x0); double xMag=x.Mag();
		TVector3 k=(xp-x0); double kMag=k.Mag();

		double n=m_detector->getRindex();
		double cosTheta,sin2Theta,lambda;
		double tmin=0;

		if (n*beta<1){ /*Very simple case, all first photons emitted from x0*/
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
			lambda = ( kMag / xMag ) * (cosTheta - sqrt(sin2Theta)/(n*beta*n*beta-1));
			if (lambda < 0){ /*photon emitted at the beginning of the particle track*/
				tmin=(n/clight)*kMag;
			}
			else if (lambda > 1){ /*photon emitted at the end of the particle track*/
				tmin=(x1-xp).Mag()*(n/clight)+xMag/(beta*clight);
			}
			else{   /*This is the most interesting case, the first photon get emitted along the particle track*/
				tmin=(kMag/(beta*clight)) * (cosTheta+sqrt(n*beta*n*beta-1)*sqrt(sin2Theta));
			}
		}
		return tmin;
}
