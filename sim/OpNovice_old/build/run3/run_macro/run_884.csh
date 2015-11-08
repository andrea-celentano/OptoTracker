#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro884.run
mv run_884_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(884\) 
mv run884.ps matrix0/ps
mv run884.out matrix0/pixels
cd ..
