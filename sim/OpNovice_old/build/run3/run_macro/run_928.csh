#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro928.run
mv run_928_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(928\) 
mv run928.ps matrix0/ps
mv run928.out matrix0/pixels
cd ..
