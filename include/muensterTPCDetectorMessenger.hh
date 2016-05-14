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
#ifndef muensterTPCDetectorMessenger_h
#define muensterTPCDetectorMessenger_h 1

#include <G4UImessenger.hh>
#include <globals.hh>

class muensterTPCDetectorConstruction;

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

class muensterTPCDetectorMessenger: public G4UImessenger {
public:
	muensterTPCDetectorMessenger(muensterTPCDetectorConstruction *pXeDetector);
	~muensterTPCDetectorMessenger();

	void SetNewValue(G4UIcommand *pUIcommand, G4String hString);

private:
	muensterTPCDetectorConstruction* m_pXeDetector;

	G4UIdirectory *m_pDetectorDir;

	G4UIcmdWithADoubleAndUnit *m_pLXeLevelCmd;
  G4UIcmdWithAString	*m_pMaterCmd;
  G4UIcmdWithAString	*m_pLXeMeshMaterialCmd;
  G4UIcmdWithAString	*m_pGXeMeshMaterialCmd;
	G4UIcmdWithADouble *m_pTeflonReflectivityCmd;
	G4UIcmdWithABool *m_pLXeScintillationCmd;
	G4UIcmdWithADoubleAndUnit *m_pLXeAbsorbtionLengthCmd;
	G4UIcmdWithADoubleAndUnit *m_pLXeRayScatterLengthCmd;

};
#endif

