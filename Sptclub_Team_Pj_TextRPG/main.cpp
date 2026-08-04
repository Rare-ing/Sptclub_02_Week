#include "Character.h"
#include "Menu.h"
#include "Title.h"
#include "Player.h"
#include "Inventory.h"
#include "Stage.h"
#include "Battle.h"
#include "Monster.h"
#include "Imoogi.h"
#include "Podo.h"
#include "Nang.h"
#include "Jag.h"
#include "Amh.h"
#include "Gunb.h"
#include "jangg.h"
#include "Umyang.h"
#include "Jusul.h"
#include "Jwado.h"
#include "Guks.h"
#include "Sansin.h"
#include "Yos.h"
#include "PotionWorkshop.h"
#include "WeaponManager.h"
#include "MaterialItem.h"
#include "Game.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

void stageStartFunc(int stageLevel, Player* player, Inventory& inventory, WeaponManager& weaponManager)
{

    WeaponItem* weapon = new WeaponItem(weaponManager.CreateWeaponForJob(player->getJob()));
    switch (stageLevel)
    {
    case 1:
        GotoXY(4, 4);
        cout << "주막에서 술을 마시고 있는 중 소란이 나서 고개를 돌려보니";

        GotoXY(4, 5);
        cout << "도적들이 쳐들어와 주막에서 행패를 부리고 있었다.";

        GotoXY(4, 6);
        cout << "식사 중에 소란은 달갑지 않은데 말이지..";

        GotoXY(4, 7);
        cout << "적 : 뭐? 어디서 분위기를 잡고있어! 야 저 자식 꿇려!";
        break;
    case 2:
        GotoXY(4, 4);
        cout << "소란이 가라앉고, 주인공이 상황을 정리하던 순간,";

        GotoXY(4, 5);
        cout << "평범한 행색의 사내가 천천히 다가왔다. 그러나 그 눈빛만큼은 범상치 않았다.";

        GotoXY(4, 6);
        cout << "??:제법이구나.";

        GotoXY(4, 7);
        cout << "누구시오 ? ";
        break;
    case 3:
        cout << "주막에서 술을 마시고 있는 중 소란이 나서 고개를 돌렸다" << endl;
        cout << "도적들이 쳐들어와 주막에서 행패를 부린다" << endl;
        cout << "저 자식들 심심했는데 잘걸렸다 그러면 건방진 놈들 혼좀 내러 가보실까!" << endl;
        cout << "적 : 도적, 취객, 걸귀" << endl;
        break;
    case 4:
        cout << "주막에서 술을 마시고 있는 중 소란이 나서 고개를 돌렸다" << endl;
        cout << "도적들이 쳐들어와 주막에서 행패를 부린다" << endl;
        cout << "저 자식들 심심했는데 잘걸렸다 그러면 건방진 놈들 혼좀 내러 가보실까!" << endl;
        cout << "적 : 도적, 취객, 걸귀" << endl;
        break;
    case 5:
        cout << "주막에서 술을 마시고 있는 중 소란이 나서 고개를 돌렸다" << endl;
        cout << "도적들이 쳐들어와 주막에서 행패를 부린다" << endl;
        cout << "저 자식들 심심했는데 잘걸렸다 그러면 건방진 놈들 혼좀 내러 가보실까!" << endl;
        cout << "적 : 도적, 취객, 걸귀" << endl;
        break;
    }

    if (player->getLevel() > 8)
    {
        cout << "전하께서 새로운 무기를 하사하셨다" << endl;
    }
    return;
}

bool CheckImoogiUnlock(Player* player, Inventory& inventory)
{
    if (!inventory.hasItem("봉인된 여의주"))
    {
        return false;
    }
    return true;
}

void mainloop(Player*& player, Inventory& inventory)
{
    DrawGameFrame();
    int switchNum;
    int stageLevel = 1;
    bool bossDefeated = false;
    bool unlockImoogi = false;
    bool trueEnding = false;
    PotionWorkshop workshop;
    WeaponManager weaponManager;
    workshop.AddDefaultRecipes();

    while (true)
    {
        stageStartFunc(stageLevel, player, inventory, weaponManager);

        GotoXY(0, 4);

        DrawPlayerHUD(player);

        Stage stage(stageLevel);
        bossDefeated = false;

        while (!bossDefeated)
        {
            unlockImoogi = CheckImoogiUnlock(player, inventory);

            DrawPlayerHUD(player);

            ClearGameMenu();

            for (int y = 4; y < 22; y++)
            {
                GotoXY(0, y);
                cout << string(120, ' ');
            }

            GotoXY(4, 23);
            cout << "현재 스테이지 : " << stageLevel;

            GotoXY(4, 24);
            cout << "1. 길을 걸어가다";

            GotoXY(25, 24);
            cout << "2. 스테이터스 확인";

            GotoXY(50, 24);
            cout << "3. 인벤토리 확인";

            GotoXY(75, 24);
            cout << "4. 영약방 가기";

            GotoXY(95, 24);
            cout << "5. 보스 도전";

            if (unlockImoogi)
            {
                cout << "6. 봉인된 여의주를 해방한다" << endl;
                cout << "7. 종료" << endl;
            }
            else
            {
            cout << "6. 종료" << endl;
            }

            cin >> switchNum;

            switch (switchNum)
            {
            case 1:
            {

                int random = rand() % 11;
				cout << "랜덤 이벤트 발생! (0 : 허탕 1~4 : 약초 발견 5~10 : 몬스터 등장) : " << random << endl;
				if (random == 0)
				{
					cout << "아무일도 일어나지 않았다." << endl;
					break;
				}
                else if (random <= 4)
                {
                    cout << "약초를 " << random << "개 발견했다!" << endl;

                    MaterialItem::AddItem(inventory, random);
                }
                else
                {
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
                }
                break;
            }

            case 2:
                player->showStatus();
                break;

            case 3:
                inventory.showInventory();
                break;
            
            case 4:
                workshop.RunMenu(inventory);
                break;
            case 5:
            {
                cout << player->getLevel() << endl;
                // 보스 입장 레벨 확인
                if (player->getLevel() <= stage.getBossOpenLevel())
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
            {
                if (!unlockImoogi)
                {
                    cout << "게임을 종료합니다." << endl;
                    return;
                }



                cout << "봉인된 여의주가 반응한다..." << endl;
                cout << "천년을 기다린 이무기가 모습을 드러낸다!" << endl;


                Imoogi* imoogi = new Imoogi();

                Battle imoogiBattle(player, imoogi, &inventory);

                imoogiBattle.StartBattle();


                if (!imoogi->getAlive())
                {
                    cout << "\n전설의 이무기를 쓰러뜨렸다!" << endl;
                    cout << "진정한 여의주를 손에 넣었다..." << endl;

                    inventory.removeItem("봉인된 여의주");

                    Item* trueOrb = new Item( "진정한 여의주", ItemType::Quest, 9999, 0);


                    inventory.addItem(trueOrb);

                    trueEnding = true;

                    cout << "축하합니다! 진엔딩을 달성했습니다." << endl;

                    return;
                }
                else
                {
                    cout << "이무기는 당신을 삼켰다..." << endl;
                    cout << "게임 오버" << endl;

                    delete imoogi;
                    return;
                }


                delete imoogi;

                break;
            }

            case 7:
            {
                cout << "게임을 종료합니다." << endl;
                return;
            }

            default:
                cout << "잘못된 입력입니다." << endl;
                break;
            }
        }
    }
}



int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

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
            player = new Jwado(startplayer.getName());
        }
    }

    if (player == nullptr)
    {
        cout << "플레이어 생성 실패" << endl;
        return 1;
    }

    player->setJob(startplayer.getJob());
    player->setRace(startplayer.getRace());
	player->setType(startplayer.getType());
    //8랩 시뮬용player->addExp(700);

    //8랩 시뮬용player->levelUp();

   //8랩 시뮬용 std::cout << "\n===== 전직 테스트 =====" << std::endl;
    //8랩 시뮬용std::cout << "현재 레벨 : " << player->getLevel() << std::endl;
    //8랩 시뮬용std::cout << "현재 직업 : " << player->getJob() << std::endl;  

    player->applyRace();
    player->applyType();

    // 게임 시작
    mainloop(player, inventory);

    delete player;

    return 0;
}