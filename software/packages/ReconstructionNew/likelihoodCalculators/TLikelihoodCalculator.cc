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

	m_ON = 0;
	m_disc = 0;
	m_Q = 0;
	m_T = 0;

	m_driver = 0;
	m_detector = 0;
	m_detectorUtils = 0;
	m_realSetupHandler = 0;
}

TLikelihoodCalculator::~TLikelihoodCalculator() {
	// TODO Auto-generated destructor stub
}

void TLikelihoodCalculator::SetData(vector<vector<int>> *ON, vector<vector<int>> *disc, vector<vector<double>> *T, vector<vector<double>> *Q) {
	if (m_detector == 0) {
		Error("Init", "No TDetector set with the method setDetector or setDriver");
		return;
	}
	if (m_detectorUtils == 0) {
		Error("Init", "No TDetectorUtils set with the method setDetector or setDriver");
		return;
	}
	/*Set all the pointers. This get called only ONCE!*/
	m_ON = ON;
	m_disc = disc;
	m_Q = Q;
	m_T = T;
	/*for (int iface = 0; iface < 6; iface++) {
	 m_ON[iface] = ON[iface];
	 m_disc[iface] = disc[iface];
	 m_Q[iface] = Q[iface];
	 m_T[iface] = T[iface];
	 }*/
	return;

}

void TLikelihoodCalculator::setDriver(TDriver* driver) {
	m_driver = driver;
	if (m_driver != 0) {
		m_detector = m_driver->getManager()->getDetector();
		m_detectorUtils = m_driver->getManager()->getDetectorUtils();
	}
	return;
}
