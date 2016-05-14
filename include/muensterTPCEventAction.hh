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
#ifndef __muensterTPCPEVENTACTION_H__
#define __muensterTPCPEVENTACTION_H__

#include <G4UserEventAction.hh>
#include <string>
#include <sstream>
#include <unistd.h>
#include <sys/time.h>
#include "muensterTPCAnalysisManager.hh"

class G4Event;

class muensterTPCEventAction : public G4UserEventAction {
public:
	muensterTPCEventAction(muensterTPCAnalysisManager *pAnalysisManager = 0);
	~muensterTPCEventAction();

public:
	void BeginOfEventAction(const G4Event *pEvent);
	void EndOfEventAction(const G4Event *pEvent);

private:
	muensterTPCAnalysisManager *m_pAnalysisManager;
	time_t time_un;
	time_t starttimeunix, currtimeunix, endtimeunix;
	tm *time_now, *time_end;
	char endtime[80];
	stringstream starttime, currtime;
	G4int m_iNbEventsToSimulate;
};

#endif // __muensterTPCPEVENTACTION_H__

