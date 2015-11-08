#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro849.run
mv run_849_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(849\) 
mv run849.ps matrix0/ps
mv run849.out matrix0/pixels
cd ..
