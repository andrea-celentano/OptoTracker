#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro99.run
mv run_99_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(99\) 
mv run99.ps matrix0/ps
mv run99.out matrix0/pixels
cd ..
