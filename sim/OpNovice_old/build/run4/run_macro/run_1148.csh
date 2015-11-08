#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1148.run
mv run_1148_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1148\) 
mv run1148.ps matrix0/ps
mv run1148.out matrix0/pixels
cd ..
