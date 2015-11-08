#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro795.run
mv run_795_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(795\) 
mv run795.ps matrix0/ps
mv run795.out matrix0/pixels
cd ..
