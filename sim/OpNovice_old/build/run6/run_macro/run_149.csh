#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro149.run
mv run_149_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(149\) 
mv run149.ps matrix0/ps
mv run149.out matrix0/pixels
cd ..
