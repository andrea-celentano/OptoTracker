#!/bin/tcsh -f

set MC = $OPTO/bin/OpNoviceExe
set RECON = $OPTO/bin/ReconstructionNew
set DET = PrototypeGeometry.dat
set STEERING = reconCharge.xml

set BENCHS = (alphaCenter alphaLateral alphaLateral2 muonCenter muonLateral)

foreach bench ($BENCHS)
echo $bench
$MC -det $DET -m ${bench}.mac
$RECON -s $STEERING ${bench}_0.root -DCHARGE_TXT=\"${bench}Out.txt\" -DCHARGE_ROOT=\"${bench}Out.root\"
end
