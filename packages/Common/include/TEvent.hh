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


	TClonesArray* getCollection (int id) const;
	void deleteCollection (int id);

public:
	TEvent();
	virtual ~TEvent();
	virtual void Clear(Option_t* option="");
	void clearCollections(){m_collections.clear();}

	inline int getNcollections() const{return m_collections.size();}
	void		printCollections() const;


	void		  addCollection(TClonesArray *coll,int checkAlreadyExists=1);
	TClonesArray* getCollection(TClass *theClass,string name) const;
	void          deleteCollection(TClass *theClass,string name);

	int  		 hasCollection(TClonesArray *coll) const;
	int 		 hasCollection(TClass *theClass,string name) const;





	ClassDef(TEvent,1);
};



#endif
