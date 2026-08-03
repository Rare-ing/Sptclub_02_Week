#pragma once

#include "Monster.h"

class Drunk : public Monster
{
public:
	Drunk();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};