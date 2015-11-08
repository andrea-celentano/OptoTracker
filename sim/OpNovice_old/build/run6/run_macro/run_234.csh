#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro234.run
mv run_234_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(234\) 
mv run234.ps matrix0/ps
mv run234.out matrix0/pixels
cd ..
