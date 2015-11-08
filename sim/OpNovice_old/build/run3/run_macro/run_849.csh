#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro849.run
mv run_849_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(849\) 
mv run849.ps matrix0/ps
mv run849.out matrix0/pixels
cd ..
