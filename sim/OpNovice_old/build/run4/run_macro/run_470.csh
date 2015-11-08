#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro470.run
mv run_470_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(470\) 
mv run470.ps matrix0/ps
mv run470.out matrix0/pixels
cd ..
