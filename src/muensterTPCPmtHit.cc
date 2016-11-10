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
#include "muensterTPCPmtHit.hh"

G4Allocator<muensterTPCPmtHit> muensterTPCPmtHitAllocator;

muensterTPCPmtHit::muensterTPCPmtHit() {}

muensterTPCPmtHit::~muensterTPCPmtHit() {}

muensterTPCPmtHit::muensterTPCPmtHit(const muensterTPCPmtHit &hmuensterTPCPmtHit):G4VHit()
{
	m_hPosition = hmuensterTPCPmtHit.m_hPosition;
	m_dTime = hmuensterTPCPmtHit.m_dTime;
	m_iPmtNb = hmuensterTPCPmtHit.m_iPmtNb;

}

const muensterTPCPmtHit &
muensterTPCPmtHit::operator=(const muensterTPCPmtHit &hmuensterTPCPmtHit)
{
	m_hPosition = hmuensterTPCPmtHit.m_hPosition;
	m_dTime = hmuensterTPCPmtHit.m_dTime;
	m_iPmtNb = hmuensterTPCPmtHit.m_iPmtNb;

	return *this;
}

G4int
muensterTPCPmtHit::operator==(const muensterTPCPmtHit &hmuensterTPCPmtHit) const
{
	return ((this == &hmuensterTPCPmtHit) ? (1) : (0));
}

void muensterTPCPmtHit::Draw()
{
    //G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
    
    //if(pVVisManager)
    //{
    //    G4Circle hCircle(m_hPosition);
    //    G4Colour hColour(1.000, 0.973, 0.184);
    //    G4VisAttributes hVisAttributes(hColour);
    //    
    //    hCircle.SetScreenSize(0.1);
    //    hCircle.SetFillStyle(G4Circle::filled);
    //    hCircle.SetVisAttributes(hVisAttributes);
    //    pVVisManager->Draw(hCircle);
    //}
}

void muensterTPCPmtHit::Print()
{
	G4cout << "Pmt hit ---> " 
		<< "Pmt#" << m_iPmtNb
		<< " Position: " << m_hPosition.x()/mm
		<< " " << m_hPosition.y()/mm
		<< " " << m_hPosition.z()/mm
		<< " mm"
		<< " Time: " << m_dTime/s << " s" << G4endl;
}

