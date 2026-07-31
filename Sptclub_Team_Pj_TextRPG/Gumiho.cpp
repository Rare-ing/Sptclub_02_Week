#include "Gumiho.h"
#include <iostream>
#include <cstdlib>

Gumiho::Gumiho() : Monster("구미호", 3, 50, "구미호의 털", 60, 3, "아름다운 모습 뒤에 숨은 구미호가 나타났다!") {}

void Gumiho::Attack(Player* player)
{
	std::cout << "구미호는 날카로운 손톱으로 공격했다!" << std::endl;

	int damage = CalculateDamage(player->getDefence());
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;
}

void Gumiho::Skill(Player* player)
{
	const int skillCost = 30;

	if (getMp() < skillCost)
	{
		Attack(player);
		return;
	}
	setMp(getMp() - skillCost);

	std::cout << "구미호는 요력을 모아 홀리는 기운을 내뿜었다!" << std::endl;

	int damage = CalculateSkillDamage(player->getDefence(), 0.8f);
	player->TakeDamage(damage);

	std::cout << damage << "의 피해를 입었다!" << std::endl;

	int stunChance = rand() % 100;

	if (stunChance < 30)
	{
		player->setStunned(true);

		std::cout << "플레이어는 헤롱헤롱해졌다!!" << std::endl;
	}
}