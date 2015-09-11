#ifndef TRECONINPUT_HG
#define TRECONINPUT_HG

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "TROOT.h"
#include "TObject.h"

#include "TReconDefs.hh"


using namespace std;

class TReconInput : public TObject {

  public:
    TReconInput();
    TReconInput(string fname);
    virtual ~TReconInput(){printf("TReconInput deconstructor\n");}
    
    double getParVal(int id) const{return m_parVal[id];}
    void   setParVal(int id,double val){m_parVal[id]=val;}

    int    isParFixed(int id) const{return (m_isParFixed[id]>0 ? 1 : 0);}
    void   setParFixed(int id,int fix=1){m_isParFixed[id]=fix;}
    
    int    isParLowLimited(int id) const{if (m_isParLowLimited[id]) return 1; else return 0;}
    void   setParLowLimited(int id,int limit=1){m_isParLowLimited[id]=limit;}
    double getParLowLimit(int id) const{return m_parLowLimit[id];}
    void setParLowLimit(int id,double val){m_parLowLimit[id]=val;}
   
    int    isParHighLimited(int id) const{if (m_isParHighLimited[id]) return 1; else return 0;}
    void   setParHighLimited(int id,int limit=1){m_isParHighLimited[id]=limit;}
    double getParHighLimit(int id) const{return m_parHighLimit[id];}
    void setParHighLimit(int id,double val){m_parHighLimit[id]=val;}
    
    int isParBothLimited(int id) const{ if (m_isParLowLimited[id]&&(m_isParHighLimited[id])) return 1; else return 0;}
  
   

    fitObject_t getFitObject() const{return m_fitObject;}
    fitLikelihoodMode_t getFitLikelihoodMode(){return m_fitLikelihoodMode;}

    void setName(string name){m_name=name;}
    string getName(){return m_name;}

    virtual void Print() const;
  
    static const int m_nPars = 30; //larger than in TRecon.
  private:


   string m_name;
   
   int    m_isParConfigured[m_nPars];
   double m_parVal[m_nPars];
   int    m_isParFixed[m_nPars];
   int    m_isParLowLimited[m_nPars];
   int    m_isParHighLimited[m_nPars];
   double m_parLowLimit[m_nPars];
   double m_parHighLimit[m_nPars];
   
   fitObject_t m_fitObject;
   fitLikelihoodMode_t m_fitLikelihoodMode;
   
   
   ClassDef(TReconInput,1);
};
#endif
