#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro687.run
mv run_687_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(687\) 
mv run687.ps matrix0/ps
mv run687.out matrix0/pixels
cd ..
