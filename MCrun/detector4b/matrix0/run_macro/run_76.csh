#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b/matrix0/run_macro/macro76.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b/PrototypeGeometry.dat
mv run_76_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b/matrix0
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b/matrixMCcalculation.xml -DvoxelID=76 root/run_76_0.root
mv voxel_76.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b/matrix0/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b/matrix0
