#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1151.run
mv run_1151_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1151\) 
mv run1151.ps matrix0/ps
mv run1151.out matrix0/pixels
cd ..
