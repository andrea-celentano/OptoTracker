#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro727.run
mv run_727_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(727\) 
mv run727.ps matrix0/ps
mv run727.out matrix0/pixels
cd ..
