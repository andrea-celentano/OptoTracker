#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run7/run_macro/macro80.run
mv run_80_0.root run7/root 
cd run7
root -l -q -b  ../doPixels.C\(80\) 
mv run80.ps matrix0/ps
mv run80.out matrix0/pixels
cd ..
