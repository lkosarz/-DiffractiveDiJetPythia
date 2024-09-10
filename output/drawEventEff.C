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
#include "TKey.h"
#include "TProfile.h"
#include "TGaxis.h"
#include "TList.h"

//Int_t padw = 800, padh = 600;

#include "style.C"
#include "DrawHistFile.h"
#include "HistDrawOpt.h"

using namespace std;




/////////////////////////////////////////////////////////////
Int_t drawEventEff(TString name_in = "AuAu200_P16id_SL18f_noRefMultBias_0mult20_full.root", TString name_out = "TrackPhiCheck_PrimTrkId.root") {

	style();
	//gStyle->SetOptStat(0);
	gROOT->ForceStyle();
	//gStyle->SetLineColor(kBlue);
	//gStyle->SetHistLineColor(kBlue);
	gStyle->SetHistLineColor(kBlack);
	gStyle->SetPaintTextFormat(".2e");
	gStyle->SetHistLineWidth(2);
	gStyle->SetOptTitle(1);
	gStyle->SetOptStat(1);

	Int_t padw = 600, padh = 400;

	const Int_t nPadX = 2;
	const Int_t nPadY = 1;

	TGaxis::SetExponentOffset(0.02, -0.07, "x");

	TString data = "data";
	gSystem->cd(data);

	TFile *file_in = new TFile(name_in, "read");

	gSystem->cd("../");


	TCanvas *cnv = new TCanvas("cnv", "cnv", nPadX*padw, nPadY*padh);
	TCanvas *cnv_log = new TCanvas("cnv_log", "cnv_log", nPadX*padw, nPadY*padh);

	TCanvas *cnv_phi = new TCanvas("cnv_phi", "cnv_phi", nPadX*padw, nPadY*padh);
	TCanvas *cnv_phi_log = new TCanvas("cnv_phi_log", "cnv_phi_log", nPadX*padw, nPadY*padh);

	TCanvas *cnv_profY = new TCanvas("cnv_profY", "cnv_profY", nPadX*padw, nPadY*padh);

	cnv->Divide(nPadX, nPadY);
	cnv_log->Divide(nPadX, nPadY);
	cnv_phi->Divide(nPadX, nPadY);
	cnv_phi_log->Divide(nPadX, nPadY);
	cnv_profY->Divide(nPadX, nPadY);

	TString outputdir = "EventEff";

	gSystem->cd("output");
	gSystem->mkdir(outputdir);
	gSystem->cd(outputdir);
	//cnv->cd()->SaveAs("hEventStat0.png");
	TFile *file_out = new TFile(name_out, "recreate");
	file_out->cd();
	gSystem->cd("../");
	gSystem->cd("../");

	vector<TString> *list = new vector<TString>;


	TH2D *h_Event_xQ2 = (TH2D *)file_in->Get("h_Event_xQ2");
	TH2D *h_Event_yQ2 = (TH2D *)file_in->Get("h_Event_yQ2");
	TH2D *h_Event_xy = (TH2D *)file_in->Get("h_Event_xy");

	TH2D *h_Event_nHCal_xQ2 = (TH2D *)file_in->Get("h_Event_nHCal_xQ2");
	TH2D *h_Event_nHCal_yQ2 = (TH2D *)file_in->Get("h_Event_nHCal_yQ2");
	TH2D *h_Event_nHCal_xy = (TH2D *)file_in->Get("h_Event_nHCal_xy");

/*
	TProfile *prof_IdPhi_x = h_IdPhi->ProfileX("_pfx");
	TProfile *prof_IddPhi_x = h_IddPhi->ProfileX("_pfx");

	TProfile *prof_IdPhi_y = h_IdPhi->ProfileY("_pfy");
	TProfile *prof_IddPhi_y = h_IddPhi->ProfileY("_pfy");
*/
	h_IdPhi->GetYaxis()->SetRangeUser(-TMath::Pi(), TMath::Pi());
	h_IddPhi->GetYaxis()->SetRangeUser(-TMath::Pi(), TMath::Pi());

	h_IdPhi->GetXaxis()->SetRangeUser(0.0, 100.0);
	h_IddPhi->GetXaxis()->SetRangeUser(0.0, 100.0);


	prof_IdPhi_y->GetXaxis()->SetRangeUser(-TMath::Pi(), TMath::Pi());
	prof_IddPhi_y->GetXaxis()->SetRangeUser(-TMath::Pi(), TMath::Pi());

	//prof_IdPhi_y->SetLineColor(kGray);
	//prof_IddPhi_y->SetLineColor(kGray);


	cnv->cd(1);
	h_IdPhi->Draw("colz");
	prof_IdPhi_x->Draw("samee");
	cnv->cd(2);
	h_IddPhi->Draw("colz");
	prof_IddPhi_x->Draw("samee");


	cnv_log->cd(1)->SetLogz();
	h_IdPhi->Draw("colz");
	prof_IdPhi_x->Draw("samee");
	//prof_IdPhi_y->Draw("samee");

	cnv_log->cd(2)->SetLogz();
	h_IddPhi->Draw("colz");
	prof_IddPhi_x->Draw("samee");
	//prof_IddPhi_y->Draw("samee");


	// proj
	cnv_phi->cd(1);
	h_IdPhi_phi->Draw("e");
	cnv_phi->cd(2);
	h_IddPhi_phi->Draw("e");


	cnv_phi_log->cd(1)->SetLogy();
	h_IdPhi_phi->Draw("e");

	cnv_phi_log->cd(2)->SetLogy();
	h_IddPhi_phi->Draw("e");



	cnv_profY->cd(1);
	prof_IdPhi_y->Draw("samee");
	cnv_profY->cd(2);
	prof_IddPhi_y->Draw("samee");

	gSystem->cd("output");
	gSystem->cd(outputdir);

	cnv->cd(1)->SaveAs("h_IdPtrkPhi.png");
	cnv_log->cd(1)->SaveAs("h_IdPtrkPhi_log.png");
	cnv->cd(2)->SaveAs("h_IdPtrkdPhi.png");
	cnv_log->cd(2)->SaveAs("h_IdPtrkdPhi_log.png");

	cnv_phi->cd(1)->SaveAs("h_Phi.png");
	cnv_phi_log->cd(1)->SaveAs("h_Phi_log.png");

	cnv_profY->cd(1)->SaveAs("prof_IdPtrkPhi_y.png");
	cnv_profY->cd(2)->SaveAs("prof_IdPtrkdPhi_y.png");

	gSystem->cd("../");
	gSystem->cd("../");


	file_out->Write();

	//file_out->Close();

	return 1.0;

}
