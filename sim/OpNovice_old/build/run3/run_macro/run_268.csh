#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro268.run
mv run_268_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(268\) 
mv run268.ps matrix0/ps
mv run268.out matrix0/pixels
cd ..
