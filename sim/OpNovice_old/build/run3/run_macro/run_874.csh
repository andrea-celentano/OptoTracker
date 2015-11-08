#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro874.run
mv run_874_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(874\) 
mv run874.ps matrix0/ps
mv run874.out matrix0/pixels
cd ..
