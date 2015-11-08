#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro919.run
mv run_919_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(919\) 
mv run919.ps matrix0/ps
mv run919.out matrix0/pixels
cd ..
