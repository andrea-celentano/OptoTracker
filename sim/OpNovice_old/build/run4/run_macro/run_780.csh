#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro780.run
mv run_780_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(780\) 
mv run780.ps matrix0/ps
mv run780.out matrix0/pixels
cd ..
