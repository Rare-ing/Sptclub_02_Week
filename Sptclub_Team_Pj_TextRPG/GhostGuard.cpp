#include "GhostGuard.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

GhostGuard::GhostGuard() : Monster("원혼 시위군", 6, 60, "낡은 호위 무사의 검", 50, 15, "왕을 지키지 못한 시위군의 원혼이 차가운 칼날과 함께 나타났다!") {}

void GhostGuard::Attack(Player* player)
{
	std::cout << "원혼 시위군은 억울한듯 차가운 검을 휘둘렀다!" << std::endl;

	int damage = CalculateDamage();
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}

void GhostGuard::Skill(Player* player)
{
	const int skillCost = 50;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}
	setMp(getMp() - skillCost);

	std::cout << "원혼 시위군은 왕을 지키지 못한 원한으로 강력한 검격을 날렸다!" << std::endl;

	int damage = CalculateSkillDamage(1.5f);

	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}