#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro858.run
mv run_858_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(858\) 
mv run858.ps matrix0/ps
mv run858.out matrix0/pixels
cd ..
