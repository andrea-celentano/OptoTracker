#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro442.run
mv run_442_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(442\) 
mv run442.ps matrix0/ps
mv run442.out matrix0/pixels
cd ..
