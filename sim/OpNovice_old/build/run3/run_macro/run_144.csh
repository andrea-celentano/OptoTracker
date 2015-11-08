#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro144.run
mv run_144_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(144\) 
mv run144.ps matrix0/ps
mv run144.out matrix0/pixels
cd ..
