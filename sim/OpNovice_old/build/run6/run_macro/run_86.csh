#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro86.run
mv run_86_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(86\) 
mv run86.ps matrix0/ps
mv run86.out matrix0/pixels
cd ..
