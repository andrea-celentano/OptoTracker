#include "TMCTruth.hh"

#include "TLorentzVector.h"


TMCTruth::TMCTruth(){
	m_P0=0;
	m_x0=0;
	m_xin=0;
	m_xout=0;
}

TMCTruth::~TMCTruth(){
	if (m_P0) delete m_P0;
	if (m_x0) delete m_x0;
	if (m_xin) delete m_xin;
	if (m_xout) delete m_xout;
}
