#include "TMCParticle.hh"

#include "TLorentzVector.h"

TMCParticle::TMCParticle():
m_x0(0),
m_P0(0){

}

TMCParticle::~TMCParticle(){
	if (m_x0) delete m_x0;
	if (m_P0) delete m_P0;
}
/*From root TOBject*/
void TMCParticle::Clear(Option_t* option){

}
