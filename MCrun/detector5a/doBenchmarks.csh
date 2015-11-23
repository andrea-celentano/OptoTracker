#!/bin/tcsh -f

set MC = $OPTO/bin/OpNoviceExe
set RECON = $OPTO/bin/ReconstructionNew
set DET = PrototypeGeometry.dat
set STEERING = reconCharge.xml

set BENCHS = (alphaCenter alphaLateral alphaLateral2 muonCenter muonLateral)

foreach bench ($BENCHS)
echo $bench
$MC -det $DET -m ${bench}.mac

foreach file (${bench}_*.root)
$RECON -s $STEERING $file -DCHARGE_TXT=\"${file}Out.txt\" -DCHARGE_ROOT=\"${file}Out.root\"
end
