packages = Common Tofpet Simulation Maroc Citiroc ReconstructionNew 

all: $(packages) 

$(packages):
	echo Doing $@ && \
	mkdir -p ${OPTO}/software/packages/$@/build && \
	cd ${OPTO}/software/packages/$@/build && cmake ../ && \
#	cmake -DGeant4_DIR=${G4INSTALL}/lib64/Geant4-10.1.1/ -DCMAKE_BUILD_TYPE=Release  ../ ; \
	make -j16 install

clean:
	for package in ${packages} ; do \
		cd ${OPTO}/software/packages/$$package/build ; \
		rm -rf * ; \
	done ; \
	cd ${OPTO}/software/bin ; rm -f * ; cd ${OPTO}/software/lib ; rm -f *


debug:
	for package in ${packages} ; do \
                cd ${OPTO}/software/packages/$$package/build ; \
                cmake -DGeant4_DIR=${G4INSTALL}/lib64/Geant4-10.1.1/ -DCMAKE_BUILD_TYPE=Debug ../ ; \
		make -j16 install ; \
        done
