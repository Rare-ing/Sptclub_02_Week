#pragma once

#include "Monster.h"

class BanditGhost : public Monster
{
public:
	BanditGhost();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};