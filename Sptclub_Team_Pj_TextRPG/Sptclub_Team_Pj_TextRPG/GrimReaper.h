#pragma once

#include "Monster.h"

class GrimReaper : public Monster
{
public:
	GrimReaper();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};