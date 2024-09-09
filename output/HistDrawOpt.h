/*
 * HistDrawOpt.h
 *
 *  Created on: 26 sie 2015
 *      Author: Khaless
 */

#include "TString.h"

#ifndef HISTDRAWOPT_H_
#define HISTDRAWOPT_H_

TString getHistDrawOpt(TObject *obj, Bool_t &logScale, Bool_t &logScaleX, Bool_t &logScaleY);

TString getHistDrawOpt(TObject *obj, Bool_t &logScale, Bool_t &logScaleX, Bool_t &logScaleY)
{
	TString drawOpt;

	TString name = obj->GetName();

	//cout<<name<<endl;

	if(!name.CompareTo("h_Events")) {
		TH1 *objH1 = dynamic_cast<TH1*>(obj);
		drawOpt = "e";
		//objH1->GetXaxis()->SetRangeUser(0.0, 1.0);
		//objH1->RebinX(16);
		//drawOpt = "e";
		//logScale=kTRUE;
	}

	if(!name.CompareTo("h_Event_nPart_final")) {
		TH1 *objH1 = dynamic_cast<TH1*>(obj);
		drawOpt = "e";
		objH1->GetXaxis()->SetRangeUser(0.0, 100.0);
		//objH1->RebinX(16);
		//drawOpt = "e";
		//logScale=kTRUE;
	}


	if(!name.CompareTo("h_Event_xQ2")) {
		TH2 *objH2 = dynamic_cast<TH2*>(obj);
		drawOpt = "colz";
		objH2->RebinY(4);
		objH2->RebinX(4);
		objH2->GetYaxis()->SetRangeUser(0.0, 1.1);
		//objH2->GetXaxis()->SetRangeUser(-TMath::Pi(), TMath::Pi());
		//drawOpt = "e";
		//logScale=kTRUE;
		logScaleX=kTRUE;
	}

	if(!name.CompareTo("h_Event_yQ2")) {
		TH2 *objH2 = dynamic_cast<TH2*>(obj);
		drawOpt = "colz";
		objH2->RebinY(4);
		objH2->RebinX(4);
		objH2->GetYaxis()->SetRangeUser(0.0, 1.1);
		//objH2->GetXaxis()->SetRangeUser(-TMath::Pi(), TMath::Pi());
		//drawOpt = "e";
		//logScale=kTRUE;
		logScaleX=kFALSE;
	}

	if(!name.CompareTo("h_Event_xy")) {
		TH2 *objH2 = dynamic_cast<TH2*>(obj);
		drawOpt = "colz";
		objH2->RebinY(4);
		objH2->RebinX(4);
		//objH2->GetYaxis()->SetRangeUser(0.0, 1.1);
		//objH2->GetXaxis()->SetRangeUser(-TMath::Pi(), TMath::Pi());
		//drawOpt = "e";
		//logScale=kTRUE;
		logScaleX=kTRUE;
	}
	if(!name.CompareTo("h_Event_nHCal_xQ2")) {
		TH2 *objH2 = dynamic_cast<TH2*>(obj);
		drawOpt = "colz";
		objH2->RebinY(4);
		objH2->RebinX(4);
		objH2->GetYaxis()->SetRangeUser(0.0, 1.1);
		//objH2->GetXaxis()->SetRangeUser(-TMath::Pi(), TMath::Pi());
		//drawOpt = "e";
		//logScale=kTRUE;
		logScaleX=kTRUE;
	}

	if(!name.CompareTo("h_Event_nHCal_yQ2")) {
		TH2 *objH2 = dynamic_cast<TH2*>(obj);
		drawOpt = "colz";
		objH2->RebinY(4);
		objH2->RebinX(4);
		objH2->GetYaxis()->SetRangeUser(0.0, 1.1);
		//objH2->GetXaxis()->SetRangeUser(-TMath::Pi(), TMath::Pi());
		//drawOpt = "e";
		//logScale=kTRUE;
		logScaleX=kFALSE;
	}

	if(!name.CompareTo("h_Event_nHCal_xy")) {
		TH2 *objH2 = dynamic_cast<TH2*>(obj);
		drawOpt = "colz";
		objH2->RebinY(4);
		objH2->RebinX(4);
		//objH2->GetYaxis()->SetRangeUser(0.0, 1.1);
		//objH2->GetXaxis()->SetRangeUser(-TMath::Pi(), TMath::Pi());
		//drawOpt = "e";
		//logScale=kTRUE;
		logScaleX=kTRUE;
	}

	if(!name.CompareTo("h_Event_nPion_p")) {
		TH1 *objH1 = dynamic_cast<TH1*>(obj);
		drawOpt = "e";
		objH1->GetXaxis()->SetRangeUser(0.0, 100.0);
		//objH1->RebinX(16);
		//drawOpt = "e";
		//logScale=kTRUE;
	}

	if(!name.CompareTo("h_Event_nPion_n")) {
		TH1 *objH1 = dynamic_cast<TH1*>(obj);
		drawOpt = "e";
		objH1->GetXaxis()->SetRangeUser(0.0, 100.0);
		//objH1->RebinX(16);
		//drawOpt = "e";
		//logScale=kTRUE;
	}

	if(!name.CompareTo("h_Event_nKaon_p")) {
		TH1 *objH1 = dynamic_cast<TH1*>(obj);
		drawOpt = "e";
		objH1->GetXaxis()->SetRangeUser(0.0, 100.0);
		//objH1->RebinX(16);
		//drawOpt = "e";
		//logScale=kTRUE;
	}

	if(!name.CompareTo("h_Event_nKaon_n")) {
		TH1 *objH1 = dynamic_cast<TH1*>(obj);
		drawOpt = "e";
		objH1->GetXaxis()->SetRangeUser(0.0, 100.0);
		//objH1->RebinX(16);
		//drawOpt = "e";
		//logScale=kTRUE;
	}

	if(!name.CompareTo("h_Event_nProton_p")) {
		TH1 *objH1 = dynamic_cast<TH1*>(obj);
		drawOpt = "e";
		objH1->GetXaxis()->SetRangeUser(0.0, 100.0);
		//objH1->RebinX(16);
		//drawOpt = "e";
		//logScale=kTRUE;
	}

	if(!name.CompareTo("h_Event_nProton_n")) {
		TH1 *objH1 = dynamic_cast<TH1*>(obj);
		drawOpt = "e";
		objH1->GetXaxis()->SetRangeUser(0.0, 100.0);
		//objH1->RebinX(16);
		//drawOpt = "e";
		//logScale=kTRUE;
	}

	if(!name.CompareTo("h_Event_nElectron_p")) {
		TH1 *objH1 = dynamic_cast<TH1*>(obj);
		drawOpt = "e";
		objH1->GetXaxis()->SetRangeUser(0.0, 100.0);
		//objH1->RebinX(16);
		//drawOpt = "e";
		//logScale=kTRUE;
	}

	if(!name.CompareTo("h_Event_nElectron_n")) {
		TH1 *objH1 = dynamic_cast<TH1*>(obj);
		drawOpt = "e";
		objH1->GetXaxis()->SetRangeUser(0.0, 100.0);
		//objH1->RebinX(16);
		//drawOpt = "e";
		//logScale=kTRUE;
	}

	if(!name.CompareTo("h_Event_nNeutron")) {
		TH1 *objH1 = dynamic_cast<TH1*>(obj);
		drawOpt = "e";
		objH1->GetXaxis()->SetRangeUser(0.0, 100.0);
		//objH1->RebinX(16);
		//drawOpt = "e";
		//logScale=kTRUE;
	}

	if(!name.CompareTo("h_Event_nGamma")) {
		TH1 *objH1 = dynamic_cast<TH1*>(obj);
		drawOpt = "e";
		objH1->GetXaxis()->SetRangeUser(0.0, 100.0);
		//objH1->RebinX(16);
		//drawOpt = "e";
		//logScale=kTRUE;
	}


/*
	if(!name.CompareTo("NtracksBvsF")) {
		TH2 *objH2 = dynamic_cast<TH2*>(obj);
		drawOpt = "colz";
		logScale=kFALSE;
		//objH2->GetXaxis()->SetRangeUser(-TMath::Pi(), TMath::Pi());
		//objH2->GetYaxis()->SetRangeUser(-TMath::Pi(), TMath::Pi());
		objH2->SetTitle("Number of tracks backward vs. forward");
		objH2->GetXaxis()->SetTitle("Ntracks backward");
		objH2->GetYaxis()->SetTitle("Ntracks forward");
	}
*/



	return drawOpt;
}



#endif /* HISTDRAWOPT_H_ */
