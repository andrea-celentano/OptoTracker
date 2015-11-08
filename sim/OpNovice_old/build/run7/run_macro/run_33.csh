#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run7/run_macro/macro33.run
mv run_33_0.root run7/root 
cd run7
root -l -q -b  ../doPixels.C\(33\) 
mv run33.ps matrix0/ps
mv run33.out matrix0/pixels
cd ..
