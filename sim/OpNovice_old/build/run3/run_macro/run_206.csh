#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro206.run
mv run_206_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(206\) 
mv run206.ps matrix0/ps
mv run206.out matrix0/pixels
cd ..
