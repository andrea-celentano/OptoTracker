#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro656.run
mv run_656_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(656\) 
mv run656.ps matrix0/ps
mv run656.out matrix0/pixels
cd ..
