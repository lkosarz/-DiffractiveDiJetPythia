//==============================================================================

//==============================================================================

#include "Pythia8/Pythia.h"
#include "TTree.h"
#include "TFile.h"

#include <vector>
#include <utility>
#include <map>

#include "Pythia8Plugins/HepMC3.h"

#include "PythiaEvent.h"
#include "HistogramsPythia.h"

#define PR(x) std::cout << #x << " = " << (x) << std::endl;

using namespace Pythia8; 

double costhetastar(int, int, const Event&);
bool isInAcceptance(int, const Event&);  // acceptance filter
int MakeEvent(Pythia *pythia, PythiaEvent *eventStore, int iev, bool writeTree = false);            // event handler (analyze event and
                                         // stores data in tuple)
int findFinalElectron(const Event& event);

int FillHCals(TH2F *hist, TH1F *hEne, TH1F *hEneDenom, bool &anyHcal_jets);

void SortPairs(std::vector<pair<int, double>> &input, std::vector<pair<int, double>> &output);

bool compFunc(pair<int, double> a, pair<int, double> b);
void PrintVec(std::vector<pair<int, double>> input);

int main(int argc, char* argv[]) {
    
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " runcard  outfile" << endl;
        return 2;
    }
    char* runcard  = argv[1];
    char* outfile = argv[2];
    //const char* xmlDB    = "/users/PAS2524/lkosarz/Pythia/pythia8312/share/Pythia8/xmldoc";
    const char* xmlDB    = "/opt/local/share/Pythia8/xmldoc";
    
    bool WriteHepMC = false;
    bool WriteTree = false;


    //
    //  Create instance of Pythia 
    //
    //Pythia pythia(xmlDB); // the default parameters are read from xml files
                          // stored in the xmldoc directory. This includes
                          // particle data and decay definitions.
    
    Pythia *pythia = new Pythia();


    // Shorthand for (static) settings
    Settings& settings = pythia->settings;
    
    //  Read in runcard (should be star_hf_tune_v1.0.cmd)
    pythia->readFile(runcard);
    cout << "Runcard '" << runcard << "' loaded." << endl;
    

    TFile *treeFile  = new TFile(Form("%s_tree.root", outfile),"RECREATE");
    TFile *histFile  = new TFile(Form("%s_hist.root", outfile),"RECREATE");

    treeFile->cd();

    TTree *eventTree = new TTree("eventTree", "Event tree");
    PythiaEvent *eventStore = new PythiaEvent();
    eventTree->Branch("eventTree", &eventStore, 32000, 1);




    //
    //  Retrieve number of events and other parameters from the runcard.
    //  We need to deal with those settings ourself. Getting
    //  them through the runcard just avoids recompiling.
    //
    long  maxNumberOfEvents = settings.mode("Main:numberOfEvents");
    int  nList     = settings.mode("Main:numberToList");
	//int  nList = 10;
    //int  nShow     = settings.mode("Main:timesToShow");
    int  nShow = 10;
    int  maxErrors = settings.mode("Main:timesAllowErrors");
    //bool showCS    = settings.flag("Main:showChangedSettings");
    //bool showAS    = settings.flag("Main:showAllSettings");
    int  pace = maxNumberOfEvents/nShow;
 
    
    //  Initialize Pythia, ready to go
    pythia->init();
    
    // List changed or all data
    //if (showCS) settings.listChanged();
    //if (showAS) settings.listAll();
    settings.listChanged();
    settings.listAll();
    

    Pythia8ToHepMC toHepMC(Form("%s.hepmc3", outfile));
    //IO_GenEvent ascii_io(Form("%s.hepmc3", outfile));
    //HepMC::WriterRootTree WriterRootfile("file.root")
    //GenEvent hepmcevt;


    histFile->cd();
    CreateHistograms();

    //--------------------------------------------------------------
    //  Event loop
    //--------------------------------------------------------------
    int ievent = 0;
    int iErrors = 0;
    
    while (ievent < maxNumberOfEvents) {
        
        if (!pythia->next()) {
            if (++iErrors < maxErrors) continue;
            cout << "Error: too many errors in event generation - check your settings & code" << endl;
            break;
        }

        MakeEvent(pythia, eventStore, ievent, WriteTree);  // in MakeEvent we deal with the whole event and return

        if(WriteTree)	eventTree->Fill();
        ievent++;

        if (ievent%pace == 0) {
            cout << "# of events generated = " << ievent << endl;
        }
        
        // List first few events.
        if (ievent < nList) {
            pythia->info.list();
            pythia->process.list();
            pythia->event.list(false, true, 3);
        }


        if(WriteHepMC)	toHepMC.writeNextEvent(*pythia);

        //GenEvent* hepmcevt = new HepMC::GenEvent();
        //toHepMC.fill_next_event( *pythia.Pythia8(), hepmcevt);
        //ascii_io << hepmcevt;
        //delete hepmcevt;

    }
    
    //--------------------------------------------------------------
    //  Finish up
    //--------------------------------------------------------------
    //pythia.statistics();
    pythia->stat();

    cout << "Writing files" << endl;

    histFile->cd();
    histFile->Write();

    treeFile->cd();
	if(WriteTree) eventTree->Write();
    //treeFile->Write();

	histFile->Close();
	treeFile->Close();

    cout << "Finish!" << endl;
    
    return 0;
}

//
//  Event analysis
//
int MakeEvent(Pythia *pythia, PythiaEvent *eventStore, int iev, bool writeTree)
{
    Event &event = pythia->event;

	cout<<"NEW EVENT ---------------------------"<<endl;
    
	hist_eta_energy_tmp->Reset();
	hist_eta_energy_denom_tmp->Reset();

	//if (event[1].id() == 11)

	//int eleid = findFinalElectron(event);

	float EsumF = 0.0;
	double EsumD = 0.0;

	bool has_nHcalActivity = false;

	int nPartFinal = 0;

	int nPion_p = 0;
	int nPion_n = 0;
	int nKaon_p = 0;
	int nKaon_n = 0;
	int nProton_p = 0;
	int nProton_n = 0;
	int nElectron_p = 0;
	int nElectron_n = 0;

	int nNeutron = 0;
	int nGamma = 0;

    int njpsi = 0;
    for (int i = 0; i < event.size(); i++) {

    	Particle part = event[i];

    	// accept final particles only
    	if(!part.isFinal()) continue;

    	nPartFinal++;

		if(part.id() == 211) nPion_p++;
		if(part.id() == -211) nPion_n++;
		if(part.id() == 321) nKaon_p++;
		if(part.id() == -321) nKaon_n++;
		if(part.id() == 2212) nProton_p++;
		if(part.id() == -2212) nProton_n++;
		if(part.id() == -11) nElectron_p++;
		if(part.id() == 11) nElectron_n++;

		if(part.id() == 2112) nNeutron++;
		if(part.id() == 22) nGamma++;

		h_Particle_eta->Fill(part.eta());
		h_Particle_eta_wE->Fill(part.eta(), part.e());

		h_Particle_eta_p->Fill(part.eta(), part.pAbs());
		h_Particle_eta_pT->Fill(part.eta(), part.pT());
		h_Particle_eta_E->Fill(part.eta(), part.e());


		// eta, momentum
		if(part.id() == 211) h_Particle_pion_p_eta_p->Fill(part.eta(), part.pAbs());
		if(part.id() == -211) h_Particle_pion_n_eta_p->Fill(part.eta(), part.pAbs());
		if(part.id() == 321) h_Particle_Kaon_p_eta_p->Fill(part.eta(), part.pAbs());
		if(part.id() == -321) h_Particle_Kaon_n_eta_p->Fill(part.eta(), part.pAbs());
		if(part.id() == 2212) h_Particle_proton_p_eta_p->Fill(part.eta(), part.pAbs());
		if(part.id() == -2212) h_Particle_proton_n_eta_p->Fill(part.eta(), part.pAbs());
		if(part.id() == -11) h_Particle_Electron_p_eta_p->Fill(part.eta(), part.pAbs());
		if(part.id() == 11) h_Particle_Electron_n_eta_p->Fill(part.eta(), part.pAbs());

		if(part.id() == 2112) h_Particle_Neutron_eta_p->Fill(part.eta(), part.pAbs());
		if(part.id() == 22) h_Particle_Gamma_eta_p->Fill(part.eta(), part.pAbs());

		// eta, transverse momentum pT
		if(part.id() == 211) h_Particle_pion_p_eta_pT->Fill(part.eta(), part.pT());
		if(part.id() == -211) h_Particle_pion_n_eta_pT->Fill(part.eta(), part.pT());
		if(part.id() == 321) h_Particle_Kaon_p_eta_pT->Fill(part.eta(), part.pT());
		if(part.id() == -321) h_Particle_Kaon_n_eta_pT->Fill(part.eta(), part.pT());
		if(part.id() == 2212) h_Particle_proton_p_eta_pT->Fill(part.eta(), part.pT());
		if(part.id() == -2212) h_Particle_proton_n_eta_pT->Fill(part.eta(), part.pT());
		if(part.id() == -11) h_Particle_Electron_p_eta_pT->Fill(part.eta(), part.pT());
		if(part.id() == 11) h_Particle_Electron_n_eta_pT->Fill(part.eta(), part.pT());

		if(part.id() == 2112) h_Particle_Neutron_eta_pT->Fill(part.eta(), part.pT());
		if(part.id() == 22) h_Particle_Gamma_eta_pT->Fill(part.eta(), part.pT());

		// eta, energy
		if(part.id() == 211) h_Particle_Pion_p_eta_E->Fill(part.eta(), part.e());
		if(part.id() == -211) h_Particle_Pion_n_eta_E->Fill(part.eta(), part.e());
		if(part.id() == 321) h_Particle_Kaon_p_eta_E->Fill(part.eta(), part.e());
		if(part.id() == -321) h_Particle_Kaon_n_eta_E->Fill(part.eta(), part.e());
		if(part.id() == 2212) h_Particle_Proton_p_eta_E->Fill(part.eta(), part.e());
		if(part.id() == -2212) h_Particle_Proton_n_eta_E->Fill(part.eta(), part.e());
		if(part.id() == -11) h_Particle_Electron_p_eta_E->Fill(part.eta(), part.e());
		if(part.id() == 11) h_Particle_Electron_n_eta_E->Fill(part.eta(), part.e());

		if(part.id() == 2112) h_Particle_Neutron_eta_E->Fill(part.eta(), part.e());
		if(part.id() == 22) h_Particle_Gamma_eta_E->Fill(part.eta(), part.e());


		if(11>part.status() || part.status()>19)
		{
			hist_eta_energy_tmp->Fill(part.eta(), part.e());

			//cout<<"part E ="<<part.e()<<endl;

			EsumF += part.e();
			EsumD += part.e();

			//cout<<"EsumF ="<<EsumF<<endl;
			//cout<<"EsumD ="<<EsumD<<endl;

			for (int i = 1; i <= hist_eta_energy_denom_tmp->GetNbinsX(); ++i) {

				double xbin_cent = hist_eta_energy_denom_tmp->GetXaxis()->GetBinCenter(i);

				hist_eta_energy_denom_tmp->Fill(xbin_cent, part.e());

			}

		}


		// Store particle
		if(writeTree) eventStore->particles.push_back(part);


		// select nHCal acceptance
		//if(part.eta()<-4.03 ||  part.eta()>-1.27)	continue;
		if(part.eta()<-4.14 ||  part.eta()>-1.18)	continue;

		has_nHcalActivity = true;



    	/*
            //
            //  Get daughters
            //
            vector<int> daughters = event.daughterList(i);
            
            if (daughters.size() != 2) continue;
            int ielectron = daughters[0];
            int ipositron = daughters[1];
            
            if (abs(event[ielectron].id()) != 11) continue;
            if (abs(event[ipositron].id()) != 11) continue;
            
            if (event[ielectron].id() == -11) {
                int k = ielectron;
                ielectron = ipositron;
                ipositron = k;
            }*/
            
           // if (!(isInAcceptance(ielectron, event) && isInAcceptance(ipositron, event))) continue;
            
            
    } // particles loop



    // Four-momenta of proton, electron, virtual photon/Z^0/W^+-.
    Vec4 pProton = event[1].p();
    Vec4 peIn    = event[2].p();
    Vec4 pPhoton = event[4].p();

    //Vec4 peIn    = event[4].p();
    //Vec4 peOut   = event[6].p();
    //Vec4 pPhoton = peIn - peOut;

    // Q2, W2, Bjorken x, y.
    double Q2    = - pPhoton.m2Calc();
    double W2    = (pProton + pPhoton).m2Calc();
    double x     = Q2 / (2. * pProton * pPhoton);
    double y     = (pProton * pPhoton) / (pProton * peIn);

    h_Events->Fill(1);

	// Store event
    if(writeTree)
    {
    	eventStore->eventId = iev;
    	eventStore->nParticlesFinal = nPartFinal;
    	eventStore->Q2 = Q2;
    	eventStore->x = x;
    	eventStore->y = y;
    }


    h_Event_xQ2->Fill(x, Q2);
    h_Event_yQ2->Fill(y, Q2);
    h_Event_xy->Fill(x, y);


    if(has_nHcalActivity)
    {
        h_Event_nHCal_xQ2->Fill(x, Q2);
        h_Event_nHCal_yQ2->Fill(y, Q2);
        h_Event_nHCal_xy->Fill(x, y);
    }

    h_Event_nPart_final->Fill(nPartFinal);

	h_Event_nPion_p->Fill(nPion_p);
	h_Event_nPion_n->Fill(nPion_n);
	h_Event_nKaon_p->Fill(nKaon_p);
	h_Event_nKaon_n->Fill(nKaon_n);
	h_Event_nProton_p->Fill(nProton_p);
	h_Event_nProton_n->Fill(nProton_n);
	h_Event_nElectron_p->Fill(nElectron_p);
	h_Event_nElectron_n->Fill(nElectron_n);

	h_Event_nNeutron->Fill(nNeutron);
	h_Event_nGamma->Fill(nGamma);


	// summary
	bool anyHcal_jets = false;

	int nHCal_jets = FillHCals(h_Event_eta_wE, hist_eta_energy_tmp, hist_eta_energy_denom_tmp, anyHcal_jets);


	h_Event_Q2->Fill(Q2);
	h_Event_x->Fill(x);
	h_Event_y->Fill(y);

	if(nHCal_jets == 0)
	{
		h_Event_nHCal_0_Q2->Fill(Q2);
		h_Event_nHCal_0_x->Fill(x);
		h_Event_nHCal_0_y->Fill(y);
	}

	if(nHCal_jets == 1)
	{
		h_Event_nHCal_1_Q2->Fill(Q2);
		h_Event_nHCal_1_x->Fill(x);
		h_Event_nHCal_1_y->Fill(y);
	}


	if(nHCal_jets == 2)
	{
		h_Event_nHCal_2_Q2->Fill(Q2);
		h_Event_nHCal_2_x->Fill(x);
		h_Event_nHCal_2_y->Fill(y);
	}

	if(anyHcal_jets == true) // Both jets in any HCal
	{
		h_Event_AllHCal_Q2->Fill(Q2);
		h_Event_AllHCal_x->Fill(x);
		h_Event_AllHCal_y->Fill(y);
	}


    return 1;
}

//
//  Acceptance filter
//
bool isInAcceptance(int i, const Event& event)
{
    // accept all (useful for many studies)
    // return true;
    
    // limit to STAR TPC/BEMC/ToF acceptance + EEMC
    double eta = event[i].eta();
    if (fabs(eta) < 2)
        return true;
    else
        return false;
}

//
// Cosine of angle of electron daughter in J/Psi rest frame
// i.e, cos(theta)* of decay
// 
// Reference frame: recoil
// 
// Returns in range [0,1]
//
// Polarization: dN/dcost* = 1+alpha*cost*^2
// alpha = +1 means tranverse (helicity = +-1) 
//       = -1 means long. (helicity 0)
//       = 0  unpolarized

double costhetastar(int im, int ie, const Event& event)
{
    double gammaFrame = event[im].e()/event[im].m(); // gamma = E/m
    double gammabetaFrame = event[im].pAbs()/event[im].m();  // gamma*beta = p/m
    
    double costheta = (event[im].px()*event[ie].px()+
                       event[im].py()*event[ie].py()+
                       event[im].pz()*event[ie].pz())/(event[im].pAbs()*event[ie].pAbs());
    double pl = event[ie].pAbs()*costheta;    // wrt J/Psi axis
    double pt = sin(acos(costheta))*event[ie].pAbs();   // wrt J/Psi axis
    double pzstar = -gammabetaFrame*event[ie].e()+gammaFrame*pl;
    double tanThetaStar = pt/pzstar;
    double thetaStar = atan(tanThetaStar);
    return cos(thetaStar);
}

int findFinalElectron(const Event& event)
{

	int eleid = 2;
	bool found = false;

	while(found==false)
	{
		int d1 = event[eleid].daughter1();
		int d2 = event[eleid].daughter2();


		if(event[d1].id() == 11) eleid = event[eleid].daughter1();
		if(event[d2].id() == 11) eleid = event[eleid].daughter2();

		if(event[eleid].daughter1() == event[eleid].daughter2()) found = true;

	}

	return eleid;
}


int FillHCals(TH2F *hist, TH1F *hEne, TH1F *hEneDenom, bool &anyHcal_jets)
{

	TH1F *hEne_Norm = (TH1F *)hEne->Clone("hEne_Norm");


	float integral = hEne->Integral();

	//cout<<"integral = "<<integral<<endl;
	//cout<<"Esum = "<<hEneDenom->GetBinContent(1)<<endl;

	hEne_Norm->Divide(hEneDenom);

	std::map<int, int> BinIdToCalo = { {1,-1}, {2,0}, {3,-1}, {4,1}, {5,-1}, {6,2}, {7,-1} };


	std::vector<pair<int, double>> input;
	std::vector<pair<int, double>> sorted;

	for (int i = 1; i <= hEne_Norm->GetNbinsX(); ++i) {

		pair<int, double> binPair;

		binPair.first = i;
		binPair.second = hEne_Norm->GetBinContent(i);

		input.push_back(binPair);
	}

	SortPairs(input, sorted);

	if(sorted.at(0).second > 2.0*sorted.at(1).second)
	{
		sorted.at(1) = sorted.at(0);
	}


	//cout<<"Final:"<<endl;
	//PrintVec(sorted);

	int a = BinIdToCalo.at(sorted.at(0).first);
	int b = BinIdToCalo.at(sorted.at(1).first);

	hist->Fill(a, b);

	if(a >= 0) a = 3;
	if(b >= 0) b = 3;

	hist->Fill(a, b);

	a = BinIdToCalo.at(sorted.at(0).first);
	b = BinIdToCalo.at(sorted.at(1).first);

	//cout<<"a ="<<a<<endl;
	//cout<<"b ="<<b<<endl;

	if(a >= 0 && b >= 0 )
	{
		anyHcal_jets = true;
		//cout<<"Both jets in any HCal"<<endl;
	}

	if(a == 0 && b == 0) return 2; // 2 jets in nHCal
	if(a == 0 || b == 0) return 1; // 1 jet in nHCal
	if(a != 0 && b != 0) return 0; // 0 jet in nHCal
	//if(a == 3 && b == 3) return 3; // jets in any HCal

	return -1;

}


void SortPairs(std::vector<pair<int, double>> &input, std::vector<pair<int, double>> &output)
{

	//int maxId = 0;
	//int maxVal = 0.0;

	std::vector<pair<int, double>> input_copy = input;

	//PrintVec(input_copy);

	sort(input_copy.rbegin(), input_copy.rend(), compFunc);

	//cout<<"Sorted:"<<endl;
	//PrintVec(input_copy);

	output = input_copy;

/*
	for (int i = 0; i < input_copy.size(); ++i) {

		for (int j = 0; j < input_copy.size(); ++j) {

			double currVal = input_copy.at(j).second;

			if(currVal > maxVal)
			{
				maxId = j+1;
				maxVal = currVal;
			}
		} // j

		pair<int, double> newPair;
		newPair.first = maxId;
		newPair.second = maxVal;


		output.push_back(newPair);
		input_copy.erase(maxId-1);

	} // i
*/
}



bool compFunc(pair<int, double> a, pair<int, double> b)
{
	return (a.second < b.second);
}


void PrintVec(std::vector<pair<int, double>> input)
{

	for (int i = 0; i < input.size(); ++i) {

		int a = input.at(i).first;
		float b = input.at(i).second;

		cout<<i<<": <"<<a<<","<<b<<">\t";

	}
	cout<<endl;

}
