#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro443.run
mv run_443_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(443\) 
mv run443.ps matrix0/ps
mv run443.out matrix0/pixels
cd ..
