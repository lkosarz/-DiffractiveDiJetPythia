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


void MakeLogBins(double *array, int nbins, double binLo, double binHi)
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

// Event

TH1F *h_Events;

TH1F *h_Events_Diffractive;

TH1F *h_Event_nPart_final;
TH1F *h_Event_nJets;
TH1F *h_Event_nJets_meas;

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

TH1F *h_Event_jets_Q2;
TH1F *h_Event_jets_x;
TH1F *h_Event_jets_y;

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


TH1F *h_Event_JetMeas_nHCal_0_Q2;
TH1F *h_Event_JetMeas_nHCal_0_x;
TH1F *h_Event_JetMeas_nHCal_0_y;

TH1F *h_Event_JetMeas_nHCal_1_Q2;
TH1F *h_Event_JetMeas_nHCal_1_x;
TH1F *h_Event_JetMeas_nHCal_1_y;

TH1F *h_Event_JetMeas_nHCal_2_Q2;
TH1F *h_Event_JetMeas_nHCal_2_x;
TH1F *h_Event_JetMeas_nHCal_2_y;

TH1F *h_Event_JetMeas_AllHCal_Q2;
TH1F *h_Event_JetMeas_AllHCal_x;
TH1F *h_Event_JetMeas_AllHCal_y;

TH2F *h_Event_HCal_jets;
TH2F *h_Event_HCal_jets_meas;

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


// Jets
TH1D *h_Jet_nPart;
TH1D *h_Jet_mass;
TH1D *h_Jet_charge;
TH1D *h_Jet_E;
TH1D *h_Jet_p;
TH1D *h_Jet_pT;
TH1D *h_Jet_eta;
TH1D *h_Jet_deta;

// Jets measured
TH1D *h_Jet_meas_nPart;
TH1D *h_Jet_meas_mass;
TH1D *h_Jet_meas_charge;
TH1D *h_Jet_meas_E;
TH1D *h_Jet_meas_p;
TH1D *h_Jet_meas_pT;
TH1D *h_Jet_meas_eta;
TH1D *h_Jet_meas_deta;


TH1D *h_Jet_bHCal_part_eta;
TH1D *h_Jet_meas_bHCal_part_eta;

TH2D *h_Jet_HCal_part_eta;
TH2D *h_Jet_meas_HCal_part_eta;


// temp

TH1F *hist_eta_energy_tmp;
TH1F *hist_eta_energy_denom_tmp;



int CreateHistograms()
{


	const int nbins_x = 200;

	const int nbinEdg_x = nbins_x+1;

	double *logBinsArray_x = new double[nbins_x];

	MakeLogBins(logBinsArray_x, nbins_x, 10e-7, 1.0);


	// Event

	h_Events = new TH1F("h_Events", "Number of events; events; counts", 10, 0.0, 10.0);

	h_Events_Diffractive = new TH1F("h_Events_Diffractive", "Number of diffractive events; events; counts", 10, 0.0, 10.0);

	h_Events_Diffractive->GetXaxis()->SetBinLabel(1, "Diffractive A");
	h_Events_Diffractive->GetXaxis()->SetBinLabel(2, "Diffractive B");
	h_Events_Diffractive->GetXaxis()->SetBinLabel(3, "Hard diffractive A");
	h_Events_Diffractive->GetXaxis()->SetBinLabel(4, "Hard diffractive B");

	h_Event_nPart_final = new TH1F("h_Event_nPart_final", "Number of final MC particles; N_{MC} [1]; counts", 2001, -0.5, 2000.5);
	h_Event_nJets = new TH1F("h_Event_nJets", "Number of jets; N_{jet} [1]; counts", 21, -0.5, 20.5);
	h_Event_nJets_meas = new TH1F("h_Event_nJets_meas", "Number of measured jets; N_{jet} [1]; counts", 21, -0.5, 20.5);


	h_Event_xQ2 = new TH2F("h_Event_xQ2", "Event Q^{2} vs. x; x [1]; Q^{2} [GeV^{2}/c^{2}]; counts", nbins_x, logBinsArray_x, 500, 0.0, 5.0);
	h_Event_yQ2 = new TH2F("h_Event_yQ2", "Event Q^{2} vs. inelasticity y; y [1]; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 1.0, 500, 0.0, 5.0);
	h_Event_xy = new TH2F("h_Event_xy", "Event inelasticity y vs. x; x [1]; y [1]; counts", nbins_x, logBinsArray_x, 1000, 0.0, 1.0);


	h_Event_nHCal_xQ2 = new TH2F("h_Event_nHCal_xQ2", "Event with nHCal activity Q^{2} vs. x; x [1]; Q^{2} [GeV^{2}/c^{2}]; counts", nbins_x, logBinsArray_x, 500, 0.0, 5.0);
	h_Event_nHCal_yQ2 = new TH2F("h_Event_nHCal_yQ2", "Event with nHCal activity Q^{2} vs. inelasticity y; y [1]; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 1.0, 500, 0.0, 5.0);
	h_Event_nHCal_xy = new TH2F("h_Event_nHCal_xy", "Event with nHCal activity inelasticity y vs. x; x [1]; y [1]; counts", nbins_x, logBinsArray_x, 1000, 0.0, 1.0);


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
	h_Event_x = new TH1F("h_Event_x", "Event x; x [1]; counts", nbins_x, logBinsArray_x);
	h_Event_y = new TH1F("h_Event_y", "Event inelasticity y; y [1]; counts", 1000, 0.0, 1.0);

	h_Event_jets_Q2 = new TH1F("h_Event_jets_Q2", "Event with jets>=2 Q^{2}; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 10.0);
	h_Event_jets_x = new TH1F("h_Event_jets_x", "Event with jets>=2 x; x [1]; counts", nbins_x, logBinsArray_x);
	h_Event_jets_y = new TH1F("h_Event_jets_y", "Event with jets>=2 inelasticity y; y [1]; counts", 1000, 0.0, 1.0);

	h_Event_nHCal_0_Q2 = new TH1F("h_Event_nHCal_0_Q2", "Event with 0 jets in nHCal Q^{2}; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 10.0);
	h_Event_nHCal_0_x = new TH1F("h_Event_nHCal_0_x", "Event with 0 jets in nHCal x; x [1]; counts", nbins_x, logBinsArray_x);
	h_Event_nHCal_0_y = new TH1F("h_Event_nHCal_0_y", "Event with 0 jets in nHCal inelasticity y; y [1]; counts", 1000, 0.0, 1.0);

	h_Event_nHCal_1_Q2 = new TH1F("h_Event_nHCal_1_Q2", "Event with 1 jet in nHCal Q^{2}; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 10.0);
	h_Event_nHCal_1_x = new TH1F("h_Event_nHCal_1_x", "Event with 1 jet in nHCal x; x [1]; counts", nbins_x, logBinsArray_x);
	h_Event_nHCal_1_y = new TH1F("h_Event_nHCal_1_y", "Event with 1 jet in nHCal inelasticity y; y [1]; counts", 1000, 0.0, 1.0);

	h_Event_nHCal_2_Q2 = new TH1F("h_Event_nHCal_2_Q2", "Event with 2 jets in nHCal Q^{2}; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 10.0);
	h_Event_nHCal_2_x = new TH1F("h_Event_nHCal_2_x", "Event with 2 jets in nHCal x; x [1]; counts", nbins_x, logBinsArray_x);
	h_Event_nHCal_2_y = new TH1F("h_Event_nHCal_2_y", "Event with 2 jets in nHCal inelasticity y; y [1]; counts", 1000, 0.0, 1.0);

	h_Event_AllHCal_Q2 = new TH1F("h_Event_AllHCal_Q2", "Event with jets in any HCal Q^{2}; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 10.0);
	h_Event_AllHCal_x = new TH1F("h_Event_AllHCal_x", "Event with jets in any HCal x; x [1]; counts", nbins_x, logBinsArray_x);
	h_Event_AllHCal_y = new TH1F("h_Event_AllHCal_y", "Event with jets in any HCal inelasticity y; y [1]; counts", 1000, 0.0, 1.0);


	h_Event_JetMeas_nHCal_0_Q2 = new TH1F("h_Event_JetMeas_nHCal_0_Q2", "Event with 0 jets measured in nHCal Q^{2}; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 10.0);
	h_Event_JetMeas_nHCal_0_x = new TH1F("h_Event_JetMeas_nHCal_0_x", "Event with 0 jets measured in nHCal x; x [1]; counts", nbins_x, logBinsArray_x);
	h_Event_JetMeas_nHCal_0_y = new TH1F("h_Event_JetMeas_nHCal_0_y", "Event with 0 jets measured in nHCal inelasticity y; y [1]; counts", 1000, 0.0, 1.0);

	h_Event_JetMeas_nHCal_1_Q2 = new TH1F("h_Event_JetMeas_nHCal_1_Q2", "Event with 1 jet measured in nHCal Q^{2}; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 10.0);
	h_Event_JetMeas_nHCal_1_x = new TH1F("h_Event_JetMeas_nHCal_1_x", "Event with 1 jet measured in nHCal x; x [1]; counts", nbins_x, logBinsArray_x);
	h_Event_JetMeas_nHCal_1_y = new TH1F("h_Event_JetMeas_nHCal_1_y", "Event with 1 jet measured in nHCal inelasticity y; y [1]; counts", 1000, 0.0, 1.0);

	h_Event_JetMeas_nHCal_2_Q2 = new TH1F("h_Event_JetMeas_nHCal_2_Q2", "Event with 2 jets measured in nHCal Q^{2}; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 10.0);
	h_Event_JetMeas_nHCal_2_x = new TH1F("h_Event_JetMeas_nHCal_2_x", "Event with 2 jets measured in nHCal x; x [1]; counts", nbins_x, logBinsArray_x);
	h_Event_JetMeas_nHCal_2_y = new TH1F("h_Event_JetMeas_nHCal_2_y", "Event with 2 jets measured in nHCal inelasticity y; y [1]; counts", 1000, 0.0, 1.0);

	h_Event_JetMeas_AllHCal_Q2 = new TH1F("h_Event_JetMeas_AllHCal_Q2", "Event with jets measured in any HCal Q^{2}; Q^{2} [GeV^{2}/c^{2}]; counts", 1000, 0.0, 10.0);
	h_Event_JetMeas_AllHCal_x = new TH1F("h_Event_JetMeas_AllHCal_x", "Event with jets measured in any HCal x; x [1]; counts", nbins_x, logBinsArray_x);
	h_Event_JetMeas_AllHCal_y = new TH1F("h_Event_JetMeas_AllHCal_y", "Event with jets measured in any HCal inelasticity y; y [1]; counts", 1000, 0.0, 1.0);



	h_Event_HCal_jets = new TH2F("h_Event_HCal_jets", "Event with dijets in HCals; Jet #1; Jet #2; counts", 4, 0.0, 4.0, 4, 0.0, 4.0);
	h_Event_HCal_jets_meas = new TH2F("h_Event_HCal_jets_meas", "Event with measured dijets in HCals; Jet #1; Jet #2; counts", 4, 0.0, 4.0, 4, 0.0, 4.0);

	h_Event_HCal_jets->GetXaxis()->SetBinLabel(1, "nHCal");
	h_Event_HCal_jets->GetXaxis()->SetBinLabel(2, "Barrel HCal");
	h_Event_HCal_jets->GetXaxis()->SetBinLabel(3, "LFHCAL");
	h_Event_HCal_jets->GetXaxis()->SetBinLabel(4, "Any");

	h_Event_HCal_jets->GetYaxis()->SetBinLabel(1, "nHCal");
	h_Event_HCal_jets->GetYaxis()->SetBinLabel(2, "Barrel HCal");
	h_Event_HCal_jets->GetYaxis()->SetBinLabel(3, "LFHCAL");
	h_Event_HCal_jets->GetYaxis()->SetBinLabel(4, "Any");


	h_Event_HCal_jets_meas->GetXaxis()->SetBinLabel(1, "nHCal");
	h_Event_HCal_jets_meas->GetXaxis()->SetBinLabel(2, "Barrel HCal");
	h_Event_HCal_jets_meas->GetXaxis()->SetBinLabel(3, "LFHCAL");
	h_Event_HCal_jets_meas->GetXaxis()->SetBinLabel(4, "Any");

	h_Event_HCal_jets_meas->GetYaxis()->SetBinLabel(1, "nHCal");
	h_Event_HCal_jets_meas->GetYaxis()->SetBinLabel(2, "Barrel HCal");
	h_Event_HCal_jets_meas->GetYaxis()->SetBinLabel(3, "LFHCAL");
	h_Event_HCal_jets_meas->GetYaxis()->SetBinLabel(4, "Any");


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

	// Jets
	h_Jet_nPart = new TH1D("h_Jet_nPart", "Jet number of particles; N_{part} [1]; counts", 201, -0.5, 200.5);
	h_Jet_mass = new TH1D("h_Jet_mass", "Jet mass; m [GeV/c^{2}]; counts", 2000, 0.0, 20.0);
    h_Jet_charge = new TH1D("h_Jet_charge", "Jet charge; q [1]; counts", 101, -50.5, 50.5);
	h_Jet_E = new TH1D("h_Jet_E", "Jet energy; E [GeV]; counts", 500, 0.0, 50.0);
	h_Jet_p = new TH1D("h_Jet_p", "Jet momentum; p [GeV/c]; counts", 500, 0.0, 50.0);
	h_Jet_pT = new TH1D("h_Jet_pT", "Jet transverse momentum; p_{T} [GeV/c]; counts", 500, 0.0, 50.0);
	h_Jet_eta = new TH1D("h_Jet_eta", "Jet #eta; #eta [1]; counts", 200, -5.0, 5.0);
	h_Jet_deta = new TH1D("h_Jet_deta", "Jet #Delta#eta; #Delta#eta [1]; counts", 400, -10.0, 10.0);


	// Jets measured
	h_Jet_meas_nPart = new TH1D("h_Jet_meas_nPart", "Jet measured number of particles; N_{part} [1]; counts", 201, -0.5, 200.5);
	h_Jet_meas_mass = new TH1D("h_Jet_meas_mass", "Jet measured mass; m [GeV/c^{2}]; counts", 2000, 0.0, 20.0);
    h_Jet_meas_charge = new TH1D("h_Jet_meas_charge", "Jet measured charge; q [1]; counts", 101, -50.5, 50.5);
	h_Jet_meas_E = new TH1D("h_Jet_meas_E", "Jet measured energy; E [GeV]; counts", 500, 0.0, 50.0);
	h_Jet_meas_p = new TH1D("h_Jet_meas_p", "Jet measured momentum; p [GeV/c]; counts", 500, 0.0, 50.0);
	h_Jet_meas_pT = new TH1D("h_Jet_meas_pT", "Jet measured transverse momentum; p_{T} [GeV/c]; counts", 500, 0.0, 50.0);
	h_Jet_meas_eta = new TH1D("h_Jet_meas_eta", "Jet measured #eta; #eta [1]; counts", 200, -5.0, 5.0);
	h_Jet_meas_deta = new TH1D("h_Jet_meas_deta", "Jet measured #Delta#eta; #Delta#eta [1]; counts", 400, -10.0, 10.0);

	h_Jet_bHCal_part_eta = new TH1D("h_Jet_bHCal_part_eta", "Jet in bHCal particle #eta; #eta [1]; counts", 200, -5.0, 5.0);
	h_Jet_meas_bHCal_part_eta = new TH1D("h_Jet_meas_bHCal_part_eta", "Jet measured in bHCal particle #eta; #eta [1]; counts", 200, -5.0, 5.0);

	h_Jet_HCal_part_eta = new TH2D("h_Jet_HCal_part_eta", "Jet in HCals particle #eta; #eta [1]; HCal; counts", 200, -5.0, 5.0, 4, 0.0, 4.0);
	h_Jet_meas_HCal_part_eta = new TH2D("h_Jet_meas_HCal_part_eta", "Jet measured in HCals particle #eta; #eta [1]; HCal; counts", 200, -5.0, 5.0, 4, 0.0, 4.0);

	h_Jet_HCal_part_eta->GetYaxis()->SetBinLabel(1, "no HCal");
	h_Jet_HCal_part_eta->GetYaxis()->SetBinLabel(2, "nHCal");
	h_Jet_HCal_part_eta->GetYaxis()->SetBinLabel(3, "bHCal");
	h_Jet_HCal_part_eta->GetYaxis()->SetBinLabel(4, "LFHCAL");

	h_Jet_meas_HCal_part_eta->GetYaxis()->SetBinLabel(1, "no HCal");
	h_Jet_meas_HCal_part_eta->GetYaxis()->SetBinLabel(2, "nHCal");
	h_Jet_meas_HCal_part_eta->GetYaxis()->SetBinLabel(3, "bHCal");
	h_Jet_meas_HCal_part_eta->GetYaxis()->SetBinLabel(4, "LFHCAL");


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
