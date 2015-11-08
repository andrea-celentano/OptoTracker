#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro995.run
mv run_995_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(995\) 
mv run995.ps matrix0/ps
mv run995.out matrix0/pixels
cd ..
