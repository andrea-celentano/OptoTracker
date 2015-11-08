#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1014.run
mv run_1014_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1014\) 
mv run1014.ps matrix0/ps
mv run1014.out matrix0/pixels
cd ..
