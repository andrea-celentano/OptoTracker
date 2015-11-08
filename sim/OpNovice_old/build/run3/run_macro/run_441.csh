#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro441.run
mv run_441_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(441\) 
mv run441.ps matrix0/ps
mv run441.out matrix0/pixels
cd ..
