#include "Banran.h"
#include <iostream>
#include <cstdlib>

Banran::Banran() : Monster("역심품은 신하", 4, 50, "핏빛 상소문", 55, 12, "권력을 탐했던 신하의 원한이 궁궐 깊은 곳에서 모습을 드러냈다!") {}

void Banran::Attack(Player* player)
{
	std::cout << "역심품은 신하는 숨겨둔 비수를 꺼내 찔렀다!" << std::endl;

	int damage = CalculateDamage(player->getDefence());
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}

void Banran::Skill(Player* player)
{
	const int skillCost = 20;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}
	setMp(getMp() - skillCost);

	std::cout << "역심품은 신하는 핏빛 상소문의 저주로 상대를 억눌렀다!" << std::endl;

	int damage = CalculateSkillDamage(player->getDefence(), 1.3f);
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;

	int poisonChance = rand() % 100;

	if (poisonChance < 30)
	{
		std::cout << "플레이어는 끔찍한 저주에 걸렸다!" << std::endl;

		player->setPoison(15, 3);
	}
}