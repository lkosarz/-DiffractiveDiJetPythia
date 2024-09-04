/*
 * HistogramsPythia.h
 *
 *  Created on: 30 sie 2024
 *      Author: Khaless
 */

#ifndef HISTOGRAMSPYTHIA_H_
#define HISTOGRAMSPYTHIA_H_

#include "TH1.h"
#include "TH2.h"
#include "TH3.h"

int CreateHistograms();


TH2F *h_xQ2;
TH2F *h_yQ2;
TH2F *h_xy;






int CreateHistograms()
{

	h_xQ2 = new TH2F("h_xQ2", "Event Q^{2} vs. x; x [1]; Q^{2} [GeV^{2}/c^{2}]", 1000, 0.0, 1.0, 1000, 0.0, 10.0);
	h_yQ2 = new TH2F("h_yQ2", "Event Q^{2} vs. inelasticity y; y [1]; Q^{2} [GeV^{2}/c^{2}]", 1000, 0.0, 1.0, 1000, 0.0, 10.0);
	h_xy = new TH2F("h_xy", "Event inelasticity y vs. x; x [1]; y [1]", 1000, 0.0, 1.0, 1000, 0.0, 1.0);


	return 1;
}


#endif /* HISTOGRAMSPYTHIA_H_ */
