#include "Jangsanbeom.h"
#include "Player.h"
#include "GameUI.h"

#include <cstdlib>


Jangsanbeom::Jangsanbeom()
	: Monster("장산범", 5, 0, "장산범의 가면", 200, 20, "사람의 목소리를 흉내내는 괴수, 장산범이 나타났다!")
{
	setBoss(true);
	ApplyBossBonus();
}


void Jangsanbeom::TakeTurn(Player* player)
{
	int action = rand() % 100;

	if (action < 70)
	{
		Attack(player);
	}
	else
	{
		Skill(player);
	}
}


void Jangsanbeom::Attack(Player* player)
{
	PrintStory(0, "장산범은 날카로운 발톱으로 찢어냈다!");

	int damage = CalculateDamage();

	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	WaitForEnter();
}


void Jangsanbeom::Skill(Player* player)
{
	const int skillCost = 70;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}

	setMp(getMp() - skillCost);

	PrintStory(0, "장산범은 사람의 목소리로 적을 혼란시켰다!");

	int damage = CalculateSkillDamage(1.5f);

	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	int stunChance = rand() % 100;

	if (stunChance < 50)
	{
		player->setStunned(true);

		PrintStory(3, "플레이어는 사람의 소리를 듣고 혼란에 빠졌다!");
	}
	WaitForEnter();
}