#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix0/run_macro/macro107.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/PrototypeGeometry.dat
mv run_107_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix0
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrixMCcalculation.xml -DvoxelID=107 root/run_107_0.root
mv voxel_107.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix0/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix0
