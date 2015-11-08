#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1149.run
mv run_1149_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1149\) 
mv run1149.ps matrix0/ps
mv run1149.out matrix0/pixels
cd ..
