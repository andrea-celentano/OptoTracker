#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro287.run
mv run_287_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(287\) 
mv run287.ps matrix0/ps
mv run287.out matrix0/pixels
cd ..
