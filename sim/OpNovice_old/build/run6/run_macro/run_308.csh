#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro308.run
mv run_308_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(308\) 
mv run308.ps matrix0/ps
mv run308.out matrix0/pixels
cd ..
