#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro714.run
mv run_714_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(714\) 
mv run714.ps matrix0/ps
mv run714.out matrix0/pixels
cd ..
