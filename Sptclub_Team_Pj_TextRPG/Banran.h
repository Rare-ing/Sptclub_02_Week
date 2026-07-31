#pragma once

#include "Monster.h"

class Banran : public Monster
{
public:
	Banran();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};