#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro721.run
mv run_721_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(721\) 
mv run721.ps matrix0/ps
mv run721.out matrix0/pixels
cd ..
