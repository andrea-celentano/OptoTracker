#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro648.run
mv run_648_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(648\) 
mv run648.ps matrix0/ps
mv run648.out matrix0/pixels
cd ..
