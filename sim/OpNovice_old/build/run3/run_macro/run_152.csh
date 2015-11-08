#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro152.run
mv run_152_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(152\) 
mv run152.ps matrix0/ps
mv run152.out matrix0/pixels
cd ..
