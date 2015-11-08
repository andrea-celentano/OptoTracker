#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro343.run
mv run_343_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(343\) 
mv run343.ps matrix0/ps
mv run343.out matrix0/pixels
cd ..
