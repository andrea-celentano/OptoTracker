#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro376.run
mv run_376_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(376\) 
mv run376.ps matrix0/ps
mv run376.out matrix0/pixels
cd ..
