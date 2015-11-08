#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro28.run
mv run_28_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(28\) 
mv run28.ps matrix0/ps
mv run28.out matrix0/pixels
cd ..
