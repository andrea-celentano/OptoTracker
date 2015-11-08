#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro462.run
mv run_462_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(462\) 
mv run462.ps matrix0/ps
mv run462.out matrix0/pixels
cd ..
