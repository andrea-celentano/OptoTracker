#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro650.run
mv run_650_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(650\) 
mv run650.ps matrix0/ps
mv run650.out matrix0/pixels
cd ..
