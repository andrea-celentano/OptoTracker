#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro566.run
mv run_566_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(566\) 
mv run566.ps matrix0/ps
mv run566.out matrix0/pixels
cd ..
