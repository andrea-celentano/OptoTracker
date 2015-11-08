#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro184.run
mv run_184_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(184\) 
mv run184.ps matrix0/ps
mv run184.out matrix0/pixels
cd ..
