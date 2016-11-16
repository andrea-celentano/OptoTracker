#ifndef TDETECTORUTILS_HG
#define TDETECTORUTILS_HG

#include <complex>

#include "TVector3.h"
#include "TObject.h"

using namespace std;

#define clight 299.792  /*in mm/ns*/
/*In this class, I insert all the relevant function that
 * are used during reconstruction and depend on the detector
 *
 */

class TDetector;
class TF1;

class TDetectorUtils : public TObject{

private:
	TDetector* m_detector;
	TF1 *m_SinglePhotonTimeProbKernel;
	TF1 *m_TrackChargeKernel;
	double GaussianCDF(const double &x,const double &mean,const double &sigma) const;
	double TrackChargeKernel(double *x,double *p);
	double SinglePhotonTimeProbKernel(double *x,double *p);

	double getFresnelReflectivityCustomDetector(const TVector3& x0, int iface, int idetector, int id) const;
	double getFresnelAbsorbanceH8500(const TVector3& x0,int iface,int idetector,int id) const;
	double FresnelReflectivity(double n1,double ctheta1,double n2) const;

	static const int nPxFluxCalculation=5;
	static const int nPyFluxCalculation=5;

public:
	TDetectorUtils(TDetector *det=0);
	virtual ~TDetectorUtils();

	double SinglePhotonTimeProb(double t,double tau,double sigma) const;
	double SinglePhotonIntegratedTimeProb(double t,double tau,double sigma) const;


	double SinglePixelAverageCharge(const TVector3 &x0,int iface,int idetector,int id) const;
	double GetSolidAngle(const TVector3 &x0,int iface,int idetector,int id) const;


	double TrackAverageCharge(const TVector3 &x0,const TVector3 &x1,int iface,int idetector,int id) const;

	double GetMinimalDelay(const TVector3 &x0,const TVector3 &x1,double beta,int iface,int idetector,int id) const;

	ClassDef(TDetectorUtils,1);

};

#endif
