#ifndef TEVENT_HG
#define TEVENT_HG


#include <vector>
#include <string>
#include <iostream>

#include "TObject.h"
#include "TClass.h"
#include "TClonesArray.h"
#include "TObjArray.h"
using namespace std;

class TEventHeader;

class TEvent : public TObject{


private:

	TEventHeader*		   m_eventHeader;
	TObjArray			   m_objects;
	vector <TClonesArray*> m_collections;



	TClonesArray* getCollection (int id) const;
	void deleteCollection (int id);

public:
	TEvent();
	virtual ~TEvent();
	virtual void Clear(Option_t* option="");
	void clearCollections(){m_collections.clear();}
	void clearObjects(){m_objects.Clear();}

	void printObjects() const;
	void addObject(TObject *obj);
	TObject* getObject(string name) const;
	int hasObject(string name) const;

	inline int  getNcollections() const{return m_collections.size();}
	void		printCollections() const;


	void		  addCollection(TClonesArray *coll,int checkAlreadyExists=1);
	TClonesArray* getCollection(TClass *theClass,string name) const;
	void          deleteCollection(TClass *theClass,string name);

	int  		 hasCollection(TClonesArray *coll) const;
	int 		 hasCollection(TClass *theClass,string name) const;






	TEventHeader* getEventHeader() const {
		return m_eventHeader;
	}

	void setEventHeader(TEventHeader* eventHeader) {
		m_eventHeader = eventHeader;
	}

	ClassDef(TEvent,2);
};



#endif
