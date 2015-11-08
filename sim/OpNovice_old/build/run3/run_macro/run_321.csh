#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro321.run
mv run_321_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(321\) 
mv run321.ps matrix0/ps
mv run321.out matrix0/pixels
cd ..
