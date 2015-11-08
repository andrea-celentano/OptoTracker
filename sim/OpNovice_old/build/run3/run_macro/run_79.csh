#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro79.run
mv run_79_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(79\) 
mv run79.ps matrix0/ps
mv run79.out matrix0/pixels
cd ..
