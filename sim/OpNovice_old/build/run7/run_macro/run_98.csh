#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run7/run_macro/macro98.run
mv run_98_0.root run7/root 
cd run7
root -l -q -b  ../doPixels.C\(98\) 
mv run98.ps matrix0/ps
mv run98.out matrix0/pixels
cd ..
