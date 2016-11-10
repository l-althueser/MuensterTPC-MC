/******************************************************************
 * muensterTPCsim
 * 
 * Simulations of the Muenster TPC
 * 
 * @author Lutz Althüser, based on muensterTPC (Levy) and Xenon100
 * @date   2015-04-14
 *
 * @comment 
 ******************************************************************/
#include <G4SDManager.hh>

#include <Randomize.hh>
#include <sys/time.h>

#include "muensterTPCAnalysisManager.hh"
#include "muensterTPCRunAction.hh"

muensterTPCRunAction::muensterTPCRunAction(muensterTPCAnalysisManager *pAnalysisManager) {
	m_pAnalysisManager = pAnalysisManager;
}

muensterTPCRunAction::~muensterTPCRunAction() {

}

void muensterTPCRunAction::BeginOfRunAction(const G4Run *pRun) {
	if (( ! G4Threading::IsMultithreadedApplication() ) ||
			( G4Threading::IsMultithreadedApplication() && ! G4Threading::IsWorkerThread() )) {
		if(m_pAnalysisManager)
			m_pAnalysisManager->BeginOfRun(pRun);

		struct timeval hTimeValue;
		gettimeofday(&hTimeValue, NULL);
		
		CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
		CLHEP::HepRandom::setTheSeed(hTimeValue.tv_usec);
	}
}

void muensterTPCRunAction::EndOfRunAction(const G4Run *pRun) {
	if (( ! G4Threading::IsMultithreadedApplication() ) ||
				( G4Threading::IsMultithreadedApplication() && ! G4Threading::IsWorkerThread() )) {
		if(m_pAnalysisManager)
			m_pAnalysisManager->EndOfRun(pRun);
	}
}

