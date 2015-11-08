#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run5/run_macro/macro23.run
mv run_23_0.root run5/root 
cd run5
root -l -q -b  ../doPixels.C\(23\) 
mv run23.ps matrix0/ps
mv run23.out matrix0/pixels
cd ..
