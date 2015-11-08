#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro780.run
mv run_780_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(780\) 
mv run780.ps matrix0/ps
mv run780.out matrix0/pixels
cd ..
