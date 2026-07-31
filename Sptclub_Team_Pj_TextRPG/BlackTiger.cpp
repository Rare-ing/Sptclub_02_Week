#include "BlackTiger.h"
#include <iostream>
#include <cstdlib>

BlackTiger::BlackTiger() : Monster("흑호 요괴", 9, 100, "흑호의 송곳니", 100, 10, "검은 호랑이의 형상을 한 요괴가 포효하며 나타났다!") {}

void BlackTiger::Attack(Player* player)
{
	std::cout << "흑호 요괴는 날카로운 발톱으로 할퀴었다!" << std::endl;

	int damage = CalculateDamage(player->getDefence());
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
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

	std::cout << "흑호 요괴는 검은 기운을 두르고 맹렬하게 돌진했다!" << std::endl;

	int damage = CalculateSkillDamage(player->getDefence(), 2.0f);
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;

	int stunChance = rand() % 100;

	if (stunChance < 30)
	{
		player->setStunned(true);

		std::cout << "플레이어는 돌진에 감당하지 못하고 넘어졌다!" << std::endl;
	}
}