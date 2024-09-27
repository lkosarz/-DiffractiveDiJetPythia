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
void drawAcceptance_Q2(TString infile = "data/diffractiveDiJets_ep_18x275GeV_anti_kT_full.root", TString mkdir = "Acceptance", TString outfile = "Acceptance_Q2.root") {

	style();
	gStyle->SetOptStat(0);
	gROOT->ForceStyle();

	Int_t padw = 800, padh = 530;

	const Int_t nPadX = 2;
	const Int_t nPadY = 1;

	const Int_t nFiles = 4;

	vector<TFile*> *files = new vector<TFile*>;

	files->push_back(TFile::Open(infile));
	files->push_back(TFile::Open(infile));
	files->push_back(TFile::Open(infile));
	files->push_back(TFile::Open(infile));

	gSystem->MakeDirectory("output");
	gSystem->cd("output");
	gSystem->MakeDirectory(mkdir.Data());
	gSystem->cd(mkdir);
	TFile *fileOut = new TFile(outfile, "recreate");
	fileOut->cd();
	gSystem->cd("../");
	gSystem->cd("../");


	vector<TH1D*> *hists = new vector<TH1D*>;
	vector<TH1D*> *hists_den = new vector<TH1D*>;

	vector<TCanvas*> *vec_cnv = new vector<TCanvas*>;
	vector<TLegend*> *legends = new vector<TLegend*>;
	vector<TString> *names = new vector<TString>;
	vector<TString> *names_den = new vector<TString>;
	vector<int> *colors = new vector<int>;
	vector<TString> *drawOpt = new vector<TString>;
	vector<TString> *labels = new vector<TString>;

	vector<bool> *log = new vector<bool>;
	vector<int> *rebin = new vector<int>;
	vector<double> *range_hi = new vector<double>;
	vector<double> *range_lo = new vector<double>;

	names->push_back("h_Event_nHCal_2_Q2");
	names->push_back("h_Event_nHCal_1_Q2");
	names->push_back("h_Event_nHCal_0_Q2");
	names->push_back("h_Event_AllHCal_Q2");

	names_den->push_back("h_Event_Q2");
	names_den->push_back("h_Event_Q2");
	names_den->push_back("h_Event_Q2");
	names_den->push_back("h_Event_Q2");


	log->push_back(true);

	colors->push_back(kRed);
	colors->push_back(kBlue);
	colors->push_back(kBlack);
	colors->push_back(kMagenta);
	//colors->push_back(kGreen);
	//colors->push_back(kTeal);

	drawOpt->push_back("e");
	drawOpt->push_back("samee");
	drawOpt->push_back("samee");
	drawOpt->push_back("samee");

	legends->push_back(new TLegend(0.7, 0.6, 1.0, 1.0));
	//legends->push_back(new TLegend(0.7, 0.6, 0.75, 1.0));
	//legends_mean->push_back(new TLegend(0.75, 0.6, 1.0, 1.0));

	labels->push_back("2 jets in nHCal");
	labels->push_back("1 jet in nHCal");
	labels->push_back("0 jets in nHCal");
	labels->push_back("jets in any HCal");

/*
	rebin->push_back(4);
	rebin->push_back(4);
	rebin->push_back(4);
	rebin->push_back(4);
*/
	range_hi->push_back(0.5);
	range_lo->push_back(0.0);

	vec_cnv->push_back(new TCanvas("cnv_jets", "Jets in HCals", nPadX*padw, nPadY*padh));

	cout<<"Starting loop"<<endl;

	for (int i = 0; i < names->size(); ++i) {

		TH1D *hist = (TH1D *)files->at(i)->Get(names->at(i));
		TH1D *hist_den = (TH1D *)files->at(i)->Get(names_den->at(i));

		//int biny_hi = hist->GetXaxis()->FindBin(etahi);
		//int biny_lo = hist->GetXaxis()->FindBin(etalo);

		//TH1D *hist = (TH1D *)hist2d->ProjectionY(Form("%s_px", hist2d->GetName()), biny_lo, biny_hi);

		//hist->SetName(Form("data_%s", hist->GetName()));

		cout<<hist->GetName()<<endl;

		//hist->Rebin(rebin->at(i));


		hist->Sumw2();
		hist->Divide(hist, hist_den, 1.0, 1.0, "b");

		hist->GetXaxis()->SetRangeUser(range_lo->at(0), range_hi->at(0));
		hist->GetYaxis()->SetRangeUser(0.00001, 1.0);

		hists->push_back(hist);
		hists_den->push_back(hist_den);

		cout<<i<<endl;
	}


	gSystem->cd("output");
	gSystem->cd(mkdir.Data());

	vec_cnv->at(0)->Divide(nPadX,nPadY);

	for (int i = 0; i < hists->size(); ++i) {

		cout<<i<<endl;


		//hists->at(i)->Scale(1.0/hists->at(i)->Integral());

		hists->at(i)->SetLineColor(colors->at(i));
		
		legends->at(0)->AddEntry(hists->at(i), labels->at(i));
		//legends->at(i/nFiles)->AddEntry(hists->at(i), Form("%s <E> = %.2f [GeV]", labels->at(i).Data(), hists->at(i)->GetMean()));
		//legends_mean->at(i/nFiles)->AddEntry((TObject*)0, Form("<E> = %.2f [GeV]", hists->at(i)->GetMean()), "");

		vec_cnv->at(0)->cd(1);
		hists->at(i)->Draw(drawOpt->at(i));

		vec_cnv->at(0)->cd(2)->SetLogy();
		hists->at(i)->Draw(drawOpt->at(i));

		//legends_mean->at(i/nFiles)->Draw("same");
		//legends->at(0)->Draw("same");


		//cout<<hists->at(i)->GetName()<<"\t mean E = "<<hists->at(i)->GetMean()<<endl;

		//vec_cnv->at(i/nFiles)->cd(1)->SaveAs(Form("%s.png", hists->at(i)->GetName()));
		//hists->at(i)->Write();
	}

	vec_cnv->at(0)->cd(1);
	legends->at(0)->Draw("same");
	//vec_cnv->at(0)->cd(2);
	//legends->at(0)->Draw("same");

	//TLatex *latex = new TLatex();
	//latex->SetNDC();
	//latex->DrawLatex(0.5, 0.75, Form("%.2f<#eta<%.2f", etalo, etahi));

	//vec_cnv->at(0)->cd(1)->SaveAs(Form("Acceptance_.png", pngfile.Data(), etalo, etahi));
	vec_cnv->at(0)->cd(1)->SaveAs("Acceptance_Q2.png");
	vec_cnv->at(0)->cd(2)->SaveAs("Acceptance_Q2_log.png");

	//--------------------------------------------

	gSystem->cd("../");
	gSystem->cd("../");

	//fileOut->cd();
	fileOut->Write();

}
