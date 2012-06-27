#include <iostream>
#include <vector>

#include "event_handler.h"


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


int main()
{
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


