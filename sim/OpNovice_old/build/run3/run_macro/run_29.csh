#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro29.run
mv run_29_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(29\) 
mv run29.ps matrix0/ps
mv run29.out matrix0/pixels
cd ..
