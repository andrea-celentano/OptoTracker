#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro245.run
mv run_245_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(245\) 
mv run245.ps matrix0/ps
mv run245.out matrix0/pixels
cd ..
