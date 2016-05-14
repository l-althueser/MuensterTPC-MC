/******************************************************************
 * muensterTPCsim
 * 
 * Simulations of the Muenster dual phase xenon TPC
 * 
 * @author Lutz Althueser
 * @date   2013-02-11
 *
 * @comment 
 *
 ******************************************************************/
// include C++ classes
#include <string>
#include <sstream>
#include <unistd.h>
#include <sys/time.h>

#include "muensterTPCActionInitialization.hh"
#include "muensterTPCPrimaryGeneratorAction.hh"
#include "muensterTPCAnalysisManager.hh"
#include "muensterTPCStackingAction.hh"
#include "muensterTPCRunAction.hh"
#include "muensterTPCEventAction.hh"

muensterTPCActionInitialization::muensterTPCActionInitialization (string NewDatafileName, muensterTPCPrimaryGeneratorAction *pNewPrimaryGeneratorAction) {
	DatafileName << NewDatafileName;	
	pPrimaryGeneratorAction = pNewPrimaryGeneratorAction;
  
	// create an analysis manager object
	pAnalysisManager = new muensterTPCAnalysisManager(pPrimaryGeneratorAction);
	// set the filename for the root datafile
	pAnalysisManager->SetDataFilename(DatafileName.str());
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

muensterTPCActionInitialization::~muensterTPCActionInitialization() {

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void muensterTPCActionInitialization::BuildForMaster() const {
  SetUserAction(new muensterTPCRunAction(pAnalysisManager));
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void muensterTPCActionInitialization::Build() const {
	SetUserAction(pPrimaryGeneratorAction);
	SetUserAction(new muensterTPCStackingAction(pAnalysisManager));
	SetUserAction(new muensterTPCRunAction(pAnalysisManager));
	SetUserAction(new muensterTPCEventAction(pAnalysisManager));
}

