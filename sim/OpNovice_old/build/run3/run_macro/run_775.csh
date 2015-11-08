#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro775.run
mv run_775_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(775\) 
mv run775.ps matrix0/ps
mv run775.out matrix0/pixels
cd ..
