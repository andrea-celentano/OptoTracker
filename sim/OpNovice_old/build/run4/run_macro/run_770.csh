#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro770.run
mv run_770_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(770\) 
mv run770.ps matrix0/ps
mv run770.out matrix0/pixels
cd ..
