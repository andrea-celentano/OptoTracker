#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro941.run
mv run_941_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(941\) 
mv run941.ps matrix0/ps
mv run941.out matrix0/pixels
cd ..
