#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro842.run
mv run_842_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(842\) 
mv run842.ps matrix0/ps
mv run842.out matrix0/pixels
cd ..
