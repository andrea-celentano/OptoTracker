#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro153.run
mv run_153_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(153\) 
mv run153.ps matrix0/ps
mv run153.out matrix0/pixels
cd ..
