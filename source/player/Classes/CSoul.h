//-------------------------------------------------------------------------
// Namn: Rickard Skeppström
// E-mail: rickard_skeppstrom@gmail.com
// 
//-------------------------------------------------------------------------

#ifndef CSOUL_H
#define CSOUL_H

#include <vector>
class CSoul;

class CSoul
{
public:
	CSoul();
	CSoul(string Name,int HP,int Agi, int Dex,int Str,int Ldr,int Wis,int Mrk,int Mec,int Exp,int Med,int Lvl,int DailyCost,int Skill1,int Skill2);
	~CSoul();

private:

	// Name      HP Agi Dex Str Ldr Wis Mrk Mec Exp Med Lvl Daily$ Skill #1 Skill #2
	// Standard Soul info
	string m_sName;

	// Attributes
	int m_iAgility;
	int m_iDexterity;
	int m_iStrength;
	int m_iLeadership;
	int m_iWisdom;

	// Skills
	int m_iMarksmanship;
	int m_iExplosives;
	int m_iMechanical;
	int m_iMedical;
	int m_iPrimary;
	int m_iSecondary;

	// Energy Level
	int m_iHealth;
	int m_iEnergy;
	int m_iMoral;
	int m_iExperience;

	// Costs
	int m_iCost;

	int Init(string InitName,int HP,int Agi, int Dex,int Str,int Ldr,int Wis,int Mrk,int Mec,int Exp,int Med,int Lvl,int DailyCost,int Skill1,int Skill2);
};
#endif

/*
#ifndef SSOUL_H
#define SSOUL_H

#include <vector>
#include <cmath>
using namespace std;
#include "../misc/macros.h"


struct SSoul
{
	// Actor stats
	int m_Strength;
	int m_Intelligence;
	int m_Wisdom;
	int m_Constitution;
	int m_Charisma;
	int m_Dexterity;
	int m_StatPoints;
	// Actor class
	int m_ClassID;
	int m_Guild;
	// Other
	int m_Sprite;
	int m_Attack;
	int m_Defence;
	int m_Gender;

	SSoul()
	{
		m_Strength = 10;
		m_Intelligence = 10;
		m_Wisdom = 10;
		m_Constitution = 10;
		m_Charisma = 10;
		m_Dexterity = 10;
		m_StatPoints = 0;
		m_ClassID = 0;
		m_Guild = 0;
		m_Sprite = 1;
		m_Attack = m_Strength;
		m_Defence = m_Dexterity;
	};

	int getCharacterLevel(int experience)
	{
		
		m_StatPoints = (int)(floor((float)(-((float)7/2) + sqrt((float)(((float)7/2)*((float)7/2) - 4 * ((float)1/2) * ((float)-4 - experience)))) / (2 * ((float)1/2))));
		return (int)(floor((float)(-((float)7/2) + sqrt((float)(((float)7/2)*((float)7/2) - 4 * ((float)1/2) * ((float)-4 - experience)))) / (2 * ((float)1/2))));
	}

	struct ItemMods
	{
		int m_Attack;
		int m_Defence;

		void Reset()
		{
			m_Attack = 0;
			m_Defence = 0;
		}

		void ImproveAttack( int value )
		{
			m_Attack += value;
		}

		void ImproveDefence( int value )
		{
			m_Defence += value;
		}

	} IMods;

	struct GuildMods
	{
		int m_Strength;
		int m_Intelligence;
		int m_Wisdom;
		int m_Constitution;
		int m_Charisma;
		int m_Dexterity;

		void Reset()
		{
			m_Strength = 0;
			m_Intelligence = 0;
			m_Wisdom = 0;
			m_Constitution = 0;
			m_Charisma = 0;
			m_Dexterity = 0;
		}

		void Fighter()
		{
			m_Strength = 5;
		}
		void Mage()
		{
			m_Intelligence = 5;
		}
		void Cleric()
		{
			m_Wisdom = 5;
		}
		void Thief()
		{
			m_Dexterity = 5;
		}
	} GMods;
};

#endif*/