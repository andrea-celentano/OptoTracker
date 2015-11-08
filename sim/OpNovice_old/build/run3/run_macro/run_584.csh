#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro584.run
mv run_584_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(584\) 
mv run584.ps matrix0/ps
mv run584.out matrix0/pixels
cd ..
