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
	Init("Default",0,0,0,0,0,0,0,0,0,0,0,0,0,0);
};

CSoul::CSoul(string Name,int HP,int Agi, int Dex,int Str,int Ldr,int Wis,int Mrk,int Mec,int Exp,int Med,int Lvl,int DailyCost,int Skill1,int Skill2) 
{
	Init(Name,HP,Agi,Dex,Str,Ldr,Wis,Mrk,Mec,Exp,Med,Lvl,DailyCost,Skill1,Skill2);
};

int CSoul::Init(string InitName,int HP,int Agi, int Dex,int Str,int Ldr,int Wis,int Mrk,int Mec,int Exp,int Med,int Lvl,int DailyCost,int Skill1,int Skill2)
{
	// Standard Soul info
	m_sName = InitName;

	cout << "The creator made a new soul..." << endl;
	
	// Attributes
	m_iAgility = Agi;
	m_iDexterity = Dex;
	m_iStrength = Str;
	m_iLeadership = Ldr;
	m_iWisdom = Wis;

	cout << "The creator zeroes in on the attributes..." << endl;
	// Skills
	m_iMarksmanship = Mrk;
	m_iExplosives = Exp;
	m_iMechanical = Mec;
	m_iMedical = Med;	
	m_iPrimary = Skill1;
	m_iSecondary = Skill2;

	cout << "The creator zeroes in on the Skills..." << endl;

	// Energy Level
	m_iHealth = HP;
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