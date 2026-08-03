#pragma once

#include "Monster.h"

class Player;
class Inventory;


class Battle
{
private:

	Player* player;
	Monster* monster;
	Inventory* inventory;

	int turn;

	void PlayerTurn();

	void MonsterTurn();

	void OpenInventory();

	bool CheckBattleEnd();

	void GiveReward();

	bool CanUsePotion;

public:
	Battle(Player* player, Monster* monster, Inventory* inventory, bool CanUsePotion = true);

	void StartBattle();
};