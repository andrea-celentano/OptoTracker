#include <string>

#include "TNamed.h"

#include "TNamedContainer.hh"

TNamedContainer::TNamedContainer(TObject* obj,std::string name,std::string title):
m_object(obj){
	SetName(name.c_str());
	SetTitle(title.c_str());
}


TNamedContainer::~TNamedContainer(){

}
