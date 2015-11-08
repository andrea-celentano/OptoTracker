#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro797.run
mv run_797_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(797\) 
mv run797.ps matrix0/ps
mv run797.out matrix0/pixels
cd ..
