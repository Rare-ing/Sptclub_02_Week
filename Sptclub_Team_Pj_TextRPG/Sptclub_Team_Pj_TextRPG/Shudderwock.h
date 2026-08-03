#pragma once

#include "Monster.h"

class Shudderwock : public Monster
{
public:
	Shudderwock();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};