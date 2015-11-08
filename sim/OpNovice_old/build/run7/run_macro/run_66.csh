#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run7/run_macro/macro66.run
mv run_66_0.root run7/root 
cd run7
root -l -q -b  ../doPixels.C\(66\) 
mv run66.ps matrix0/ps
mv run66.out matrix0/pixels
cd ..
