#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro306.run
mv run_306_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(306\) 
mv run306.ps matrix0/ps
mv run306.out matrix0/pixels
cd ..
