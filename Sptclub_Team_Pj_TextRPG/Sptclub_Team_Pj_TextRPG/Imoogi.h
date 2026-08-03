#pragma once

#include "Monster.h"

class Imoogi : public Monster
{
public:
	Imoogi();

	void TakeTurn(Player* player) override;

	void Attack(Player* player) override;

	void Skill(Player* player) override;

private:
	void PoisonSkill(Player* player);

	void StunSkill(Player* player);
};