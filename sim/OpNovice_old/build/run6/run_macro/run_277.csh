#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro277.run
mv run_277_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(277\) 
mv run277.ps matrix0/ps
mv run277.out matrix0/pixels
cd ..
