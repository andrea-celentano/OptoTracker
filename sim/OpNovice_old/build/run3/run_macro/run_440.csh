#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro440.run
mv run_440_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(440\) 
mv run440.ps matrix0/ps
mv run440.out matrix0/pixels
cd ..
