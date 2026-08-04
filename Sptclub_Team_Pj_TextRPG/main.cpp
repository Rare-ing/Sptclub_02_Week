#include "Character.h"
#include "Menu.h"
#include "Title.h"
#include "Player.h"
#include "PlayerHud.h"
#include "Inventory.h"
#include "Stage.h"
#include "Battle.h"
#include "Monster.h"
#include "Podo.h"
#include "Nang.h"
#include "Jag.h"
#include "Amh.h"
#include "Gunb.h"
#include "jangg.h"
#include "Umyang.h"
#include "Jusul.h"
#include "Jwado.h"
#include "PotionWorkshop.h"
#include <iostream>

void mainloop(Player* player, Inventory& inventory)
{
    system("cls");
    int switchNum;
	int stageLevel = 1;
	bool bossDefeated = false;
    PotionWorkshop workshop;
    while (true)
    {
        // 현재 스테이지 생성
        Stage stage(stageLevel);
		bossDefeated = false;
        // 해당 스테이지에서 계속 활동
        while (!bossDefeated)
        {
            cout << "\n===== 메뉴 =====\n";
            cout << "현재 스테이지 : " << stageLevel << endl;
            cout << "1. 전투" << endl;
            cout << "2. 스테이터스 확인" << endl;
            cout << "3. 인벤토리 확인" << endl;
            cout << "4. 영약방 가기" << endl;
            cout << "5. 보스 도전" << endl;
            cout << "6. 종료" << endl;

            cin >> switchNum;

            switch (switchNum)
            {
            case 1:
            {
                system("cls");

                Monster* monster = stage.GetRandomMonster();

                if (monster == nullptr)
                {
                    cout << "몬스터가 없습니다." << endl;
                    break;
                }

                Battle battle(player, monster, &inventory);
                battle.StartBattle();
                if (!monster->getAlive())
                {
					monster->resetMonster();
                }
                break;
            }

            case 2:
                system("cls");
                DrawPlayerHUD(player);
                break;

            case 3:
                system("cls");
                inventory.showInventory();
                break;
            
            case 4:
                system("cls");
                workshop.RunMenu();
                break;
            case 5:
            {
                system("cls");

                // 보스 입장 레벨 확인
                if (player->getLevel() < stage.getBossOpenLevel())
                {
                    cout << "아직 보스에게 도전할 수 없습니다." << endl;
                    cout << "필요 레벨 : "
                        << stage.getBossOpenLevel() << endl;
                    break;
                }

                cout << "보스방이 열렸다!" << endl;

                Monster* boss = stage.GetBoss();

                Battle bossBattle(player, boss, &inventory);
                bossBattle.StartBattle();

                // 보스를 죽였는지 확인
                if (!boss->getAlive())
                {
                    cout << "\n보스를 처치했다!" << endl;

                    bossDefeated = true;
                    stageLevel++;
                }

                break;
            }

            case 6:
                return;

            default:
                cout << "잘못된 입력입니다." << endl;
                break;
            }
        }
    }
}

int main()
{
    ShowTitle();

    Character startplayer;
    startplayer.CreateCharacter();
    StatusMenu(startplayer);

    Inventory inventory;

    Player* player = nullptr;
	
    // 무인 계열
    if (startplayer.getType() == "무인")
    {
        if (startplayer.getRace() == "인간")
        {
            player = new Podo(startplayer.getName());
        }
        else if (startplayer.getRace() == "호족")
        {
            player = new Nang(startplayer.getName());
        }
        else if (startplayer.getRace() == "귀신")
        {
            player = new Jag(startplayer.getName());
        }
    }

    // 도사 계열
    else if (startplayer.getType() == "도사")
    {
        if (startplayer.getRace() == "인간")
        {
            player = new Umyang(startplayer.getName());
        }
        else if (startplayer.getRace() == "호족")
        {
            player = new Jusul(startplayer.getName());
        }
        else if (startplayer.getRace() == "귀신")
        {
            // 아직 클래스가 준비 안 됐다면 나중에
            // player = new Jwado(startplayer.getName());
        }
    }

    if (player == nullptr)
    {
        cout << "플레이어 생성 실패" << endl;
        return 1;
    }

    player->setJob(startplayer.getJob());
    player->setRace(startplayer.getRace());

    player->applyRace();
    player->applyType();

    // 게임 시작
    mainloop(player, inventory);

    // Player 소멸자가 virtual이므로 안전
    delete player;

    return 0;
}