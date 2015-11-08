#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro9.run
mv run_9_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(9\) 
mv run9.ps matrix0/ps
mv run9.out matrix0/pixels
cd ..
