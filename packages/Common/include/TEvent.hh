#ifndef TEVENT_HG
#define TEVENT_HG


#include <vector>
#include <string>
#include <iostream>

#include "TObject.h"
#include "TClass.h"
#include "TClonesArray.h"

using namespace std;

class TEvent : public TObject{


private:
	vector <TClonesArray*> m_collections;

public:
	TEvent();
	virtual ~TEvent();
	virtual void Clear(Option_t* option="");

	inline int getNcollections() const{return m_collections.size();}
	void clearCollections(){m_collections.clear();}

	TClonesArray* getCollection (int id) const;
	TClonesArray* getCollectionByName(string name) const;

	void		  addCollection(TClonesArray *coll,int checkNameAlreadyExists=0);

	int 		 hasCollectionByName(string name) const;
	int  		 hasCollectionByClass(string name) const;

	void		printCollectionsName() const;
	void		printCollectionsClass() const;



	ClassDef(TEvent,1);
};



#endif
