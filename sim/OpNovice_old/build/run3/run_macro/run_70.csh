#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro70.run
mv run_70_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(70\) 
mv run70.ps matrix0/ps
mv run70.out matrix0/pixels
cd ..
