#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro544.run
mv run_544_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(544\) 
mv run544.ps matrix0/ps
mv run544.out matrix0/pixels
cd ..
