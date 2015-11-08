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

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceDetectorConstruction::OpNoviceDetectorConstruction()
 : G4VUserDetectorConstruction()
{
  fDetectorMessenger=new OpNoviceDetectorMessenger(this);
  SetDefaults();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceDetectorConstruction::~OpNoviceDetectorConstruction(){;}

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

	//First, create the logical volume
	G4LogicalVolume* h8500=buildH8500();
	//assign the surface properties
	H8500SurfaceProperties();
	
	
	
	G4double deltaScint = 1*mm;
	// The Scintillator
	G4Box* Scintillator_box = new G4Box("Scintillator",fScint_x/2,fScint_y/2,fScint_z/2);
	G4LogicalVolume* Scintillator_log = new G4LogicalVolume(Scintillator_box,fEJ230,"Scintillator",0,0,0);
	G4VPhysicalVolume* Scintillator_phys = new G4PVPlacement(0,G4ThreeVector(),Scintillator_log,"Scintillator",fExperimentalHall_log,false,0);

	
   
      
	
	//Create "dummy" volumes around the scintillator to define the optical properties of the surfaces
	
	//Top and bottom (+Y and -Y), we do not have PMTs here
	G4Box* Scintillator_box_Y = new G4Box("Scintillator_Y",fScint_x/2,deltaScint/2,fScint_z/2);
	G4LogicalVolume* Scintillator_log_Y = new G4LogicalVolume(Scintillator_box_Y,fAir,"Scintillator_Y",0,0,0);
	G4VPhysicalVolume* Scintillator_phys_Ytop = new G4PVPlacement(0,G4ThreeVector(0.,(fScint_y+deltaScint)/2,0.),Scintillator_log_Y,"Scintillator_Yt",fExperimentalHall_log,false,0);
	G4VPhysicalVolume* Scintillator_phys_Ybot = new G4PVPlacement(0,G4ThreeVector(0.,-(fScint_y+deltaScint)/2,0.),Scintillator_log_Y,"Scintillator_Yb",fExperimentalHall_log,false,1);
	
	//X, subtract PMT
	G4Box* Scintillator_box_X0 = new G4Box("Scintillator_X0",deltaScint/2,fScint_y/2,fScint_z/2);
	G4Box* Scintillator_box_X1 = new G4Box("Scintillator_X1",deltaScint,fH8500box_x/2,fH8500box_y/2);
	G4SubtractionSolid *Scintillator_box_X = new G4SubtractionSolid("Scintillator_X",Scintillator_box_X0,Scintillator_box_X1);
	G4LogicalVolume* Scintillator_log_X = new G4LogicalVolume(Scintillator_box_X,fAir,"Scintillator_X",0,0,0);
	G4LogicalVolume* Scintillator_log_X1 = new G4LogicalVolume(Scintillator_box_X0,fAir,"Scintillator_X",0,0,0);

	//-X
	//G4VPhysicalVolume* Scintillator_phys_Xtop = new G4PVPlacement(0,G4ThreeVector(-(fScint_x+deltaScint)/2.,0.,0.),Scintillator_log_X,"Scintillator_Xt",fExperimentalHall_log,false,0);
	G4VPhysicalVolume* Scintillator_phys_Xtop = new G4PVPlacement(0,G4ThreeVector(-(fScint_x+deltaScint)/2.,0.,0.),Scintillator_log_X1,"Scintillator_Xt",fExperimentalHall_log,false,0);
	//+X, 	
	//G4VPhysicalVolume* Scintillator_phys_Xbot = new G4PVPlacement(0,G4ThreeVector(+(fScint_x+deltaScint)/2.,0.,0.),Scintillator_log_X,"Scintillator_Xb",fExperimentalHall_log,false,0);
	G4VPhysicalVolume* Scintillator_phys_Xbot = new G4PVPlacement(0,G4ThreeVector(+(fScint_x+deltaScint)/2.,0.,0.),Scintillator_log_X1,"Scintillator_Xb",fExperimentalHall_log,false,0);

	//Z, subtract PMT
	G4Box* Scintillator_box_Z0 = new G4Box("Scintillator_Z0",fScint_x/2,fScint_y/2,deltaScint/2);
	G4Box* Scintillator_box_Z1 = new G4Box("Scintillator_Z1",fH8500box_x/2,fH8500box_y/2,deltaScint);
	G4SubtractionSolid *Scintillator_box_Z = new G4SubtractionSolid("Scintillator_Z",Scintillator_box_Z0,Scintillator_box_Z1);
	G4LogicalVolume* Scintillator_log_Z = new G4LogicalVolume(Scintillator_box_Z,fAir,"Scintillator_Z",0,0,0);

	//-Z
	G4VPhysicalVolume* Scintillator_phys_Ztop = new G4PVPlacement(0,G4ThreeVector(0.,0.,(fScint_z+deltaScint)/2.),Scintillator_log_Z,"Scintillator_Zt",fExperimentalHall_log,false,0);
	//+Z, 	
	G4VPhysicalVolume* Scintillator_phys_Zbot = new G4PVPlacement(0,G4ThreeVector(0.,0.,-(fScint_z+deltaScint)/2.),Scintillator_log_Z,"Scintillator_Zb",fExperimentalHall_log,false,0);
	
	
	
	
	
	
	
	
	//Place the PMTs
	
	//Then place it (with replicas)
	G4RotationMatrix* yRot_1=new G4RotationMatrix;
	yRot_1->rotateY(M_PI*rad);	             	
	G4VPhysicalVolume* h8500_phys1 = new G4PVPlacement(yRot_1,G4ThreeVector(0.,0.,(fScint_z+fH8500box_z)/2.),h8500,"PMT1",fExperimentalHall_log,false,0);
	
	G4RotationMatrix* yRot_2=new G4RotationMatrix;
	yRot_2->rotateY(M_PI/2.*rad);	             	
	//G4VPhysicalVolume* h8500_phys2 = new G4PVPlacement(yRot_2,G4ThreeVector((fScint_x+fH8500box_z)/2.,0.*cm,0.*cm),h8500,"PMT2",fExperimentalHall_log,false,1);	
	
	G4VPhysicalVolume* h8500_phys3 = new G4PVPlacement(0,G4ThreeVector(0.*cm,0.*cm,-(fScint_z+fH8500box_z)/2.),h8500,"PMT3",fExperimentalHall_log,false,2);
	
	G4RotationMatrix* yRot_4=new G4RotationMatrix;
	yRot_4->rotateY(-M_PI/2.*rad);	
	//	G4VPhysicalVolume* h8500_phys4 = new G4PVPlacement(yRot_4,G4ThreeVector(-(fScint_x+fH8500box_z)/2.,0.*cm,0.*cm),h8500,"PMT4",fExperimentalHall_log,false,3);
	
	
	
	//G4VPhysicalVolume* h8500_phys5 = new G4PVPlacement(yRot_4,G4ThreeVector(0.,20.*cm,0.*cm),h8500,"PMT5",fExperimentalHall_log,false,4);
	
	
        fPmtPlaced=true;


	
	
	/*Optical surfaces*/
	G4OpticalSurface* Scint_opsurf=new G4OpticalSurface("scint_opsurf",glisur,groundbackpainted,dielectric_dielectric);
	Scint_opsurf->SetSigmaAlpha(.1);
	
	G4MaterialPropertiesTable* ScintSurf_mt = new G4MaterialPropertiesTable();
	const G4int numScintSurf=2;
	G4double ePhotonScintSurf[numScintSurf]={1.,10.};
	G4double ScintSurfRI[numScintSurf]={1.4,1.5};
	G4double ScintSurfReflectivity[numScintSurf]={0.2,0.2};
	G4double ScintSurfSpecularLobe[numScintSurf]={0.,0.};
	G4double ScintSurfSpecularSpike[numScintSurf]={0.,0.};
	G4double ScintSurfBackScatter[numScintSurf]={0.,0.};
	
	
	ScintSurf_mt->AddProperty("RINDEX",ePhotonScintSurf,ScintSurfRI,numScintSurf);
	ScintSurf_mt->AddProperty("REFLECTIVITY",ePhotonScintSurf,ScintSurfReflectivity,numScintSurf);
	ScintSurf_mt->AddProperty("SPECULARLOBECONSTANT",ePhotonScintSurf,ScintSurfSpecularLobe,numScintSurf);
	ScintSurf_mt->AddProperty("SPECULARSPIKECONSTANT",ePhotonScintSurf,ScintSurfSpecularSpike,numScintSurf);
	ScintSurf_mt->AddProperty("BACKSCATTERCONSTANT",ePhotonScintSurf,ScintSurfBackScatter,numScintSurf);
	
	Scint_opsurf->SetMaterialPropertiesTable(ScintSurf_mt);
	
	//**Create logical skin surfaces
	new G4LogicalBorderSurface("scint_surf",Scintillator_phys,Scintillator_phys_Ytop,Scint_opsurf);
	new G4LogicalBorderSurface("scint_surf",Scintillator_phys,Scintillator_phys_Ybot,Scint_opsurf);
	new G4LogicalBorderSurface("scint_surf",Scintillator_phys,Scintillator_phys_Xtop,Scint_opsurf);
	new G4LogicalBorderSurface("scint_surf",Scintillator_phys,Scintillator_phys_Xbot,Scint_opsurf);
	new G4LogicalBorderSurface("scint_surf",Scintillator_phys,Scintillator_phys_Ztop,Scint_opsurf);
	new G4LogicalBorderSurface("scint_surf",Scintillator_phys,Scintillator_phys_Zbot,Scint_opsurf);
	
	
	/*Set the step limit in the scintillator*/
	fStepLimit = new G4UserLimits(fMaxStep);
	Scintillator_log->SetUserLimits(fStepLimit);
	
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
	


	//H8500 Glass
	fH8500GlassWindow=new G4Material("H8500GlassWindow",2.23*g/cm3, 6);
	fH8500GlassWindow->AddElement(fB,0.040064);
	fH8500GlassWindow->AddElement(fO,0.539562);
	fH8500GlassWindow->AddElement(fNa,0.028191);
	fH8500GlassWindow->AddElement(fAl,0.011644);
	fH8500GlassWindow->AddElement(fSi,0.377220);
	fH8500GlassWindow->AddElement(fK,0.003321);

	
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

	//PMT glass
	/*http://refractiveindex.info/?shelf=glass&book=HIKARI-BK&page=E-BK7*/
	const int numGlassRindex=16;
	G4double lambdaGlassRindex[numGlassRindex]={0.280*um, 0.301*um, 0.322*um, 0.343*um, 0.364*um, 0.386*um, 0.407*um, 0.428*um, 0.449*um, 0.470*um, 0.492*um, 0.513*um, 0.534*um, 0.555*um, 0.576*um, 0.598*um};
	G4double eGlassRindex[numGlassRindex];
	for (int ii=0;ii<numGlassRindex;ii++) eGlassRindex[ii]=h_Planck*c_light/lambdaGlassRindex[ii];
	G4double GlassRindex[numGlassRindex]={1.559270391734, 1.5517282889676, 1.5455412428539, 1.5404772727192, 1.5363084676414, 1.5328456722088, 1.5299403818291, 1.527478148734, 1.5253710432964, 1.5235512346146, 1.5219660054967, 1.5205740166685, 1.5193425426726, 1.5182454307052, 1.5172615878831, 1.5163738528142};
	G4MaterialPropertiesTable* fH8500GlassWindow_mt = new G4MaterialPropertiesTable();
	fH8500GlassWindow_mt ->AddProperty("RINDEX",eGlassRindex,GlassRindex,numGlassRindex);
	fH8500GlassWindow->SetMaterialPropertiesTable(fH8500GlassWindow_mt);
	
	
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
  
  SetSensitiveDetector(H8500Photo_log, fPmt_SD.Get());





}












void OpNoviceDetectorConstruction::SetDefaults() {
	
	//Resets to default values
	fExpHall_x = fExpHall_y = fExpHall_z = 50.0*cm;
	
	
	fScint_x = 6.*cm;
	fScint_y = 6.*cm;
	fScint_z = 6.*cm;
	/*
	fScint_x = 5.2*cm;
	fScint_y = 5.2*cm;
	fScint_z = 5.2*cm;
	*/
	
	
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

void OpNoviceDetectorConstruction::SetDimensions(G4ThreeVector dims) {
	
	this->fScint_x=dims[0];
	this->fScint_y=dims[1];
	this->fScint_z=dims[2];
	
	G4RunManager::GetRunManager()->ReinitializeGeometry(true);
}



G4LogicalVolume* OpNoviceDetectorConstruction::buildH8500(){
	//This is the function to create the H8500 logical, including all the sub-components
	//Construct it so that the glass is at z=const, in the xy plane, and the glass starts at z=+14*mm
	//First, build the box
	fH8500box_x=52*mm;
	fH8500box_y=52*mm;
	fH8500box_z=28*mm;	
	H8500_box = new G4Box("H8500Box",fH8500box_x/2,fH8500box_y/2,fH8500box_z/2);
	G4LogicalVolume* H8500_log = new G4LogicalVolume(H8500_box,fAir,"H8500Box",0,0,0);
	
	//Then, build the internal glass, that is active (photocathode is deposited on it)
	G4double int_glass_x=51.5*mm;
	G4double int_glass_y=51.5*mm;
	G4double int_glass_z=1.5*mm;
	G4Box *H8500IntGlass_box = new G4Box("H8500GlassInt",int_glass_x/2,int_glass_y/2,int_glass_z/2);
	H8500IntGlass_log = new G4LogicalVolume(H8500IntGlass_box,fH8500GlassWindow,"H8500GlassInt",0,0,0);
	//place it wrt the mother
	H8500IntGlass_phys = new G4PVPlacement(0,G4ThreeVector(0.,0.,fH8500box_z/2-int_glass_z/2),H8500IntGlass_log,"H8500GlassInt",H8500_log,false,0);
	//visual attributes
	G4VisAttributes* VisAtt1 = new G4VisAttributes(G4Colour(0.,1.,1.,.6));
	VisAtt1->SetForceSolid(true);
	H8500IntGlass_log->SetVisAttributes(VisAtt1);
	
	//Then, build the external glass, not active
	G4double ext_glass_x=52*mm;
	G4double ext_glass_y=52*mm;
	G4double ext_glass_z=1.5*mm;
	
	G4Box *H8500SubtractionGlass_box1 = new G4Box("H8500SubtractionGlass1",ext_glass_x/2,ext_glass_y/2,ext_glass_z/2);
	G4Box *H8500SubtractionGlass_box2 = new G4Box("H8500SubtractionGlass2",int_glass_x/2,int_glass_y/2,int_glass_z); //should be int_glass_z/2, but this helps the subtraction	
	G4SubtractionSolid* H8500ExtGlass_box=new G4SubtractionSolid("H8500GlassExt",H8500SubtractionGlass_box1,H8500SubtractionGlass_box2);
	
	//smooth it
	
		
	G4SubtractionSolid* H8500ExtGlass=H8500ExtGlass_box;
	G4LogicalVolume* H8500ExtGlass_log = new G4LogicalVolume(H8500ExtGlass,fH8500GlassWindow,"H8500GlassExt",0,0,0);
	//place it wrt the mother
	G4VPhysicalVolume* H8500ExtGlass_phys = new G4PVPlacement(0,G4ThreeVector(0.,0.,fH8500box_z/2-ext_glass_z/2),H8500ExtGlass_log,"H8500GlassExt",H8500_log,false,0);
	//visual attributes
	G4VisAttributes* VisAtt2 = new G4VisAttributes(G4Colour(0.,.4,.6,.6));
	VisAtt2->SetForceSolid(true);
	H8500ExtGlass_log->SetVisAttributes(VisAtt2);
	
	//Then build the photo-cathode, that it is used only for the surface.
	G4double photo_x= int_glass_x;
	G4double photo_y= int_glass_y;
	G4double photo_z=.1*mm;
	
	G4Box *H8500Photo_box=new G4Box("H8500Photocathode",photo_x/2,photo_y/2,photo_z/2); 
	H8500Photo_log = new G4LogicalVolume(H8500Photo_box,fAir,"H8500Photocathode",0,0,0); //material is irrelevant, since I define surface properties!
	H8500Photo_phys= new G4PVPlacement(0,G4ThreeVector(0.,0.,fH8500box_z/2-int_glass_z-photo_z/2),H8500Photo_log,"H8500Photocathode",H8500_log,false,0);
	G4VisAttributes* VisAtt3 = new G4VisAttributes(G4Colour(0.5,0.5,0.5));
	VisAtt3->SetForceSolid(true);
	H8500Photo_log->SetVisAttributes(VisAtt3);
	
	//draw a marker on the first pixel to mark it!
	G4Box *H8500Marker=new G4Box("H8500Marker",2*mm,0.2*mm,0.2*mm);
	G4LogicalVolume *H8500Marker_log=new G4LogicalVolume(H8500Marker,fVacuum,"h8500Marker",0,0,0);
	new G4PVPlacement(0,G4ThreeVector(-6.125*mm*3.5,-6.125*mm*3.5,fH8500box_z/2-int_glass_z-photo_z-0.1*mm),H8500Marker_log,"H8500PhotoMarker",H8500_log,false,0);
	G4VisAttributes* VisAtt4 = new G4VisAttributes(G4Colour(0.,0.,0.));
	VisAtt4->SetForceSolid(true);
	H8500Marker_log->SetVisAttributes(VisAtt4);
	
	/*
	
	//Then build the pixels 
	double photo_z=0.5*mm;
	double photo_x=5.8*mm; //pixel effective area
	double photo_y=5.8*mm; //pixel effective area
	double photo_border=3*mm;
	int npixel=0;
	double xp,yp;
	double x0,y0;
	double deltaPixel=6.125*mm;
	x0=-deltaPixel*3.5;
	y0=-deltaPixel*3.5;
	//external border, 1.5mm all sides.
	G4Box *H8500PhotoAll_box1=new G4Box("H8500PhotoAll1",glass_x/2,glass_y/2,photo_z/2);
	G4Box *H8500PhotoAll_box2=new G4Box("H8500PhotoAll2",(glass_x-photo_border)/2,(glass_y-photo_border)/2,photo_z); //should be photo_z/2, but this helps the subtraction
	
	G4LogicalVolume* H8500PhotoExt_log = new G4LogicalVolume(H8500PhotoExt,fAir,"H8500PhotoBorderExt",0,0,0);
	
	//place it wrt the mother
	G4VPhysicalVolume* H8500PhotoExt_phys = new G4PVPlacement(0,G4ThreeVector(0.,0.,fH8500box_z/2-glass_z-photo_z/2),H8500PhotoExt_log,"H85000PhotoBorderExt",H8500_log,false,0);
	//visual attributes
	G4VisAttributes* VisAtt2 = new G4VisAttributes(G4Colour(0.5,0.5,0.5));
	VisAtt2->SetForceSolid(true);
	H8500PhotoExt_log->SetVisAttributes(VisAtt2);
	
	//build the photo_cathods
	G4VisAttributes* VisAtt3 = new G4VisAttributes(G4Colour(0.2,0.5,0.6));
	VisAtt3->SetForceSolid(true);
	G4Box *H8500PhotoPixel_box=new G4Box("H8500Pixel",photo_x/2,photo_y/2,photo_z/2); 
	H8500PhotoPixel_log = new G4LogicalVolume(H8500PhotoPixel_box,fAir,"H8500PhotoPixel",0,0,0);
	H8500PhotoPixel_log->SetVisAttributes(VisAtt3);
	//mark pixels with ii,jj.ii is along X, jj is along Y in the mother frame
	
	for (int ii=0;ii<8;ii++){
		for (int jj=0;jj<8;jj++){
			xp=y0+jj*deltaPixel;
			yp=x0+ii*deltaPixel;
			new G4PVPlacement(0,G4ThreeVector(xp,yp,fH8500box_z/2-glass_z-photo_z/2),H8500PhotoPixel_log,Form("H85000PhotoPixel_%i",npixel),H8500_log,false,npixel++);
		}
	}
		
	
	*/
	return H8500_log;
}


void OpNoviceDetectorConstruction::H8500SurfaceProperties(){
	/*Here I set the H8500 surface properties*/
	//**Photocathode surface properties
	
	G4double thickness=20*nm;
	
	/*This is the photocathode EXTERNAL quantum efficiency,
	measured in AIR, with normal incidence*/
	const G4int numPhotocathEff = 75;
	G4double LambdaPhotocathEff[]={274.59518*nm, 278.73752*nm, 282.8772*nm, 287.535*nm, 294.25598*nm, 301.49377*nm, 311.82565*nm, 320.0877*nm, 326.79672*nm, 336.09033*nm, 347.9633*nm, 355.18576*nm, 364.4774*nm, 373.76703*nm, 384.0856*nm, 396.4727*nm, 404.7274*nm, 416.59436*nm, 423.81747*nm, 434.65085*nm, 442.38745*nm, 450.63882*nm, 458.89288*nm, 467.65842*nm, 474.87955*nm, 485.7069*nm, 492.92804*nm, 496.5356*nm, 502.2037*nm, 508.90405*nm, 511.99216*nm, 518.171*nm, 523.8318*nm, 527.9495*nm, 533.0988*nm, 538.2454*nm, 542.8779*nm, 549.5736*nm, 555.2364*nm, 560.38367*nm, 566.5665*nm, 572.7441*nm, 576.347*nm, 579.9466*nm, 584.0643*nm, 588.6981*nm, 590.7473*nm, 594.3502*nm, 596.4041*nm, 601.03125*nm, 604.1114*nm, 607.1982*nm, 609.2427*nm, 613.3591*nm, 617.99023*nm, 620.0321*nm, 624.14514*nm, 627.22125*nm, 631.83777*nm, 633.8783*nm, 637.9834*nm, 642.08844*nm, 642.5879*nm, 646.1821*nm, 647.1938*nm, 649.7584*nm, 653.35*nm, 656.42346*nm, 657.9499*nm, 662.0582*nm, 664.1048*nm, 667.69507*nm, 669.2161*nm, 670.73987*nm, 674.8502*nm};
	G4double ePhotocathEff[numPhotocathEff]; 
	for (int ii=0;ii<numPhotocathEff;ii++) ePhotocathEff[ii]=h_Planck*c_light/LambdaPhotocathEff[ii];
	/*This is the EXTERNAL QE, that accounts also for the reflectance in air*/
	
	/*	G4double PhotocathEff[numPhotocathEff]={13.586567,  15.345904,  16.915827,  18.990091,  21.059896,  23.497814,  25.585638,  26.534729,  26.370888,  27.18259,  27.6789,  26.845625,  27.170841,  27.002012,  26.028843,  26.023933,  25.240084,  24.329842,  23.741571,  22.608604,  21.53072,  20.255777,  19.52636,  18.037308,  17.282454,  15.579739,  14.927732,  14.216934,  13.053632,  11.985329,  11.072302,  9.682687,  8.314206,  7.4958334,  6.716867,  5.8739676,  5.2316213,  4.602951,  4.0252953,  3.5416696,  3.2124698,  2.775275,  2.5327923,  2.242155,  2.0214584,  1.8224705,  1.5841646,  1.4457523,  1.3114513,  1.1124817,  0.9552891,  0.87183,  0.72619474,  0.6467869,  0.56908214,  0.46260914,  0.3996638,  0.33087486,  0.25461057,  0.20446768,  0.16419475,  0.13185418,  0.113227755,  0.09546736,  0.079038285,  0.06828548,  0.056188624,  0.045397855,  0.037129875,  0.030738708,  0.026076145,  0.021196902,  0.016511882,  0.013179615,  0.011112233};
	for (int ii=0;ii<numPhotocathEff;ii++) PhotocathEff[ii]/=100.;
	*/
	
	/*This is the INTERNAL QE, derived by QE(ext)=QE(int)*ABSORBANCE  */
	G4double PhotocathEff[numPhotocathEff]={1.,1.,1., 0.895625, 0.696651, 0.625327, 0.566991, 0.536711, 0.506225, 0.495847, 0.484866, 0.463207, 0.463424, 0.458393, 0.442374, 0.445962, 0.436393, 0.427809, 0.422605, 0.411073, 0.39818, 0.382174, 0.376638, 0.356991, 0.350103, 0.328236, 0.32389, 0.313395, 0.295511, 0.280986, 0.264221, 0.240006, 0.214274, 0.199251, 0.186495, 0.171268, 0.160297, 0.153299, 0.145815, 0.140521, 0.146095, 0.150648, 0.157082, 0.162977, 0.188915, 0.258245, 0.297198, 0.656766,0, 0,0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,0, 0};
	
	
	//from NIM A 539 (2005) 217-235
	const G4int numPhotocathRI = 16;
	G4double LambdaPhotocathRI[numPhotocathRI] = {340*nm,380*nm,395*nm,410*nm,425*nm,440*nm,455*nm,470*nm,485*nm,500*nm,515*nm,530*nm,545*nm,560*nm,575*nm,590*nm};
	G4double ePhotocathRI[numPhotocathRI]; 
	for (int ii=0;ii<numPhotocathRI;ii++) ePhotocathRI[ii]=h_Planck*c_light/LambdaPhotocathRI[ii];
	
	//first is my extrapolation
	G4double PhotocathRIreal[numPhotocathRI]={1.4,1.92,2.18,2.38,2.61,2.70,2.87,3.00,3.00,3.00,3.09,3.26,3.2,3.12,3.06,3.01};
	G4double PhotocathRIimaginary[numPhotocathRI]={1.69,1.69,1.71,1.53,1.50,1.44,1.34,1.11,1.06,1.05,0.86,0.63,0.53,0.46,0.42};
		
	G4MaterialPropertiesTable* photocath_mt = new G4MaterialPropertiesTable();
	photocath_mt->AddProperty("EFFICIENCY",ePhotocathEff,PhotocathEff,numPhotocathEff);
	photocath_mt->AddProperty("REALRINDEX",ePhotocathRI,PhotocathRIreal,numPhotocathRI);
	photocath_mt->AddProperty("IMAGINARYRINDEX",ePhotocathRI,PhotocathRIimaginary,numPhotocathRI);
	photocath_mt->AddConstProperty("THICKNESS",thickness);
	
	
	G4OpticalSurface* photocath_opsurf=
	new G4OpticalSurface("photocath_opsurf",glisur,polished,
				dielectric_metal);
	photocath_opsurf->SetMaterialPropertiesTable(photocath_mt);
	
	//**Create logical skin surfaces
	new G4LogicalBorderSurface("photocath_surf",H8500IntGlass_phys,H8500Photo_phys,photocath_opsurf);
	
	
	/*The portion of the glass not in contact with the photo-cathode*/
	
	
	
	
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


