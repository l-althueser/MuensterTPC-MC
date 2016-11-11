/******************************************************************
 * muensterTPCsim
 * 
 * Simulations of the Muenster dual phase xenon TPC
 * 
 * @author Lutz Althueser
 * @date   2013-02-11
 *
 * @comment 
 *
 ******************************************************************/

#ifndef muensterTPCActionInitialization_h
#define muensterTPCActionInitialization_h 1

#include "G4VUserActionInitialization.hh"
#include "muensterTPCAnalysisManager.hh"
#include "muensterTPCPrimaryGeneratorAction.hh"

#include <string.h>    
#include <iostream>
#include <sstream>

/// Action initialization class.

class muensterTPCActionInitialization : public G4VUserActionInitialization
{
  public:
  	muensterTPCActionInitialization(std::string, muensterTPCPrimaryGeneratorAction*);
    virtual ~muensterTPCActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;

  private:
  	muensterTPCAnalysisManager *pAnalysisManager;
  	muensterTPCPrimaryGeneratorAction *pPrimaryGeneratorAction;

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
