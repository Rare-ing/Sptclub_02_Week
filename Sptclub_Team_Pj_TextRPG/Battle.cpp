#include "Battle.h"
#include "Player.h"
#include "Inventory.h"
#include "PlayerHud.h"
#include "Game.h"
#include "GameUI.h"
#include "Title.h"
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
		PrintStory(0, "2차 전직이 불가능한 직업입니다.");
		WaitForEnter();
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

	PrintStory(0, "★★★★★★★★★★★★");
	PrintStory(1, "2차 전직 완료!");
	PrintStory(2, "새로운 직업 : " + player->getJob());
	PrintStory(3, "★★★★★★★★★★★★");

	WaitForEnter();
}

Battle::Battle(Player*& player, Monster* monster, Inventory* inventory, bool CanUsePotion)
	: player(player), monster(monster), inventory(inventory), CanUsePotion(CanUsePotion)
{
	turn = 1;
}
void Battle::StartBattle()
{
	ClearChoiceArea();
	ClearStoryArea();

	GotoXY(1, 38);
	cout << string(50, ' ');

	DrawPlayerHUD(player);

	PrintStory(0, monster->getSpawnMessage());
	PrintStory(1, "[ 전투 시작 ]");
	PrintStory(2, monster->getName() + "과의 전투가 시작되었습니다.");

	bool isWin = false;

	while (true)
	{
		PrintStory(4, "===== " + std::to_string(turn) + "턴 =====");

		monster->ApplyDot();

		if (CheckBattleEnd())
		{
			break;
		}

		PlayerTurn();
		DrawPlayerHUD(player); 

		if (CheckBattleEnd())
		{
			if (!monster->getAlive())
			{
				isWin = true;

				PrintStory(5, monster->getName() + "을(를) 처치했다!");
				WaitForEnter();
			}

			break;
		}

		MonsterTurn();
		DrawPlayerHUD(player); //

		if (CheckBattleEnd())
		{
			break;
		}

		turn++;
	}
	if (isWin)
	{
		ClearStoryArea();

		int rewardExp = monster->getExpReward();

		player->setExp(player->getExp() + rewardExp);

		PrintStory(0, "전투 승리!");
		PrintStory(1, monster->getName() + " 처치!");
		PrintStory(2, "경험치 " + to_string(rewardExp) + " 획득!");

		WaitForEnter();


		player->levelUp();


		if (player->getLevel() >= 8 && !player->getIsSecondJob())
		{
			promotePlayer(player);
		}

		GiveReward();
	}
	player->resetBonusAttack();
	player->resetBonusDefence();

	ClearStoryArea();
	ClearChoiceArea();
}

void Battle::PlayerTurn()
{
	while (true)
	{
		PrintStory(3, "[ 플레이어 턴 ]");

		DrawBattleMenu();

		DrawInputArea();
		InputCursor();

		int choice = GetInput();


		switch (choice)
		{
		case 1:
			monster->TakeDamage(player->getAttack());

			ClearStoryArea();

			PrintStory(0, player->getName() + "이(가) " + monster->getName() + "을(를) 공격했다!");

			PrintStory(1, monster->getName() + "에게 " + std::to_string(player->getAttack()) + "의 피해를 입혔다!");
			PrintStory(2, "남은 체력 : " + std::to_string(monster->getHp()));

			WaitForEnter();

			return;

		case 2:
			ClearStoryArea();
			player->skill(*monster);

			PrintStory(3, monster->getName() + " 남은 체력 : " + std::to_string(monster->getHp()));

			WaitForEnter();

			return;

		case 3:

			OpenInventory();
			break;

		default:

			PrintStory(3, "잘못된 입력입니다.");
			break;
		}
	}
}

void Battle::MonsterTurn()
{
	ClearStoryArea();
	if (monster->getIsStunned())
	{
		PrintStory(3, monster->getName() + "은(는) 기절해서 움직일 수 없다!");

		monster->ClearStun();
		return;
	}
	monster->TakeTurn(player);
}

void Battle::OpenInventory()
{
	inventory->invenFunc(*player);
}

bool Battle::CheckBattleEnd()
{
	if (player->getHp() <= 0)
	{
		ClearStoryArea();
		PrintStory(0, "플레이어가 쓰러졌다.");
		WaitForEnter();
		return true;
	}

	if (!monster->getAlive())
	{
		return true;
	}

	return false;
}

void Battle::GiveReward()
{
	ClearStoryArea();


	Item* droppedItem = new Item(
		monster->getDropItemName(),
		ItemType::Material,
		monster->getDropItemPrice(),
		monster->getDropItemWeight()
	);


	inventory->addItem(droppedItem);


	PrintStory(0, "전투에서 승리했다!");
	PrintStory(1, "아이템 획득 : " + monster->getDropItemName());


	WaitForEnter();


	ClearStoryArea();
}