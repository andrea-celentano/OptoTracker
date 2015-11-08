#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1201.run
mv run_1201_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1201\) 
mv run1201.ps matrix0/ps
mv run1201.out matrix0/pixels
cd ..
