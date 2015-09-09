
packages = Common Simulation Reconstruction ReconstructionNew MarocAnalysis

all: $(packages) 

$(packages):
	echo Doing $@ && \
	mkdir -p ${OPTO}/packages/$@/build && \
	cd ${OPTO}/packages/$@/build && cmake ../ && \
	cmake -DGeant4_DIR=${G4INSTALL}/lib64/Geant4-10.1.1/ -DCMAKE_BUILD_TYPE=Release  ../ ; \
	make -j16 install

clean:
	for package in ${packages} ; do \
		cd ${OPTO}/packages/$$package/build ; \
		rm -rf CMakeFiles ; \
		rm -rf CMakeCache.txt ; \
		rm -rf *Classes.cpp ; \
	done ; \
	cd ${OPTO}/bin ; rm * ; cd ${OPTO}/lib ; rm *

debug:
	for package in ${packages} ; do \
                cd ${OPTO}/packages/$$package/build ; \
                cmake -DGeant4_DIR=${G4INSTALL}/lib64/Geant4-10.1.1/  -DCMAKE_BUILD_TYPE=Debug ../ ; \
		make -j16 install ; \
        done
