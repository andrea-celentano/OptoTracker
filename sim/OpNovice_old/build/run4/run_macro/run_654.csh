#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro654.run
mv run_654_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(654\) 
mv run654.ps matrix0/ps
mv run654.out matrix0/pixels
cd ..
