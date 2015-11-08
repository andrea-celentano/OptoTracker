#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro712.run
mv run_712_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(712\) 
mv run712.ps matrix0/ps
mv run712.out matrix0/pixels
cd ..
