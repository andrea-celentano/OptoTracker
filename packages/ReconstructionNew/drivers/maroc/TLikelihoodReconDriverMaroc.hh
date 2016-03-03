#ifndef TLIKELIHOODRECONDRIVERMAROC_HH_
#define TLIKELIHOODRECONDRIVERMAROC_HH_

#include <string>

#include "TObject.h"
#include "TLikelihoodReconDriverBase.hh"
#include "TEvent.hh"

class TLikelihoodReconDriverMaroc: public TLikelihoodReconDriverBase {
public:

	virtual int process(TEvent *m_event);
	ClassDef(TLikelihoodReconDriverMaroc,1);
};

#endif
