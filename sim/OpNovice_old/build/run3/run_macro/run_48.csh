#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro48.run
mv run_48_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(48\) 
mv run48.ps matrix0/ps
mv run48.out matrix0/pixels
cd ..
