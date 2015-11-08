#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro298.run
mv run_298_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(298\) 
mv run298.ps matrix0/ps
mv run298.out matrix0/pixels
cd ..
