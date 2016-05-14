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
#ifndef __muensterTPCPSTACKINGACTION_H__
#define __muensterTPCPSTACKINGACTION_H__

#include <globals.hh>
#include <G4UserStackingAction.hh>

class muensterTPCAnalysisManager;

class muensterTPCStackingAction: public G4UserStackingAction {
public:
	muensterTPCStackingAction(muensterTPCAnalysisManager *pAnalysisManager=0);
	~muensterTPCStackingAction();
  
	virtual G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track* aTrack);
	virtual void NewStage();
	virtual void PrepareNewEvent();

private:
	muensterTPCAnalysisManager *m_pAnalysisManager;
};

#endif // __muensterTPCPSTACKINGACTION_H__

