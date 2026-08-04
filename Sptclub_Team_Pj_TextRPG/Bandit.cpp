#include "Bandit.h"
#include "Player.h"

#include <iostream>
#include <cstdlib>

Bandit::Bandit() : Monster("도적", 2, 50, "녹슨 도적 단검", 20, 10, "도적이 습격했다!") {}

void Bandit::Attack(Player* player)
{
	std::cout << "도적은 단검을 휘둘렀다!" << std::endl;

	int damage = CalculateDamage();
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}

void Bandit::Skill(Player* player)
{
	const int skillCost = 20;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}
	setMp(getMp() - skillCost);

	std::cout << "도적은 독가루를 뿌렸다!" << std::endl;

	int damage = CalculateSkillDamage(0.5f);

	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;

	int poisonChance = rand() % 100;

	if (poisonChance < 5)
	{
		std::cout << "플레이어는 독에 걸렸다!" << std::endl;

		//player->setPoison(3, 3);
	}
}