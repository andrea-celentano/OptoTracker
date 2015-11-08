#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro504.run
mv run_504_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(504\) 
mv run504.ps matrix0/ps
mv run504.out matrix0/pixels
cd ..
