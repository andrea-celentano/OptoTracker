#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro970.run
mv run_970_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(970\) 
mv run970.ps matrix0/ps
mv run970.out matrix0/pixels
cd ..
