#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro129.run
mv run_129_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(129\) 
mv run129.ps matrix0/ps
mv run129.out matrix0/pixels
cd ..
