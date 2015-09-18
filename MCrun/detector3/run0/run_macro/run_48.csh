#!/bin/tcsh -f
cd /work/OptoTracker/MCrun/detector3/
cd run0
/work/OptoTracker/bin/OpNoviceExe -m /work/OptoTracker/MCrun/detector3/run0/run_macro/macro48.run -det /work/OptoTracker/MCrun/detector3//PrototypeGeometry.dat
mv run_48_0.root root/ 
cd /work/OptoTracker/MCrun/detector3/
cd run0
/work/OptoTracker/bin/ReconstructionNew -s /work/OptoTracker/MCrun/detector3/matrixAnalysis.xml -DvoxelID=48 root/run_48_0.root
mv voxel_48.dat matrix/pixels
cd /work/OptoTracker/MCrun/detector3/
