#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix3
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix3/run_macro/macro65.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/PrototypeGeometry.dat
mv run_65_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix3
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix3
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrixMCcalculation.xml -DvoxelID=65 root/run_65_0.root
mv voxel_65.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix3/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix3
