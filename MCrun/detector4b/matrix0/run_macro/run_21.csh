#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b/matrix0/run_macro/macro21.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b/PrototypeGeometry.dat
mv run_21_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b/matrix0
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b/matrixMCcalculation.xml -DvoxelID=21 root/run_21_0.root
mv voxel_21.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b/matrix0/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4b/matrix0
