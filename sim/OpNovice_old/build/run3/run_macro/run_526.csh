#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro526.run
mv run_526_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(526\) 
mv run526.ps matrix0/ps
mv run526.out matrix0/pixels
cd ..
