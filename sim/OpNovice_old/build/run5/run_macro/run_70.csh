#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run5/run_macro/macro70.run
mv run_70_0.root run5/root 
cd run5
root -l -q -b  ../doPixels.C\(70\) 
mv run70.ps matrix0/ps
mv run70.out matrix0/pixels
cd ..