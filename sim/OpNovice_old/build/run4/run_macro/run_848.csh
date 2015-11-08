#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro848.run
mv run_848_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(848\) 
mv run848.ps matrix0/ps
mv run848.out matrix0/pixels
cd ..
