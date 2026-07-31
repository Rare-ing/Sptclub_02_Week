#pragma once

#include "Monster.h"

class GhostGuard : public Monster
{
public:
	GhostGuard();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};