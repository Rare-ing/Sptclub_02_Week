#include "Shudderwock.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

Shudderwock::Shudderwock() : Monster("두억시니", 8, 80, "두억시니의 뿔조각", 100, 15, "머리를 깨뜨리는 악귀 두억시니가 나타났다!") {}

void Shudderwock::Attack(Player* player)
{
	std::cout << "두억시니는 거대한 힘으로 내려쳤다!" << std::endl;

	int damage = CalculateDamage(player->getDefence());
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}

void Shudderwock::Skill(Player* player)
{
	const int skillCost = 100;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}
	setMp(getMp() - skillCost);

	std::cout << "두억시니는 머리를 깨뜨리는 강력한 일격을 날렸다!" << std::endl;

	int damage = CalculateSkillDamage(player->getDefence(), 2.0f);
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;

	int stunChance = rand() % 100;

	if (stunChance < 10)
	{
		player->setStunned(true);

		std::cout << "두억시니한테 머리가 깨져 못움직인다.." << std::endl;
	}
}