#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclasses;

#pragma link C++ class G4VHit+;
#pragma link C++ class OpNoviceScintHit+;

#pragma link C++ class OpNoviceDetectorHit+;
#pragma link C++ class G4VDigi+;

#pragma link C++ class OpNoviceDigi+;
#pragma link C++ class CLHEP::Hep3Vector+;
/*
<class name="G4VHit"/>
<class name="OpNoviceScintHit">
	<field name="fPhysVol" transient="true"/>
</class>



<class name="OpNoviceDetectorHit">
	<field name="fPhysVolMother" transient="true"/>
	<field name="fPhysVol" transient="true"/>
</class>


<class name="G4VDigi"/>
<class name="OpNoviceDigi">
	<field name="fPhysVolMother" transient="true"/>
	<field name="fPhysVol" transient="true"/>
</class>





*/









#endif
