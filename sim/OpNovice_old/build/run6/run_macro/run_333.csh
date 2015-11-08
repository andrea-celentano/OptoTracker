#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro333.run
mv run_333_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(333\) 
mv run333.ps matrix0/ps
mv run333.out matrix0/pixels
cd ..
