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
#include <G4HCofThisEvent.hh>
#include <G4Step.hh>
#include <G4VProcess.hh>
#include <G4ThreeVector.hh>
#include <G4SDManager.hh>
#include <G4ios.hh>

#include <map>

using namespace std;

#include "muensterTPCPmtSensitiveDetector.hh"

muensterTPCPmtSensitiveDetector::muensterTPCPmtSensitiveDetector(G4String hName): G4VSensitiveDetector(hName)
{
	collectionName.insert("PmtHitsCollection");
}

muensterTPCPmtSensitiveDetector::~muensterTPCPmtSensitiveDetector()
{
}

void muensterTPCPmtSensitiveDetector::Initialize(G4HCofThisEvent* pHitsCollectionOfThisEvent)
{
	m_pPmtHitsCollection = new muensterTPCPmtHitsCollection(SensitiveDetectorName, collectionName[0]);

	static G4int iHitsCollectionID = -1;

	if(iHitsCollectionID < 0)
		iHitsCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
	
	pHitsCollectionOfThisEvent->AddHitsCollection(iHitsCollectionID, m_pPmtHitsCollection); 
}

G4bool muensterTPCPmtSensitiveDetector::ProcessHits(G4Step* pStep, G4TouchableHistory *pHistory)
{
	G4Track *pTrack = pStep->GetTrack();

	if(pTrack->GetDefinition()->GetParticleName() == "opticalphoton")
	{
		muensterTPCPmtHit* pHit = new muensterTPCPmtHit();

		pHit->SetPosition(pStep->GetPreStepPoint()->GetPosition());
		pHit->SetTime(pTrack->GetGlobalTime());
		pHit->SetPmtNb(pTrack->GetTouchable()->GetVolume(1)->GetCopyNo());

		m_pPmtHitsCollection->insert(pHit);

//        pHit->Print();
//        pHit->Draw();

		return true;
	}
	else
	{
		return false;
	}
}

void muensterTPCPmtSensitiveDetector::EndOfEvent(G4HCofThisEvent *pHitsCollectionOfThisEvent)
{

}

