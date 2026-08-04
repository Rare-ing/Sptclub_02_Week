#include "Sadoseja.h"
#include "Player.h"
#include "GameUI.h"

#include <cstdlib>

Sadoseja::Sadoseja()
	: Monster("뒤주의 망령", 5, 80, "사도세자의 옥패", 100, 20, "뒤주 속에서 한을 품고 죽어간 사도세자의 망령이 모습을 드러냈다!")
{
	setBoss(true);
	ApplyBossBonus();
}

void Sadoseja::Attack(Player* player)
{
	PrintStory(0, "뒤주의 망령은 뒤주 틈새에서 검은 손을 뻗었다!");

	int damage = CalculateDamage();

	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));

	WaitForEnter();
}

void Sadoseja::Skill(Player* player)
{
	const int skillCost = 50;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}

	setMp(getMp() - skillCost);

	PrintStory(0, "뒤주의 망령은 깊은 원한을 폭발시켜 사방으로 원혼을 내뿜었다!");

	int damage = CalculateSkillDamage(1.8f);

	player->TakeDamage(damage);

	PrintStory(1, std::to_string(damage) + "의 피해를 입었다!");
	PrintStory(2, "남은 HP : " + std::to_string(player->getHp()));
	WaitForEnter();
}