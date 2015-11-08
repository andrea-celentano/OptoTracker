#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro270.run
mv run_270_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(270\) 
mv run270.ps matrix0/ps
mv run270.out matrix0/pixels
cd ..
