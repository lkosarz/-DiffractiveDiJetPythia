#include <exception>
#include <assert.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

#include "TString.h"
#include "TClonesArray.h"
#include "TRefArray.h"
#include "TRef.h"
#include "TFile.h"
#include "TArrayI.h"
#include "TTree.h"
#include "TH1.h"
#include "TH1I.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TBranch.h"
#include "TMultiGraph.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TPaveLabel.h"
#include "TStyle.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TMath.h"
#include "TProfile.h"
#include "TLatex.h"

#include "style.C"

#include "drawAcceptance_Q2.C"
#include "drawAcceptance_x.C"
#include "drawAcceptance_y.C"
#include "drawAcceptanceMeas_Q2.C"
#include "drawAcceptanceMeas_x.C"
#include "drawAcceptanceMeas_y.C"

using namespace std;


/////////////////////////////////////////////////////////////
void drawAcceptance_All(TString infile = "data/diffractiveDiJets_ep_18x275GeV_ee_genkT_full.root") {

	style();
	gStyle->SetOptStat(0);
	gROOT->ForceStyle();

	Int_t padw = 800, padh = 530;

	const Int_t nPadX = 2;
	const Int_t nPadY = 1;

	drawAcceptance_Q2(infile);
	drawAcceptance_x(infile);
	drawAcceptance_y(infile);

	drawAcceptanceMeas_Q2(infile);
	drawAcceptanceMeas_x(infile);
	drawAcceptanceMeas_y(infile);

}
