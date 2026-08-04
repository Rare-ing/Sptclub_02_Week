#include "UndergroundNation.h"
#include "Player.h"
#include "GameUI.h"

#include <cstdlib>


UndergroundNation::UndergroundNation()
	: Monster("흉년의 악신", 10, 0, "검게 탄 풍년패", 1000, 50, "수많은 백성이 굶주림 속에서 쓰러진 원한이 모여, 흉년의 악신이 모습을 드러냈다!")
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
	PrintStory(0, "흉년의 악신은 검은 기운으로 플레이어를 내려쳤다!");

	int damage = CalculateDamage();

	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	WaitForEnter();
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

	PrintStory(0, "흉년의 악신은 굶주린 백성들의 원한을 모아 재앙의 힘을 발산했다!");

	int damage = CalculateSkillDamage(2.0f);

	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	int poisonChance = rand() % 100;

	if (poisonChance < 40)
	{
		PrintStory(3, "플레이어는 재앙을 맞아 원혼들의 공격을 받는다!");

		// player->setPoison(30, 2);
	}
	WaitForEnter();
}