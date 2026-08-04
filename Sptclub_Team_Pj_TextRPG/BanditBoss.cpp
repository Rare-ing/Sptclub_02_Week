#include "BanditBoss.h"
#include "Player.h"
#include "GameUI.h"

#include <cstdlib>


BanditBoss::BanditBoss()
	: Monster("도적 두목", 3, 0, "도적의 전리품", 30, 10, "도적 두목이 위엄을 내뿜으면 나타났다.")
{
	setBoss(true);
	ApplyBossBonus();
}


void BanditBoss::Attack(Player* player)
{
	PrintStory(0, "도적 두목은 거친 칼솜씨로 베어냈다!");

	int damage = CalculateDamage();
	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	WaitForEnter();
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

	PrintStory(1, "도적 두목은 거대한 칼을 힘껏 내리쳤다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	int damage = CalculateSkillDamage(1.5f);

	player->TakeDamage(damage);

	PrintStory(3, std::to_string(damage) + "의 피해를 입었다!");
	WaitForEnter();
}