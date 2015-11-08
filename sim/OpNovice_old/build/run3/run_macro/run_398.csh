#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro398.run
mv run_398_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(398\) 
mv run398.ps matrix0/ps
mv run398.out matrix0/pixels
cd ..
