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

using namespace std;


/////////////////////////////////////////////////////////////
void drawAcceptanceMatrix(TString infile = "data/diffractiveDiJets_ep_18x275GeV_ee_genkT_full.root", TString mkdir = "Acceptance", TString outfile = "AcceptanceMatrix.root") {

	style();
	gStyle->SetOptStat(0);
	gROOT->ForceStyle();

	Int_t padw = 800, padh = 530;

	const Int_t nPadX = 2;
	const Int_t nPadY = 1;

	//infile = "data/diffractiveDiJets_ep_18x275GeV_anti_kT_full.root";
	infile = "data/diffractiveDiJets_ep_18x275GeV_anti_kT_pT4GeV_full.root";
	//infile = "data/diffractiveDiJets_ep_18x275GeV_anti_kT_E4GeV_full.root";

	gSystem->MakeDirectory("output");
	gSystem->cd("output");
	gSystem->MakeDirectory(mkdir.Data());
	gSystem->cd(mkdir);
	TFile *fileOut = new TFile(outfile, "recreate");
	fileOut->cd();
	gSystem->cd("../");
	gSystem->cd("../");

	TFile *file = TFile::Open(infile);

	TCanvas *cnv = new TCanvas("cnv_jets", "Jets in HCals Matrix", nPadX*padw, nPadY*padh);
	TCanvas *cnv_meas = new TCanvas("cnv_jets_meas", "Jets measured in HCals Matrix", nPadX*padw, nPadY*padh);
	cnv->Divide(nPadX,nPadY);
	cnv_meas->Divide(nPadX,nPadY);

	TH2D *hist = (TH2D *)file->Get("h_Event_HCal_jets");
	TH2D *hist_meas = (TH2D *)file->Get("h_Event_HCal_jets_meas");
	TH1D *histEvents = (TH1D *)file->Get("h_Events_types");

	//double nEvents = histEvents->GetEntries();
	double nEvents = histEvents->GetBinContent(3); // 2 partons in ePIC acc.

	cout<<"Starting loop"<<endl;

	hist->SetMarkerSize(1.8);
	hist_meas->SetMarkerSize(1.8);

	hist->Sumw2();
	hist_meas->Sumw2();
	//hist->Divide(hist, hist_den, 1.0, 1.0, "b");

	hist->Scale(1.0/nEvents);
	hist_meas->Scale(1.0/nEvents);


	gSystem->cd("output");
	gSystem->cd(mkdir.Data());

	cnv->cd(1);
	hist->Draw("colzTEXT");

	cnv->cd(2)->SetLogz();
	hist->Draw("colzTEXT");


	cnv_meas->cd(1);
	hist_meas->Draw("colzTEXT");

	cnv_meas->cd(2)->SetLogz();
	hist_meas->Draw("colzTEXT");

	cnv->cd(1)->SaveAs("AcceptanceMatrix.png");
	cnv->cd(2)->SaveAs("AcceptanceMatrix_log.png");

	cnv_meas->cd(1)->SaveAs("AcceptanceMatrix_meas.png");
	cnv_meas->cd(2)->SaveAs("AcceptanceMatrix_meas_log.png");

	//--------------------------------------------

	gSystem->cd("../");
	gSystem->cd("../");

	//fileOut->cd();
	fileOut->Write();

}
