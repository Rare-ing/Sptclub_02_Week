#pragma once

#include "Monster.h"

class Player;
class Inventory;


class Battle
{
private:

	Player*& player; //준우-멤버변수도 변경
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
	Battle(Player*& player, Monster* monster, Inventory* inventory, bool CanUsePotion = true);
	//Player*는 플레이어 객체의 주소를 복사하는 거고,
    //Player*& 는 main에 있는 포인터 자체를 참조하는 것, 즉 *& 사용해야 2차전직 가능해서 수정했음-준우

	void StartBattle();
};