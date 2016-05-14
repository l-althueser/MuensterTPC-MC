#ifndef __MUENSTERTPCPHYSICSMESSENGER_H__
#define __MUENSTERTPCPHYSICSMESSENGER_H__
/******************************************************************
 * muensterTPCsim
 * 
 * Simulations of the Muenster TPC
 * Allow for setting of preferences in the PhysicsList
 * 
 * @author Lutz Althüser, based on Xenon1t
 * @date   2016-02-16
 *
 * @comment 
 ******************************************************************/

#include <G4UImessenger.hh>
#include <globals.hh>

class muensterTPCPhysicsList;

class G4UIcommand;
class G4UIdirectory;
class G4UIcmdWithoutParameter;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWith3Vector;
class G4UIcmdWith3VectorAndUnit;
class G4UIcmdWithAnInteger;
class G4UIcmdWithADouble;
class G4UIcmdWithABool;
class G4UIcmdWithoutParameter;

class muensterTPCPhysicsMessenger: public G4UImessenger
{
public:
  muensterTPCPhysicsMessenger(muensterTPCPhysicsList *pPhysicsList);
  ~muensterTPCPhysicsMessenger();
  
  void SetNewValue(G4UIcommand *pCommand, G4String hNewValues);
private:
  muensterTPCPhysicsList     *m_pPhysicsList;
  G4UIdirectory              *m_pDirectory;
  G4UIcmdWithAString         *m_pEMlowEnergyModelCmd;
  G4UIcmdWithAString         *m_pHadronicModelCmd;
  G4UIcmdWithABool           *m_pCerenkovCmd;
};

#endif // __MUENSTERTPCPHYSICSMESSENGER_H__

