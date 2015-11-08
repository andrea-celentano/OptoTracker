#!/bin/tcsh -f

foreach x(`seq 0 1 100`)
    echo $x
    ../../OpNoviceExe -m run2.mac -r $x 
    root -l -b -q ../../doPixels.C\(\"OpNovice_0.root\"\)
    mv OpNovice_0.root.out SinglePixel$x.out
end
