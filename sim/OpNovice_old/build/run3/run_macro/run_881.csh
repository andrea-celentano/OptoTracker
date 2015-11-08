#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro881.run
mv run_881_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(881\) 
mv run881.ps matrix0/ps
mv run881.out matrix0/pixels
cd ..
