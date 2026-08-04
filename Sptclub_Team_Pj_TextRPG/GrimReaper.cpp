#include "GrimReaper.h"
#include "Player.h"
#include "GameUI.h"

#include <cstdlib>

GrimReaper::GrimReaper()
	: Monster("저승사자", 8, 80, "검은 부채", 100, 5, "죽음의 사자가 검은 그림자 속에서 나타났다!") {}

void GrimReaper::Attack(Player* player)
{
	PrintStory(0, "저승사자는 검은 부채로 베어냈다!");

	int damage = CalculateDamage();
	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	WaitForEnter();
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

	PrintStory(0, "저승사자는 저승의 힘으로 죽음의 기운을 내뿜었다!");

	int damage = CalculateSkillDamage(1.2f);
	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	int poisonChance = rand() % 100;

	if (poisonChance < 30)
	{
		PrintStory(3, "저승의 손들이 플레이어를 괴롭힌다!");

		// player->setPoison(10, 3);
	}
	WaitForEnter();
}