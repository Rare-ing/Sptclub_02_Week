#include "Monster.h"
#include "Player.h"
#include <iostream>
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
	std::cout << "------------------------------------" << std::endl;

	std::cout << "등장 문구 : " << spawnMessage << std::endl;

	std::cout << "몬스터 : " << name << std::endl;

	std::cout << "레벨 : " << level << std::endl;

	std::cout << "HP : " << hp << std::endl;

	std::cout << "MP : " << mp << std::endl;

	std::cout << "공격력 : " << power << std::endl;

	std::cout << "방어력 : " << defence << std::endl;

	std::cout << "EXP : " << expReward << std::endl;

	std::cout << "드랍 아이템 : " << dropItemName << std::endl;

	std::cout << "아이템 가격 : " << dropItemPrice << std::endl;

	std::cout << "아이템 무게 : " << dropItemWeight << std::endl;

	std::cout << "------------------------------------" << std::endl;
}

std::string Monster::getName() { return name; }

int Monster::getLevel() { return level; }

int Monster::getHp() { return hp; }
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

int Monster::CalculateDamage(int targetDefence)
{
	int damage = power - targetDefence;

	if (damage < 1)
	{
		damage = 1;
	}
	return damage;
}

int Monster::CalculateSkillDamage(int targetDefence, float multiplier)
{
	int damage = (power * multiplier) - targetDefence;

	if (damage < 1)
	{
		damage = 1;
	}
	return damage;
}

void Monster::ApplyBossBonus()
{
	hp *= 1.5;
	mp *= 1.2;
	power *= 1.5;
	defence *= 1.2;
}

void Monster::ApplyDot()
{
	if (!isDot)
	{
		return;
	}

	TakeDamage(dotDamage);

	dotTurn--;

	std::cout << name << "은(는) 지속 피해를 입었다! " << dotDamage << " 피해" << std::endl;

	if (dotTurn <= 0)
	{
		isDot = false;

		std::cout << name << "의 지속피해가 사라졌다!" << std::endl;
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