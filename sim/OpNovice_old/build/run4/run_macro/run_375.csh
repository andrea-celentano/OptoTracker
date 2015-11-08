#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro375.run
mv run_375_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(375\) 
mv run375.ps matrix0/ps
mv run375.out matrix0/pixels
cd ..
