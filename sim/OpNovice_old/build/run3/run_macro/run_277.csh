#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro277.run
mv run_277_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(277\) 
mv run277.ps matrix0/ps
mv run277.out matrix0/pixels
cd ..
