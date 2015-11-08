#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1209.run
mv run_1209_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1209\) 
mv run1209.ps matrix0/ps
mv run1209.out matrix0/pixels
cd ..
