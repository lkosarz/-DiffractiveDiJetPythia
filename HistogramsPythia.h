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



// Event

TH1D *h_Events;

TH1D *h_Event_nPart_final;

TH2F *h_Event_xQ2;
TH2F *h_Event_yQ2;
TH2F *h_Event_xy;

TH2F *h_Event_nHCal_xQ2;
TH2F *h_Event_nHCal_yQ2;
TH2F *h_Event_nHCal_xy;

TH1D *h_Event_nPion_p;
TH1D *h_Event_nPion_n;
TH1D *h_Event_nKaon_p;
TH1D *h_Event_nKaon_n;
TH1D *h_Event_nProton_p;
TH1D *h_Event_nProton_n;
TH1D *h_Event_nElectron_p;
TH1D *h_Event_nElectron_n;

TH1D *h_Event_nNeutron;
TH1D *h_Event_nGamma;


// Particles

TH2D *h_Particle_eta_p;
TH2D *h_Particle_eta_pT;
TH2D *h_Particle_eta_E;

// eta, momentum
TH2D *h_Particle_pion_p_eta_p;
TH2D *h_Particle_pion_n_eta_p;
TH2D *h_Particle_Kaon_p_eta_p;
TH2D *h_Particle_Kaon_n_eta_p;
TH2D *h_Particle_proton_p_eta_p;
TH2D *h_Particle_proton_n_eta_p;
TH2D *h_Particle_Electron_p_eta_p;
TH2D *h_Particle_Electron_n_eta_p;

TH2D *h_Particle_Neutron_eta_p;
TH2D *h_Particle_Gamma_eta_p;

// eta, transverse momentum pT
TH2D *h_Particle_pion_p_eta_pT;
TH2D *h_Particle_pion_n_eta_pT;
TH2D *h_Particle_Kaon_p_eta_pT;
TH2D *h_Particle_Kaon_n_eta_pT;
TH2D *h_Particle_proton_p_eta_pT;
TH2D *h_Particle_proton_n_eta_pT;
TH2D *h_Particle_Electron_p_eta_pT;
TH2D *h_Particle_Electron_n_eta_pT;

TH2D *h_Particle_Neutron_eta_pT;
TH2D *h_Particle_Gamma_eta_pT;

// eta, energy
TH2D *h_Particle_Pion_p_eta_E;
TH2D *h_Particle_Pion_n_eta_E;
TH2D *h_Particle_Kaon_p_eta_E;
TH2D *h_Particle_Kaon_n_eta_E;
TH2D *h_Particle_Proton_p_eta_E;
TH2D *h_Particle_Proton_n_eta_E;
TH2D *h_Particle_Electron_p_eta_E;
TH2D *h_Particle_Electron_n_eta_E;

TH2D *h_Particle_Neutron_eta_E;
TH2D *h_Particle_Gamma_eta_E;


int CreateHistograms()
{


	// Event

	h_Events = new TH1D("h_Events", "Number of events; events; counts", 10, 0.0, 10.0);

	h_Event_nPart_final = new TH1D("h_Event_nPart_final", "Number of final MC particles; N_{MC} [1]; counts", 2001, -0.5, 2000.5);

	h_Event_xQ2 = new TH2F("h_Event_xQ2", "Event Q^{2} vs. x; x [1]; Q^{2} [GeV^{2}/c^{2}]", 1000, 0.0, 1.0, 1000, 0.0, 10.0);
	h_Event_yQ2 = new TH2F("h_Event_yQ2", "Event Q^{2} vs. inelasticity y; y [1]; Q^{2} [GeV^{2}/c^{2}]", 1000, 0.0, 1.0, 1000, 0.0, 10.0);
	h_Event_xy = new TH2F("h_Event_xy", "Event inelasticity y vs. x; x [1]; y [1]", 1000, 0.0, 1.0, 1000, 0.0, 1.0);


	h_Event_nHCal_xQ2 = new TH2F("h_Event_nHCal_xQ2", "Event with nHCal activity Q^{2} vs. x; x [1]; Q^{2} [GeV^{2}/c^{2}]", 1000, 0.0, 1.0, 1000, 0.0, 10.0);
	h_Event_nHCal_yQ2 = new TH2F("h_Event_nHCal_yQ2", "Event with nHCal activity Q^{2} vs. inelasticity y; y [1]; Q^{2} [GeV^{2}/c^{2}]", 1000, 0.0, 1.0, 1000, 0.0, 10.0);
	h_Event_nHCal_xy = new TH2F("h_Event_nHCal_xy", "Event with nHCal activity inelasticity y vs. x; x [1]; y [1]", 1000, 0.0, 1.0, 1000, 0.0, 1.0);


	h_Event_nPion_p = new TH1D("h_Event_nPion_p", "Number of MC particles #pi^{+}; N_{MC} [1]; counts", 2001, -0.5, 2000.5);
	h_Event_nPion_n = new TH1D("h_Event_nPion_n", "Number of MC particles #pi^{-}; N_{MC} [1]; counts", 2001, -0.5, 2000.5);
	h_Event_nKaon_p = new TH1D("h_Event_nKaon_p", "Number of MC particles K^{+}; N_{MC} [1]; counts", 2001, -0.5, 2000.5);
	h_Event_nKaon_n = new TH1D("h_Event_nKaon_n", "Number of MC particles K^{-}; N_{MC} [1]; counts", 2001, -0.5, 2000.5);
	h_Event_nProton_p = new TH1D("h_Event_nProton_p", "Number of MC particles p^{+}; N_{MC} [1]; counts", 2001, -0.5, 2000.5);
	h_Event_nProton_n = new TH1D("h_Event_nProton_n", "Number of MC particles p^{-}; N_{MC} [1]; counts", 2001, -0.5, 2000.5);
	h_Event_nElectron_p = new TH1D("h_Event_nElectron_p", "Number of MC particles e^{+}; N_{MC} [1]; counts", 2001, -0.5, 2000.5);
	h_Event_nElectron_n = new TH1D("h_Event_nElectron_n", "Number of MC particles e^{-}; N_{MC} [1]; counts", 2001, -0.5, 2000.5);

	h_Event_nNeutron = new TH1D("h_Event_nNeutron", "Number of MC particles n; N_{MC} [1]; counts", 2001, -0.5, 2000.5);
	h_Event_nGamma = new TH1D("h_Event_nGamma", "Number of MC particles #gamma; N_{MC} [1]; counts", 2001, -0.5, 2000.5);



	// Particles
	h_Particle_eta_p = new TH2D("h_Particle_eta_p", "MC particles #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_eta_pT = new TH2D("h_Particle_eta_pT", "MC particles #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_eta_E = new TH2D("h_Particle_eta_E", "MC particles #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);


    // eta, momentum
	h_Particle_pion_p_eta_p = new TH2D("h_Particle_Pion_p_eta_p", "MC particles #pi^{+} #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_pion_n_eta_p = new TH2D("h_Particle_Pion_n_eta_p", "MC particles #pi^{-} #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Kaon_p_eta_p = new TH2D("h_Particle_Kaon_p_eta_p", "MC particles K^{+} #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Kaon_n_eta_p = new TH2D("h_Particle_Kaon_n_eta_p", "MC particles K^{-} #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_proton_p_eta_p = new TH2D("h_Particle_Proton_p_eta_p", "MC particles p^{+} #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_proton_n_eta_p = new TH2D("h_Particle_Proton_n_eta_p", "MC particles p^{-} #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Electron_p_eta_p = new TH2D("h_Particle_Electron_p_eta_p", "MC particles e^{+} #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Electron_n_eta_p = new TH2D("h_Particle_Electron_n_eta_p", "MC particles e^{-} #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);

	h_Particle_Neutron_eta_p = new TH2D("h_Particle_Neutron_eta_p", "MC particles n #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Gamma_eta_p = new TH2D("h_Particle_Gamma_eta_p", "MC particles #gamman #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);


    // eta, transverse momentum pT
	h_Particle_pion_p_eta_pT = new TH2D("h_Particle_Pion_p_eta_pT", "MC particles #pi^{+} #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_pion_n_eta_pT = new TH2D("h_Particle_Pion_n_eta_pT", "MC particles #pi^{-} #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Kaon_p_eta_pT = new TH2D("h_Particle_Kaon_p_eta_pT", "MC particles K^{+} #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Kaon_n_eta_pT = new TH2D("h_Particle_Kaon_n_eta_pT", "MC particles K^{-} #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_proton_p_eta_pT = new TH2D("h_Particle_Proton_p_eta_pT", "MC particles p^{+} #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_proton_n_eta_pT = new TH2D("h_Particle_Proton_n_eta_pT", "MC particles p^{-} #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Electron_p_eta_pT = new TH2D("h_Particle_Electron_p_eta_pT", "MC particles e^{+} #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Electron_n_eta_pT = new TH2D("h_Particle_Electron_n_eta_pT", "MC particles e^{-} #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);

	h_Particle_Neutron_eta_pT = new TH2D("h_Particle_Neutron_eta_pT", "MC particles n #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Gamma_eta_pT = new TH2D("h_Particle_Gamma_eta_pT", "MC particles #gamman #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);


	// eta, energy
	h_Particle_Pion_p_eta_E = new TH2D("h_Particle_Pion_p_eta_E", "MC particles #pi^{+} #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Pion_n_eta_E = new TH2D("h_Particle_Pion_n_eta_E", "MC particles #pi^{-} #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Kaon_p_eta_E = new TH2D("h_Particle_Kaon_p_eta_E", "MC particles K^{+} #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Kaon_n_eta_E = new TH2D("h_Particle_Kaon_n_eta_E", "MC particles K^{-} #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Proton_p_eta_E = new TH2D("h_Particle_Proton_p_eta_E", "MC particles p^{+} #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Proton_n_eta_E = new TH2D("h_Particle_Proton_n_eta_E", "MC particles p^{-} #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Electron_p_eta_E = new TH2D("h_Particle_Electron_p_eta_E", "MC particles e^{+} #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Electron_n_eta_E = new TH2D("h_Particle_Electron_n_eta_E", "MC particles e^{-} #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);

	h_Particle_Neutron_eta_E = new TH2D("h_Particle_Neutron_eta_E", "MC particles n #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Gamma_eta_E = new TH2D("h_Particle_Gamma_eta_E", "MC particles #gamma #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);



	return 1;
}


#endif /* HISTOGRAMSPYTHIA_H_ */
