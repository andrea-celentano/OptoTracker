#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro242.run
mv run_242_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(242\) 
mv run242.ps matrix0/ps
mv run242.out matrix0/pixels
cd ..
