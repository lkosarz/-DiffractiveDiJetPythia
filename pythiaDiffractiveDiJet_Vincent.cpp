TPythia8* pythia8 = new TPythia8();
  pythia8->ReadString("Beams:frameType=2");
  pythia8->ReadString("Beams:idA=2212");
  pythia8->ReadString("Beams:idB=11");
  pythia8->ReadString(Form("Beams:eA=%f",Eproton));
  pythia8->ReadString(Form("Beams:eB=%f",Eelectron));
    //according to main342 for H1 dijets
  pythia8->ReadString("PDF:lepton2gamma = on");  // Allow for photon-from lepton
  pythia8->ReadString("Photon:ProcessType = 0"); // Allow all photon processes
  pythia8->ReadString("Photon:Q2max = 1.");      // Maximal Q2
  pythia8->ReadString("HardQCD:all = on");       // All dijet MEs
  pythia8->ReadString("PhotonParton:all = on");  // All dijet MEs with photons
  pythia8->ReadString("PhaseSpace:pThatMin = 4.");            // Minimal pT cut
  pythia8->ReadString("MultipartonInteractions:pT0Ref = 3."); // Tuned ep value

  // Setup of diffractive framework.
  pythia8->ReadString("Diffraction:doHard = on");
  pythia8->ReadString("Diffraction:sampleType = 1");   // 'PDF' sample
  pythia8->ReadString("Diffraction:hardDiffSide = 2"); // Diff. on photon side
  pythia8->ReadString("SigmaDiffractive:PomFlux = 7"); // H1 Fit B LO
  pythia8->ReadString("PDF:PomSet = 6");               // H1 Fit B LO

  pythia8->ReadString("Random:setSeed = on");
  pythia8->ReadString("Random:seed = 0");
  pythia8->Pythia8()->init();
