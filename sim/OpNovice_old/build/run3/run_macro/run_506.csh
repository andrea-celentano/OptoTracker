#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro506.run
mv run_506_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(506\) 
mv run506.ps matrix0/ps
mv run506.out matrix0/pixels
cd ..
