#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run5/run_macro/macro19.run
mv run_19_0.root run5/root 
cd run5
root -l -q -b  ../doPixels.C\(19\) 
mv run19.ps matrix0/ps
mv run19.out matrix0/pixels
cd ..
