#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro574.run
mv run_574_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(574\) 
mv run574.ps matrix0/ps
mv run574.out matrix0/pixels
cd ..
