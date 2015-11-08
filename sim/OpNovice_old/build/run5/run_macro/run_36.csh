#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run5/run_macro/macro36.run
mv run_36_0.root run5/root 
cd run5
root -l -q -b  ../doPixels.C\(36\) 
mv run36.ps matrix0/ps
mv run36.out matrix0/pixels
cd ..
