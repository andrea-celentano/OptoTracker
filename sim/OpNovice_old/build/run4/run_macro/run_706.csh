#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro706.run
mv run_706_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(706\) 
mv run706.ps matrix0/ps
mv run706.out matrix0/pixels
cd ..
