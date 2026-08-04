#include "Bandit.h"
#include "Player.h"
#include "GameUI.h"

#include <cstdlib>

Bandit::Bandit() : Monster("도적", 2, 50, "녹슨 도적 단검", 20, 10, "도적이 습격했다!") {}

void Bandit::Attack(Player* player)
{
	PrintStory(0, "도적은 단검을 휘둘렀다!");

	int damage = CalculateDamage();

	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");

	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	WaitForEnter();
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

	PrintStory(0, "도적은 독가루를 뿌렸다!");

	int damage = CalculateSkillDamage(0.5f);

	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");

	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	int poisonChance = rand() % 100;

	if (poisonChance < 5)
	{
		PrintStory(3, "플레이어는 독에 걸렸다!");
	}

	WaitForEnter();
}