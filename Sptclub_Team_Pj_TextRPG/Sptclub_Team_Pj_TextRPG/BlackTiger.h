#pragma once

#include "Monster.h"

class BlackTiger : public Monster
{
public:
	BlackTiger();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};