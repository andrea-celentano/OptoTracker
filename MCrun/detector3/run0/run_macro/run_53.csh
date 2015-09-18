#!/bin/tcsh -f
cd /work/OptoTracker/MCrun/detector3/
cd run0
/work/OptoTracker/bin/OpNoviceExe -m /work/OptoTracker/MCrun/detector3/run0/run_macro/macro53.run -det /work/OptoTracker/MCrun/detector3//PrototypeGeometry.dat
mv run_53_0.root root/ 
cd /work/OptoTracker/MCrun/detector3/
cd run0
/work/OptoTracker/bin/ReconstructionNew -s /work/OptoTracker/MCrun/detector3/matrixAnalysis.xml -DvoxelID=53 root/run_53_0.root
mv voxel_53.dat matrix/pixels
cd /work/OptoTracker/MCrun/detector3/
