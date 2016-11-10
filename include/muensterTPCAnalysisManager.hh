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
#ifndef __muensterTPCPANALYSISMANAGER_H__
#define __muensterTPCPANALYSISMANAGER_H__

#include <globals.hh>
#include <TParameter.h>

class G4Run;
class G4Event;
class G4Step;

class TFile;
class TTree;

class muensterTPCEventData;
class muensterTPCPrimaryGeneratorAction;

class muensterTPCAnalysisManager {
public:
	muensterTPCAnalysisManager(muensterTPCPrimaryGeneratorAction *pPrimaryGeneratorAction);
	virtual ~muensterTPCAnalysisManager();

public:
	virtual void BeginOfRun(const G4Run *pRun); 
	virtual void EndOfRun(const G4Run *pRun); 
	virtual void BeginOfEvent(const G4Event *pEvent); 
	virtual void EndOfEvent(const G4Event *pEvent); 
	virtual void Step(const G4Step *pStep);	

	void SetDataFilename(const G4String &hFilename) { m_hDataFilename = hFilename; }
	void SetNbEventsToSimulate(G4int iNbEventsToSimulate) { m_iNbEventsToSimulate = iNbEventsToSimulate; }
	G4int GetNbEventsToSimulate() { return m_iNbEventsToSimulate; }

private:
	G4bool FilterEvent(muensterTPCEventData *pEventData);

private:
	G4int m_iLXeHitsCollectionID;
	G4int m_iPmtHitsCollectionID;

	G4String m_hDataFilename;
	G4int m_iNbEventsToSimulate;

	TFile *m_pTreeFile;
	TTree *m_pTree;
	TDirectory *_events;
	
	TParameter<int> *m_pNbEventsToSimulateParameter;

	muensterTPCPrimaryGeneratorAction *m_pPrimaryGeneratorAction;

	muensterTPCEventData *m_pEventData;
	
	G4bool writeEmptyEvents;
};

#endif // __muensterTPCPANALYSISMANAGER_H__

