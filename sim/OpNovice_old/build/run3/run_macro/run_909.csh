#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro909.run
mv run_909_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(909\) 
mv run909.ps matrix0/ps
mv run909.out matrix0/pixels
cd ..
