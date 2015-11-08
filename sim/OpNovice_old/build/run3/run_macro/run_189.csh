#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro189.run
mv run_189_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(189\) 
mv run189.ps matrix0/ps
mv run189.out matrix0/pixels
cd ..
