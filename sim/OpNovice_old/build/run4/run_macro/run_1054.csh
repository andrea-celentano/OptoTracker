#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1054.run
mv run_1054_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1054\) 
mv run1054.ps matrix0/ps
mv run1054.out matrix0/pixels
cd ..
