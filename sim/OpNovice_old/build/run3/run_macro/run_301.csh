#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro301.run
mv run_301_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(301\) 
mv run301.ps matrix0/ps
mv run301.out matrix0/pixels
cd ..
