#include "Shudderwock.h"
#include "Player.h"
#include "GameUI.h"

#include <cstdlib>


Shudderwock::Shudderwock()
	: Monster("두억시니", 8, 80, "두억시니의 뿔조각", 100, 15, "머리를 깨뜨리는 악귀 두억시니가 나타났다!"){}

void Shudderwock::Attack(Player* player)
{
	PrintStory(0, "두억시니는 거대한 힘으로 내려쳤다!");

	int damage = CalculateDamage();

	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	WaitForEnter();
}

void Shudderwock::Skill(Player* player)
{
	const int skillCost = 100;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}

	setMp(getMp() - skillCost);

	PrintStory(0, "두억시니는 머리를 깨뜨리는 강력한 일격을 날렸다!");

	int damage = CalculateSkillDamage(2.0f);

	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	int stunChance = rand() % 100;

	if (stunChance < 10)
	{
		player->setStunned(true);

		PrintStory(3, "두억시니에게 머리가 깨져 움직일 수 없다..");
	}
	WaitForEnter();
}