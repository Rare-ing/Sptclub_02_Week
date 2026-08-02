#include "Battle.h"
#include "Player.h"
#include "Inventory.h"
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
		//경험치 지급
		player->setExp(player->getExp() + monster->getExpReward());
		player->levelUp();
		//아이템 드랍
		GiveReward();
	}

}

void Battle::PlayerTurn()
{
	/*
	if (player->getStunned())
	{
		std::cout << "플레이어는 스턴에 걸려 움직일 수 없다!" << std::endl;

		//player->ClearStun();
		return;
	}*/

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
		//player->Attack(monster);
		monster->TakeDamage(player->getAttack());
		cout << player->getName() << "이(가) " << monster->getName() << "을(를) 공격했다!" << std::endl;
		cout << monster->getName() << "에게 " << player->getAttack() << "의 피해를 입혔다!" << std::endl;
		cout << monster->getName() << "의 남은 체력 : " << monster->getHp() << std::endl;
		cout << "남은 MP : " << player->getMp() << std::endl;
		cout << "남은 HP : " << player->getHp() << std::endl;
		monster->TakeDamage(0);//몬스터가 죽었는지 확인
		break;

	case 2:
		player->skill(*monster);
		cout << player->getName() << "이(가) " << monster->getName() << "에게 스킬을 사용했다!" << std::endl;
		cout << monster->getName() << "에게 " << player->getAttack() << "의 피해를 입혔다!" << std::endl;
		cout << monster->getName() << "의 남은 체력 : " << monster->getHp() << std::endl;
		cout << "남은 MP : " << player->getMp() << std::endl;
		cout << "남은 HP : " << player->getHp() << std::endl;
		monster->TakeDamage(0);//몬스터가 죽었는지 확인
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

void Battle::GiveReward()
{
	Item* droppedItem = new Item(monster->getDropItemName(),ItemType::Material, monster->getDropItemPrice(), monster->getDropItemWeight());
	inventory->addItem(droppedItem);
}