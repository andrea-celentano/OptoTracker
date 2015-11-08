#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro597.run
mv run_597_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(597\) 
mv run597.ps matrix0/ps
mv run597.out matrix0/pixels
cd ..
