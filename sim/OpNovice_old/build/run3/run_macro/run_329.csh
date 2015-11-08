#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro329.run
mv run_329_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(329\) 
mv run329.ps matrix0/ps
mv run329.out matrix0/pixels
cd ..
