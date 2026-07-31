#include "MountainBeast.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

MountainBeast::MountainBeast() : Monster("산짐승", 4, 50, "짐승의 발톱", 55, 12, "산속을 배회하던 흉포한 산짐승이 달려들었다!") {}

void MountainBeast::Attack(Player* player)
{
	std::cout << "산짐승은 날카로운 발톱으로 할퀴었다!" << std::endl;

	int damage = CalculateDamage(player->getDefence());
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}

void MountainBeast::Skill(Player* player)
{
	const int skillCost = 20;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}
	setMp(getMp() - skillCost);

	std::cout << "산짐승은 포효하며 온몸으로 달려들었다!" << std::endl;

	int damage = CalculateSkillDamage(player->getDefence(), 1.3f);
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}