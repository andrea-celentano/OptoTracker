#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro611.run
mv run_611_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(611\) 
mv run611.ps matrix0/ps
mv run611.out matrix0/pixels
cd ..
