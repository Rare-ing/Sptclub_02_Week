#include "Oni.h"
#include "Player.h"
#include "GameUI.h"

#include <cstdlib>


Oni::Oni()
	: Monster("도깨비", 4, 50, "도깨비 방망이 조각", 50, 15, "요란한 웃음소리와 함께 도깨비가 나타났다!"){}


void Oni::Attack(Player* player)
{
	PrintStory(0, "도깨비는 방망이를 휘둘렀다!");

	int damage = CalculateDamage();

	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	WaitForEnter();
}


void Oni::Skill(Player* player)
{
	const int skillCost = 60;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}

	setMp(getMp() - skillCost);

	PrintStory(0, "도깨비는 도깨비 방망이를 내려쳐 강력한 충격을 일으켰다!");

	int damage = CalculateSkillDamage(1.5f);

	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));
	WaitForEnter();
}