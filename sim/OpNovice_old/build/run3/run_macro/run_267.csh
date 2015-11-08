#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro267.run
mv run_267_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(267\) 
mv run267.ps matrix0/ps
mv run267.out matrix0/pixels
cd ..
