#pragma once

#include "Monster.h"

class Gumiho : public Monster
{
public:
	Gumiho();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};