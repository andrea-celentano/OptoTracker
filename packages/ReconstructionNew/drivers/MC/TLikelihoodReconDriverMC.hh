#ifndef TLIKELIHOODRECONDRIVERMC_HH_
#define TLIKELIHOODRECONDRIVERMC_HH_

#include <string>

#include "TObject.h"
#include "TLikelihoodReconDriverBase.hh"


class TLikelihoodReconDriverMC: public TLikelihoodReconDriverBase {
public:

	virtual int process(TEvent *m_event);
	ClassDef(TLikelihoodReconDriverMC,1);
};

#endif
