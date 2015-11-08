#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro366.run
mv run_366_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(366\) 
mv run366.ps matrix0/ps
mv run366.out matrix0/pixels
cd ..
