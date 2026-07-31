#include "Drunk.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include "Player.h"

Drunk::Drunk() : Monster("취객", 1, 5, "동동주", 10, 5, "술에 잔뜩 취한 취객이 나타났다!") {}

void Drunk::Attack(Player* player)
{
	std::cout << "취객은 술병을 휘둘렀다!" << std::endl;

	int damage = CalculateDamage(player->getDefence());
	player->setHp(player->getHp() - damage); // Player가 어떤식으로 구현될지 몰라서 일단 만들어놈
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

	std::cout << "취객은 술병을 강하게 내리쳤다!" << std::endl;

	int damage = CalculateSkillDamage(player->getDefence(), 1.2f);

	player->setHp(player->getHp() - damage);  //이것도 임시로 만들어놓음

	int stunChance = rand() % 100;

	if (stunChance < 10)
	{
		player->setStunned(true);

		std::cout << "플레이어(이름)는 기절했다!" << std::endl;
	}
}