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

using namespace std;


void MakeLogBins(double *array, int nbins, int nBinPerDecimal, double binLo, double binHi);
void printArray(double *arr, int size);


/////////////////////////////////////////////////////////////
Int_t testLogBins() {

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

	const Int_t nPadX = 1;
	const Int_t nPadY = 1;

	TGaxis::SetExponentOffset(0.02, -0.07, "x");
/*
	TString data = "data";
	gSystem->cd(data);


	gSystem->cd("../");
*/

	TCanvas *cnv = new TCanvas("cnv", "cnv", nPadX*padw, nPadY*padh);

	//cnv->Divide(nPadX, nPadY);

	const int nbins = 200;
	const int nbinEdg = nbins+1;

	double *logBinsArray = new double[nbins];

	MakeLogBins(logBinsArray, nbins, 0, 10e-6, 1.0);

	printArray(logBinsArray, nbinEdg);


	TH1D *h_Energy = new TH1D("h_Energy", "Energy; E [GeV]", nbins, logBinsArray);
/*
	for (int i = 0; i < 10e4; ++i) {
		h_Energy->FillRandom("gaus", 10e4);
	}*/

	h_Energy->FillRandom("gaus", 10e4);

	cnv->cd();
	h_Energy->Draw("e");



	return 1.0;

}


void MakeLogBins(double *array, int nbins, int nBinPerDecimal, double binLo, double binHi)
{
	//double exp = (nbinEdg-1)/nBinPerDecimal;

    // Calculate the logarithmic bin edges
    double logMin = log10(binLo);
    double logMax = log10(binHi);
    double binWidth = (logMax - logMin) / nbins;

    for (int i = 0; i <= nbins; ++i) {
    	array[i] = pow(10, logMin + i * binWidth);
    }
}


void printArray(Double_t *arr, int size)
{
	for (int i = 0; i < size; ++i) {

		cout<<arr[i]<<", ";

	}
	cout<<endl;
}
