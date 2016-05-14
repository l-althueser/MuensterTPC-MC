/******************************************************************
 * muensterTPCsim
 * 
 * Simulations of the Muenster TPC
 * 
 * @author Lutz Althüser
 * @date   2015-04-14
 *
 * @update 2015-11-02 - added comments
 *
 * @comment
 ******************************************************************/
#ifndef __muensterTPCPPMTSENSITIVEDETECTOR_H__
#define __muensterTPCPPMTSENSITIVEDETECTOR_H__

#include <G4VSensitiveDetector.hh>

#include "muensterTPCPmtHit.hh"

class G4Step;
class G4HCofThisEvent;

class muensterTPCPmtSensitiveDetector: public G4VSensitiveDetector {
public:
	muensterTPCPmtSensitiveDetector(G4String hName);
	~muensterTPCPmtSensitiveDetector();

	void Initialize(G4HCofThisEvent *pHitsCollectionOfThisEvent);
	G4bool ProcessHits(G4Step *pStep, G4TouchableHistory *pHistory);
	void EndOfEvent(G4HCofThisEvent *pHitsCollectionOfThisEvent);

private:
	muensterTPCPmtHitsCollection* m_pPmtHitsCollection;
};

#endif // __muensterTPCPPMTSENSITIVEDETECTOR_H__

