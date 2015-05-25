#!/bin/tcsh -f

cd $OPTO/packages/Geometry/build
cmake ../
make -j16 install

cd $OPTO/packages/Simulation/build
cmake ../
make -j16 install

cd $OPTO/packages/Reconstruction/build
cmake ../
make -j16 install

cd $OPTO/packages/MarocAnalysis/build
cmake ../
make -j16 install
