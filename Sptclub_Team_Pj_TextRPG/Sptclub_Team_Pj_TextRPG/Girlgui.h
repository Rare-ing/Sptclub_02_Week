#pragma once

#include "Monster.h"

class Girlgui : public Monster
{
public:
	Girlgui();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};