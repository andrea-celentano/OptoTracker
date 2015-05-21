//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "OpNoviceDetectorConstruction.hh"

#include "G4Material.hh"
#include "G4Element.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4OpticalSurface.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4SubtractionSolid.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4VisAttributes.hh"
#include "G4GeometryManager.hh"
#include "G4SolidStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4SDManager.hh"
#include "G4RunManager.hh"
#include "G4UserLimits.hh"


#include "TString.h"


static OpNoviceDetectorConstruction* instance = 0;


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceDetectorConstruction::OpNoviceDetectorConstruction(TOpNoviceDetectorLight *mDetectorLight)
: G4VUserDetectorConstruction(),fDetectorLight(mDetectorLight)
{
  
  //for (int ii=0;ii<6;ii++) fDetector_log[ii]=NULL;	
  SetDefaults();
  
  instance=this;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceDetectorConstruction::~OpNoviceDetectorConstruction(){;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



OpNoviceDetectorConstruction* OpNoviceDetectorConstruction::GetInstance()
{
  if (instance == 0 )
  {
    G4cout<<"OpNoviceDetectorConstruction::GetInstance can't return any instance"<<G4endl;
    return 0;
  }
  return instance;
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



G4VPhysicalVolume* OpNoviceDetectorConstruction::Construct()
{
  
  
  
  
  G4cout<<"OpNoviceDetectorConstruction::Construct was called"<<G4endl;
  if (fExperimentalHall_phys) {
    G4GeometryManager::GetInstance()->OpenGeometry();
    G4PhysicalVolumeStore::GetInstance()->Clean();
    G4LogicalVolumeStore::GetInstance()->Clean();
    G4SolidStore::GetInstance()->Clean();
    G4LogicalSkinSurface::CleanSurfaceTable();
    G4LogicalBorderSurface::CleanSurfaceTable();
  }
  
  
  double x,y;
  double xp,yp;
  G4double faceThickness=3*mm;
  G4double detectorThickness=.2*mm;	
  G4double pixelThickness=.1*mm;	
  G4double aroundThickness=.2*mm;
  G4ThreeVector fTrans[6];
  G4VisAttributes* VisAtt;
  G4RotationMatrix* fRot[6];	
  
  int ix,iy,id;
  
  
  
  // ------------- Materials -------------
  DefineMaterials();
  // The experimental Hall
  //
  //The experimental hall walls are all 100cm away from housing walls
  fExpHall_x = 50.*cm;
  fExpHall_y = 50.*cm;
  fExpHall_z = 50.*cm;
  
  fExperimentalHall_box = new G4Box("World",fExpHall_x,fExpHall_y,fExpHall_z);
  fExperimentalHall_log = new G4LogicalVolume(fExperimentalHall_box,fAir,"World",0,0,0);
  fExperimentalHall_phys = new G4PVPlacement(0,G4ThreeVector(),fExperimentalHall_log,"World",0,false,0);
  
  fDummy_box = new G4Box("Dummy",1*mm,1*mm,1*mm);
  fDummy_log = new G4LogicalVolume(fDummy_box,fAir,"Dummy",0,0,0);
  fDummy_phys = new G4PVPlacement(0,G4ThreeVector(fExpHall_x/2-1*cm,fExpHall_y/2-1*cm,fExpHall_z/2-1*cm),fDummy_log,"Dummy",fExperimentalHall_log ,false,0);
  
  G4double delta = 1*mm;
  // The Scintillator
  fScint_x=fDetectorLight->GetScintSizeX()*cm;
  fScint_y=fDetectorLight->GetScintSizeX()*cm;
  fScint_z=fDetectorLight->GetScintSizeX()*cm;
  
  G4Box* Scintillator_box = new G4Box("Scintillator",fScint_x/2,fScint_y/2,fScint_z/2);
  G4LogicalVolume* Scintillator_log = new G4LogicalVolume(Scintillator_box,fEJ230,"Scintillator",0,0,0);
  G4VPhysicalVolume* Scintillator_phys = new G4PVPlacement(0,G4ThreeVector(),Scintillator_log,"Scintillator",fExperimentalHall_log,false,0);
  
  
  //The 6 faces
  
  for (int ii=0;ii<6;ii++){
    if (ii==0){ //xy, +z
      x=fScint_x;
      y=fScint_y;
      fTrans[0]=G4ThreeVector(0,0,(fScint_z+faceThickness)/2);
      fRot[0]=new G4RotationMatrix;
      fRot[0]->rotateY(M_PI*rad);
  }	
  if (ii==2){ //xy, -z
    x=fScint_x;
    y=fScint_y;
    fTrans[2]=G4ThreeVector(0,0,-(fScint_z+faceThickness)/2);
    fRot[2]=new G4RotationMatrix;
    fRot[2]->rotateY(0);
  }
  if (ii==1){ //yz,+x
    x=fScint_z;
    y=fScint_y;
    fTrans[1]=G4ThreeVector((fScint_x+faceThickness)/2,0,0);
    fRot[1]=new G4RotationMatrix;
    fRot[1]->rotateY(M_PI/2.*rad);
  }	
  if (ii==3){ //yz,-x
    x=fScint_z;
    y=fScint_y;	
    fTrans[3]=G4ThreeVector(-(fScint_x+faceThickness)/2,0,0);
    fRot[3]=new G4RotationMatrix;
    fRot[3]->rotateY(-M_PI/2.*rad);
  }
  if (ii==4){ //xz,+y
    x=fScint_x;
    y=fScint_z;	
    fTrans[4]=G4ThreeVector(0,(fScint_y+faceThickness)/2,0);
    fRot[4]=new G4RotationMatrix;
    fRot[4]->rotateX(-M_PI/2*rad);
  }	
  if (ii==5){ //xz,-y
    x=fScint_x;
    y=fScint_z;
    fTrans[5]=G4ThreeVector(0,-(fScint_y+faceThickness)/2,0);
    fRot[5]=new G4RotationMatrix;
    fRot[5]->rotateX(M_PI/2*rad);
  }
  fFace_box[ii]=new G4Box("Face",x/2,y/2,faceThickness/2);
  fFace_log[ii]=new G4LogicalVolume(fFace_box[ii],fAir,"Face",0,0,0);
  
  
  
  fMarker_box[ii]=new G4Box("Marker",3*mm,.5*mm,.5*mm);
  fMarker_log[ii]=new G4LogicalVolume(fMarker_box[ii],fAir,"Marker",0,0,0);
  VisAtt = new G4VisAttributes(G4Colour(0.0,0.0,0.0));
  VisAtt->SetForceSolid(true);
  fMarker_log[ii]->SetVisAttributes(VisAtt);
  
  fAround_box_a[ii]=new G4Box("Around",x/2,y/2,aroundThickness/2);
  
  for (int jj=0;jj<fDetectorLight->getNdet(ii);jj++){
    
    if (fDetectorLight->isDetPresent(ii,jj)){
      fPhotoDetectorSizeX[ii][jj]=fDetectorLight->getDetSizeX(ii,jj)*cm;
      fPhotoDetectorSizeY[ii][jj]=fDetectorLight->getDetSizeY(ii,jj)*cm;
      fPixelSizeX[ii][jj]=fDetectorLight->getPixelSizeX(ii,jj)*cm;
      fPixelSizeY[ii][jj]=fDetectorLight->getPixelSizeY(ii,jj)*cm;
      fCouplingThickness[ii][jj]=fDetectorLight->GetCouplingThickness(ii,jj)*cm;
      
      fDetector_box[ii][jj]=new G4Box("Detector",fPhotoDetectorSizeX[ii][jj]/2,fPhotoDetectorSizeY[ii][jj]/2,detectorThickness/2);
      fDetector_log[ii][jj]=new G4LogicalVolume(fDetector_box[ii],fAir,"Detector",0,0,0);
      
      
      fPixel_box[ii][jj]=new G4Box("Pixel",fPixelSizeX[ii][jj]/2,fPixelSizeY[ii][jj]/2,pixelThickness/2);
      fPixel_log[ii][jj]=new G4LogicalVolume(fPixel_box[ii][jj],fAir,"Pixel",0,0,0);
      
      VisAtt = new G4VisAttributes(G4Colour(0.1,1.,0.1,0.8));
      VisAtt->SetForceSolid(true);
      fDetector_log[ii][jj]->SetVisAttributes(VisAtt);
      new G4PVPlacement(0,G4ThreeVector(0,0,faceThickness/2-fCouplingThickness[ii][jj]-detectorThickness/2),fDetector_log[ii][jj],Form("Detector_%i_%i",ii,jj),fFace_log[ii],false,ii);//I use a copy-number to keep the face number
      
      
      
      /*Now place the pixels*/
      id=0;
      for (int iy=0;iy<fNPixelsY[ii];iy++){
	for (int ix=0;ix<fNPixelsX[ii];ix++){
	  
	  xp=(fPixelSizeX[ii]-fPhotoDetectorSizeX[ii])/2+ix*fPixelSizeX[ii];
	  yp=(fPixelSizeY[ii]-fPhotoDetectorSizeY[ii])/2+iy*fPixelSizeY[ii];
	  
	  //new G4PVPlacement(0,G4ThreeVector(xp,yp,faceThickness/2-fCouplingThickness[ii]-detectorThickness/2),fPixel_log[ii],Form("Pixel_%i_%i",ii,id),fDetector_log[ii],false,id);
	  new G4PVPlacement(0,G4ThreeVector(xp,yp,detectorThickness/2-pixelThickness/2),fPixel_log[ii],Form("Pixel_%i_%i",ii,id),fDetector_log[ii],false,id);
	  id++;		    
	}
	
      }
      
      
      
      if (fCouplingThickness[ii]>0){
	fCoupling_box[ii]=new G4Box("Coupling",fPhotoDetectorSizeX[ii]/2,fPhotoDetectorSizeY[ii]/2,fCouplingThickness[ii]/2);
	fCoupling_log[ii]=new G4LogicalVolume(fCoupling_box[ii],fCoupling[ii],"Coupling",0,0,0);
	VisAtt = new G4VisAttributes(G4Colour(0.1,1.,1.,0.3));
	VisAtt->SetForceSolid(true);
	fCoupling_log[ii]->SetVisAttributes(VisAtt);
	new G4PVPlacement(0,G4ThreeVector(0,0,faceThickness/2-fCouplingThickness[ii]/2),fCoupling_log[ii],"Coupling",fFace_log[ii],false,0);
      }	
      else{
	fCouplingThickness[ii]=0;
      }
      
      fAround_box_b[ii]=new G4Box("Around",fPhotoDetectorSizeX[ii]/2,fPhotoDetectorSizeY[ii]/2,aroundThickness);
      fAround[ii]=new G4SubtractionSolid("Around",fAround_box_a[ii],fAround_box_b[ii]);
      fAround_log[ii]=new G4LogicalVolume(fAround[ii],fAir,"Around",0,0,0);
    }
    else{
      fAround_log[ii]=new G4LogicalVolume(fAround_box_a[ii],fAir,"Around",0,0,0);
    }
    VisAtt = new G4VisAttributes(G4Colour(1.,0.,0.,0.8));
    VisAtt->SetForceSolid(true);
    fAround_log[ii]->SetVisAttributes(VisAtt);
    
    fAround_phys[ii]=new G4PVPlacement(0,G4ThreeVector(0,0,faceThickness/2-aroundThickness/2),fAround_log[ii],"Around",fFace_log[ii],false,0);
    
    new G4PVPlacement(0,G4ThreeVector(-x/2+2*3*mm,-y/2+2*.5*mm,-(faceThickness+.5*mm)/2),fMarker_log[ii],"Marker",fFace_log[ii],false,0);
    
    new G4PVPlacement(fRot[ii],fTrans[ii],fFace_log[ii],Form("Face%i",ii),fExperimentalHall_log,false,ii); //I use a copy-number to keep the face number
  }		
}


//G4VPhysicalVolume* h8500_phys5 = new G4PVPlacement(yRot_4,G4ThreeVector(0.,20.*cm,0.*cm),h8500,"PMT5",fExperimentalHall_log,false,4);


fPmtPlaced=true;




/*Optical surfaces*/

/*The wrapping*/
G4OpticalSurface* Scint_opsurf=new G4OpticalSurface("scint_opsurf",glisur,groundfrontpainted,dielectric_dielectric);
Scint_opsurf->SetSigmaAlpha(.1);	
G4MaterialPropertiesTable* ScintSurf_mt = new G4MaterialPropertiesTable();
const G4int numScintSurf=2;
G4double ePhotonScintSurf[numScintSurf]={1.,10.};
//G4double ScintSurfRI[numScintSurf]={1.4,1.5};
G4double ScintSurfReflectivity[numScintSurf]={fWrappingR,fWrappingR};
G4double ScintSurfSpecularLobe[numScintSurf]={0.,0.};
G4double ScintSurfSpecularSpike[numScintSurf]={0.,0.};
G4double ScintSurfBackScatter[numScintSurf]={0.,0.};
//ScintSurf_mt->AddProperty("RINDEX",ePhotonScintSurf,ScintSurfRI,numScintSurf);
ScintSurf_mt->AddProperty("REFLECTIVITY",ePhotonScintSurf,ScintSurfReflectivity,numScintSurf);
ScintSurf_mt->AddProperty("SPECULARLOBECONSTANT",ePhotonScintSurf,ScintSurfSpecularLobe,numScintSurf);
ScintSurf_mt->AddProperty("SPECULARSPIKECONSTANT",ePhotonScintSurf,ScintSurfSpecularSpike,numScintSurf);
ScintSurf_mt->AddProperty("BACKSCATTERCONSTANT",ePhotonScintSurf,ScintSurfBackScatter,numScintSurf);
Scint_opsurf->SetMaterialPropertiesTable(ScintSurf_mt);
/*Create logical skin surfaces*/
for (int ii=0;ii<6;ii++)	new G4LogicalBorderSurface(Form("scint_surf_%i",ii),Scintillator_phys,fAround_phys[ii],Scint_opsurf);

/*The detectors*/
G4OpticalSurface* Detector_opsurf;
G4MaterialPropertiesTable* Detector_opsurf_mt;
for (int ii=0;ii<6;ii++){
  Detector_opsurf=new G4OpticalSurface(Form("detector_opsurf_%i",ii),glisur,polished,dielectric_metal);
  Detector_opsurf_mt = new G4MaterialPropertiesTable();
  const G4int numDetSurf=2;
  G4double ePhotonDetSurf[numDetSurf]={1.,10.};
  
  G4double DetectorSurfReflectivity[numDetSurf]={fPhotoR[ii],fPhotoR[ii]};
  G4double DetectorSurfEfficiency[numDetSurf]={fPhotoQE[ii]/(1-fPhotoR[ii]),fPhotoQE[ii]/(1-fPhotoR[ii])};    //QE=(1-R)*efficiency
  
  Detector_opsurf_mt->AddProperty("REFLECTIVITY",ePhotonDetSurf,DetectorSurfReflectivity,numDetSurf);
  Detector_opsurf_mt->AddProperty("EFFICIENCY",ePhotonDetSurf,DetectorSurfEfficiency,numDetSurf);
  Detector_opsurf->SetMaterialPropertiesTable(Detector_opsurf_mt);	
  new G4LogicalSkinSurface(Form("detector_surf_%i",ii),fPixel_log[ii],Detector_opsurf);  //The detector: a skin surface
  
}
/*Set the step limit in the scintillator*/
/*fStepLimit = new G4UserLimits(fMaxStep);
Scintillator_log->SetUserLimits(fStepLimit);*/

return fExperimentalHall_phys;
}


void OpNoviceDetectorConstruction::DefineMaterials(){
  G4cout<<"OpNoviceDetectorConstruction::DefineMaterials() was called"<<G4endl;
  G4double a;  // atomic mass
  G4double z;  // atomic number
  G4double density;
  
  
  
  //***Elements
  fH = new G4Element("H","H", z=1., a=1.01*g/mole);
  fB = new G4Element("B","B",z=5., a=10.811*g/mole); 
  fC = new G4Element("C","C", z=6., a=12.01*g/mole);
  fN = new G4Element("N","N", z=7., a= 14.01*g/mole);
  fO = new G4Element("O","O", z=8., a= 16.00*g/mole);
  fNa= new G4Element("Na","Na",z=11.,a=22.989*g/mole);
  fAl = new G4Element("Al","Al",z=13.,a=26.981*g/mole);
  fSi = new G4Element("Si","Si",z=14.,a=28.0855*g/mole);
  fK = new G4Element("K","K",z=19.,a=39.0983*g/mole);
  
  
  
  //Vacuum
  fVacuum = new G4Material("Vacuum",z=1.,a=1.01*g/mole,
  density=universe_mean_density,kStateGas,0.1*kelvin,
  1.e-19*pascal);
  //Air
  fAir = new G4Material("Air", density= 1.29*mg/cm3, 2);
  fAir->AddElement(fN, 70*perCent);
  fAir->AddElement(fO, 30*perCent);
  
  
  //The coupling material.
  //Note that the critical properties of this material are mainly "collapsed" in the refraction index...
  //so I put it as "water", with density=1.
  const int numCouplingRindex=2;
  
  for (int ii=0;ii<6;ii++){
    fCoupling[ii] = new G4Material(Form("CouplingMaterial_%i",ii),density=1.*g/cm3,2);
    fCoupling[ii]->AddElement(fH, 2);
    fCoupling[ii]->AddElement(fO, 1);
    
    //coupling material		
    G4double eCouplingRindex[numCouplingRindex]={1*eV,10*eV};
    G4double CouplingRindex[numCouplingRindex]={fCouplingN[ii],fCouplingN[ii]};
    
    G4MaterialPropertiesTable* fCoupling_mt = new G4MaterialPropertiesTable();
    fCoupling_mt->AddProperty("RINDEX",eCouplingRindex,CouplingRindex,numCouplingRindex);
    fCoupling[ii]->SetMaterialPropertiesTable(fCoupling_mt);
    
  }
  
  //Properties tables
  
  //vacuum
  G4double vacuum_Energy[]={1.0*eV,10.0*eV};
  const G4int vacnum = sizeof(vacuum_Energy)/sizeof(G4double);
  G4double vacuum_RIND[]={1.,1.};
  assert(sizeof(vacuum_RIND) == sizeof(vacuum_Energy));
  G4MaterialPropertiesTable *vacuum_mt = new G4MaterialPropertiesTable();
  vacuum_mt->AddProperty("RINDEX", vacuum_Energy, vacuum_RIND,vacnum);
  fVacuum->SetMaterialPropertiesTable(vacuum_mt);
  
  //air
  fAir->SetMaterialPropertiesTable(vacuum_mt);//Give air the same rindex
  
  
  
  
  //build the EJ230 scintillator material
  makeEJ230();
  
}



void OpNoviceDetectorConstruction::ConstructSDandField() {
  
  if (!fExperimentalHall_phys) return;
  if (!fPmtPlaced) return;
  
  
  // PMT SD
  
  if (!fPmt_SD.Get()) {
    //Created here so it exists as pmts are being placed
    G4cout << "Construction /OpNoviceDet/pmtSD" << G4endl;
    OpNovicePMTSD* pmt_SD = new OpNovicePMTSD("/OpNoviceDet/pmtSD");
    fPmt_SD.Put(pmt_SD);
    
    pmt_SD->InitPMTs(2); //let pmtSD know # of pmts
    // pmt_SD->SetPmtPositions(fMainVolume->GetPmtPositions());
  }
  
  //sensitive detector is not actually on the photocathode.
  //processHits gets done manually by the stepping action.
  //It is used to detect when photons hit and get absorbed&detected at the
  //boundary to the photocathode (which doesnt get done by attaching it to a
  //logical volume.
  //It does however need to be attached to something or else it doesnt get
  //reset at the begining of events
  
  /*If I attach it to the photocathode, the G4OpBoundary process will see it, and call 
  the ProcessHits method, that is actually doing nothing.
  The OpNoviceStepping action is calling instead ProcessHits_conststep, that is doing the real record*/
  
  /*for (int ii=0;ii<6;ii++){
  if (fDetector_log[ii])	SetSensitiveDetector(fDetector_log[ii], fPmt_SD.Get());
  }*/
  
  SetSensitiveDetector(fDummy_log, fPmt_SD.Get());
  
  
  }
  
  
  
  
  
  
  
  
  
  
  
  
  void OpNoviceDetectorConstruction::SetDefaults() {
    
    //Resets to default values
    fExpHall_x = fExpHall_y = fExpHall_z = 50.0*cm;
    
    
    fScint_x = 6.*cm;
    fScint_y = 6.*cm;
    fScint_z = 6.*cm;
    
    for (int ii=0;ii<6;ii++){
      fCouplingThickness[ii]=1.*mm;	
      fCouplingN[ii]=1.5;	
      fPhotoDetectorSizeX[ii]=5.*cm;
      fPhotoDetectorSizeY[ii]=5.*cm;	
      fPhotoQE[ii]=0.2;
      fPhotoR[ii]=0.1;
      
      fNPixelsX[ii]=1;
      fNPixelsY[ii]=1;
      
      fPixelSizeX[ii]=fPhotoDetectorSizeX[ii];
      fPixelSizeY[ii]=fPhotoDetectorSizeY[ii];
    }
    
    
    /*EJ230*/
    fEJ230_LY=9700./MeV;            //from the datasheet
    fEJ230_FastTimeConstant=1.5*ns; //from the datasheet
    
    
    fPmtPlaced=false;
    /* 
    G4UImanager::GetUIpointer()
    ->ApplyCommand("/LXe/detector/scintYieldFactor 1.");
    
    if(fLXe_mt)fLXe_mt->AddConstProperty("SCINTILLATIONYIELD",12000./MeV);
    if(fMPTPStyrene)fMPTPStyrene->AddConstProperty("SCINTILLATIONYIELD",10./keV);
    */
    
    fMaxStep=0.5*mm;
    
    G4RunManager::GetRunManager()->ReinitializeGeometry();
  }
  
  
  
  
  
  
  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  
  void OpNoviceDetectorConstruction::makeEJ230(){
    
    /*Physical properties*/
    G4double density=1.023*g/cm3;
    G4double Hnum=5.15E22/cm3;
    G4double Cnum=4.69E22/cm3;
    G4double Hw=(Hnum*fH->GetA())/(Avogadro*density);
    G4double Cw=(Cnum*fC->GetA())/(Avogadro*density);
    
    const G4int numRI = 2;
    G4double ePhotonRI[numRI] = {1.*eV,10.*eV};
    G4double RI[numRI] = {1.58,1.58};
    G4double absLength[numRI] = {100.*cm,100.*cm}; //temporary
    
    const G4int numFastLY = 101;
    //as Reported in the datasheet
    G4double LambdaPhotLY[numFastLY] = {351.527*nm, 354.962*nm, 359.160*nm, 361.196*nm, 362.595*nm, 364.122*nm, 365.649*nm, 367.176*nm, 368.575*nm, 369.720*nm, 370.738*nm, 371.883*nm, 372.519*nm, 373.282*nm, 374.300*nm, 374.809*nm, 375.827*nm, 376.463*nm, 377.226*nm, 377.863*nm, 378.626*nm, 379.517*nm, 380.153*nm, 380.534*nm, 381.679*nm, 382.188*nm, 383.333*nm, 384.606*nm, 385.623*nm, 386.768*nm, 388.041*nm, 389.313*nm, 391.221*nm, 393.130*nm, 395.038*nm, 396.056*nm, 397.455*nm, 398.473*nm, 399.746*nm, 400.636*nm, 401.272*nm, 402.290*nm, 403.053*nm, 404.198*nm, 404.962*nm, 405.725*nm, 406.616*nm, 407.761*nm, 408.906*nm, 409.542*nm, 410.560*nm, 411.705*nm, 413.232*nm, 413.868*nm, 414.504*nm, 415.649*nm, 416.667*nm, 418.066*nm, 419.338*nm, 420.356*nm, 421.247*nm, 422.265*nm, 423.155*nm, 424.173*nm, 425.191*nm, 426.590*nm, 428.626*nm, 430.025*nm, 430.789*nm, 431.807*nm, 432.316*nm, 433.588*nm, 435.115*nm, 436.896*nm, 438.295*nm, 440.331*nm, 443.257*nm, 444.911*nm, 445.802*nm, 448.346*nm, 449.618*nm, 451.527*nm, 453.562*nm, 455.598*nm, 457.125*nm, 459.542*nm, 461.705*nm, 464.758*nm, 467.430*nm, 470.865*nm, 473.155*nm, 475.954*nm, 478.371*nm, 481.552*nm, 484.606*nm, 487.659*nm, 489.567*nm, 491.858*nm, 494.020*nm, 495.802*nm, 498.219*nm};
    G4double PhotLYFast[numFastLY] = {0.00881057, 0.0176211, 0.0396476, 0.0558003, 0.0734214, 0.0939794, 0.120411, 0.154185, 0.185022, 0.221733, 0.249633, 0.298091, 0.348018, 0.395007, 0.447871, 0.493392, 0.550661, 0.603524, 0.635830, 0.678414, 0.728341, 0.762115, 0.795888, 0.822320, 0.857562, 0.894273, 0.922173, 0.947137, 0.963289, 0.976505, 0.989721, 0.995595, 0.997063, 0.986784, 0.975037, 0.963289, 0.948605, 0.928047, 0.908957, 0.885463, 0.872247, 0.848752, 0.825257, 0.797357, 0.773862, 0.751836, 0.728341, 0.698972, 0.675477, 0.656388, 0.627019, 0.603524, 0.568282, 0.553598, 0.537445, 0.511013, 0.488987, 0.471366, 0.440529, 0.421439, 0.405286, 0.396476, 0.378855, 0.368576, 0.348018, 0.330396, 0.302496, 0.287812, 0.273128, 0.267254, 0.252570, 0.246696, 0.232012, 0.218796, 0.205580, 0.183554, 0.160059, 0.145374, 0.140969, 0.127753, 0.114537, 0.107195, 0.0969163, 0.0851689, 0.0792952, 0.0734214, 0.0646109, 0.0587372, 0.0543319, 0.0455213, 0.0440529, 0.0367107, 0.0352423, 0.0264317, 0.0220264, 0.0205580, 0.0176211, 0.0161527, 0.0146843, 0.0161527, 0.0146843};
    G4double ePhotonLY[numFastLY]; 
    for (int ii=0;ii<numFastLY;ii++) ePhotonLY[ii]=h_Planck*c_light/LambdaPhotLY[ii];
    
    
    
    
    /*Set Physical properties*/
    fEJ230=new G4Material("EJ230",density,2,kStateSolid);
    fEJ230->AddElement(fH,Hw);
    fEJ230->AddElement(fC,1.-Hw);	
    
    /*Create the propertie table and set it*/
    G4MaterialPropertiesTable* EJ230_mt = new G4MaterialPropertiesTable();
    
    EJ230_mt->AddProperty("RINDEX",ePhotonRI,RI,numRI);
    EJ230_mt->AddConstProperty("SCINTILLATIONYIELD",fEJ230_LY);
    EJ230_mt->AddConstProperty("FASTTIMECONSTANT",fEJ230_FastTimeConstant);
    EJ230_mt->AddConstProperty("RESOLUTIONSCALE",1.); //this is to broaden the number of optical photons : scale*sqrt(mean_photons)
    EJ230_mt->AddProperty("FASTCOMPONENT",ePhotonLY,PhotLYFast,numFastLY);
    
    EJ230_mt->AddProperty("ABSLENGTH",ePhotonRI,absLength,numRI);
    
    fEJ230->SetMaterialPropertiesTable(EJ230_mt);
    }
    
    
    
    
    
    
    G4bool OpNoviceDetectorConstruction::isDetPresent(int ii){
      G4bool ret=true;
      if (fPhotoDetectorSizeX[ii]<=0) ret=false;
      if (fPhotoDetectorSizeY[ii]<=0) ret=false;
      return ret;    
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    