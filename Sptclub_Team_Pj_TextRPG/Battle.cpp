#include"Battle.h"
#include "Player.h"
#include<iostream>
#include<algorithm>

Battle::Battle(Player* player, Monster* monster)
	: player(player), monster(monster), turn(1) {}

void Battle::StartBattle()
{
	std::cout << "[ 전투 시작 ]" << std::endl;
	bool isWin = false;

	while (true)
	{
		std::cout << "\n=====" << turn << "턴 =====\n";

		//player->ApplyDot();
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
	}

}

void Battle::PlayerTurn()
{
	/*
	if (player->getIsStunned())
	{
		std::cout << "플레이어는 스턴에 걸려 움직일 수 없다!" << std::endl;

		player->ClearStun();
		return;
	}*/

	int action = rand() % 100;

	if (action < 70)
	{
		//player 공격
	}
	else
	{
		//player 스킬
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

bool Battle::CheckBattleEnd()
{
	if (player->getHp() <= 0)
	{
		std::cout << "플레이어가 쓰러졌다." << std::endl;
		return true;
	}

	if (monster->getHp() <= 0)
	{
		monster->setAlive(false);

		std::cout << monster->getName() << "을(를) 처치했다!" << std::endl;

		return true;
	}

	return false;
}