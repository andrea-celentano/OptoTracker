#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro878.run
mv run_878_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(878\) 
mv run878.ps matrix0/ps
mv run878.out matrix0/pixels
cd ..
