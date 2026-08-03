#include "Battle.h"
#include "Player.h"
#include "Inventory.h"
#include "Jangg.h"
#include "Gunb.h"
#include "Amh.h"
#include "Guks.h"
#include "Sansin.h"
#include "Yos.h"
#include <iostream>
#include <cstdlib>

void promotePlayer(Player*& player)
{
	if (player == nullptr)
	{
		return;
	}

	// 이미 2차 전직했다면 종료
	if (player->getIsSecondJob())
	{
		return;
	}

	Player* newPlayer = nullptr;

	// 현재 1차 직업에 맞는 2차 직업 객체 생성
	if (player->getJob() == "포도대장")
	{
		newPlayer = new Jangg(player->getName());
	}

	else if (player->getJob() == "낭인")
	{
		newPlayer = new Gunb(player->getName());
	}
	else if (player->getJob() == "자객")
	{
		newPlayer = new Amh(player->getName());
	}
	else if (player->getJob() == "음양무녀")
	{
		newPlayer = new Guks(player->getName());
	}
	else if (player->getJob() == "주술사")
	{
		newPlayer = new Sansin(player->getName());
	}
	else if (player->getJob() == "좌도방사")
	{
		newPlayer = new Yos(player->getName());
	}

	// 대응되는 2차 직업이 없다면 종료
	if (newPlayer == nullptr)
	{
		cout << "2차 전직이 불가능한 직업입니다." << endl;
		return;
	}

	// 기존 캐릭터 정보 복사
	newPlayer->copyPlayerData(*player);

	// 2차 직업명 변경
	if (player->getJob() == "포도대장")
	{
		newPlayer->setJob("장군");
	}
	else if (player->getJob() == "낭인")
	{
		newPlayer->setJob("군벌");
	}
	else if (player->getJob() == "자객")
	{
		newPlayer->setJob("암행어사");
	}
	else if (player->getJob() == "음양무녀")
	{
		newPlayer->setJob("국선");
	}
	else if (player->getJob() == "주술사")
	{
		newPlayer->setJob("산신");
	}
	else if (player->getJob() == "좌도방사")
	{
		newPlayer->setJob("요선");
	}

	// 기존 객체 삭제 후 새 객체로 교체
	delete player;
	player = newPlayer;

	std::cout << std::endl;
	std::cout << "★★★★★★★★★★★★★★★★★★" << std::endl;
	std::cout << "       2차 전직 완료!" << std::endl;
	std::cout << "       새로운 직업 : " << player->getJob() << std::endl;
	std::cout << "★★★★★★★★★★★★★★★★★★" << std::endl;//준우-2차전직 추가
}

Battle::Battle(Player*& player, Monster* monster, Inventory* inventory, bool CanUsePotion)
	: player(player), monster(monster), inventory(inventory), CanUsePotion(CanUsePotion)
{
	turn = 1;
}
void Battle::StartBattle()
{
	std::cout << monster->getSpawnMessage() << std::endl;
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
		player->setExp(player->getExp() + monster->getExpReward());
		player->levelUp();	//경험치 지급

		if (player->getLevel() >= 8 && !player->getIsSecondJob())
		{
			promotePlayer(player); //Lv.8 자동전직은 여기서 호출
		}

		GiveReward();		//아이템 드랍
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
	while (true)
	{

		int choice;

		std::cout << "\n[ 플레이어 턴 ] " << std::endl;
		std::cout << "1. 공격" << std::endl;
		std::cout << "2. 스킬" << std::endl;
		std::cout << "3. 행낭" << std::endl;
		std::cout << "선택 : ";

		std::cin >> choice;
		switch (choice)
		{
		case 1:
			//player->Attack(monster);
			monster->TakeDamage(player->getAttack() + player->getBonusAttack());
			cout << player->getName() << "이(가) " << monster->getName() << "을(를) 공격했다!" << std::endl;
			cout << monster->getName() << "에게 " << player->getAttack() << "의 피해를 입혔다!" << std::endl;
			cout << monster->getName() << "의 남은 체력 : " << monster->getHp() << std::endl;
			cout << "남은 HP : " << player->getHp() << std::endl;
			cout << "남은 MP : " << player->getMp() << std::endl;
			monster->TakeDamage(0);//몬스터가 죽었는지 확인
			return;

		case 2:
			player->skill(*monster);
			cout << player->getName() << "이(가) " << monster->getName() << "에게 스킬을 사용했다!" << std::endl;
			cout << monster->getName() << "에게 " << player->getAttack() << "의 피해를 입혔다!" << std::endl;
			cout << monster->getName() << "의 남은 체력 : " << monster->getHp() << std::endl;
			cout << "남은 HP : " << player->getHp() << std::endl;
			cout << "남은 MP : " << player->getMp() << std::endl;
			monster->TakeDamage(0);//몬스터가 죽었는지 확인
			return;

		case 3:
			OpenInventory();
			break;


		default:
			std::cout << "잘못된 입력입니다." << std::endl;
			break;
		}
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