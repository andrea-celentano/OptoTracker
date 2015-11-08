#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro254.run
mv run_254_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(254\) 
mv run254.ps matrix0/ps
mv run254.out matrix0/pixels
cd ..
