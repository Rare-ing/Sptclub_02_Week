#include "Banran.h"
#include "Player.h"
#include "GameUI.h"

#include <cstdlib>


Banran::Banran()
	: Monster("역심품은 신하", 4, 50, "핏빛 상소문", 55, 12, "권력을 탐했던 신하의 원한이 궁궐 깊은 곳에서 모습을 드러냈다!"){}

void Banran::Attack(Player* player)
{
	PrintStory(0, "역심품은 신하는 숨겨둔 비수를 꺼내 찔렀다!");

	int damage = CalculateDamage();
	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	WaitForEnter();
}


void Banran::Skill(Player* player)
{
	const int skillCost = 20;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}

	setMp(getMp() - skillCost);

	PrintStory(0, "역심품은 신하는 핏빛 상소문의 저주로 상대를 억눌렀다!");

	int damage = CalculateSkillDamage(1.3f);

	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));


	int poisonChance = rand() % 100;

	if (poisonChance < 30)
	{
		PrintStory(0, "플레이어는 끔찍한 저주에 걸렸다!");

		//player->setPoison(15, 3);
	}
	WaitForEnter();
}