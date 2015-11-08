#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro583.run
mv run_583_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(583\) 
mv run583.ps matrix0/ps
mv run583.out matrix0/pixels
cd ..
