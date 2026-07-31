#pragma once

#include "Monster.h"

class Yaksa : public Monster
{
public:
	Yaksa();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};