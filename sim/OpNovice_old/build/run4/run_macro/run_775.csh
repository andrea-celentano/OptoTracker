#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro775.run
mv run_775_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(775\) 
mv run775.ps matrix0/ps
mv run775.out matrix0/pixels
cd ..
