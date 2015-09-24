#ifndef TNAMEDCONTAINER_HG
#define TNAMEDCONTAINER_HG

#include <string>


#include "TNamed.h"
#include "TObject.h"

class TNamedContainer : public TNamed {

public:
	TNamedContainer(TObject *obj=0,std::string m_name="",std::string m_title="");
	virtual ~TNamedContainer();

	TObject *getObject(){return m_object;}
	void setObject(TObject *obj){m_object=obj;}

private:
	TObject *m_object;

	ClassDef(TNamedContainer,1);
};

#endif
