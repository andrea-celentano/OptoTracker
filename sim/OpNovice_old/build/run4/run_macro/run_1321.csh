#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1321.run
mv run_1321_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1321\) 
mv run1321.ps matrix0/ps
mv run1321.out matrix0/pixels
cd ..
