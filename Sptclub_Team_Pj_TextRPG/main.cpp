#include "Character.h"
#include "Menu.h"
#include "Title.h"
#include "Player.h"
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
#include "WeaponManager.h"
#include <iostream>

void stageStartFunc(int stageLevel, Player* player, Inventory& inventory, WeaponManager& weaponManager)
{

    WeaponItem* weapon = new WeaponItem(weaponManager.CreateWeaponForJob(player->getJob()));
    switch (stageLevel)
    {
    case 1:
        cout << "주막에서 술을 마시고 있는 중 소란이 나서 고개를 돌려보니" << endl;
        cout << "도적들이 쳐들어와 주막에서 행패를 부린다" << endl;
        cout << "저 자식들 심심했는데 잘걸렸다 그러면 건방진 놈들 혼좀 내러 가보실까!" << endl;
        cout << "적 : 도적, 취객, 걸귀" << endl;
        break;
    case 2:
        cout << "술집에서의 소란을 정리하니 어떤 남자가 나를 부른다" << endl;
        cout << "누구지? 잠깐.. 저...저..저..전하???????????????????" << endl;
        cout << "전하께서 내가 싸우시는 모습이 인상깊으셨다고 한다 " << endl;
        cout << "그래서 비밀 지령을 맡겨주신다는데 전하를 암살하려는 것들이 기승을 부리기에 그걸 조사해 달라고하신다" << endl;
        cout << "어명이라 어기면 내가 큰일날거같아서 고개를 끄덕이고 궁궐로 향하는 산길을 올라간다" << endl;
        cout << "잠깐만... 전하께서 무기를 주신다 감사히 받자" << endl;
        inventory.addItem(weapon);
        cout << "플레이어는 전하에게서 " << weapon->GetName() << "을 하사받았다" << endl;
        cout << "적 : 도깨비, 구미호, 창귀" << endl;
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

void mainloop(Player* player, Inventory& inventory)
{
    system("cls");
    int switchNum;
	int stageLevel = 1;
	bool bossDefeated = false;
    PotionWorkshop workshop;
	WeaponManager weaponManager;
	workshop.AddDefaultRecipes();
    while (true)
    {
		stageStartFunc(stageLevel, player, inventory, weaponManager);
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
                player->showStatus();
                break;

            case 3:
                system("cls");
                inventory.showInventory();
                break;
            
            case 4:
                system("cls");
                workshop.RunMenu(inventory);
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
    player->addExp(700);

    player->levelUp();

    std::cout << "\n===== 전직 테스트 =====" << std::endl;
    std::cout << "현재 레벨 : " << player->getLevel() << std::endl;
    std::cout << "현재 직업 : " << player->getJob() << std::endl;

    player->applyRace();
    player->applyType();

    // 게임 시작
    mainloop(player, inventory);

    // Player 소멸자가 virtual이므로 안전
    delete player;

    return 0;
}