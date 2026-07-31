#include "HungryEunuch.h"
#include <iostream>
#include <cstdlib>

HungryEunuch::HungryEunuch() : Monster("굶주린 내관", 6, 60, "낡은 내관의 관모", 25, 5, "굶주림에 시달리다 죽은 내관의 원혼이 궁궐 안에서 배회한다!") {}

void HungryEunuch::Attack(Player* player)
{
	std::cout << "굶주린 내관은 낡은 손톱으로 할퀴었다!" << std::endl;

	int damage = CalculateDamage(player->getDefence());
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}

void HungryEunuch::Skill(Player* player)
{
	const int skillCost = 20;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}
	setMp(getMp() - skillCost);

	std::cout << "굶주린 내관은 끝없는 허기를 담아 생기를 빼앗았다!" << std::endl;

	int damage = CalculateSkillDamage(player->getDefence(), 1.2f);

	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}