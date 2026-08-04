#include "Drunk.h"
#include "Player.h"
#include "GameUI.h"

#include <cstdlib>


Drunk::Drunk()
	: Monster("취객", 1, 50, "동동주", 10, 5, "술에 잔뜩 취한 취객이 나타났다!"){}


void Drunk::Attack(Player* player)
{
	PrintStory(0, "취객은 술병을 휘둘렀다!");


	int damage = CalculateDamage();

	player->TakeDamage(damage);


	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	WaitForEnter();
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


	PrintStory(0, "취객은 술에 취한 힘으로 술병을 강하게 내리쳤다!");


	int damage = CalculateSkillDamage(1.2f);

	player->TakeDamage(damage);


	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));
	WaitForEnter();
}