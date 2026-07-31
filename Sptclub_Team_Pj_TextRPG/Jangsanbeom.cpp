#include "Jangsanbeom.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

Jangsanbeom::Jangsanbeom() : Monster("장산범", 7, 150, "장산범의 가면", 200, 20, "사람의 목소리를 흉내내는 괴수, 장산범이 나타났다!")
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
	std::cout << "장산범은 날카로운 발톱으로 찢어냈다!" << std::endl;

	int damage = CalculateDamage(player->getDefence());
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
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

	std::cout << "장산범은 사람의 목소리를 적을 혼란시켰다!" << std::endl;

	int damage = CalculateSkillDamage(player->getDefence(), 1.5f);
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;

	int stunChance = rand() % 100;

	if (stunChance < 50)
	{
		player->setStunned(true);

		std::cout << "플레이어는 사람의 소리를 듣고 혼란에 빠졌다!" << std::endl;
	}
}