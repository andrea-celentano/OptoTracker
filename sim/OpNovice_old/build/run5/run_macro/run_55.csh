#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run5/run_macro/macro55.run
mv run_55_0.root run5/root 
cd run5
root -l -q -b  ../doPixels.C\(55\) 
mv run55.ps matrix0/ps
mv run55.out matrix0/pixels
cd ..
