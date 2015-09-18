#!/bin/tcsh -f
cd /work/OptoTracker/MCrun/detector3/
cd run0
/work/OptoTracker/bin/OpNoviceExe -m /work/OptoTracker/MCrun/detector3/run0/run_macro/macro78.run -det /work/OptoTracker/MCrun/detector3//PrototypeGeometry.dat
mv run_78_0.root root/ 
cd /work/OptoTracker/MCrun/detector3/
cd run0
/work/OptoTracker/bin/ReconstructionNew -s /work/OptoTracker/MCrun/detector3/matrixAnalysis.xml -DvoxelID=78 root/run_78_0.root
mv voxel_78.dat matrix/pixels
cd /work/OptoTracker/MCrun/detector3/
