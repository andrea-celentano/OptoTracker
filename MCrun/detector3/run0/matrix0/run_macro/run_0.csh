#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/run0/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/run0/matrix0/run_macro/macro0.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/PrototypeGeometry.dat
mv run_0_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/run0/matrix0
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/run0/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/matrixMCcalculation.xml -DvoxelID=0 root/run_0_0.root
mv voxel_0.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/run0/matrix0/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/run0/matrix0
