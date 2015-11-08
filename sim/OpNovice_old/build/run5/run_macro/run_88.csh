#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run5/run_macro/macro88.run
mv run_88_0.root run5/root 
cd run5
root -l -q -b  ../doPixels.C\(88\) 
mv run88.ps matrix0/ps
mv run88.out matrix0/pixels
cd ..
