#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix2
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix2/run_macro/macro200.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/PrototypeGeometry.dat
mv run_200_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix2
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix2
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrixMCcalculation.xml -DvoxelID=200 root/run_200_0.root
mv voxel_200.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix2/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix2
