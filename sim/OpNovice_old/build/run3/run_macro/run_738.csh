#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro738.run
mv run_738_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(738\) 
mv run738.ps matrix0/ps
mv run738.out matrix0/pixels
cd ..
