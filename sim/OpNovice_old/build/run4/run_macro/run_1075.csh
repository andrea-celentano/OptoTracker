#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1075.run
mv run_1075_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1075\) 
mv run1075.ps matrix0/ps
mv run1075.out matrix0/pixels
cd ..
