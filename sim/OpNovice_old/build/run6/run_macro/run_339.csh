#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro339.run
mv run_339_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(339\) 
mv run339.ps matrix0/ps
mv run339.out matrix0/pixels
cd ..