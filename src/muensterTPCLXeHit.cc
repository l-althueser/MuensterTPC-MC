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
#include <G4UnitsTable.hh>
#include <G4VVisManager.hh>
#include <G4Circle.hh>
#include <G4Colour.hh>
#include <G4VisAttributes.hh>
#include "G4SystemOfUnits.hh"

#include "muensterTPCLXeHit.hh"

G4Allocator<muensterTPCLXeHit> muensterTPCLXeHitAllocator;

muensterTPCLXeHit::muensterTPCLXeHit() {}

muensterTPCLXeHit::~muensterTPCLXeHit()
{
	if(m_pParticleType) delete m_pParticleType;
	if(m_pParentType) delete m_pParentType;
	if(m_pCreatorProcess) delete m_pCreatorProcess;
	if(m_pDepositingProcess) delete m_pDepositingProcess;
}

muensterTPCLXeHit::muensterTPCLXeHit(const muensterTPCLXeHit &hmuensterTPCLXeHit):G4VHit()
{
	m_iTrackId = hmuensterTPCLXeHit.m_iTrackId;
	m_iParentId = hmuensterTPCLXeHit.m_iParentId;
	m_pParticleType = hmuensterTPCLXeHit.m_pParticleType;
	m_pParentType = hmuensterTPCLXeHit.m_pParentType ;
	m_pCreatorProcess = hmuensterTPCLXeHit.m_pCreatorProcess ;
	m_pDepositingProcess = hmuensterTPCLXeHit.m_pDepositingProcess ;
	m_hPosition = hmuensterTPCLXeHit.m_hPosition;
	m_dEnergyDeposited = hmuensterTPCLXeHit.m_dEnergyDeposited;
	m_dKineticEnergy = hmuensterTPCLXeHit.m_dKineticEnergy ;
	m_dTime = hmuensterTPCLXeHit.m_dTime;
}

const muensterTPCLXeHit &
muensterTPCLXeHit::operator=(const muensterTPCLXeHit &hmuensterTPCLXeHit)
{
	m_iTrackId = hmuensterTPCLXeHit.m_iTrackId;
	m_iParentId = hmuensterTPCLXeHit.m_iParentId;
	m_pParticleType = hmuensterTPCLXeHit.m_pParticleType;
	m_pParentType = hmuensterTPCLXeHit.m_pParentType ;
	m_pCreatorProcess = hmuensterTPCLXeHit.m_pCreatorProcess ;
	m_pDepositingProcess = hmuensterTPCLXeHit.m_pDepositingProcess ;
	m_hPosition = hmuensterTPCLXeHit.m_hPosition;
	m_dEnergyDeposited = hmuensterTPCLXeHit.m_dEnergyDeposited;
	m_dKineticEnergy = hmuensterTPCLXeHit.m_dKineticEnergy ;
	m_dTime = hmuensterTPCLXeHit.m_dTime;
	
	return *this;
}

G4int
muensterTPCLXeHit::operator==(const muensterTPCLXeHit &hmuensterTPCLXeHit) const
{
	return ((this == &hmuensterTPCLXeHit) ? (1) : (0));
}

void muensterTPCLXeHit::Draw()
{
	G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
	G4cout << "---------------------- möp -----------------" << G4endl;
	if(pVVisManager)
	{
		
		G4Circle hCircle(m_hPosition);
		G4Colour hColour(1.000, 0.973, 0.184);
		G4VisAttributes hVisAttributes(hColour);
		
		hCircle.SetScreenSize(1.);
		hCircle.SetFillStyle(G4Circle::filled);
		hCircle.SetVisAttributes(hVisAttributes);
		pVVisManager->Draw(hCircle);
	}
}

void muensterTPCLXeHit::Print()
{
	/*G4cout << "-------------------- LXe hit --------------------" 
		<< "Id: " << m_iTrackId
		<< " Particle: " << *m_pParticleType
		<< " ParentId: " << m_iParentId
		<< " ParentType: " << *m_pParentType << G4endl
		<< "CreatorProcess: " << *m_pCreatorProcess
		<< " DepositingProcess: " << *m_pDepositingProcess << G4endl
		<< "Position: " << m_hPosition.x()/mm
		<< " " << m_hPosition.y()/mm
		<< " " << m_hPosition.z()/mm
		<< " mm" << G4endl
		<< "EnergyDeposited: " << m_dEnergyDeposited/keV << " keV"
		<< " KineticEnergyLeft: " << m_dKineticEnergy/keV << " keV"
		<< " Time: " << m_dTime/s << " s" << G4endl;*/
}

