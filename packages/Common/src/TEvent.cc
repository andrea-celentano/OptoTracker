#include "TEvent.hh"

TEvent::TEvent(){

}

TEvent::~TEvent(){

}


TClonesArray* TEvent::getCollection (int id) const{
	if (id<this->getNcollections()){
		return m_collections.at(id);
	}
	else{
		Error("TEvent","TEvent::getCollection bad id");
		return NULL;
	}
}

TClonesArray* TEvent::getCollectionByName(string name) const{
	TClonesArray* ret=0;
	vector < TClonesArray* >::const_iterator it;
	for (it=m_collections.begin();it!=m_collections.end();it++){
		if (strcmp((*it)->GetName(),name.c_str())==0){
			ret=*it;
			break;
		}
	}
	if (ret==0){
		Error("TEvent","TEvent::getCollectionByName not found %s",name.c_str());
	}
	return ret;
}

void TEvent::addCollection(TClonesArray *coll,int checkNameAlreadyExists){
	if (coll==NULL){
		Error("TEvent","TEvent::addCollection input null");
		return;
	}
	if (checkNameAlreadyExists){
		if (this->hasCollectionByName(coll->GetName())){
			Warning("TEvent","TEvent::addCollection. Collection with same name already exists");
			return;
		}
	}
	m_collections.push_back(coll);
}

int TEvent::hasCollectionByName(string name)const{
	int ret=0;
	vector < TClonesArray* >::const_iterator it;
	for (it=m_collections.begin();it!=m_collections.end();it++){
		if ((*it)->GetName()==name) ret=1;
	}
	return ret;
}


int TEvent::hasCollectionByClass(string name)const{
	int ret=0;
	vector < TClonesArray* >::const_iterator it;
	for (it=m_collections.begin();it!=m_collections.end();it++){
		if ((*it)->GetName()==name) ret=1;
	}
	return ret;
}

void TEvent::printCollectionsName()const{
	vector < TClonesArray* >::const_iterator it;
	for (it=m_collections.begin();it!=m_collections.end();it++){
		cout<<(*it)->GetName()<<endl;
	}
}

void TEvent::printCollectionsClass()const{
	vector < TClonesArray* >::const_iterator it;
	for (it=m_collections.begin();it!=m_collections.end();it++){
		cout<<(*it)->Class()->GetName()<<endl;
	}
}


void	TEvent::Clear(Option_t* opt){
	vector < TClonesArray* >::iterator it;
	for (it=m_collections.begin();it!=m_collections.end();it++){
		(*it)->Clear(opt);
	}
}


