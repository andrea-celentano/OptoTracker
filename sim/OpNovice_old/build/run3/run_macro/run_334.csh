#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro334.run
mv run_334_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(334\) 
mv run334.ps matrix0/ps
mv run334.out matrix0/pixels
cd ..
