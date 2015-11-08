#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro791.run
mv run_791_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(791\) 
mv run791.ps matrix0/ps
mv run791.out matrix0/pixels
cd ..
