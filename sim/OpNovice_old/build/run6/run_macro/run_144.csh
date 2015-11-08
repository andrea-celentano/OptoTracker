#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro144.run
mv run_144_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(144\) 
mv run144.ps matrix0/ps
mv run144.out matrix0/pixels
cd ..
