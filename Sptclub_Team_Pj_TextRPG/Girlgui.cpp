#include "Girlgui.h"
#include "Player.h"
#include "GameUI.h"

#include <cstdlib>

Girlgui::Girlgui()
	: Monster("걸귀", 1, 50, "찢어진 치마자락", 15, 8, "걸귀가 배고파하며 다가오고 있다.") {}

void Girlgui::Attack(Player* player)
{
	PrintStory(0, "걸귀가 치마자락을 휘둘렀다!");

	int damage = CalculateDamage();
	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	WaitForEnter();
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

	PrintStory(0, "걸귀가 치마를 휘감았다!");

	int damage = CalculateSkillDamage(1.1f);

	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	int stunChance = rand() % 100;

	if (stunChance < 15)
	{
		player->setStunned(true);

		PrintStory(3, "플레이어는 움직임이 멈췄다!");
	}
	WaitForEnter();
}