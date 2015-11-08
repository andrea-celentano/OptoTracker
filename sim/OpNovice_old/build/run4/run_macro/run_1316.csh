#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1316.run
mv run_1316_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1316\) 
mv run1316.ps matrix0/ps
mv run1316.out matrix0/pixels
cd ..
