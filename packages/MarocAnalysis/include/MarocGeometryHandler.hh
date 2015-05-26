#ifndef MarocGeometryHandler_HG
#define MarocGeometryHandler_HG

class MarocGeometryHandler:public RealGeometryHandler{
  
  public:
    int GetMarocId(int globalId);
    int GetH8500Id(int globalId);
    double H8500Gain(int H8500Id,int PmtID);

    double MarocGain(int MarocId);
    int GetGeometryId(int MarocId,int faceID);


};
#endif 

