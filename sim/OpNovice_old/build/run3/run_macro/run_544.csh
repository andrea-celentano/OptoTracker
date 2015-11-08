#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro544.run
mv run_544_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(544\) 
mv run544.ps matrix0/ps
mv run544.out matrix0/pixels
cd ..
