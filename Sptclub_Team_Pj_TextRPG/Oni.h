#pragma once

#include "Monster.h"

class Oni : public Monster
{
public:
	Oni();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};