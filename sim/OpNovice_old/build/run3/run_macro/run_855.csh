#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro855.run
mv run_855_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(855\) 
mv run855.ps matrix0/ps
mv run855.out matrix0/pixels
cd ..
