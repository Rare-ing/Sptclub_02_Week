#pragma once

#include "Monster.h"

class MountainBeast : public Monster
{
public:
	MountainBeast();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};