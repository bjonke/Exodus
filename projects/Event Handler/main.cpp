#include <iostream>
#include <vector>

#include "event_handler.h"

class Talk : public Event
{
public:
	Talk(int pos) : _pos(pos), _answer(60) {};

	int getPosition()	const	{return _pos;}
	int getAnswer()		const	{return _answer;}

private:
	int _pos, _answer;
};
class Explosion : public Event
{
public:
	Explosion(int pos) : _pos(pos), _damage(60) {};

	int getPosition()	const	{return _pos;}
	int getDamage()		const	{return _damage;}

private:
	int _pos, _damage;
};

class Enemy
{
public:
	Enemy() : _name("Bad Enemy"), _damage(15) {};
	
	std::string getName()	const {return _name;}
	int			getDamage()	const {return _damage;}

private:
	std::string _name;
	int _damage;
};

class EnemyHit : public Event
{
public:
	EnemyHit(Enemy* enemy) : _enemy(enemy){}

	Enemy* getEnemy() const		{return _enemy;}

private:
	Enemy* _enemy;
};


class Monster : public EventHandler
{
public:
	Monster() : _pos(20), _hp(100)
	{
		registerEventFunc(this, &Monster::onExplosion);
		registerEventFunc(this, &Monster::onEnemyHit);
	}

	void receiveDamage(int dmg)
	{
		_hp -= dmg;
		std::cout << "hp: " << _hp << std::endl;
		if(_hp <= 0)
		{
			std::cout << "I'm dead" << std::endl;
		}
	}

	void onExplosion(const Explosion* explosion)
	{
		if(abs(_pos - explosion->getPosition()) < 20)
		{
			std::cout << "Hit by explosion!!!" << std::endl;
			receiveDamage(explosion->getDamage());
		}
		else
		{
			std::cout << "Out of explosion range :)" << std::endl;
		}
	}

	void onEnemyHit(const EnemyHit* hit)
	{
		Enemy* enemy = hit->getEnemy();
		std::cout << "Hit by enemy: " << enemy->getName().c_str() << " got damage: " << enemy->getDamage() << std::endl;
		receiveDamage(enemy->getDamage());

	}

	int _pos;
	int _hp;
};

class Tank
{
public:
	Tank() : _eventHandler(this) {}

	void handleEvent(const Event* event) 
	{
		_eventHandler.handleEvent(event);
	}

private:
	class TankEventHandler : public EventHandler
	{
	public:
		TankEventHandler(Tank* tank) : _tank(tank)
		{
			registerEventFunc(_tank, &Tank::onDamagedByExplosion);
		}
		Tank* _tank;
	};
	friend class TankEventHandler;
	void onDamagedByExplosion(const Explosion* explosion)
	{
		std::cout << "Hit by explosion. Whatever" << std::endl;
	}
	TankEventHandler _eventHandler;
};

// ---------------------- EXODUS ADDONS --------------------------------------- //
class Mercenary : public EventHandler
{
public:
	Mercenary() : _shortname("Mercenary"), _fullname("Firstname Last"), 
		_hlt(0), _agi(0), _dex(0), _str(0), _ldr(0), _wis(0), _mrk(0), _mec(0), _exp(0), _med(0), _lvl(0), 
		_pos(20), _hp(100)
	{
		registerEventFunc(this, &Mercenary::onExplosion);
		registerEventFunc(this, &Mercenary::onEnemyHit);
		registerEventFunc(this, &Mercenary::onTalk);
	}

	Mercenary(std::string ShortName) : _fullname(_shortname.append(" Last")),	
		_hlt(0), _agi(0), _dex(0), _str(0), _ldr(0), _wis(0), _mrk(0), _mec(0), _exp(0), _med(0), _lvl(0), 
		_pos(20), _hp(100)
	{
		_shortname = ShortName;
		registerEventFunc(this, &Mercenary::onExplosion);
		registerEventFunc(this, &Mercenary::onEnemyHit);
		registerEventFunc(this, &Mercenary::onTalk);
	}

	std::string getShortName()	const {return _shortname;}
	std::string getFullName()	const {return _fullname;}
	int getHealth()	const {return _hlt;}
	int getAgility()	const {return _agi;}
	int getDexterity()	const {return _dex;}
	int getStrength()	const {return _str;}
	int getLeadership()	const {return _ldr;}
	int getWisdom()	const {return _wis;}
	int getMarksmanship()	const {return _mrk;}
	int getMechanic()	const {return _mec;}
	int getExplosive()	const {return _exp;}

	void receiveDamage(int dmg)
	{
		_hp -= dmg;
		std::cout << "hp: " << _hp << std::endl;
		if(_hp <= 0)
		{
			std::cout << _shortname.c_str() << " is dead..." << std::endl;
		}
	}
	void receiveAnswer(int dmg)
	{
		_hp -= dmg;
		std::cout << "talk: " << _hp << std::endl;
		if(_hp <= 0)
		{
			std::cout << this->getShortName().c_str() << " is talking..." << std::endl;
		}
	}

	void onExplosion(const Explosion* explosion)
	{
		if(abs(_pos - explosion->getPosition()) < 20)
		{
			std::cout << "Boom!!!" << std::endl << this->getExplosive();
			receiveDamage(explosion->getDamage());
		}
		else
		{
			std::cout << "Out of explosion range :)" << std::endl;
		}
	}

	void onTalk(const Talk* talk)
	{
		if(abs(_pos - talk->getPosition()) < 20)
		{
			std::cout << "Yes sir what can i help you with?" << std::endl;
			receiveAnswer(talk->getAnswer());
		}
		else
		{
			std::cout << "Out of talk range :)" << std::endl;
		}
	}

	void onEnemyHit(const EnemyHit* hit)
	{
		Enemy* enemy = hit->getEnemy();
		std::cout << enemy->getName().c_str() << " hits " << this->getShortName().c_str() << " for " << enemy->getDamage() << std::endl;
		receiveDamage(enemy->getDamage());
	}

	std::string _shortname;
	std::string _fullname;
	int _hlt;
	int _agi;
	int _dex;
	int _str;
	int _ldr;
	int _wis;
	int _mrk;
	int _mec;
	int _exp;
	int _med;
	int _lvl;
	std::string _skills;
	std::string _trait;
	std::string _attitude;
	int _basemorale;
	std::string sexism;
	int _salary;
	int _weekly;
	int _biweekly;
	std::string _deposit;
	std::string _appearance;
	std::string _equipment;
	std::string _friends;
	std::string _enemies;
	std::string _civiliangroup;
	std::string learntohate;
	int _aps;
	int _healing;
	int _repair;
	int _militia;
	std::string _notes;
	
	int _pos;
	int _hp;
};



int main()
{


	std::cout << "=== Mercenary ===" << std::endl; 
	Mercenary Barry("Barry");
	Mercenary Blood("Blood");
	Mercenary Bull("Bull");
	Mercenary Buns("Buns");
	Mercenary Buzz("Buzz");

	unsigned long n;
	do {
		std::cout << "1.Explosion " << std::endl;
		std::cout << "2. Talk " << std::endl;
		std::cout << "3. EnemyHit " << std::endl;
		std::cout << "4. EnemyHit " << std::endl;
		std::cout << "5. EnemyHit " << std::endl;
		std::cout << "6. EnemyHit " << std::endl;
		std::cout << "7. EnemyHit " << std::endl;
		std::cout << "8. EnemyHit " << std::endl;
		std::cout << "9. EnemyHit " << std::endl;

		std::cout << "Enter number (0 to end): ";
		std::cin >> n;
		if( n == 1 )
			Barry.handleEvent(new Explosion(10));
		if( n == 2 )
			Barry.handleEvent(new Talk(10));
		if( n == 3 )
			Barry.handleEvent(new EnemyHit(new Enemy));
		if( n == 4 )
			Barry.handleEvent(new Explosion(40));
		if( n == 5 )
			Barry.handleEvent(new Explosion(40));
		if( n == 6 )
			Barry.handleEvent(new Explosion(40));
		if( n == 7 )
			Barry.handleEvent(new Explosion(40));
		if( n == 8 )
			Barry.handleEvent(new Explosion(40));
		if( n == 9 )
			Barry.handleEvent(new Explosion(40));

	} while (n != 0);

	Barry.handleEvent(new Explosion(40));
	Barry.handleEvent(new Explosion(10));
	Barry.handleEvent(new Talk(10));
	Barry.handleEvent(new EnemyHit(new Enemy));
	Barry.handleEvent(new EnemyHit(new Enemy));
	Barry.handleEvent(new EnemyHit(new Enemy));

	std::cout << "=== Monster ===" << std::endl; 
	Monster monster;
	monster.handleEvent(new Explosion(40));
	monster.handleEvent(new Explosion(10));
	monster.handleEvent(new EnemyHit(new Enemy));
	monster.handleEvent(new EnemyHit(new Enemy));
	monster.handleEvent(new EnemyHit(new Enemy));

	std::cout << "\n=== Tank ===" << std::endl; 
	Tank tank;
	tank.handleEvent(new Explosion(40));
	tank.handleEvent(new Explosion(10));
	tank.handleEvent(new EnemyHit(new Enemy));

	system("PAUSE");
}


