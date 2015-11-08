#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro661.run
mv run_661_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(661\) 
mv run661.ps matrix0/ps
mv run661.out matrix0/pixels
cd ..
