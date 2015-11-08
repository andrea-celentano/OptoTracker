#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro791.run
mv run_791_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(791\) 
mv run791.ps matrix0/ps
mv run791.out matrix0/pixels
cd ..
