#include "TDriver.hh"


TDriver::TDriver(TJobManager *manager):
m_manager(manager),m_name(""),m_verboseLevel(0),m_iterationN(0)
{
	m_isProofCompatible=1; //by default, we are proof compatible
	m_collectionName="";
	m_collectionRawName="";
	m_collectionOutName="";

}
TDriver::~TDriver(){


}

