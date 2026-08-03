#include "Drunk.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

Drunk::Drunk() : Monster("취객", 1, 50, "동동주", 10, 5, "술에 잔뜩 취한 취객이 나타났다!") {}

void Drunk::Attack(Player* player)
{
	std::cout << "취객은 술병을 휘둘렀다!" << std::endl;

	int damage = CalculateDamage(player->getDefence());

	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}

void Drunk::Skill(Player* player)
{
	const int skillCost = 10;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}
	setMp(getMp() - skillCost);

	std::cout << "취객은 술에 취한 힘으로 술병을 강하게 내리쳤다!" << std::endl;

	int damage = CalculateSkillDamage(player->getDefence(), 1.2f);

	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}