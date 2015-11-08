#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run7/run_macro/macro120.run
mv run_120_0.root run7/root 
cd run7
root -l -q -b  ../doPixels.C\(120\) 
mv run120.ps matrix0/ps
mv run120.out matrix0/pixels
cd ..
