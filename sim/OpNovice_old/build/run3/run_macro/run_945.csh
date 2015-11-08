#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro945.run
mv run_945_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(945\) 
mv run945.ps matrix0/ps
mv run945.out matrix0/pixels
cd ..
