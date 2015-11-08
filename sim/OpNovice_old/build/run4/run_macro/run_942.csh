#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro942.run
mv run_942_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(942\) 
mv run942.ps matrix0/ps
mv run942.out matrix0/pixels
cd ..
