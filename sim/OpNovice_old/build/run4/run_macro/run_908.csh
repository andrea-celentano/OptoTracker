#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro908.run
mv run_908_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(908\) 
mv run908.ps matrix0/ps
mv run908.out matrix0/pixels
cd ..
