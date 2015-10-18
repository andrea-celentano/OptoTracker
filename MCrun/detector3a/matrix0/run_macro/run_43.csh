#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix0/run_macro/macro43.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/PrototypeGeometry.dat
mv run_43_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix0
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrixMCcalculation.xml -DvoxelID=43 root/run_43_0.root
mv voxel_43.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix0/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix0
