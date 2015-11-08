#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro160.run
mv run_160_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(160\) 
mv run160.ps matrix0/ps
mv run160.out matrix0/pixels
cd ..
