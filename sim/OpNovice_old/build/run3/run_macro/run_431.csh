#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro431.run
mv run_431_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(431\) 
mv run431.ps matrix0/ps
mv run431.out matrix0/pixels
cd ..
