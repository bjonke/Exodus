#pragma once
#include <iostream>
#include <list>
#include <vector>

using namespace std;
#include <SDL.h>


class Object
{
public:
	std::string Type;
	float xPos, yPos;
	int Width, Height;
	int surface;
	int Frame;
	int radius;

	SDL_Rect Clips[ 10 ];
	SDL_Rect SingleClip;
	
private:
};

class Weapon : public Object
{
	public:
		int Grip;
		int BaseChance;
		int Damage;
		int Strength;
		int Cost;
		int Range;
		int Speed;
		int Weight;

	Weapon(){};
	~Weapon(){};
};

class Armour : public Object
{
	public:
		int Absorbation;
		int Strength;
		int Cost;
		int Range;
		int Speed;
		int Weight;

	Armour(){};
	~Armour(){};
};

class Spear : public Object
{
	public:

	Spear()	{};
	~Spear(){};
};
class Dagger : public Object
{
	public:

	Dagger()	{};
	~Dagger(){};
};
class Shortsword : public Object
{
	public:

	Shortsword()	{};
	~Shortsword(){};
};
class Broadsword : public Object
{
	public:

	Broadsword()	{};
	~Broadsword(){};
};


class Gender : public Object
{
public:

	Gender()
	{
		char choice;
		std::cout << "Please select gender ( M= Male, F=Femal ): " << endl;
		cin >> choice;

		if( choice == 'f' )
			std::cout << "You choose to be a female character" << endl;
		else
			std::cout << "You choose to be a male character" << endl;

		if( rand() % 100 < 50 )
			Type = "Male";
		else
			Type = "Female";
	};
	~Gender(){};
};

class Race : public Object
{
public:

	Race()
	{
		char choice;

		std::cout << "Select your race" << endl;
		std::cout << "----------------" << endl;
		std::cout << "1Minotaur" << endl;
		std::cout << "2Duck" << endl;
		std::cout << "3Halfling" << endl;
		std::cout << "4Catman" << endl;
		std::cout << "5Centaur" << endl;
		std::cout << "6Human" << endl;
		cin >> choice;

		switch( choice )
		{
		case 1:
			std::cout << "You selected to be the big montaor" << endl;
			Type = "Minotaur";
			break;
		case 2:
			std::cout << "You selected to be duck" << endl;
			Type = "Duck";
			break;
		case 3:
			std::cout << "You selected to be halfling" << endl;
			Type = "Halfling";
			break;
		case 4:
			std::cout << "You selected to be catman" << endl;
			Type = "Catman";
			break;
		case 5:
			std::cout << "You selected to be the big centaur" << endl;
			Type = "Centaur";
			break;
		case 6:
			std::cout << "You selected to be the normal human" << endl;
			Type = "Human";
			break;
		default:
			std::cout << "You selected to be something rather unknown" << endl;
			Type = "Unknown";
			break;
		}
		
	};
	~Race(){};
};

class Rank : public Object
{
public:

	Rank()
	{
		char choice;

		std::cout << "Select your rank" << endl;
		std::cout << "----------------" << endl;
		std::cout << "1Aristocracy" << endl;
		std::cout << "2something" << endl;
		std::cout << "3flooger" << endl;
		std::cout << "4buntoly" << endl;
		std::cout << "5fredilkk" << endl;
		std::cout << "6CHongo" << endl;
		cin >> choice;

		switch( choice )
		{
		case 1:
			std::cout << "You selected to be the aristocrat" << endl;
			Type = "aristocracyr";
			break;
		case 2:
			std::cout << "You selected to be something" << endl;
			Type = "something";
			break;
		case 3:
			std::cout << "You selected to be halfling" << endl;
			Type = "Halfling";
			break;
		case 4:
			std::cout << "You selected to be catman" << endl;
			Type = "Catman";
			break;
		case 5:
			std::cout << "You selected to be the big centaur" << endl;
			Type = "Centaur";
			break;
		case 6:
			std::cout << "You selected to be the normal human" << endl;
			Type = "Human";
			break;
		default:
			std::cout << "You selected to be something rather unknown" << endl;
			Type = "Unknown";
			break;
		}	};
	~Rank(){};

};

class Age : public Object
{
public:

	Age(){Type = "young";};
	~Age(){};
};

class Profession : public Object
{
public:

	Profession(){Type = "Jester";};
	~Profession(){};
};

class LifeGoal : public Object
{
public:

	LifeGoal(){Type = "Anarchism";};
	~LifeGoal(){};
};

class EyeColor : public Object
{
public:

	EyeColor(){Type = "Blue";};
	~EyeColor(){};
};

class Voice : public Object
{
public:

	Voice(){Type = "Soft";};
	~Voice(){};
};

class HairLength : public Object
{
public:

	HairLength(){Type = "Bald";};
	~HairLength(){};
};

class Equipment : public Object
{
public:

	Equipment(){Type = "Backpack";};
	~Equipment(){};
};

class Archetype : public Object
{
public:
	Gender ArchetypeGender;
	Race ArchetypeRace;
	Rank ArchetypeRank;
	Age ArchetypeAge;
	Profession ArchetypeProfession;
	LifeGoal ArchetypeLifeGoal;
	EyeColor ArchetypeEyeColor;
	Voice ArchetypeVoice;
	HairLength ArchetypeHairLength;
	Equipment ArchetypeEquipment;


	Archetype()	{};
	~Archetype(){};
};



class Jester : public Object
{
public:
	Jester(){};
	~Jester(){};
};

class Hunter : public Object
{
public:
	Hunter(){};
	~Hunter(){};
};

class Merchant : public Object
{
public:
	Merchant(){};
	~Merchant(){};
};

class Warrior : public Object
{
public:
	Warrior(){};
	~Warrior(){};
};

class Scholar : public Object
{
public:
	Scholar(){};
	~Scholar(){};
};

class Monk : public Object
{
public:
	Monk(){};
	~Monk(){};
};

class Brigand : public Object
{
public:
	Brigand(){};
	~Brigand(){};
};

class Wizard : public Object
{
public:
	Wizard(){};
	~Wizard(){};
};

class Pirate : public Object
{
public:
	Pirate(){};
	~Pirate(){};
};

class Knight : public Object
{
public:
	Knight(){};
	~Knight(){};
};

class Thief : public Object
{
public:
	Thief(){};
	~Thief(){};
};

class ThingsToDemon : public Object
{
public:
	ThingsToDemon();
	void SetClips();
	SDL_Rect HealthClips[ 6 ];
	int SurfaceHealth;

private:

};

class PowerUp : public Object
{
public:
	PowerUp( int xpos, int ypos, int Surface );
	void SetClips();
	void SetFrame();
	bool Left, Right;

private:
};

class Tree : public Object
{
public:
	Tree();
	
private:
};

class FireBall : public Object
{
public:
	FireBall();
	void SetClips();
	int FrameRight, FrameLeft;
	bool FireRight, FireLeft;

	int FireWidth, FireHeight;

private:

};

class Coffin : public Object
{
public:
	Coffin();
	void SetClips();
	void SetFrames();
	
};

class Control_Objects
{
public:
	Control_Objects();
	void DrawObjects();
	void CreateObjects();

	
	int WhichLifeToShow;
	SDL_Rect destHealth;
	int FrameHealth;

	int Zombie, Skeleton, Skull;

	bool PowerUpMan;
	
	FireBall * CreateFireBall( int xpos, int ypos, int Surface, bool right, bool left );
	Coffin * CreateCoffin( int xPos, int yPos, int Surface );

	PowerUp * WereWolf;
	
	std::list< PowerUp * > List_PowerUps;
	std::list< Tree * > List_Trees;
	std::list< FireBall * > List_FireBalls;
	std::list< Coffin * > List_Coffins;

	ThingsToDemon * DemonLife;
	
	std::vector<Archetype> Archetypes;
	Archetype SpawnArchetype()
	{
		Archetype tmp;
		return tmp;
	};

private:
};

extern Control_Objects Control_OBJ;