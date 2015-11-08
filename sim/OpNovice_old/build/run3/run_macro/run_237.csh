#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro237.run
mv run_237_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(237\) 
mv run237.ps matrix0/ps
mv run237.out matrix0/pixels
cd ..
