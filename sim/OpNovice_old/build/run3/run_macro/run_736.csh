#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro736.run
mv run_736_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(736\) 
mv run736.ps matrix0/ps
mv run736.out matrix0/pixels
cd ..
