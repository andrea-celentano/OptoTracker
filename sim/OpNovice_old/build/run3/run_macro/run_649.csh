#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro649.run
mv run_649_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(649\) 
mv run649.ps matrix0/ps
mv run649.out matrix0/pixels
cd ..
