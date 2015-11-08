#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro411.run
mv run_411_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(411\) 
mv run411.ps matrix0/ps
mv run411.out matrix0/pixels
cd ..
