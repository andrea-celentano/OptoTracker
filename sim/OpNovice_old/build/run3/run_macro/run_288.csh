#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro288.run
mv run_288_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(288\) 
mv run288.ps matrix0/ps
mv run288.out matrix0/pixels
cd ..
