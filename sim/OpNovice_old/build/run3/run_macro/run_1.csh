#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro1.run
mv run_1_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(1\) 
mv run1.ps matrix0/ps
mv run1.out matrix0/pixels
cd ..
