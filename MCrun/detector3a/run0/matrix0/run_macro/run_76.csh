#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/run0/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/run0/matrix0/run_macro/macro76.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/PrototypeGeometry.dat
mv run_76_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/run0/matrix0
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/run0/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrixMCcalculation.xml -DvoxelID=76 root/run_76_0.root
mv voxel_76.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/run0/matrix0/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/run0/matrix0
