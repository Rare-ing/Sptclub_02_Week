#pragma once

#include "Monster.h"

class HungryEunuch : public Monster
{
public:
	HungryEunuch();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};