#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix0/run_macro/macro112.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/PrototypeGeometry.dat
mv run_112_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix0
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrixMCcalculation.xml -DvoxelID=112 root/run_112_0.root
mv voxel_112.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix0/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix0
