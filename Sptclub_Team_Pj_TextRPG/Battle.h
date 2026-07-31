#pragma once

#include "Monster.h"

class Player;


class Battle
{
private:

	Player* player;
	Monster* monster;

	int turn;

	void PlayerTurn();

	void MonsterTurn();

	bool CheckBattleEnd();

public:
	Battle(Player* player, Monster* monster);

	void StartBattle();
};