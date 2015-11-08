#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro339.run
mv run_339_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(339\) 
mv run339.ps matrix0/ps
mv run339.out matrix0/pixels
cd ..
