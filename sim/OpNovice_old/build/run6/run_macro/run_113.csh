#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro113.run
mv run_113_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(113\) 
mv run113.ps matrix0/ps
mv run113.out matrix0/pixels
cd ..
