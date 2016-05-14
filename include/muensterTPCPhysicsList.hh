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
#ifndef __muensterTPCPPHYSICSLIST_H__
#define __muensterTPCPPHYSICSLIST_H__

#include <G4VUserPhysicsList.hh>
#include <globals.hh>

#include "muensterTPCPhysicsMessenger.hh"
#include "G4DecayPhysics.hh"

class muensterTPCPhysicsList: public G4VUserPhysicsList {
public:
	muensterTPCPhysicsList();
	~muensterTPCPhysicsList();

public:
	void SetCuts();

	// functions for the messenger interface
  void SetEMlowEnergyModel(G4String theModel) { m_hEMlowEnergyModel = theModel; }
  void SetHadronicModel(G4String theModel)    { m_hHadronicModel = theModel; }
  void SetCerenkov(G4bool useCerenkov) { m_bCerenkov = useCerenkov; }

protected:
	void ConstructParticle();
	void ConstructProcess();

	void ConstructGeneral();
	void ConstructEM();
	void ConstructHad();
	void ConstructOp();

	void AddTransportation();

	void SetBuilderList1(G4bool flagHP);

private:
	G4int VerboseLevel;
	G4int OpVerbLevel;

	G4double cutForGamma;
	G4double cutForElectron;
	G4double cutForPositron;
	G4double cutForProton;
	G4double cutForAlpha;
	G4double cutForGenericIon;

	void ConstructMyBosons();
	void ConstructMyLeptons();
	void ConstructMyHadrons();
	void ConstructMyShortLiveds();

	G4VPhysicsConstructor*               emPhysicsList;
  G4VPhysicsConstructor*               opPhysicsList;
  std::vector<G4VPhysicsConstructor*>  hadronPhys;

	muensterTPCPhysicsMessenger *m_pMessenger;
  G4String                 m_hEMlowEnergyModel;
  G4String                 m_hHadronicModel;
  G4bool                   m_bCerenkov;
  G4DecayPhysics          *particleList;

};

#endif // __muensterTPCPPHYSICSLIST_H__

