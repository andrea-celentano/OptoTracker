#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro257.run
mv run_257_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(257\) 
mv run257.ps matrix0/ps
mv run257.out matrix0/pixels
cd ..
