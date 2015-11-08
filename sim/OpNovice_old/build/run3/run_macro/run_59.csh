#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro59.run
mv run_59_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(59\) 
mv run59.ps matrix0/ps
mv run59.out matrix0/pixels
cd ..
