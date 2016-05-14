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
#ifndef __muensterTPCPPMTHIT_H__
#define __muensterTPCPPMTHIT_H__

#include <G4VHit.hh>
#include <G4THitsCollection.hh>
#include <G4Allocator.hh>
#include <G4ThreeVector.hh>

class muensterTPCPmtHit: public G4VHit {
public:
	muensterTPCPmtHit();
	~muensterTPCPmtHit();
	muensterTPCPmtHit(const muensterTPCPmtHit &);
	const muensterTPCPmtHit & operator=(const muensterTPCPmtHit &);
	G4int operator==(const muensterTPCPmtHit &) const;

	inline void* operator new(size_t);
	inline void  operator delete(void*);

	void Draw();
	void Print();

public:
	void SetPosition(G4ThreeVector hPosition) { m_hPosition = hPosition; }
	void SetTime(G4double dTime) { m_dTime = dTime; }
	void SetPmtNb(G4int iPmtNb) { m_iPmtNb = iPmtNb; }

	G4ThreeVector GetPosition() { return m_hPosition; }
	G4double GetTime() { return m_dTime; }
	G4int GetPmtNb() { return m_iPmtNb; }

private:
	G4ThreeVector m_hPosition;
	G4double m_dTime;
	G4int m_iPmtNb;
};

typedef G4THitsCollection<muensterTPCPmtHit> muensterTPCPmtHitsCollection;

extern G4Allocator<muensterTPCPmtHit> muensterTPCPmtHitAllocator;

inline void* muensterTPCPmtHit::operator new(size_t) {
	return((void *) muensterTPCPmtHitAllocator.MallocSingle());
}

inline void muensterTPCPmtHit::operator delete(void *pmuensterTPCPmtHit) {
	muensterTPCPmtHitAllocator.FreeSingle((muensterTPCPmtHit*) pmuensterTPCPmtHit);
}

#endif // __muensterTPCPPMTHIT_H__

