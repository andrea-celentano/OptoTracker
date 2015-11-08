#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro872.run
mv run_872_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(872\) 
mv run872.ps matrix0/ps
mv run872.out matrix0/pixels
cd ..
