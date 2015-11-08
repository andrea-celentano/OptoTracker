#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1152.run
mv run_1152_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1152\) 
mv run1152.ps matrix0/ps
mv run1152.out matrix0/pixels
cd ..
