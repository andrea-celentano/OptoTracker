#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix0/run_macro/macro89.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/PrototypeGeometry.dat
mv run_89_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix0
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrixMCcalculation.xml -DvoxelID=89 root/run_89_0.root
mv voxel_89.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix0/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix0
