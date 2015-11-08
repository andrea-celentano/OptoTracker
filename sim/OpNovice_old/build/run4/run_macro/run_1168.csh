#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1168.run
mv run_1168_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1168\) 
mv run1168.ps matrix0/ps
mv run1168.out matrix0/pixels
cd ..
