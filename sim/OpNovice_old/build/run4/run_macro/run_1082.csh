#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1082.run
mv run_1082_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1082\) 
mv run1082.ps matrix0/ps
mv run1082.out matrix0/pixels
cd ..
