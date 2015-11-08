#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro592.run
mv run_592_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(592\) 
mv run592.ps matrix0/ps
mv run592.out matrix0/pixels
cd ..
