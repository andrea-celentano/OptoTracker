#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro296.run
mv run_296_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(296\) 
mv run296.ps matrix0/ps
mv run296.out matrix0/pixels
cd ..
