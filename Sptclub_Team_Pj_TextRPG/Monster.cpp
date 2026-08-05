#include "Monster.h"
#include "Player.h"
#include "GameUI.h"

#include <cstdlib>


Monster::Monster(std::string monsterName, int level, int expReward, std::string dropItemName,
	int dropItemPrice, int dropItemWeight, std::string spawnMessage)
{
	name = monsterName;

	this->level = level;

	int minHp = level * 20;
	int maxHp = level * 30;

	hp = minHp + (rand() % (maxHp - minHp + 1));
	maxHpCheck = hp;
	int minMp = level * 10;
	int maxMp = level * 20;

	mp = minMp + (rand() % (maxMp - minMp + 1));

	int minPower = level * 5;
	int maxPower = level * 10;

	power = minPower + (rand() % (maxPower - minPower + 1));

	int minDefence = level * 2;
	int maxDefence = level * 5;

	defence = minDefence + (rand() % (maxDefence - minDefence + 1));

	this->expReward = expReward;

	this->dropItemName = dropItemName;
	this->dropItemPrice = dropItemPrice;
	this->dropItemWeight = dropItemWeight;

	this->spawnMessage = spawnMessage;

	isBoss = false;
	isStunned = false;
	isDot = false;
	isAlive = true;

	dotDamage = 0;
	dotTurn = 0;
}

void Monster::printMonsterStatus()
{
	PrintStory(0, "------------------------------------");

	PrintStory(1, "등장 문구 : " + spawnMessage);

	PrintStory(2, "몬스터 : " + name);

	PrintStory(3, "레벨 : " + std::to_string(level));

	PrintStory(4, "HP : " + std::to_string(hp));

	PrintStory(5, "MP : " + std::to_string(mp));

	PrintStory(6, "공격력 : " + std::to_string(power));

	PrintStory(7, "방어력 : " + std::to_string(defence));

	PrintStory(8, "EXP : " + std::to_string(expReward));

	PrintStory(9, "드랍 아이템 : " + dropItemName);

	PrintStory(10, "아이템 가격 : " + std::to_string(dropItemPrice));

	PrintStory(11, "아이템 무게 : " + std::to_string(dropItemWeight));

	PrintStory(12, "------------------------------------");
}

std::string Monster::getName() { return name; }

int Monster::getLevel() { return level; }

int Monster::getHp() { return hp; }
int Monster::getMaxHp() { return maxHpCheck; }
int Monster::getMp() { return mp; }

int Monster::getPower() { return power; }
int Monster::getDefence() { return defence; }

int Monster::getExpReward() { return expReward; }

std::string Monster::getDropItemName() { return dropItemName; }
int Monster::getDropItemPrice() { return dropItemPrice; }
int Monster::getDropItemWeight() { return dropItemWeight; }

std::string Monster::getSpawnMessage() { return spawnMessage; }

bool Monster::getBoss() { return isBoss; }

bool Monster::getIsStunned() { return isStunned; }
void Monster::ClearStun() { isStunned = false; }

bool Monster::getDot() { return isDot; }

bool Monster::getAlive() { return isAlive; }

void Monster::setHp(int hp) { this->hp = hp; }
void Monster::setMp(int mp) { this->mp = mp; }

void Monster::setBoss(bool state) { isBoss = state; }

void Monster::setStunned(bool state) { isStunned = state; }

void Monster::setAlive(bool state) { isAlive = state; }

void Monster::setDot(int damage, int turn)
{
	isDot = true;

	dotDamage = damage;

	dotTurn = turn;
}

void Monster::TakeTurn(Player* player)
{
	int action = rand() % 100;

	if (action < 80)
	{
		Attack(player);
	}
	else
	{
		Skill(player);
	}
}

int Monster::CalculateDamage()
{
	return power;
}

int Monster::CalculateSkillDamage(float multiplier)
{
	return static_cast<int>(power * multiplier);
}

void Monster::ApplyBossBonus()
{
	hp = static_cast<int>(hp * 2);
	maxHpCheck = hp;

	mp = static_cast<int>(mp * 1.5);
	power = static_cast<int>(power * 2);
	defence = static_cast<int>(defence * 1.5);
}

void Monster::ApplyDot()
{
	if (!isDot)
	{
		return;
	}

	TakeDamage(dotDamage);

	dotTurn--;

	PrintStory(0, name + "은(는) 지속 피해를 입었다! " + std::to_string(dotDamage) + " 피해");

	if (dotTurn <= 0)
	{
		isDot = false;

		PrintStory(0, name + "의 지속피해가 사라졌다!");
	}
}

void Monster::TakeDamage(int damage)
{
	hp -= damage;

	if (hp <= 0)
	{
		hp = 0;
		isAlive = false;
	}
}

void Monster::resetMonster()
{
	isAlive = true;
	isStunned = false;
	isDot = false;
	dotDamage = 0;
	dotTurn = 0;
	hp = maxHpCheck;
}