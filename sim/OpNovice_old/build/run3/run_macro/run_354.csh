#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro354.run
mv run_354_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(354\) 
mv run354.ps matrix0/ps
mv run354.out matrix0/pixels
cd ..
