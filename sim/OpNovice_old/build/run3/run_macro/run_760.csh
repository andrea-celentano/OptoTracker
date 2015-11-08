#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro760.run
mv run_760_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(760\) 
mv run760.ps matrix0/ps
mv run760.out matrix0/pixels
cd ..
