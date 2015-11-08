#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro170.run
mv run_170_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(170\) 
mv run170.ps matrix0/ps
mv run170.out matrix0/pixels
cd ..
