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
#include <G4ThreeVector.hh>
#include <G4RotationMatrix.hh>
#include <G4ParticleTable.hh>
#include <G4UIdirectory.hh>
#include <G4UIcmdWithoutParameter.hh>
#include <G4UIcmdWithAString.hh>
#include <G4UIcmdWithADoubleAndUnit.hh>
#include <G4UIcmdWith3Vector.hh>
#include <G4UIcmdWith3VectorAndUnit.hh>
#include <G4UIcmdWithAnInteger.hh>
#include <G4UIcmdWithADouble.hh>
#include <G4UIcmdWithABool.hh>
#include <G4Tokenizer.hh>
#include <G4ios.hh>
#include <fstream>
#include <iomanip>

#include "muensterTPCDetectorMessenger.hh"

#include "muensterTPCDetectorConstruction.hh"

muensterTPCDetectorMessenger::muensterTPCDetectorMessenger(muensterTPCDetectorConstruction *pXeDetector)
:m_pXeDetector(pXeDetector)
{ 
	m_pDetectorDir = new G4UIdirectory("/Xe/detector/");
	m_pDetectorDir->SetGuidance("detector control.");

	// Not working - just a template
	m_pLXeLevelCmd = new G4UIcmdWithADoubleAndUnit("/Xe/detector/setLXeLevel", this);
	m_pLXeLevelCmd->SetGuidance("Define level of the liquid xenon - spread of the GXe.");
	m_pLXeLevelCmd->SetParameterName("LXeLevel", false);
	m_pLXeLevelCmd->SetRange("LXeLevel >= 0.");
	m_pLXeLevelCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

  m_pMaterCmd = new G4UIcmdWithAString("/Xe/detector/setMat",this);
  m_pMaterCmd->SetGuidance("Select material of the LXe volume.");
  m_pMaterCmd->SetParameterName("choice",false);
  m_pMaterCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

  m_pLXeMeshMaterialCmd = new G4UIcmdWithAString("/Xe/detector/setLXeMeshMaterial",this);
  m_pLXeMeshMaterialCmd->SetGuidance("Select material of the LXe Meshes.");
  m_pLXeMeshMaterialCmd->SetParameterName("choice",false);
  m_pLXeMeshMaterialCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

  m_pGXeMeshMaterialCmd = new G4UIcmdWithAString("/Xe/detector/setGXeMeshMaterial",this);
  m_pGXeMeshMaterialCmd->SetGuidance("Select material of the GXe Meshes.");
  m_pGXeMeshMaterialCmd->SetParameterName("choice",false);
  m_pGXeMeshMaterialCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

	m_pTeflonReflectivityCmd = new G4UIcmdWithADouble("/Xe/detector/setTeflonReflectivity", this);
	m_pTeflonReflectivityCmd->SetGuidance("Define teflon reflectivity.");
	m_pTeflonReflectivityCmd->SetParameterName("R", false);
	m_pTeflonReflectivityCmd->SetRange("R >= 0. && R <= 1.");
	m_pTeflonReflectivityCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

	m_pLXeScintillationCmd = new G4UIcmdWithABool("/Xe/detector/setLXeScintillation", this);
	m_pLXeScintillationCmd->SetGuidance("Switch on/off LXe scintillation in the sensitive volume.");
	m_pLXeScintillationCmd->SetParameterName("LXeScint", false); 
	m_pLXeScintillationCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

	m_pLXeAbsorbtionLengthCmd = new G4UIcmdWithADoubleAndUnit("/Xe/detector/setLXeAbsorbtionLength", this);
	m_pLXeAbsorbtionLengthCmd->SetGuidance("Define LXe absorbtion length.");
	m_pLXeAbsorbtionLengthCmd->SetParameterName("AbsL", false);
	m_pLXeAbsorbtionLengthCmd->SetRange("AbsL >= 0.");
	m_pLXeAbsorbtionLengthCmd->SetUnitCategory("Length");
	m_pLXeAbsorbtionLengthCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

	m_pLXeRayScatterLengthCmd = new G4UIcmdWithADoubleAndUnit("/Xe/detector/setLXeRayScatterLength", this);
	m_pLXeRayScatterLengthCmd->SetGuidance("Define LXe Rayleigh Scattering length.");
	m_pLXeRayScatterLengthCmd->SetParameterName("ScatL", false);
	m_pLXeRayScatterLengthCmd->SetRange("ScatL >= 0.");
	m_pLXeRayScatterLengthCmd->SetUnitCategory("Length");
	m_pLXeRayScatterLengthCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

}

muensterTPCDetectorMessenger::~muensterTPCDetectorMessenger()
{
	delete m_pLXeLevelCmd;
	delete m_pMaterCmd;
	delete m_pLXeMeshMaterialCmd;
	delete m_pGXeMeshMaterialCmd;
	delete m_pTeflonReflectivityCmd;
	delete m_pLXeScintillationCmd;
	delete m_pLXeAbsorbtionLengthCmd;
	delete m_pLXeRayScatterLengthCmd;


	delete m_pDetectorDir;
}

void muensterTPCDetectorMessenger::SetNewValue(G4UIcommand *pUIcommand, G4String hNewValue)
{

	if(pUIcommand == m_pLXeLevelCmd)
		m_pXeDetector->SetLXeLevel(m_pLXeLevelCmd->GetNewDoubleValue(hNewValue));

  if(pUIcommand == m_pMaterCmd )
    m_pXeDetector->SetMaterial(hNewValue);

  if(pUIcommand == m_pLXeMeshMaterialCmd )
    m_pXeDetector->SetLXeMeshMaterial(hNewValue);

  if(pUIcommand == m_pGXeMeshMaterialCmd )
    m_pXeDetector->SetGXeMeshMaterial(hNewValue);

	if(pUIcommand == m_pLXeScintillationCmd)
		m_pXeDetector->SetLXeScintillation(m_pLXeScintillationCmd->GetNewBoolValue(hNewValue));

	if(pUIcommand == m_pTeflonReflectivityCmd)
		m_pXeDetector->SetTeflonReflectivity(m_pTeflonReflectivityCmd->GetNewDoubleValue(hNewValue));		
		
	if(pUIcommand == m_pLXeAbsorbtionLengthCmd)
		m_pXeDetector->SetLXeAbsorbtionLength(m_pLXeAbsorbtionLengthCmd->GetNewDoubleValue(hNewValue));

	if(pUIcommand == m_pLXeRayScatterLengthCmd)
		m_pXeDetector->SetLXeRayScatterLength(m_pLXeRayScatterLengthCmd->GetNewDoubleValue(hNewValue));
		
		

}


