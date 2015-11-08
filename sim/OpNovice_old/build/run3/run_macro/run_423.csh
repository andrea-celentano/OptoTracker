#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro423.run
mv run_423_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(423\) 
mv run423.ps matrix0/ps
mv run423.out matrix0/pixels
cd ..
