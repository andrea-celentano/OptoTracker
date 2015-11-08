#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro381.run
mv run_381_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(381\) 
mv run381.ps matrix0/ps
mv run381.out matrix0/pixels
cd ..
