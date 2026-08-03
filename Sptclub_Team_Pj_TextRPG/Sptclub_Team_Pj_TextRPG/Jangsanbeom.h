#pragma once

#include "Monster.h"

class Jangsanbeom : public Monster
{
public:
	Jangsanbeom();

	void TakeTurn(Player* player) override;

	void Attack(Player* player) override;

	void Skill(Player* player) override;
};