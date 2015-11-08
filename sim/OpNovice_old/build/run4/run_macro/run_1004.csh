#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1004.run
mv run_1004_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1004\) 
mv run1004.ps matrix0/ps
mv run1004.out matrix0/pixels
cd ..
