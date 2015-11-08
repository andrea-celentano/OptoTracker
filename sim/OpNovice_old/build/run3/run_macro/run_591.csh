#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro591.run
mv run_591_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(591\) 
mv run591.ps matrix0/ps
mv run591.out matrix0/pixels
cd ..
