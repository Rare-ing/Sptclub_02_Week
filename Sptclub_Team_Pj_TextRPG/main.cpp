#include "Character.h"
#include "Menu.h"
#include "Title.h"
#include "Player.h"
#include "PlayerHud.h"
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
#include "GameUI.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

void stageStartFunc(int stageLevel, Player* player, Inventory& inventory, WeaponManager& weaponManager)
{
    ClearStoryArea();
    WeaponItem* weapon = new WeaponItem(weaponManager.CreateWeaponForJob(player->getJob()));
    switch (stageLevel)
    {
    case 1:
        PrintStory(0, "주막에서 술을 마시던 중 소란이 나서 고개를 돌려보니");
        PrintStory(1, "도적들이 쳐들어와 주막에서 행패를 부리고 있었다.");
        PrintStory(2, "식사 중에 소란은 달갑지 않은데 말이지..");
        PrintStory(3, "적 : 뭐? 어디서 분위기를 잡고있어! 야 저 자식 꿇려!");
        break;
    case 2:
         PrintStory(0, "=======1스테이지 클리어!======");
        PrintStory(1, "소란이 가라앉고, 주인공이 상황을 정리하던 순간,");
        PrintStory(2, "평범한 행색의 사내가 천천히 다가왔다.");
        PrintStory(3, "그러나 그 눈빛만큼은 범상치 않았다.");
        PrintStory(4, "?? : 제법이구나.");
        PrintStory(5, "누구시오?");
        break;
    case 3:
        PrintStory(0, "=======2스테이지 클리어!======");
        PrintStory(1, "소란이 가라앉고, 주인공이 상황을 정리하던 순간,");
        PrintStory(2, "평범한 행색의 사내가 천천히 다가왔다.");
        PrintStory(3, "그러나 그 눈빛만큼은 범상치 않았다.");
        PrintStory(4, "?? : 제법이구나.");
        PrintStory(5, "누구시오?");
        break;
    case 4:
        PrintStory(0, "=======3스테이지 클리어!======");
        PrintStory(1, "소란이 가라앉고, 주인공이 상황을 정리하던 순간,");
        PrintStory(2, "평범한 행색의 사내가 천천히 다가왔다.");
        PrintStory(3, "그러나 그 눈빛만큼은 범상치 않았다.");
        PrintStory(4, "?? : 제법이구나.");
        PrintStory(5, "누구시오?");
        break;
    case 5:
        PrintStory(0, "=======4스테이지 클리어!======");
        PrintStory(1, "소란이 가라앉고, 주인공이 상황을 정리하던 순간,");
        PrintStory(2, "평범한 행색의 사내가 천천히 다가왔다.");
        PrintStory(3, "그러나 그 눈빛만큼은 범상치 않았다.");
        PrintStory(4, "?? : 제법이구나.");
        PrintStory(5, "누구시오?");
        break;
    }

    if (player->getLevel() > 8)
    {
        ClearStoryArea();
        PrintStory(0, "전하께서 새로운 무기를 하사하셨다");
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

        DrawPlayerHUD(player);

        Stage stage(stageLevel);
        bossDefeated = false;

        while (!bossDefeated)
        {
            unlockImoogi = CheckImoogiUnlock(player, inventory);

            DrawPlayerHUD(player);

            DrawMainMenu(unlockImoogi);

            PrintStory(0, "현재 스테이지 : " + to_string(stageLevel));

            DrawInputArea();
            InputCursor();
            switchNum = GetInput();

            switch (switchNum)
            {
            case 1:
            {
                int random = rand() % 11;

                ClearStoryArea();

                PrintStory(0, "길을 걷고 있다...");
                PrintStory(1, "주변을 살펴본다.");

                WaitForEnter();


                if (random == 0)
                {
                    ClearStoryArea();

                    PrintStory(0, "아무 일도 일어나지 않았다.");

                    WaitForEnter();
                    break;
                }
                else if (random <= 4)
                {
                    ClearStoryArea();

                    PrintStory(0, "약초 " + to_string(random) + "개를 발견했다!");

                    MaterialItem::AddItem(inventory, random);

                    WaitForEnter();
                }
                else
                {
                    Monster* monster = stage.GetRandomMonster();

                    if (monster == nullptr)
                    {
                        ClearStoryArea();
                        PrintStory(0, "몬스터가 없습니다.");
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
                DrawGameFrame();
                DrawPlayerHUD(player);
                player->showStatus();

                WaitForEnter();

                DrawGameFrame();
                break;

            case 3:
            {
                inventory.invenFunc(*player);

                DrawGameFrame();
                DrawPlayerHUD(player);

                break;
            }

            case 4:
            {
                workshop.RunMenu(inventory);

                DrawGameFrame();
                DrawPlayerHUD(player);

                break;
            }
            case 5:
            {
                // 보스 입장 레벨 확인
                if (player->getLevel() < stage.getBossOpenLevel())
                {
                    ClearStoryArea();

                    PrintStory(0, "아직 보스에게 도전할 수 없습니다.");
                    PrintStory(1, "필요 레벨 : " + to_string(stage.getBossOpenLevel()));
                    break;
                }

                ClearStoryArea();
                PrintStory(0, "보스방이 열렸습니다.");

                Monster* boss = stage.GetBoss();

                Battle bossBattle(player, boss, &inventory);
                bossBattle.StartBattle();

                // 보스를 죽였는지 확인
                if (!boss->getAlive())
                {
                    ClearStoryArea();

                    PrintStory(0, "보스를 처치했습니다!");
                    PrintStory(1, "다음 스테이지로 이동합니다.");

                    WaitForEnter();

                    bossDefeated = true;
                    stageLevel++;
                }
                break;
            }

            case 6:
            {
                if (!unlockImoogi)
                {
                    ClearStoryArea();
                    PrintStory(0, "게임을 종료합니다.");
                    return;
                }

                ClearStoryArea();
                PrintStory(0, "봉인된 여의주가 반응한다...");
                PrintStory(1, "천년을 기다린 이무기가 모습을 드러낸다!");

                Imoogi* imoogi = new Imoogi();

                Battle imoogiBattle(player, imoogi, &inventory);

                imoogiBattle.StartBattle();

                if (!imoogi->getAlive())
                {
                    ClearStoryArea();
                    PrintStory(0, "전설의 이무기를 쓰러뜨렸다!");
                    PrintStory(1, "진정한 여의주를 손에 넣었다...");

                    inventory.removeItem("봉인된 여의주");

                    Item* trueOrb = new Item( "진정한 여의주", ItemType::Quest, 9999, 0);


                    inventory.addItem(trueOrb);

                    trueEnding = true;

                    ClearStoryArea();
                    PrintStory(0, "축하합니다! 진엔딩을 달성했습니다.");

                    WaitForEnter();

                    delete imoogi;
                    return;
                }
                else
                {
                    ClearStoryArea();
                    PrintStory(0, "이무기는 당신을 삼켰다...");
                    PrintStory(1, "게임 오버");

                    delete imoogi;
                    return;
                }


                delete imoogi;

                break;
            }

            case 7:
            {
                ClearStoryArea();
                PrintStory(0, "게임을 종료합니다.");
                return;
            }

            default:
                ClearStoryArea();
                PrintStory(0, "잘못된 입력입니다.");
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
        ClearStoryArea();
        PrintStory(0, "플레이어 생성 실패");
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