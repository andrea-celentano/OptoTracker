#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro478.run
mv run_478_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(478\) 
mv run478.ps matrix0/ps
mv run478.out matrix0/pixels
cd ..
