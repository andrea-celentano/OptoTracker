#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro729.run
mv run_729_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(729\) 
mv run729.ps matrix0/ps
mv run729.out matrix0/pixels
cd ..
