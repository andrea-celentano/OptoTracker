#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro190.run
mv run_190_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(190\) 
mv run190.ps matrix0/ps
mv run190.out matrix0/pixels
cd ..
