#include "Girlgui.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

Girlgui::Girlgui() : Monster("걸귀", 1, 50, "찢어진 치마자락", 15, 8, "걸귀가 배고파하면 다가오고있다.") {}

void Girlgui::Attack(Player* player)
{
	std::cout << "걸귀가 치마자락을 휘둘렀다!" << std::endl;

	int damage = CalculateDamage();
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}

void Girlgui::Skill(Player* player)
{
	const int skillCost = 10;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}
	setMp(getMp() - skillCost);

	std::cout << "걸귀가 치마를 휘감았다!" << std::endl;

	int damage = CalculateSkillDamage(1.1f);

	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;

	int stunChance = rand() % 100;

	if (stunChance < 15)
	{
		player->setStunned(true);

		std::cout << "플레이어(이름)는 움직임이 멈췄다!" << std::endl;
	}
}