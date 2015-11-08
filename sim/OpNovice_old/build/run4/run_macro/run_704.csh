#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro704.run
mv run_704_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(704\) 
mv run704.ps matrix0/ps
mv run704.out matrix0/pixels
cd ..
