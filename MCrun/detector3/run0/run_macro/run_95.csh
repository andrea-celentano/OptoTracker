#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/run0/run_macro/macro95.run -det PrototypeGeometry.dat
mv run_95_0.root run0/root 
cd run0
cd ..
