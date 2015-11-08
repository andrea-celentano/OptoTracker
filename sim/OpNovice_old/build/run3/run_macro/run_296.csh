#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro296.run
mv run_296_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(296\) 
mv run296.ps matrix0/ps
mv run296.out matrix0/pixels
cd ..
