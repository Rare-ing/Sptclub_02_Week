#pragma once

#include "Monster.h"

class UndergroundNation : public Monster
{
public:
	UndergroundNation();

	void TakeTurn(Player* player) override;

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};