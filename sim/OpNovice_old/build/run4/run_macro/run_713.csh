#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro713.run
mv run_713_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(713\) 
mv run713.ps matrix0/ps
mv run713.out matrix0/pixels
cd ..
