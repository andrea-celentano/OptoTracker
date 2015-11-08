#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro591.run
mv run_591_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(591\) 
mv run591.ps matrix0/ps
mv run591.out matrix0/pixels
cd ..
