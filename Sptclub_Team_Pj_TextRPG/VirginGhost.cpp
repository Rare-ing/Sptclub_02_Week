#include "VirginGhost.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

VirginGhost::VirginGhost() : Monster("처녀귀신", 4, 45, "찢어진 비단 저고리", 50, 7, "원한을 품은 처녀귀신이 차가운 바람과 함께 나타났다!") {}

void VirginGhost::Attack(Player* player)
{
	std::cout << "처녀귀신은 긴 머리카락으로 휘감았다!" << std::endl;

	int damage = CalculateDamage(player->getDefence());
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}

void VirginGhost::Skill(Player* player)
{
	const int skillCost = 50;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}
	setMp(getMp() - skillCost);

	std::cout << "처녀귀신은 한 맺힌 울음소리로 상대를 저주했다!" << std::endl;

	int damage = CalculateSkillDamage(player->getDefence(), 0.8f);

	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;

	int poisonChance = rand() % 100;

	if (poisonChance < 30)
	{
		std::cout << "플레이어는 저주에 걸렸다.." << std::endl;

		//player->setPoison(5, 3);
	}
}