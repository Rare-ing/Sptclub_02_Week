#include "BanditBoss.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

BanditBoss::BanditBoss() : Monster("도적 두목", 3, 30, "도적의 전리품", 30, 10, "도적 두목이 위엄을 내뿜으면 나타났다.")
{
	setBoss(true);
	ApplyBossBonus();
}

void BanditBoss::Attack(Player* player)
{
	std::cout << "도적 두목은 거친 칼솜씨로 베어냈다!" << std::endl;

	int damage = CalculateDamage(player->getDefence());
	//damage = player->onDamaged(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}

void BanditBoss::Skill(Player* player)
{
	const int skillCost = 30;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}
	setMp(getMp() - skillCost);

	std::cout << "도적 두목 거대한 칼을 힘껏 내리쳤다!" << std::endl;

	int damage = CalculateSkillDamage(player->getDefence(), 1.5f);

	//damage = player->onDamaged(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}