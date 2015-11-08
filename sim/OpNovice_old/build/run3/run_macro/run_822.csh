#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro822.run
mv run_822_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(822\) 
mv run822.ps matrix0/ps
mv run822.out matrix0/pixels
cd ..
