#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro604.run
mv run_604_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(604\) 
mv run604.ps matrix0/ps
mv run604.out matrix0/pixels
cd ..
