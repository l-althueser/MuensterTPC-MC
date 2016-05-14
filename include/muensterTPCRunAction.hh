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
#ifndef __muensterTPCPRUNACTION_H__
#define __muensterTPCPRUNACTION_H__

#include <G4UserRunAction.hh>

class G4Run;

class muensterTPCAnalysisManager;

class muensterTPCRunAction: public G4UserRunAction {
public:
	muensterTPCRunAction(muensterTPCAnalysisManager *pAnalysisManager=0);
	~muensterTPCRunAction();

public:
	void BeginOfRunAction(const G4Run *pRun);
	void EndOfRunAction(const G4Run *pRun);

private:
	muensterTPCAnalysisManager *m_pAnalysisManager;
};

#endif // __muensterTPCPRUNACTION_H__

