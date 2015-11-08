#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro942.run
mv run_942_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(942\) 
mv run942.ps matrix0/ps
mv run942.out matrix0/pixels
cd ..
