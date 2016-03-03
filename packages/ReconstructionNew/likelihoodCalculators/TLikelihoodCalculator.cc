/*
 * TLikelihoodCalculator.cc
 *
 *  Created on: Mar 3, 2016
 *      Author: celentan
 */

#include "TLikelihoodCalculator.hh"

#include "../drivers/common/TLikelihoodReconDriverBase.hh"
#include "TDriver.hh"

TLikelihoodCalculator::TLikelihoodCalculator() {
	// TODO Auto-generated constructor stub

	for (int iface=0;iface<6;iface++){
		m_N[iface]=0;
		m_Q[iface]=0;
		m_T[iface]=0;
	}
	m_driver=0;
}

TLikelihoodCalculator::~TLikelihoodCalculator() {
	// TODO Auto-generated destructor stub
}

void TLikelihoodCalculator::Init(int **N[6],double **T[6],double **Q[6]) {
	if (m_driver->getManager()->getDetector()==0){
		Error("Init","No TDetectorLight set with the method setDetector!!");
		return;
	}
	/*Set all the pointers. This get called only ONCE!*/
	for (int iface=0;iface<6;iface++){
		m_N[iface]=new int*[m_driver->getManager()->getDetector()->getNdet(iface)];
		m_Q[iface]=new double*[m_driver->getManager()->getDetector()->getNdet(iface)];
		m_T[iface]=new double*[m_driver->getManager()->getDetector()->getNdet(iface)];
		for (int idet=0;idet<m_driver->getManager()->getDetector()->getNdet(iface);idet++){
			m_N[iface][idet]=N[iface][idet];
			m_Q[iface][idet]=Q[iface][idet];
			m_T[iface][idet]=T[iface][idet];
		}
	}
	return;

}
