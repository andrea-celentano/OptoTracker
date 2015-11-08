#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro944.run
mv run_944_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(944\) 
mv run944.ps matrix0/ps
mv run944.out matrix0/pixels
cd ..
