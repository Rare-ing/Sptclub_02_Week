#include "BanditGhost.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

BanditGhost::BanditGhost() : Monster("산적 귀신", 3, 30, "녹슨 호패", 25, 5, "죽어서도 욕심을 버리지 못한 산적귀신이 나타났다!") {}

void BanditGhost::Attack(Player* player)
{
	std::cout << "산적귀신은 녹슨 칼날로 베어냈다!" << std::endl;

	int damage = CalculateDamage(player->getDefence());
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}

void BanditGhost::Skill(Player* player)
{
	const int skillCost = 20;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}
	setMp(getMp() - skillCost);

	std::cout << "산적귀신은 원혼의 힘으로 모습을 숨긴 뒤 기습했다!" << std::endl;

	int damage = CalculateSkillDamage(player->getDefence(), 1.2f);

	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}