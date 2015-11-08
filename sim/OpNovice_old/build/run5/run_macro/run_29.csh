#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run5/run_macro/macro29.run
mv run_29_0.root run5/root 
cd run5
root -l -q -b  ../doPixels.C\(29\) 
mv run29.ps matrix0/ps
mv run29.out matrix0/pixels
cd ..
