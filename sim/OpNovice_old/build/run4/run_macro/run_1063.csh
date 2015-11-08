#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro1063.run
mv run_1063_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(1063\) 
mv run1063.ps matrix0/ps
mv run1063.out matrix0/pixels
cd ..
