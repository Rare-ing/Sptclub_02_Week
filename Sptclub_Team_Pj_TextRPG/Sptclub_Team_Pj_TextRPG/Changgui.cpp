#include "Changgui.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

Changgui::Changgui() : Monster("창귀", 4, 70, "호랑이 발톱 장식", 80, 10, "호랑이에게 잡아먹힌 원혼, 창귀가 모습을 드러냈다!") {}

void Changgui::Attack(Player* player)
{
	std::cout << "창귀는 짐승 같은 움직임으로 달려들었다!" << std::endl;

	int damage = CalculateDamage(player->getDefence());
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}

void Changgui::Skill(Player* player)
{
	const int skillCost = 50;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}
	setMp(getMp() - skillCost);

	std::cout << "창귀는 호랑이의 원한을 담아 맹렬하게 덮쳤다!" << std::endl;

	int damage = CalculateSkillDamage(player->getDefence(), 1.5f);
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}