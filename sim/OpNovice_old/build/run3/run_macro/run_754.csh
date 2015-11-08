#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro754.run
mv run_754_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(754\) 
mv run754.ps matrix0/ps
mv run754.out matrix0/pixels
cd ..
