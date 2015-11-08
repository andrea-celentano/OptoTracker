#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro560.run
mv run_560_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(560\) 
mv run560.ps matrix0/ps
mv run560.out matrix0/pixels
cd ..
