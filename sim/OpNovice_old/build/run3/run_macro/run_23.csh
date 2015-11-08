#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro23.run
mv run_23_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(23\) 
mv run23.ps matrix0/ps
mv run23.out matrix0/pixels
cd ..
