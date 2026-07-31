#include "Battle.h"

#include <iostream>
#include <cstdlib>

Battle::Battle(Player* player, Monster* monster, Inventory* inventory)
	: player(player), monster(monster), inventory(inventory), turn(1) {}

void Battle::StartBattle()
{
	std::cout << "[ 전투 시작 ]" << std::endl;
	bool isWin = false;

	while (true)
	{
		std::cout << "\n=====" << turn << "턴 =====\n";

		player->ApplyDot();
		monster->ApplyDot();

		if (CheckBattleEnd())
		{
			break;
		}

		PlayerTurn();

		if (CheckBattleEnd())
		{
			isWin = true;
			break;
		}

		MonsterTurn();

		if (CheckBattleEnd())
		{
			break;
		}

		turn++;
	}
	if (isWin)
	{
		//경험치 지급
		//아이템 드랍
	}

}

void Battle::PlayerTurn()
{
	if (player->getIsStunned())
	{
		std::cout << "플레이어는 스턴에 걸려 움직일 수 없다!" << std::endl;

		player->ClearStun();
		return;
	}

	int choice;

	std::cout << "\n[ 플레이어 턴 ] " << std::endl;
	std::cout << "1. 공격" << std::endl;
	std::cout << "2. 스킬" << std::endl;
	std::cout << "3. 행낭" << std::endl;
	std::cout << "선택 : ";

	while (true)
	{
		std::cin >> choice;

		if (choice >= 1 && choice <= 3)
		{
			break;
		}

		std::cout << "잘못된 입력입니다. 다시 선택해주세요 : ";
	}

	switch (choice)
	{
	case 1:
		player->Attack(monster);
		break;

	case 2:
		player->skill(*monster);
		break;

	case 3:
		OpenInventory();
		break;


	default:
		std::cout << "잘못된 입력입니다." << std::endl;
		break;
	}
}

void Battle::MonsterTurn()
{
	if (monster->getIsStunned())
	{
		std::cout << monster->getName() << "은(는) 기절해서 움직일 수 없다!" << std::endl;

		monster->ClearStun();
		return;
	}
	monster->TakeTurn(player);
}

void Battle::OpenInventory()
{
	inventory->invenFunc();
}

bool Battle::CheckBattleEnd()
{
	if (player->getHp() <= 0)
	{
		std::cout << "플레이어가 쓰러졌다." << std::endl;
		return true;
	}

	if (!monster->getAlive())
	{
		std::cout << monster->getName() << "을(를) 처치했다!" << std::endl;
		return true;
	}

	return false;
}