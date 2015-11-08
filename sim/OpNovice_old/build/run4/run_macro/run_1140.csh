#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1140.run
mv run_1140_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1140\) 
mv run1140.ps matrix0/ps
mv run1140.out matrix0/pixels
cd ..
