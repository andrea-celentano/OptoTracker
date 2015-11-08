#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro677.run
mv run_677_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(677\) 
mv run677.ps matrix0/ps
mv run677.out matrix0/pixels
cd ..
