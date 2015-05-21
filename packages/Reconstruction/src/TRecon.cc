#include "TRecon.hh"
#include "TOpNoviceDetectorLight.hh"


#include "TMath.h"

#include <vector>
#include <iostream>

using namespace std;

TRecon::TRecon(TOpNoviceDetectorLight *detector):
m_detector(detector),
m_fitObject(k_point),
m_freeFitObject(1),
m_fitLikelihoodMode(k_onlyTime),
m_SinglePhotonTimeProbKernel(NULL)
{
	std::cout<<"TRecon::constructor"<<std::endl;
	/*Create the fitter*/
//	m_minimizer=new TMinuitMinimizer("migrad",10);
        m_minimizer=ROOT::Math::Factory::CreateMinimizer("Minuit2","Migrad"); //minimizer name: Minuit, Minuit2 //algo: Migrad, Simplex, Combined, Scan.
	
	m_minimizer->SetFunction(*this);
	m_minimizer->SetPrintLevel(1);
	m_minimizer->SetMaxFunctionCalls(1000000);
	m_minimizer->SetMaxIterations(100000);
	//m_minimizer->SetTolerance(0.01);//The minimization will stop when the estimated distance to the minimum is less than 0.001*tolerance (from ROOT FORUM)
	m_minimizer->SetPrecision(0); //find it automatically	
	
	double tau=m_detector->getFastScintTime();
	m_SinglePhotonTimeProbKernel=new TF1("SinglePhotonTimeProbIntegral",this,&TRecon::SinglePhotonTimeProbKernel,-3*tau,10*tau,2);
	m_TrackLikelihoodChargeKernel=new TF1("TrackLikelihoodChargeKernel",this,&TRecon::TrackLikelihoodChargeKernel,0.,1.,8); //8 fixed parameters: x0(3x), x1(3x), face, pixel
	
}

TRecon::~TRecon(){
	delete m_minimizer;
	if (m_SinglePhotonTimeProbKernel) delete m_SinglePhotonTimeProbKernel;
}


void TRecon::doFit(){
	
	//m_minimizer->SetMinuitFCN(this);
	
	ROOT::Fit::ParameterSettings parSettings;
	printf("TRecon::start the maximum likelihood fit\n");
	printf("Parameter \t \t Value \t \t IsFixed? \t IsBounded? \n");
	for (int ii=0;ii<m_minimizer->NDim();ii++){
	    m_minimizer->GetVariableSettings(ii,parSettings);
	    if (parSettings.IsBound()){
	        printf("%s \t \t %f \t \t %i \t \t 1 \t \t%f \t\t %f\n",m_minimizer->VariableName(ii).c_str(),parSettings.Value(),m_minimizer->IsFixedVariable(ii),parSettings.LowerLimit(),parSettings.UpperLimit());
	
	    }
	  else{
	          printf("%s \t \t %f \t \t %i \t \t 1 \n",m_minimizer->VariableName(ii).c_str(),parSettings.Value(),m_minimizer->IsFixedVariable(ii));
	  }
	}
	
	m_minimizer->Minimize();
}

void TRecon::initParameters(){
  
        //SetVariable(ivar,name,val,step)
	//SetLimitedVariable(ivar,name,val,step,min,max)
	m_minimizer->SetLimitedVariable(0,"X0",0.,.1,-m_detector->getScintSizeX()*.5,m_detector->getScintSizeX()*.5);	
	m_minimizer->SetLimitedVariable(1,"Y0",0.,.1,-m_detector->getScintSizeY()*.5,m_detector->getScintSizeY()*.5);
	m_minimizer->SetLimitedVariable(2,"Z0",0.,.1,-m_detector->getScintSizeZ()*.5,m_detector->getScintSizeZ()*.5);
	m_minimizer->SetLimitedVariable(3,"X1",0.,.1,-m_detector->getScintSizeX()*.5,m_detector->getScintSizeX()*.5);		
	m_minimizer->SetLimitedVariable(4,"Y1",0.,.1,-m_detector->getScintSizeY()*.5,m_detector->getScintSizeY()*.5);
	m_minimizer->SetLimitedVariable(5,"Z1",0.,.1,-m_detector->getScintSizeZ()*.5,m_detector->getScintSizeZ()*.5);
	m_minimizer->SetLimitedVariable(6,"b",0.999,.1,0.,1.);
	m_minimizer->SetVariable(7,"t",0.,.1);
	m_minimizer->SetLowerLimitedVariable(8,"N",1000,0.1,0.); 
	m_minimizer->SetLowerLimitedVariable(9,"tau",1.5,0.1,0.);
	
}


void TRecon::setFitObject(fitObject_t type){
	m_fitObject=type;
	if (m_fitObject==k_point){
		cout<<"Point-like fit, fix parameters"<<endl;
		
		m_minimizer->FixVariable(3);	  		
		m_minimizer->FixVariable(4);	  
		m_minimizer->FixVariable(5);	  		
		/*Fix beta*/
		m_minimizer->FixVariable(6);
		cout<<"Point-like fit, parameters fixed"<<endl;		
	}	
}
void TRecon::setFitLikelihoodMode(fitLikelihoodMode_t mode){
	m_fitLikelihoodMode=mode;

	/*If we fit only the time info, we can't get N*/
	if (m_fitLikelihoodMode==k_onlyTime){
		cout<<"Fixing parameters for onlyTime mode"<<endl;
		m_minimizer->FixVariable(8);
	}
	/*If we fit only the charge info, we can't get t0 and beta and tau*/
	else if (m_fitLikelihoodMode==k_onlyCharge){
		cout<<"Fixing parameters for onlyCharge mode"<<endl;
		m_minimizer->FixVariable(6);
		m_minimizer->FixVariable(7);
		m_minimizer->FixVariable(9);
	}
	


}








/*This is the method that computes the function, x are the variables*/

//double TRecon::operator()(const std::vector< double >& x) const{
double TRecon::DoEval(const double *x) const{
	double ret;
	switch (m_fitObject){
	case (k_point):
		ret=PointLikelihood(x);
		break;
	case (k_track):
		ret=TrackLikelihood(x);	
		break;		
	}
	
	

	return ret; 
}


unsigned int TRecon::NDim() const{
 return 10; //@TODO better 
}

 ROOT::Math::IBaseFunctionMultiDim* TRecon::Clone() const{
  return 0; 
 }



double TRecon::SinglePhotonTimeProbKernel(double *x,double *p){
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
/*This already returns log(1-F), where F=int(-inf .. t) p(q)dq
Note that 1-F = int(t...+inf) p(q)dq
*/
double TRecon::SinglePhotonIntegratedTimeProb(double t,double tau,double sigma) const{
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
	
	/*Prepare the parameters*/
	/*
	m_SinglePhotonTimeProbKernel->SetRange(-3*tau,10*tau);
	m_SinglePhotonTimeProbKernel->SetParameter(0,tau);
	m_SinglePhotonTimeProbKernel->SetParameter(1,sigma);
	m_SinglePhotonTimeProbKernel->SetNpx(1000);
	//I have to compute int(t...+inf)p(q)dq, trough the above int. kernel. For large q, p(q)-->0, as exponential, so It is fine to integrate up to a "large" number
	ret1=m_SinglePhotonTimeProbKernel->Integral(t,10*tau);
	if (ret1<=0) ret = 0.00000001; //very bad work-around
	*/
	
	
	  
	ret=log(ret);
	
	
	
	return ret;
	
	
}

/*This is the cumulative function of a normalized gaussian distribution*/
double TRecon::GaussianCDF(const double &t,const double &mean,const double &sigma) const{
    
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
double TRecon::SinglePhotonTimeProb(double t,double tau,double sigma) const{
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






/*This is a function that, given the source point x0,
returns the average number of photons on the pixel iPMT, id,
assuming a unitary excitation at the source.
*/
double TRecon::SinglePixelAverageCharge(const TVector3 &x0,int iPMT,int id) const{
	double ret;
	double solidAngle;
	TVector3 xp=m_detector->getPosPixel(iPMT,id);
	
	/*First account for the solid angle*/
	solidAngle=this->GetSolidAngle(x0,iPMT,id);
	solidAngle /= ( 4 * TMath::Pi() );
	
	/*Then, at large angles there may be other effects*/
	
	ret = solidAngle;
	
	
	return ret;
	
}


/*This is the method that returns the solid angle of a given pixel (for detector iPMT)
from the point x0*/
double TRecon::GetSolidAngle(const TVector3 &x0,int iPMT,int id) const{
	
	TVector3 xp=m_detector->getPosPixel(iPMT,id);
	TVector3 r=(x0-xp);
	
	double a,b,c,Lx,Ly,r2,ret;
	
	c=fabs(r*m_detector->getPixelNormal(iPMT,id));
	a=r*m_detector->getPixelT1(iPMT,id);
	b=r*m_detector->getPixelT2(iPMT,id);
	
	
	Lx=m_detector->getPixelSizeX(iPMT);
	Ly=m_detector->getPixelSizeY(iPMT);
	
	
	r2=r.Mag2();
	ret = 0;
	
	ret += atan( (Lx-2*a)*(Ly-2*b) / (2*c*sqrt(4*r2-4*a*Lx-4*b*Ly+Lx*Lx+Ly*Ly)));
	ret += atan( (Lx+2*a)*(Ly+2*b) / (2*c*sqrt(4*r2+4*a*Lx+4*b*Ly+Lx*Lx+Ly*Ly)));
	ret += atan( (Lx+2*a)*(Ly-2*b) / (2*c*sqrt(4*r2+4*a*Lx-4*b*Ly+Lx*Lx+Ly*Ly)));
	ret += atan( (Lx-2*a)*(Ly+2*b) / (2*c*sqrt(4*r2-4*a*Lx+4*b*Ly+Lx*Lx+Ly*Ly)));
	
	
	return ret;
}

/*Center of gravity from charge*/
TVector3 TRecon::computeCOG(){
	int ipixel;
	double qNew=0;
	double qTotNew=0;
	TVector3 cog(0.,0.,0.);
	for (int ii=0;ii<6;ii++){
		if (m_detector->isDetPresent(ii)==0) continue;
		for (int iy=0;iy<m_detector->getNPixelsY(ii);iy++){
			for (int ix=0;ix<m_detector->getNPixelsX(ii);ix++){
				ipixel=ix+iy*m_detector->getNPixelsX(ii);
				qNew=1.*m_N[ii][ipixel];
				qNew=pow(qNew,1.5);			
				cog=cog+qNew*(m_detector->getPosPixel(ii,ipixel));
				qTotNew+=qNew;
			}
		}
	}
	cog=cog*(1./qTotNew);
	return cog;
}











