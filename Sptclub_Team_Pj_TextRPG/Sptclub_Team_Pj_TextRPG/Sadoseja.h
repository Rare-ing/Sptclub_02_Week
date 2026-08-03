#pragma once

#include "Monster.h"

class Sadoseja : public Monster
{
public:
	Sadoseja();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};