#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4a
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4a/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4a/matrix0/run_macro/macro96.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4a/PrototypeGeometry.dat
mv run_96_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4a/matrix0
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4a/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4a/matrixMCcalculation.xml -DvoxelID=96 root/run_96_0.root
mv voxel_96.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4a/matrix0/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector4a/matrix0
