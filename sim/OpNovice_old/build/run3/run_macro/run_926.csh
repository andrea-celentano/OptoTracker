#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro926.run
mv run_926_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(926\) 
mv run926.ps matrix0/ps
mv run926.out matrix0/pixels
cd ..
