#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro545.run
mv run_545_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(545\) 
mv run545.ps matrix0/ps
mv run545.out matrix0/pixels
cd ..
