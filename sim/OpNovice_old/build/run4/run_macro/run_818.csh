#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro818.run
mv run_818_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(818\) 
mv run818.ps matrix0/ps
mv run818.out matrix0/pixels
cd ..
