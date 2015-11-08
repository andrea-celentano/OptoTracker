#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro878.run
mv run_878_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(878\) 
mv run878.ps matrix0/ps
mv run878.out matrix0/pixels
cd ..
