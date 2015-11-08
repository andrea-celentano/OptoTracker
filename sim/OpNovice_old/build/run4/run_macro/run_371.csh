#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro371.run
mv run_371_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(371\) 
mv run371.ps matrix0/ps
mv run371.out matrix0/pixels
cd ..
