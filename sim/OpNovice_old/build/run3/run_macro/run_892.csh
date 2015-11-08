#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro892.run
mv run_892_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(892\) 
mv run892.ps matrix0/ps
mv run892.out matrix0/pixels
cd ..
