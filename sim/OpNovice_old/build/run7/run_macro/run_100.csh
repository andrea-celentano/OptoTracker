#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run7/run_macro/macro100.run
mv run_100_0.root run7/root 
cd run7
root -l -q -b  ../doPixels.C\(100\) 
mv run100.ps matrix0/ps
mv run100.out matrix0/pixels
cd ..