#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix0/run_macro/macro103.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/PrototypeGeometry.dat
mv run_103_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix0
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrixMCcalculation.xml -DvoxelID=103 root/run_103_0.root
mv voxel_103.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix0/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix0
