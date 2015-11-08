#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro643.run
mv run_643_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(643\) 
mv run643.ps matrix0/ps
mv run643.out matrix0/pixels
cd ..
