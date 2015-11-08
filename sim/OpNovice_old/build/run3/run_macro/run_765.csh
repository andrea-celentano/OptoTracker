#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro765.run
mv run_765_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(765\) 
mv run765.ps matrix0/ps
mv run765.out matrix0/pixels
cd ..
