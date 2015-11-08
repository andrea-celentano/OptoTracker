#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro866.run
mv run_866_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(866\) 
mv run866.ps matrix0/ps
mv run866.out matrix0/pixels
cd ..
