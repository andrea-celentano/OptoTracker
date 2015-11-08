#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro608.run
mv run_608_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(608\) 
mv run608.ps matrix0/ps
mv run608.out matrix0/pixels
cd ..
