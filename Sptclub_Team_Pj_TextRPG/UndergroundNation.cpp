#include "UndergroundNation.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

UndergroundNation::UndergroundNation() : Monster("지하국대적", 10, 0, "지하국대적의 보물", 1000, 50, "지하 세계를 지배하는 대적이 모습을 드러냈다!")
{
	setBoss(true);
	ApplyBossBonus();
}

void UndergroundNation::TakeTurn(Player* player)
{
	int action = rand() % 100;

	if (action < 60)
	{
		Attack(player);
	}
	else
	{
		Skill(player);
	}
}

void UndergroundNation::Attack(Player* player)
{
	std::cout << "지하국대적은 거대한 힘으로 땅을 내려쳤다!" << std::endl;

	int damage = CalculateDamage(player->getDefence());
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}

void UndergroundNation::Skill(Player* player)
{
	const int skillCost = 80;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}
	setMp(getMp() - skillCost);

	std::cout << "지하국대적은 지하의 힘을 끌어올려 대지를 뒤흔들었다!" << std::endl;

	int damage = CalculateSkillDamage(player->getDefence(), 2.5f);
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}