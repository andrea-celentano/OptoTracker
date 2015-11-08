#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1162.run
mv run_1162_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1162\) 
mv run1162.ps matrix0/ps
mv run1162.out matrix0/pixels
cd ..
