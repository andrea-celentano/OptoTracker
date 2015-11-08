#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro108.run
mv run_108_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(108\) 
mv run108.ps matrix0/ps
mv run108.out matrix0/pixels
cd ..
