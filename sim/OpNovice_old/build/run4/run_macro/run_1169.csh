#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1169.run
mv run_1169_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1169\) 
mv run1169.ps matrix0/ps
mv run1169.out matrix0/pixels
cd ..
