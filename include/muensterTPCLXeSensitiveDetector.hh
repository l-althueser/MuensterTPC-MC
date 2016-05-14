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
#ifndef __muensterTPCPLXESENSITIVEDETECTOR_H__
#define __muensterTPCPLXESENSITIVEDETECTOR_H__

#include <G4VSensitiveDetector.hh>

#include "muensterTPCLXeHit.hh"

using std::map;

class G4Step;
class G4HCofThisEvent;

class muensterTPCLXeSensitiveDetector: public G4VSensitiveDetector {
public:
	muensterTPCLXeSensitiveDetector(G4String hName);
	~muensterTPCLXeSensitiveDetector();

	void Initialize(G4HCofThisEvent *pHitsCollectionOfThisEvent);
	G4bool ProcessHits(G4Step *pStep, G4TouchableHistory *pHistory);
	void EndOfEvent(G4HCofThisEvent *pHitsCollectionOfThisEvent);

private:
	muensterTPCLXeHitsCollection* m_pLXeHitsCollection;

	map<int,G4String> m_hParticleTypes;
};

#endif // __muensterTPCPLXESENSITIVEDETECTOR_H__

