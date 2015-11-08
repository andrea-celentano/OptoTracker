#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1150.run
mv run_1150_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1150\) 
mv run1150.ps matrix0/ps
mv run1150.out matrix0/pixels
cd ..
