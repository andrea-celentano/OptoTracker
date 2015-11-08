#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro729.run
mv run_729_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(729\) 
mv run729.ps matrix0/ps
mv run729.out matrix0/pixels
cd ..
