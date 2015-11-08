#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro783.run
mv run_783_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(783\) 
mv run783.ps matrix0/ps
mv run783.out matrix0/pixels
cd ..
