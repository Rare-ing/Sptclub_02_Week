#pragma once

#include "Monster.h"

class BanditBoss : public Monster
{
public:
	BanditBoss();

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};