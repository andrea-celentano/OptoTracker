#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro194.run
mv run_194_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(194\) 
mv run194.ps matrix0/ps
mv run194.out matrix0/pixels
cd ..
