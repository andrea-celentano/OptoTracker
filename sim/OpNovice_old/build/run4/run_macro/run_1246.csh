#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1246.run
mv run_1246_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1246\) 
mv run1246.ps matrix0/ps
mv run1246.out matrix0/pixels
cd ..
