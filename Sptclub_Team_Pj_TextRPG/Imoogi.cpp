#include "Imoogi.h"
#include "Player.h"
#include "GameUI.h"

#include <cstdlib>


Imoogi::Imoogi()
	: Monster("전설의 이무기", 15, 0, "여의주", 9999, 0,
		"천년의 세월을 견딘 이무기가 하늘을 향해 꿈틀거린다!")
{
	setBoss(true);
	ApplyBossBonus();
}


void Imoogi::TakeTurn(Player* player)
{
	int action = rand() % 100;

	if (action < 50)
	{
		Attack(player);
	}
	else
	{
		Skill(player);
	}
}


void Imoogi::Attack(Player* player)
{
	PrintStory(0, "이무기는 거대한 몸으로 휘감아 공격했다!");

	int damage = CalculateDamage();

	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	WaitForEnter();
}


void Imoogi::Skill(Player* player)
{
	int skill = rand() % 100;

	if (skill < 50)
	{
		PoisonSkill(player);
	}
	else
	{
		StunSkill(player);
	}
}


void Imoogi::PoisonSkill(Player* player)
{
	const int skillCost = 40;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}


	setMp(getMp() - skillCost);


	PrintStory(1, "이무기가 독 안개를 내뿜었다!");


	int damage = CalculateSkillDamage(1.5f);

	player->TakeDamage(damage);


	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));


	int poisonChance = rand() % 100;

	if (poisonChance < 50)
	{
		PrintStory(3, "플레이어는 독에 걸렸다!");

		// player->setPoison(15,3);
	}
	WaitForEnter();
}


void Imoogi::StunSkill(Player* player)
{
	const int skillCost = 50;


	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}


	setMp(getMp() - skillCost);


	PrintStory(0, "이무기가 하늘을 향해 포효했다!");


	int damage = CalculateSkillDamage(3.0f);

	player->TakeDamage(damage);


	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));


	int stunChance = rand() % 100;


	if (stunChance < 50)
	{
		player->setStunned(true);

		PrintStory(3, "플레이어는 공포에 몸이 굳었다!");
	}
	WaitForEnter();
}