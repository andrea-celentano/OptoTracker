#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1225.run
mv run_1225_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1225\) 
mv run1225.ps matrix0/ps
mv run1225.out matrix0/pixels
cd ..
