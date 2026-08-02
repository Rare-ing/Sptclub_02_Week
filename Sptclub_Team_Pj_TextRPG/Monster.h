#pragma once

#include <string>

class Player;

class Monster
{
private:
	std::string name;

	int level;

	int hp;
	int maxHpCheck;
	int mp;

	int power;
	int defence;

	int expReward;

	std::string dropItemName;
	int dropItemPrice;
	int dropItemWeight;

	std::string spawnMessage;

	bool isBoss;

	bool isStunned;

	bool isDot;
	int dotDamage;
	int dotTurn;

	bool isAlive;

public:
	Monster(std::string monsterName, int level, int expReward, std::string dropItemName, int dropItemPrice, int dropItemWeight, std::string spawnMessage);

	virtual void Attack(Player* player) = 0;

	virtual void Skill(Player* player) = 0;

	virtual void TakeTurn(Player* player);

	virtual ~Monster() {}

	void printMonsterStatus();

	std::string getName();

	int getLevel();

	int getHp();
	int getMp();

	int getPower();
	int getDefence();

	int getExpReward();

	std::string getDropItemName();
	int getDropItemPrice();
	int getDropItemWeight();

	std::string getSpawnMessage();

	bool getBoss();

	bool getIsStunned();
	void ClearStun();

	bool getDot();

	bool getAlive();

	void setHp(int hp);
	void setMp(int mp);

	void setBoss(bool state);

	void setStunned(bool state);

	void setAlive(bool state);

	int CalculateDamage(int targetDefence);

	int CalculateSkillDamage(int targetDefence, float multiplier);

	void ApplyBossBonus();

	void setDot(int damage, int turn);

	void ApplyDot();

	void TakeDamage(int damage);

	void resetMonster();
};