#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro340.run
mv run_340_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(340\) 
mv run340.ps matrix0/ps
mv run340.out matrix0/pixels
cd ..
