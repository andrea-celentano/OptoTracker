#!/bin/tcsh -f

set MC = $OPTO/bin/OpNoviceExe
set RECON = $OPTO/bin/ReconstructionNew
set DET = PrototypeGeometry.dat
set STEERING1 = reconCharge.xml
set STEERING2 = reconLikelihood.xml

set BENCHS = (alphaCenter alphaLateral1 alphaLateral2 alphaLateral3 alphaLateral4)

foreach bench ($BENCHS)
echo $bench
$MC -det $DET -m ${bench}.mac
$RECON -s $STEERING1 ${bench}_0.root -DCHARGE_ROOT=\"${bench}OutCharge.root\"
$RECON -s $STEERING2 ${bench}_0.root -DLIKELIHOOD_ROOT=\"${bench}OutLikelihood.root\"
end
