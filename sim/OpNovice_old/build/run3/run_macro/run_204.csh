#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro204.run
mv run_204_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(204\) 
mv run204.ps matrix0/ps
mv run204.out matrix0/pixels
cd ..
