#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro713.run
mv run_713_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(713\) 
mv run713.ps matrix0/ps
mv run713.out matrix0/pixels
cd ..
