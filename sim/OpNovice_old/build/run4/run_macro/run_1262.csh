#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1262.run
mv run_1262_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1262\) 
mv run1262.ps matrix0/ps
mv run1262.out matrix0/pixels
cd ..
