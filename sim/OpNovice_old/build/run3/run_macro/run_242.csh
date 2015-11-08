#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro242.run
mv run_242_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(242\) 
mv run242.ps matrix0/ps
mv run242.out matrix0/pixels
cd ..
