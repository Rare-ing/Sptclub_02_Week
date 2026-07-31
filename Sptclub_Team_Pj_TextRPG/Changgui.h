#pragma once

#include "Monster.h"

class Changgui : public Monster
{
public:
	Changgui();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};