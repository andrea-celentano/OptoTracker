#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro587.run
mv run_587_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(587\) 
mv run587.ps matrix0/ps
mv run587.out matrix0/pixels
cd ..
