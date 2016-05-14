/******************************************************************
 * muensterTPCsim
 * 
 * Simulations of the Muenster dual phase xenon TPC
 * 
 * @author Lutz Althueser
 * @date   2015-09-28
 *
 * @comment This is the main class of the Muenster dual phase xenon TPC.
 *					It includes ..
 *						- argument handling for interactive or batch mode
 *						- naming of the output data file
 *						- enable/disable Multithreading
 *
 *					The simulation is ready for ..
 * 						- dual and single phase simulations (change LXe -> GXe)
 * 						  see DetectorMessenger.cc
 *						- different source types (shape and particle)
 *						  see ParticleSourceMessenger.cc
 *						- different PhysicsLists are available (incl. Cerenkov) 
 *							see PhysicsList.cc
 ******************************************************************/
// include C++ classes
#include <string>
#include <sstream>
#include <unistd.h>
#include <sys/time.h>

// include GEANT4 classes
//#ifdef G4MULTITHREADED
//#include "G4MTRunManager.hh"
//#else
#include "G4RunManager.hh"
//#endif
#include <G4UImanager.hh>
#include <G4UIterminal.hh>
#include <G4UItcsh.hh>
#include <G4VisExecutive.hh>
#include <G4UIExecutive.hh>

//include Muenster TPC simulation classes
#include "muensterTPCDetectorConstruction.hh"
#include "muensterTPCPhysicsList.hh"
#include "muensterTPCPrimaryGeneratorAction.hh"
#include "muensterTPCAnalysisManager.hh"
#include "muensterTPCStackingAction.hh"
#include "muensterTPCRunAction.hh"
#include "muensterTPCEventAction.hh"
#include "muensterTPCActionInitialization.hh"

//******************************************************************/
// call of the main function with optional arguments 
//******************************************************************/
int main(int argc, char **argv)
{
	// Detect interactive mode (if no arguments) and define UI session
 	G4UIExecutive* ui = 0;
 	if ( argc == 1 ) ui = new G4UIExecutive(argc, argv, "qt");

  // get local time for the output file time stamp
	time_t time_un;
	tm *time_now;
	time_un = time(0);
	time_now = localtime(&time_un);
	stringstream DatafileName;
	DatafileName << time_now->tm_year+1900 << "-" << time_now->tm_mon+1 
		     << "-" << time_now->tm_mday << "_" << time_now->tm_hour
		     << "-" << time_now->tm_min << "-" << time_now->tm_sec
		     << "_";

	G4String fileName;

 	if ( ! ui ) { 
		fileName = argv[1];

		// delete the path to the macro file while building the datafile name
		// /home/../test.mac will save a test.mac.root file in the working directory
		unsigned found=fileName.find_last_of("/");
 		if (found!=std::string::npos)
		  DatafileName << fileName.substr(found+1) << ".root";
		else
 		  DatafileName << fileName << ".root";
  }
  else { 
		// flag the root data with 'interactive'
		DatafileName << "interactive" << ".root";
	}

	// create the run manager
	//#ifdef G4MULTITHREADED
	//	G4MTRunManager *pRunManager = new G4MTRunManager;
	//	pRunManager->SetNumberOfThreads(G4Threading::G4GetNumberOfCores());
	//#else
		G4RunManager *pRunManager = new G4RunManager;
	//#endif
	
	// set user-defined initialization classes
	pRunManager->SetUserInitialization(new muensterTPCDetectorConstruction);
	pRunManager->SetUserInitialization(new muensterTPCPhysicsList);
	
	// create the primary generator action
	muensterTPCPrimaryGeneratorAction *pPrimaryGeneratorAction = new muensterTPCPrimaryGeneratorAction();
	pRunManager->SetUserInitialization(new muensterTPCActionInitialization(DatafileName.str(), pPrimaryGeneratorAction));
	pRunManager->Initialize();

	// start visualization and ui manager
	G4VisManager* pVisManager = new G4VisExecutive;
	pVisManager->Initialize();
	G4UImanager* pUImanager = G4UImanager::GetUIpointer();
	
 	// Process macro or start UI session
 	if ( ! ui ) { 
		// batch mode - call macro file of the optional parameter
 		G4String command = "/control/execute ";

		// run the macro
 		pUImanager->ApplyCommand(command+fileName);
  }
  else { 
  	// interactive mode
		// .. execute the initialisation macro for visualization manager in generall
  	pUImanager->ApplyCommand("/control/execute macros/vis_init.mac");
		// .. execute the customization macro for the QT VI manager
		pUImanager->ApplyCommand("/control/execute macros/vis_Qt.mac");

		// start ui and delete it when the user closes the ui
  	ui->SessionStart();  	
		delete ui;
		// note: The segmentation fault after closing the ui without simulating events is a bug in the current GEANT4 10.01 Version (2015-10-01)
  }
  
	// delete all created objects
	delete pVisManager;
	delete pRunManager;
	
	G4cout 	<< "===========================================" 	<< G4endl;
	G4cout	<< "Simulation successfully completed :)" 				<< G4endl;
	G4cout 	<< "===========================================" 	<< G4endl;
	return 0;	
}
