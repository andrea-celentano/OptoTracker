/*
 * TLikelihoodCalculator.cc
 *
 *  Created on: Mar 3, 2016
 *      Author: celentan
 */

#include "TLikelihoodCalculator.hh"

#include "TDriver.hh"
#include "TLikelihoodReconDriver.hh"

TLikelihoodCalculator::TLikelihoodCalculator() {
	// TODO Auto-generated constructor stub

	for (int iface=0;iface<6;iface++){
		m_ON[iface]=0;
		m_disc[iface]=0;
		m_Q[iface]=0;
		m_T[iface]=0;
	}
	m_driver=0;
	m_detector=0;
	m_detectorUtils=0;
	m_realSetupHandler=0;
}

TLikelihoodCalculator::~TLikelihoodCalculator() {
	// TODO Auto-generated destructor stub
}

void TLikelihoodCalculator::SetData(int **ON[6],int **disc[6],double **T[6],double **Q[6]) {
	if (m_detector==0){
		Error("Init","No TDetector set with the method setDetector or setDriver");
		return;
	}
	if (m_detectorUtils==0){
			Error("Init","No TDetectorUtils set with the method setDetector or setDriver");
			return;
		}
	/*Set all the pointers. This get called only ONCE!*/
	for (int iface=0;iface<6;iface++){
		m_ON[iface]=new int*[m_detector->getNdet(iface)];
		m_disc[iface]=new int*[m_detector->getNdet(iface)];
		m_Q[iface]=new double*[m_detector->getNdet(iface)];
		m_T[iface]=new double*[m_detector->getNdet(iface)];
		for (int idet=0;idet<m_detector->getNdet(iface);idet++){
			m_ON[iface][idet]=ON[iface][idet];
			m_disc[iface][idet]=disc[iface][idet];
			m_Q[iface][idet]=Q[iface][idet];
			m_T[iface][idet]=T[iface][idet];
		}
	}
	return;

}

void TLikelihoodCalculator::setDriver(TDriver* driver) {
	m_driver = driver;
	if (m_driver!=0){
		m_detector=m_driver->getManager()->getDetector();
		m_detectorUtils=m_driver->getManager()->getDetectorUtils();
	}
	return;
}
