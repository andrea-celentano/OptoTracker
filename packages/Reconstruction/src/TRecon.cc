#include "TRecon.hh"
#include "TOpNoviceDetectorLight.hh"


#include "TMath.h"

#include <vector>
#include <iostream>

using namespace std;

TRecon::TRecon(TOpNoviceDetectorLight *detector,TReconInput *input):
m_detector(detector),
m_reconInput(input),
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
	m_TrackLikelihoodChargeKernel=new TF1("TrackLikelihoodChargeKernel",this,&TRecon::TrackLikelihoodChargeKernel,0.,1.,9); //9 fixed parameters: x0(3x), x1(3x), face, detector, pixel
	
	
	m_parNames[0]="X0";
	m_parNames[1]="Y0";
	m_parNames[2]="Z0";
	m_parNames[3]="X1";
	m_parNames[4]="Y1";
	m_parNames[5]="Z1";
	m_parNames[6]="beta";
	m_parNames[7]="T0";
	m_parNames[8]="N0";
	m_parNames[9]="tau";
}

TRecon::~TRecon(){
	delete m_minimizer;
	if (m_SinglePhotonTimeProbKernel) delete m_SinglePhotonTimeProbKernel;
}


void TRecon::doFit(){
	
	if (m_fitObject==k_null){
		return;
	}


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
	if (m_fitObject==k_null){
			return;
		}
  
 	Info("initParameters","InitParameters start");
	m_minimizer->SetLimitedVariable(0,"X0",m_reconInput->getParVal(0),.1,-m_detector->getScintSizeX()*.5,m_detector->getScintSizeX()*.5);	
	m_minimizer->SetLimitedVariable(1,"Y0",m_reconInput->getParVal(1),.1,-m_detector->getScintSizeY()*.5,m_detector->getScintSizeY()*.5);
	m_minimizer->SetLimitedVariable(2,"Z0",m_reconInput->getParVal(2),.1,-m_detector->getScintSizeZ()*.5,m_detector->getScintSizeZ()*.5);
	m_minimizer->SetLimitedVariable(3,"X1",m_reconInput->getParVal(3),.1,-m_detector->getScintSizeX()*.5,m_detector->getScintSizeX()*.5);		
	m_minimizer->SetLimitedVariable(4,"Y1",m_reconInput->getParVal(4),.1,-m_detector->getScintSizeY()*.5,m_detector->getScintSizeY()*.5);
	m_minimizer->SetLimitedVariable(5,"Z1",m_reconInput->getParVal(5),.1,-m_detector->getScintSizeZ()*.5,m_detector->getScintSizeZ()*.5);
	m_minimizer->SetLimitedVariable(6,"b",m_reconInput->getParVal(6),.1,0.,1.);
	m_minimizer->SetVariable(7,"t",m_reconInput->getParVal(7),.1);
	m_minimizer->SetLowerLimitedVariable(8,"N",m_reconInput->getParVal(8),0.1,0.); 
	m_minimizer->SetLowerLimitedVariable(9,"tau",m_reconInput->getParVal(9),0.1,0.);
	
	/*Then, verify if we need to fix anything*/
	 for (int ii=0;ii<m_nPars;ii++){
	  if (m_reconInput->isParFixed(ii)) m_minimizer->FixVariable(ii);
	 }
 	Info("initParameters","InitParameters end");
	 
	 /*@TODO: consider par limits in the file*/
	 
}


void TRecon::setFitObject(fitObject_t type){
	Info("setFitObject","Set fit Object called with %i",type);
	m_fitObject=type;
	if (m_fitObject==k_null){
			return;
	}
	else if (m_fitObject==k_point){
	    Info("setFitObject","Fixing parameters for point mode");

		
		m_minimizer->FixVariable(3);	  		
		m_minimizer->FixVariable(4);	  
		m_minimizer->FixVariable(5);	  		
		/*Fix beta*/
		m_minimizer->FixVariable(6);
		 Info("setFitObject","Fixed parameters for point mode");
	}	
}
void TRecon::setFitLikelihoodMode(fitLikelihoodMode_t mode){
	m_fitLikelihoodMode=mode;

	/*If we fit only the time info, we can't get N*/
	if (m_fitLikelihoodMode==k_onlyTime){
		Info("setFitLikelihoodMode","Fixing parameters for onlyTime mode");
		m_minimizer->FixVariable(8);
	}
	/*If we fit only the charge info, we can't get t0 and beta and tau*/
	else if (m_fitLikelihoodMode==k_onlyCharge){
		Info("setFitLikelihoodMode","Fixing parameters for onlyCharge mode");
		m_minimizer->FixVariable(6);
		m_minimizer->FixVariable(7);
		m_minimizer->FixVariable(9);
	}
	


}


void TRecon::initFit(){
	Info("initFit","InitFit was called");
  
	initParameters(); /*Create all the parameters and set them*/
	
	setFitObject(m_reconInput->getFitObject()); /*Set the fit object: point or track. Correspondingly, fix the parameters we are not sensitive to*/
	setFitLikelihoodMode(m_reconInput->getFitLikelihoodMode());/*Set the fit data: charge, time, both. Correspondingly, fix the parameters we are not sensitive to*/
 }





/*This is the method that computes the function, x are the variables*/

//double TRecon::operator()(const std::vector< double >& x) const{
double TRecon::DoEval(const double *x) const{
	double ret;
	switch (m_fitObject){
	case (k_null):
		ret=0;
		break;
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
double TRecon::SinglePixelAverageCharge(const TVector3 &x0,int iface,int idetector,int id) const{
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
double TRecon::GetSolidAngle(const TVector3 &x0,int iface,int idetector,int id) const{
	
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

/*Center of gravity from charge*/
TVector3 TRecon::computeCOG(){
	int ipixel;
	double qNew=0;
	double qTotNew=0;
	TVector3 cog(0.,0.,0.);
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<m_detector->getNdet(ii);jj++){
		if (m_detector->isDetPresent(ii,jj)==0) continue;
		for (int iy=0;iy<m_detector->getNPixelsY(ii,jj);iy++){
			for (int ix=0;ix<m_detector->getNPixelsX(ii,jj);ix++){
				ipixel=ix+iy*m_detector->getNPixelsX(ii,jj);
				qNew=1.*m_N[ii][jj][ipixel];
				qNew=pow(qNew,1.5);			
				cog=cog+qNew*(m_detector->getPosPixel(ii,jj,ipixel));
				qTotNew+=qNew;
			}
		}
	}
	}
	cog=cog*(1./qTotNew);
	return cog;
}











