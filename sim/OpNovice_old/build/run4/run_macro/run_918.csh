#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro918.run
mv run_918_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(918\) 
mv run918.ps matrix0/ps
mv run918.out matrix0/pixels
cd ..
