#include "Imoogi.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

Imoogi::Imoogi() : Monster("전설의 이무기", 15, 0, "여의주", 9999, 0, "천년의 세월을 견딘 이무기가 하늘을 향해 꿈틀거린다!")
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
	std::cout << "이무기는 거대한 몸으로 휘감아 공격했다!" << std::endl;

	int damage = CalculateDamage();
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
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

	std::cout << "이무기가 독 안개를 내뿜었다!" << std::endl;

	int damage = CalculateSkillDamage(1.5f);

	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;

	int poisonChance = rand() % 100;
	if (poisonChance < 50)
	{
		std::cout << "플레이어는 독에 걸렸다!" << std::endl;

		//player->setPoison(15, 3);
	}
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


	std::cout << "이무기가 하늘을 향해 포효했다!" << std::endl;


	int damage = CalculateSkillDamage(3.0f);
	player->TakeDamage(damage);
	std::cout << damage << "의 피해를 입었다!" << std::endl;

	int stunChance = rand() % 100;

	if (stunChance < 50)
	{
		player->setStunned(true);

		std::cout << "플레이어는 공포에 몸이 굳었다!" << std::endl;
	}
}