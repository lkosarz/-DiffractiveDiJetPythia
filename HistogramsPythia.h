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

TH1F *h_Events;

TH1F *h_Event_nPart_final;

TH2F *h_Event_xQ2;
TH2F *h_Event_yQ2;
TH2F *h_Event_xy;

TH2F *h_Event_nHCal_xQ2;
TH2F *h_Event_nHCal_yQ2;
TH2F *h_Event_nHCal_xy;

TH1F *h_Event_nPion_p;
TH1F *h_Event_nPion_n;
TH1F *h_Event_nKaon_p;
TH1F *h_Event_nKaon_n;
TH1F *h_Event_nProton_p;
TH1F *h_Event_nProton_n;
TH1F *h_Event_nElectron_p;
TH1F *h_Event_nElectron_n;

TH1F *h_Event_nNeutron;
TH1F *h_Event_nGamma;

// special


TH1F *h_Event_Q2;
TH1F *h_Event_x;
TH1F *h_Event_y;

TH1F *h_Event_nHCal_0_Q2;
TH1F *h_Event_nHCal_0_x;
TH1F *h_Event_nHCal_0_y;

TH1F *h_Event_nHCal_1_Q2;
TH1F *h_Event_nHCal_1_x;
TH1F *h_Event_nHCal_1_y;

TH1F *h_Event_nHCal_2_Q2;
TH1F *h_Event_nHCal_2_x;
TH1F *h_Event_nHCal_2_y;

TH1F *h_Event_AllHCal_Q2;
TH1F *h_Event_AllHCal_x;
TH1F *h_Event_AllHCal_y;

TH2F *h_Event_HCal_jets;

// Particles

TH1F *h_Particle_eta;

TH2F *h_Particle_eta_p;
TH2F *h_Particle_eta_pT;
TH2F *h_Particle_eta_E;


// weighted
TH1F *h_Particle_eta_wE;

// eta, momentum
TH2F *h_Particle_pion_p_eta_p;
TH2F *h_Particle_pion_n_eta_p;
TH2F *h_Particle_Kaon_p_eta_p;
TH2F *h_Particle_Kaon_n_eta_p;
TH2F *h_Particle_proton_p_eta_p;
TH2F *h_Particle_proton_n_eta_p;
TH2F *h_Particle_Electron_p_eta_p;
TH2F *h_Particle_Electron_n_eta_p;

TH2F *h_Particle_Neutron_eta_p;
TH2F *h_Particle_Gamma_eta_p;

// eta, transverse momentum pT
TH2F *h_Particle_pion_p_eta_pT;
TH2F *h_Particle_pion_n_eta_pT;
TH2F *h_Particle_Kaon_p_eta_pT;
TH2F *h_Particle_Kaon_n_eta_pT;
TH2F *h_Particle_proton_p_eta_pT;
TH2F *h_Particle_proton_n_eta_pT;
TH2F *h_Particle_Electron_p_eta_pT;
TH2F *h_Particle_Electron_n_eta_pT;

TH2F *h_Particle_Neutron_eta_pT;
TH2F *h_Particle_Gamma_eta_pT;

// eta, energy
TH2F *h_Particle_Pion_p_eta_E;
TH2F *h_Particle_Pion_n_eta_E;
TH2F *h_Particle_Kaon_p_eta_E;
TH2F *h_Particle_Kaon_n_eta_E;
TH2F *h_Particle_Proton_p_eta_E;
TH2F *h_Particle_Proton_n_eta_E;
TH2F *h_Particle_Electron_p_eta_E;
TH2F *h_Particle_Electron_n_eta_E;

TH2F *h_Particle_Neutron_eta_E;
TH2F *h_Particle_Gamma_eta_E;



// temp

TH1F *hist_eta_energy_tmp;
TH1F *hist_eta_energy_denom_tmp;



int CreateHistograms()
{


	// Event

	h_Events = new TH1F("h_Events", "Number of events; events; counts", 10, 0.0, 10.0);

	h_Event_nPart_final = new TH1F("h_Event_nPart_final", "Number of final MC particles; N_{MC} [1]; counts", 2001, -0.5, 2000.5);

	h_Event_xQ2 = new TH2F("h_Event_xQ2", "Event Q^{2} vs. x; x [1]; Q^{2} [GeV^{2}/c^{2}]; counts", 10000, 0.0, 0.02, 500, 0.0, 5.0);
	h_Event_yQ2 = new TH2F("h_Event_yQ2", "Event Q^{2} vs. inelasticity y; y [1]; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 1.0, 500, 0.0, 5.0);
	h_Event_xy = new TH2F("h_Event_xy", "Event inelasticity y vs. x; x [1]; y [1]; counts", 10000, 0.0, 0.02, 1000, 0.0, 1.0);


	h_Event_nHCal_xQ2 = new TH2F("h_Event_nHCal_xQ2", "Event with nHCal activity Q^{2} vs. x; x [1]; Q^{2} [GeV^{2}/c^{2}]; counts", 10000, 0.0, 0.02, 500, 0.0, 5.0);
	h_Event_nHCal_yQ2 = new TH2F("h_Event_nHCal_yQ2", "Event with nHCal activity Q^{2} vs. inelasticity y; y [1]; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 1.0, 500, 0.0, 5.0);
	h_Event_nHCal_xy = new TH2F("h_Event_nHCal_xy", "Event with nHCal activity inelasticity y vs. x; x [1]; y [1]; counts", 10000, 0.0, 0.02, 1000, 0.0, 1.0);


	h_Event_nPion_p = new TH1F("h_Event_nPion_p", "Number of MC particles #pi^{+}; N_{MC} [1]; counts", 2001, -0.5, 2000.5);
	h_Event_nPion_n = new TH1F("h_Event_nPion_n", "Number of MC particles #pi^{-}; N_{MC} [1]; counts", 2001, -0.5, 2000.5);
	h_Event_nKaon_p = new TH1F("h_Event_nKaon_p", "Number of MC particles K^{+}; N_{MC} [1]; counts", 2001, -0.5, 2000.5);
	h_Event_nKaon_n = new TH1F("h_Event_nKaon_n", "Number of MC particles K^{-}; N_{MC} [1]; counts", 2001, -0.5, 2000.5);
	h_Event_nProton_p = new TH1F("h_Event_nProton_p", "Number of MC particles p^{+}; N_{MC} [1]; counts", 2001, -0.5, 2000.5);
	h_Event_nProton_n = new TH1F("h_Event_nProton_n", "Number of MC particles p^{-}; N_{MC} [1]; counts", 2001, -0.5, 2000.5);
	h_Event_nElectron_p = new TH1F("h_Event_nElectron_p", "Number of MC particles e^{+}; N_{MC} [1]; counts", 2001, -0.5, 2000.5);
	h_Event_nElectron_n = new TH1F("h_Event_nElectron_n", "Number of MC particles e^{-}; N_{MC} [1]; counts", 2001, -0.5, 2000.5);

	h_Event_nNeutron = new TH1F("h_Event_nNeutron", "Number of MC particles n; N_{MC} [1]; counts", 2001, -0.5, 2000.5);
	h_Event_nGamma = new TH1F("h_Event_nGamma", "Number of MC particles #gamma; N_{MC} [1]; counts", 2001, -0.5, 2000.5);


	// special

	h_Event_Q2 = new TH1F("h_Event_Q2", "Event Q^{2}; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 10.0);
	h_Event_x = new TH1F("h_Event_x", "Event x; x [1]; counts", 10000, 0.0, 0.1);
	h_Event_y = new TH1F("h_Event_y", "Event inelasticity y; y [1]; counts", 1000, 0.0, 1.0);

	h_Event_nHCal_0_Q2 = new TH1F("h_Event_nHCal_0_Q2", "Event with 0 jets in nHCal Q^{2}; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 10.0);
	h_Event_nHCal_0_x = new TH1F("h_Event_nHCal_0_x", "Event with 0 jets in nHCal x; x [1]; counts", 10000, 0.0, 0.1);
	h_Event_nHCal_0_y = new TH1F("h_Event_nHCal_0_y", "Event with 0 jets in nHCal inelasticity y; y [1]; counts", 1000, 0.0, 1.0);

	h_Event_nHCal_1_Q2 = new TH1F("h_Event_nHCal_1_Q2", "Event with 1 jet in nHCal Q^{2}; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 10.0);
	h_Event_nHCal_1_x = new TH1F("h_Event_nHCal_1_x", "Event with 1 jet in nHCal x; x [1]; counts", 10000, 0.0, 0.1);
	h_Event_nHCal_1_y = new TH1F("h_Event_nHCal_1_y", "Event with 1 jet in nHCal inelasticity y; y [1]; counts", 1000, 0.0, 1.0);

	h_Event_nHCal_2_Q2 = new TH1F("h_Event_nHCal_2_Q2", "Event with 2 jets in nHCal Q^{2}; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 10.0);
	h_Event_nHCal_2_x = new TH1F("h_Event_nHCal_2_x", "Event with 2 jets in nHCal x; x [1]; counts", 10000, 0.0, 0.1);
	h_Event_nHCal_2_y = new TH1F("h_Event_nHCal_2_y", "Event with 2 jets in nHCal inelasticity y; y [1]; counts", 1000, 0.0, 1.0);

	h_Event_AllHCal_Q2 = new TH1F("h_Event_AllHCal_Q2", "Event with jets in any HCal Q^{2}; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 10.0);
	h_Event_AllHCal_x = new TH1F("h_Event_AllHCal_x", "Event with jets in any HCal x; x [1]; counts", 10000, 0.0, 0.1);
	h_Event_AllHCal_y = new TH1F("h_Event_AllHCal_y", "Event with jets in any HCal inelasticity y; y [1]; counts", 1000, 0.0, 1.0);


	h_Event_HCal_jets = new TH2F("h_Event_HCal_jets", "Event with dijets in HCals; Jet #1; Jet #2; counts", 4, 0.0, 4.0, 4, 0.0, 4.0);

	h_Event_HCal_jets->GetXaxis()->SetBinLabel(1, "nHCal");
	h_Event_HCal_jets->GetXaxis()->SetBinLabel(2, "Barrel HCal");
	h_Event_HCal_jets->GetXaxis()->SetBinLabel(3, "LFHCAL");
	h_Event_HCal_jets->GetXaxis()->SetBinLabel(4, "Any");

	h_Event_HCal_jets->GetYaxis()->SetBinLabel(1, "nHCal");
	h_Event_HCal_jets->GetYaxis()->SetBinLabel(2, "Barrel HCal");
	h_Event_HCal_jets->GetYaxis()->SetBinLabel(3, "LFHCAL");
	h_Event_HCal_jets->GetYaxis()->SetBinLabel(4, "Any");

	// Particles
	h_Particle_eta = new TH1F("h_Particle_eta", "MC particle #eta; #eta; counts", 200, -10.0, 10.0);
	h_Particle_eta_wE = new TH1F("h_Particle_eta_wE", "MC particle #eta, E weighed; #eta; counts", 200, -10.0, 10.0);

	h_Particle_eta_p = new TH2F("h_Particle_eta_p", "MC particles #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_eta_pT = new TH2F("h_Particle_eta_pT", "MC particles #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_eta_E = new TH2F("h_Particle_eta_E", "MC particles #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);


    // eta, momentum
	h_Particle_pion_p_eta_p = new TH2F("h_Particle_Pion_p_eta_p", "MC particles #pi^{+} #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_pion_n_eta_p = new TH2F("h_Particle_Pion_n_eta_p", "MC particles #pi^{-} #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Kaon_p_eta_p = new TH2F("h_Particle_Kaon_p_eta_p", "MC particles K^{+} #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Kaon_n_eta_p = new TH2F("h_Particle_Kaon_n_eta_p", "MC particles K^{-} #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_proton_p_eta_p = new TH2F("h_Particle_Proton_p_eta_p", "MC particles p^{+} #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_proton_n_eta_p = new TH2F("h_Particle_Proton_n_eta_p", "MC particles p^{-} #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Electron_p_eta_p = new TH2F("h_Particle_Electron_p_eta_p", "MC particles e^{+} #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Electron_n_eta_p = new TH2F("h_Particle_Electron_n_eta_p", "MC particles e^{-} #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);

	h_Particle_Neutron_eta_p = new TH2F("h_Particle_Neutron_eta_p", "MC particles n #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Gamma_eta_p = new TH2F("h_Particle_Gamma_eta_p", "MC particles #gamman #eta vs. momentum; #eta [1]; p_{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);


    // eta, transverse momentum pT
	h_Particle_pion_p_eta_pT = new TH2F("h_Particle_Pion_p_eta_pT", "MC particles #pi^{+} #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_pion_n_eta_pT = new TH2F("h_Particle_Pion_n_eta_pT", "MC particles #pi^{-} #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Kaon_p_eta_pT = new TH2F("h_Particle_Kaon_p_eta_pT", "MC particles K^{+} #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Kaon_n_eta_pT = new TH2F("h_Particle_Kaon_n_eta_pT", "MC particles K^{-} #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_proton_p_eta_pT = new TH2F("h_Particle_Proton_p_eta_pT", "MC particles p^{+} #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_proton_n_eta_pT = new TH2F("h_Particle_Proton_n_eta_pT", "MC particles p^{-} #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Electron_p_eta_pT = new TH2F("h_Particle_Electron_p_eta_pT", "MC particles e^{+} #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Electron_n_eta_pT = new TH2F("h_Particle_Electron_n_eta_pT", "MC particles e^{-} #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);

	h_Particle_Neutron_eta_pT = new TH2F("h_Particle_Neutron_eta_pT", "MC particles n #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Gamma_eta_pT = new TH2F("h_Particle_Gamma_eta_pT", "MC particles #gamman #eta vs. momentum; #eta [1]; p_{T}^{MC} [GeV/c]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);


	// eta, energy
	h_Particle_Pion_p_eta_E = new TH2F("h_Particle_Pion_p_eta_E", "MC particles #pi^{+} #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Pion_n_eta_E = new TH2F("h_Particle_Pion_n_eta_E", "MC particles #pi^{-} #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Kaon_p_eta_E = new TH2F("h_Particle_Kaon_p_eta_E", "MC particles K^{+} #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Kaon_n_eta_E = new TH2F("h_Particle_Kaon_n_eta_E", "MC particles K^{-} #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Proton_p_eta_E = new TH2F("h_Particle_Proton_p_eta_E", "MC particles p^{+} #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Proton_n_eta_E = new TH2F("h_Particle_Proton_n_eta_E", "MC particles p^{-} #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Electron_p_eta_E = new TH2F("h_Particle_Electron_p_eta_E", "MC particles e^{+} #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Electron_n_eta_E = new TH2F("h_Particle_Electron_n_eta_E", "MC particles e^{-} #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);

	h_Particle_Neutron_eta_E = new TH2F("h_Particle_Neutron_eta_E", "MC particles n #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);
	h_Particle_Gamma_eta_E = new TH2F("h_Particle_Gamma_eta_E", "MC particles #gamma #eta vs. energy; #eta [1]; E_{MC} [GeV]; counts", 200, -10.0, 10.0, 500, 0.0, 50.0);

	// temp
	const int nEtaBins = 7;
	double EtaBins[nEtaBins+1] = {-10, -4.14, -1.18, -1.1, 1.1, 1.2, 4.2, 10};

	hist_eta_energy_tmp = new TH1F("hist_eta_energy_tmp", "hist_eta_energy_tmp; #eta, E [GeV]", nEtaBins, EtaBins);
	hist_eta_energy_denom_tmp = new TH1F("hist_eta_energy_denom_tmp", "hist_eta_energy_denom_tmp; #eta, E [GeV]", nEtaBins, EtaBins);


	//hist_eta_energy_tmp->Sumw2();
	//hist_eta_energy_denom_tmp->Sumw2();


	return 1;
}


#endif /* HISTOGRAMSPYTHIA_H_ */
