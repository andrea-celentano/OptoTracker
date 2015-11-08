#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro440.run
mv run_440_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(440\) 
mv run440.ps matrix0/ps
mv run440.out matrix0/pixels
cd ..
