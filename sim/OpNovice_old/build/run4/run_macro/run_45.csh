#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro45.run
mv run_45_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(45\) 
mv run45.ps matrix0/ps
mv run45.out matrix0/pixels
cd ..
