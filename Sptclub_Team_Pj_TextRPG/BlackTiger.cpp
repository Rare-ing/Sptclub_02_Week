#include "BlackTiger.h"
#include "Player.h"
#include "GameUI.h"

#include <cstdlib>


BlackTiger::BlackTiger()
	: Monster("흑호 요괴", 9, 100, "흑호의 송곳니", 100, 10,
		"검은 호랑이의 형상을 한 요괴가 포효하며 나타났다!"){}

void BlackTiger::Attack(Player* player)
{
	PrintStory(0, "흑호 요괴는 날카로운 발톱으로 할퀴었다!");

	int damage = CalculateDamage();

	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	WaitForEnter();
}

void BlackTiger::Skill(Player* player)
{
	const int skillCost = 10;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}

	setMp(getMp() - skillCost);

	PrintStory(0, "흑호 요괴는 검은 기운을 두르고 맹렬하게 돌진했다!");

	int damage = CalculateSkillDamage(2.0f);

	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	int stunChance = rand() % 100;
	if (stunChance < 30)
	{
		player->setStunned(true);

		PrintStory(3, "플레이어는 돌진을 버티지 못하고 넘어졌다!");
	}
	WaitForEnter();
}