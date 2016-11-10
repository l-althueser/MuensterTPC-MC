#ifndef __MUENSTERTPCPRIMARYGENERATORMESSENGER_H__
#define __MUENSTERTPCPRIMARYGENERATORMESSENGER_H__

#include <G4UImessenger.hh>
#include <globals.hh>

class muensterTPCPrimaryGeneratorAction;

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

class muensterTPCPrimaryGeneratorMessenger: public G4UImessenger
{
public:
  muensterTPCPrimaryGeneratorMessenger(muensterTPCPrimaryGeneratorAction *pPrimaryGeneratorAction);
  ~muensterTPCPrimaryGeneratorMessenger();
  
  void SetNewValue(G4UIcommand *pCommand, G4String hNewValues);

private:
  muensterTPCPrimaryGeneratorAction *m_pPrimaryGeneratorAction;
  G4UIdirectory                 *m_pDirectory;
  G4UIcmdWithABool              *m_pWriteEmptyCmd;

};

#endif 

