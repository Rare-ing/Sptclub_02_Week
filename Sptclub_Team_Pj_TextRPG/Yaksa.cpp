#include "Yaksa.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

Yaksa::Yaksa() : Monster("야차", 5, 80, "야차의 뿔", 100, 20, "산을 지배하는 악귀 야차가 모습을 드러냈다!")
{
	setBoss(true);
	ApplyBossBonus();
}

void Yaksa::Attack(Player* player)
{
	std::cout << "야차는 빠르게 움직여 거대한 손톱으로 내려쳤다!" << std::endl;

	int damage = CalculateDamage(player->getDefence());
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}

void Yaksa::Skill(Player* player)
{
	const int skillCost = 50;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}
	setMp(getMp() - skillCost);

	std::cout << "야차는 악귀의 힘을 끌어올려 강력한 일격을 날렸다!" << std::endl;

	int damage = CalculateSkillDamage(player->getDefence(), 1.8f);

	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}