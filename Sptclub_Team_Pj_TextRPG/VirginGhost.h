#pragma once

#include "Monster.h"

class VirginGhost : public Monster
{
public:
	VirginGhost();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};