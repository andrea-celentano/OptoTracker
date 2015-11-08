#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro112.run
mv run_112_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(112\) 
mv run112.ps matrix0/ps
mv run112.out matrix0/pixels
cd ..
