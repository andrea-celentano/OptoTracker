#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro243.run
mv run_243_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(243\) 
mv run243.ps matrix0/ps
mv run243.out matrix0/pixels
cd ..
