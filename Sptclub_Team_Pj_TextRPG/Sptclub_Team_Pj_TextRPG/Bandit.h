#pragma once

#include "Monster.h"

class Bandit : public Monster
{
public:
	Bandit();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};