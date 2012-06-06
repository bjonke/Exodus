//-------------------------------------------------------------------------
// Namn: Rickard Skeppström
// E-mail: rickard_skeppstrom@gmail.com
// 
//-------------------------------------------------------------------------

#include <iostream>
using namespace std;
#include "CSoul.h"

CSoul::CSoul() 
{
	Init("Default");
};

CSoul::CSoul(string Name) 
{
	Init(Name);
};

int CSoul::Init(string InitName)
{
	// Standard Soul info
	m_sName = InitName;

	cout << "The creator made a new soul..." << endl;
	
	// Attributes
	m_iAgility = 0;
	m_iDexterity = 0;
	m_iStrength = 0;
	m_iLeadership = 0;
	m_iWisdom = 0;

	cout << "The creator zeroes in on the attributes..." << endl;
	// Skills
	m_iMarksmanship = 0;
	m_iExplosives = 0;
	m_iMechanical = 0;
	m_iMedical = 0;	

	cout << "The creator zeroes in on the Skills..." << endl;

	// Energy Level
	m_iHealth = 0;
	m_iEnergy = 0;
	m_iMoral = 0;
	m_iExperience = 0;

	cout << "The creator zeroes in on the Energy levels..." << endl;

	// Costs
	m_iCost = 0;

	cout << "The creator applies a cost for the mercs soul" << endl;
	return 0;
}

CSoul::~CSoul() 
{
	cout << "Reaper reposessed soul" << endl;
};