#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro490.run
mv run_490_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(490\) 
mv run490.ps matrix0/ps
mv run490.out matrix0/pixels
cd ..
