#include "Oni.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

Oni::Oni() : Monster("도깨비", 6, 70, "도깨비 방망이 조각", 50, 15, "요란한 웃음소리와 함께 도깨비가 나타났다!") {}

void Oni::Attack(Player* player)
{
	std::cout << "도깨비는 방망이를 휘둘렀다!" << std::endl;

	int damage = CalculateDamage(player->getDefence());
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
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

	std::cout << "도깨비는 도깨비 방망이를 내려쳐 강력한 충격을 일으켰다!" << std::endl;

	int damage = CalculateSkillDamage(player->getDefence(), 1.5f);
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}