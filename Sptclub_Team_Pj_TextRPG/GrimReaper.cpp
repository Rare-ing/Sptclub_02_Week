#include "GrimReaper.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

GrimReaper::GrimReaper() : Monster("저승사자", 8, 80, "검은 부채", 100, 5, "죽음의 사자가 검은 그림자속에서 나타났다!") {}

void GrimReaper::Attack(Player* player)
{
	std::cout << "저승사자는 검은 부채로 베어냈다!" << std::endl;

	int damage = CalculateDamage();
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}

void GrimReaper::Skill(Player* player)
{
	const int skillCost = 10;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}
	setMp(getMp() - skillCost);

	std::cout << "저승사자는 저승의 힘으로 죽음의 기운을 내뿜었다!" << std::endl;

	int damage = CalculateSkillDamage(1.2f);
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;

	int poisonChance = rand() % 100;

	if (poisonChance < 30)
	{
		std::cout << "저승의 손들이 플레이어를 괴롭힌다!" << std::endl;

		//player->setPoison(10, 3);
	}
}