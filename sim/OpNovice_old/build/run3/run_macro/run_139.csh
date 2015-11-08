#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro139.run
mv run_139_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(139\) 
mv run139.ps matrix0/ps
mv run139.out matrix0/pixels
cd ..
