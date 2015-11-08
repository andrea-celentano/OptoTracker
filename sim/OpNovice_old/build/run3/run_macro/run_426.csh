#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro426.run
mv run_426_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(426\) 
mv run426.ps matrix0/ps
mv run426.out matrix0/pixels
cd ..
