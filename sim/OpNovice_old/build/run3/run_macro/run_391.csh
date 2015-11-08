#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro391.run
mv run_391_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(391\) 
mv run391.ps matrix0/ps
mv run391.out matrix0/pixels
cd ..
