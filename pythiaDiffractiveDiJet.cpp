//==============================================================================

//==============================================================================

#include "Pythia8/Pythia.h"
#include "TTree.h"
#include "TFile.h"

#include "Pythia8Plugins/HepMC3.h"

#include "PythiaEvent.h"
#include "HistogramsPythia.h"

#define PR(x) std::cout << #x << " = " << (x) << std::endl;

using namespace Pythia8; 

double costhetastar(int, int, const Event&);
bool isInAcceptance(int, const Event&);  // acceptance filter
int MakeEvent(Pythia *pythia, PythiaEvent *eventStore, double);            // event handler (analyze event and
                                         // stores data in tuple)
int findFinalElectron(const Event& event);


int main(int argc, char* argv[]) {
    
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " runcard  rootfile" << endl;
        return 2;
    }
    char* runcard  = argv[1];
    char* rootfile = argv[2];
    //const char* xmlDB    = "/users/PAS2524/lkosarz/Pythia/pythia8312/share/Pythia8/xmldoc";
    const char* xmlDB    = "/opt/local/share/Pythia8/xmldoc";
    
    bool WriteHepMC = false;


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
    

    TFile *treeFile  = new TFile(Form("%s_tree.root", rootfile),"RECREATE");
    TFile *histFile  = new TFile(Form("%s_hist.root", rootfile),"RECREATE");

    treeFile->cd();

    TTree *eventTree = new TTree("eventTree", "Event tree");
    PythiaEvent *eventStore = new PythiaEvent();
    eventTree->Branch("eventTree", &eventStore, 32000, 1);




    //
    //  Retrieve number of events and other parameters from the runcard.
    //  We need to deal with those settings ourself. Getting
    //  them through the runcard just avoids recompiling.
    //
    int  maxNumberOfEvents = settings.mode("Main:numberOfEvents");
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
    

    Pythia8ToHepMC toHepMC(Form("%s.hepmc3", rootfile));
    //IO_GenEvent ascii_io(Form("%s.hepmc3", rootfile));
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

        MakeEvent(pythia, eventStore, maxNumberOfEvents);  // in myEvent we deal with the whole event and return

        eventTree->Fill();
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
	eventTree->Write();
    //treeFile->Write();

	histFile->Close();
	treeFile->Close();

    cout << "Finish!" << endl;
    
    return 0;
}

//
//  Event analysis
//
int MakeEvent(Pythia *pythia, PythiaEvent *eventStore, double nMaxEvt)
{
    Event &event = pythia->event;

	cout<<"NEW EVENT ---------------------------"<<endl;
    

	//if (event[1].id() == 11)

	int eleid = findFinalElectron(event);

    int njpsi = 0;
    for (int i = 0; i < event.size(); i++) {


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


        h_xQ2->Fill(x, Q2);
        h_yQ2->Fill(y, Q2);
        h_xy->Fill(x, y);

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

