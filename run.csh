#!/bin/csh

#starpro
#setup 64b
#setup ROOT 5.34.38
#source /star/u/huangbc/.cshrc
#cd /star/u/zbtang/myTools/root/
#source bin/thisroot.csh

	setenv PYTHIA8 /users/PAS2524/lkosarz/Pythia/pythia8312
	setenv LHAPDFSYS /users/PAS2524/lkosarz/LHAPDF/LHAPDF-6.5.4
	setenv PATH ${PATH}:${LHAPDFSYS}/bin
	setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${LHAPDFSYS}/lib:${PYTHIA8}/lib
	
	setenv PYTHIA8DATA ${PYTHIA8}/share/Pythia8/xmldoc


./pythiaDiffractiveDiJet ep_diffractiveDiJets.cmnd diffractiveDiJets_ep_18x275GeV | tee test.log
