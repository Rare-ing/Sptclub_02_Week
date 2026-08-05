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

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>


void stageStartFunc(int stageLevel, Player* player, Inventory& inventory, WeaponManager& weaponManager)
{
    ClearStoryArea();
    //WeaponItem* weapon = new WeaponItem(weaponManager.CreateWeaponForJob(player->getJob())); 우선 메모리 누수 이슈로 주석처리합니다.-준우
    switch (stageLevel)
    {
    case 1:
        PrintStory(0, "주막에서 술을 마시던 중 소란이 나서 고개를 돌려보니");
        PrintStory(1, "도적들이 쳐들어와 주막에서 행패를 부리고 있었다.");
        PrintStory(2, "식사 중에 소란은 달갑지 않은데 말이지..");
        PrintStory(3, "적 : 뭐? 어디서 분위기를 잡고있어! 야 저 자식 꿇려!");
        break;
    case 2:
    {
        // ==============================
        // 1스테이지 클리어 후 스토리
        // ==============================

        ClearStoryArea();

        PrintStory(0, "소란이 가라앉았다.");
        PrintStory(1, "주인공이 칼을 거두려는 순간,");
        PrintStory(2, "저 멀리서 한 사내가 천천히 다가왔다.");
        PrintStory(3, "평범한 행색이었다.");

        WaitForEnter();

        ClearStoryArea();

        PrintStory(0, "그러나 그 눈빛만큼은 범상치 않았다.");
        PrintStory(1, "??: 제법이구나.");
        PrintStory(2, "주인공: 누구시오?");
        PrintStory(3, "잠시 정적이 흘렀다.");

        WaitForEnter();

        ClearStoryArea();

        PrintStory(0, "======= 1스테이지 클리어! =======");
        PrintStory(1, "?? : 그보다 먼저 묻지.");
        PrintStory(2, "저들이 왜 칼을 들었는지 알고 있는가?");
        PrintStory(3, "주인공 : ...굶주림 때문이겠지.");

        WaitForEnter();

        // ==============================
        // 다음 장면
        // ==============================

        ClearStoryArea();

        PrintStory(0, "맞다.");
        PrintStory(1, "지금 조선은 굶주리고 있다.");
        PrintStory(2, " 흉년이 들었고, 괴질이 퍼졌다.");
        PrintStory(3, "그런데 그것만이 문제가 아니다.");

        WaitForEnter();

        // ==============================
        // 요괴에 대한 이야기
        // ==============================

        ClearStoryArea();

        PrintStory(0, "최근 들어 산과 들에서 요괴들이 나타나기 시작했다.");
        PrintStory(1, "백성들은 이미 공포에 질려 있다.");

        WaitForEnter();

        // ==============================
        // 정조의 부탁
        // ==============================

        ClearStoryArea();

        PrintStory(0, "정조 : 나는 조선의 정당한 임금으로");
        PrintStory(1, "민간의 상황을 직접 살피고 있다.");
        PrintStory(2, "정조 : 그리고 그대에게 부탁할 일이 있다.");
        PrintStory(3, "정조 : 도와줄 수 있겠는가?");

        WaitForEnter();

        // ==============================
        // 선택지
        // ==============================

        ClearStoryArea();

        PrintStory(0, "정조 : 도와줄 수 있겠는가?");

        GotoXY(4, 33);
        cout << "1. 돕겠습니다.";

        GotoXY(40, 33);
        cout << "2. 무슨 일인지 먼저 듣고 싶소.";

        DrawInputArea();
        InputCursor();

        int choice = GetInput();

        ClearChoiceArea();

        // 선택 결과
        if (choice == 1)
        {
            ClearStoryArea();
            PrintStory(0, "주인공 : 돕겠습니다.");
            WaitForEnter();
        }
        else if (choice == 2)
        {
            ClearStoryArea();
            PrintStory(0, "주인공 : 무슨 일인지 먼저 듣고 싶소.");
            WaitForEnter();
        }
        else
        {
            ClearStoryArea();
            PrintStory(0, "잘못된 선택입니다.");
            WaitForEnter();
        }

        // ==============================
        // 첫 번째 의뢰
        // ==============================

        ClearStoryArea();

        PrintStory(0, "정조 : 좋다.");
        PrintStory(1, "정조 : 첫 번째 의뢰다.");
        PrintStory(2, "정조 : 장산에서 요괴들이 창궐하고 있다는 보고가 들어왔다.");
        PrintStory(3, "정조 : 산으로 들어가 요괴들을 토벌하고,");
        PrintStory(4, "무슨 일이 벌어지고 있는지 확인해주게.");

        WaitForEnter();

        // ==============================
        // 주인공의 대답
        // ==============================

        ClearStoryArea();

        PrintStory(0, "주인공 : 알겠소.");
        PrintStory(1, "정조 : 이것은 그대에게 주는 지원품이다.");

        WaitForEnter();

        // ==============================
        // 지원품 지급
        // ==============================

        ClearStoryArea();

        PrintStory(0, "[ 약초 획득 ]");
        PrintStory(1, "[ 직업별 무기 획득 ]");

        WaitForEnter();

        // ==============================
        // 마지막 당부
        // ==============================

        ClearStoryArea();

        PrintStory(0, "주인공은 장산으로 향했다.");
        PrintStory(1, "[그곳에서 기다리고 있는 것이 무엇인지,]");
        PrintStory(2, "아직 아무도 알지 못했다.");

        WaitForEnter();


        ClearStoryArea();

        PrintStory(0, "정조 : 부디 조심하게.");
        PrintStory(1, "정조 : 이번 일은 단순한 요괴 퇴치가 아닐지도 모르니.");

        WaitForEnter();
    }
    break;
    case 3:
    {
        const std::vector<std::string> stage2Script =
        {
            "[ 한양 ]",
            "한양에 돌아온 주인공은",
            "곧바로 궁궐로 향했다.",
            "그러나 궁궐의 모습은 이상했다.",
            "비명.",
            "칼부림.",
            "그리고 피.",
            "주인공:",
            "\"...무슨 일이 벌어진 거지?\"",
            "내관들은 이성을 잃고 있었다.",
            "신하들은 서로에게 칼을 겨누고 있었다.",
            "그리고 궁궐을 지키던 시위군들의 모습까지 보였다.",
            "하지만...",
            "그들은 이미 오래전에 죽은 자들이었다."
        };

        PlayScript(stage2Script);

        break;
    }
    case 4:
    {
        const std::vector<std::string> stage3StartScript =
        {
            "남양도호부.",
            "그러나 이곳에는 더 이상 사람이 살아가는 흔적조차 남아있지 않았다.",
            "논밭은 말라붙었다.",
            "우물은 바닥을 드러냈다.",
            "나무에는 잎 하나 남아있지 않았다.",
            "그리고...",
            "땅 위에는 수많은 발자국이 남아 있었다.",
            "사람의 것이 아니었다.",
            "명계의 존재들까지 인간계에 모습을 드러내고 있었다.",
            "금서에 기록된 이야기가 사실이라면...",
            "이 모든 재앙은 하나의 존재와 연결되어 있었다."
        };

        PlayScript(stage3StartScript);

        break;
    }

}   

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

                WaitForEnter();

                // ==============================
                // 보스 입장 스크립트
                // ==============================

                if (stageLevel == 1)
                {
                    const std::vector<std::string> bossScript =
                    {
                        "주막을 습격했던 도적들을 따라가다 보니",
                        "산길 깊은 곳에 숨겨진 소굴이 나타났다.",
                        "그곳에서 도적들을 이끌던 자가 모습을 드러냈다.",
                        "그의 손에는 피 묻은 칼이 들려 있었다.",
                        "도적 두목이 나타났다."
                    };

                    PlayScript(bossScript);
                }
                else if (stageLevel == 2)
                {
                    const std::vector<std::string> bossScript =
                    {
                        "장산의 가장 깊은 곳.",
                        "산길을 따라 들어갈수록 기이한 울음소리가 들려왔다.",
                        "그리고 어둠 속에서 무언가가 모습을 드러냈다.",
                        "사람의 목소리를 흉내 내는 괴수.",
                        "장산범이 나타났다."
                    };

                    PlayScript(bossScript);
                }
                else if (stageLevel == 3)
                {
                    const std::vector<std::string> bossScript =
                    {
                        "궁궐 깊숙한 곳.",
                        "아무도 들어가지 않는 오래된 공간에서",
                        "차가운 기운이 흘러나오고 있었다.",
                        "그리고 어둠 속에서 한 맺힌 목소리가 들려왔다.",
                        "뒤주의 망령이 모습을 드러냈다."
                    };

                    PlayScript(bossScript);
                }
                else if (stageLevel == 4)
                {
                    const std::vector<std::string> bossScript =
                    {
                        "남양도호부 깊숙한 곳.",
                        "금서에 기록된 장소에 도착했다.",
                        "주변의 공기가 무겁게 가라앉았다.",
                        "그리고 검은 기운이 땅을 뒤덮기 시작했다.",
                        "모든 재앙의 근원이 모습을 드러냈다."
                    };

                    PlayScript(bossScript);
                }

                // ==============================
                // 보스 생성 및 전투
                // ==============================

                Monster* boss = stage.GetBoss();

                Battle bossBattle(player, boss, &inventory);
                bossBattle.StartBattle();

                // ==============================
                // 보스 처치 확인
                // ==============================

                if (!boss->getAlive())
                {
                    ClearStoryArea();

                    if (stageLevel == 1)
                    {
                        // 1스테이지 클리어
                        PrintStory(0, "도적 두목이 쓰러졌다.");
                        PrintStory(1, "주막을 습격했던 도적들도");
                        PrintStory(2, "더 이상 움직이지 않았다.");
                        PrintStory(3, "그러나 주인공은 이상한 점을 발견했다.");
                        PrintStory(4, "도적들은 단순히 약탈을 위해 움직인 것이 아니었다.");
                        PrintStory(5, "주인공: \"...굶주림 때문인가.\"");
                        PrintStory(6, "주인공은 이 사건의 뒤에 더 큰 일이 있음을 느꼈다.");
                    }
                    else if (stageLevel == 2)
                    {
                        // 2스테이지 클리어
                        PrintStory(0, "장산범이 쓰러졌다.");
                        PrintStory(1, "산을 뒤덮고 있던 괴이한 기운도");
                        PrintStory(2, "조금씩 사라지기 시작했다.");
                        PrintStory(3, "그러나 주인공은 알 수 있었다.");
                        PrintStory(4, "이것은 시작에 불과하다는 것을.");
                        PrintStory(5, "주인공: \"임금께 보고해야 한다.\"");
                        PrintStory(6, "주인공은 다시 한양으로 향했다.");
                    }
                    else if (stageLevel == 3)
                    {
                        // 3스테이지 클리어
                        PrintStory(0, "사도세자의 원혼이 사라졌다.");
                        PrintStory(1, "궁궐을 뒤덮었던 원한도");
                        PrintStory(2, "조금씩 가라앉기 시작했다.");
                        PrintStory(3, "그러나 정조의 표정은 여전히 굳어 있었다.");

                        WaitForEnter();

                        ClearStoryArea();

                        PrintStory(0, "주인공: \"전하. 아직 끝난 것이 아닙니까?\"");
                        PrintStory(1, "정조: \"아니다.\"");
                        PrintStory(2, "정조: \"오히려 이제부터가 시작일지도 모른다.\"");

                        WaitForEnter();

                        ClearStoryArea();

                        PrintStory(0, "정조: \"사도세자의 원한이 어째서 지금 깨어났는지 알아야 한다.\"");
                        PrintStory(1, "정조: \"그리고 나는 그 답이 오래된 기록 속에 있다고 생각한다.\"");

                        WaitForEnter();

                        ClearStoryArea();

                        PrintStory(0, "[ 정조가 금서를 꺼낸다 ]");
                        PrintStory(1, "정조: \"조선 왕실의 비사가 기록된 금서다.\"");
                        PrintStory(2, "정조: \"이 기록에 따르면 남양도호부에\"");
                        PrintStory(3, "정조: \"오래된 비밀 장소가 하나 있다고 한다.\"");

                        WaitForEnter();

                        ClearStoryArea();

                        PrintStory(0, "정조: \"이것을 가지고 가게.\"");
                        PrintStory(1, "[ 비밀지도 획득 ]");
                        PrintStory(2, "정조: \"그곳에서 모든 사건의 원인을 찾아보게.\"");
                        PrintStory(3, "주인공: \"알겠습니다.\"");
                        PrintStory(4, "정조: \"...그리고 반드시 살아 돌아오게.\"");

                        WaitForEnter();

                        ClearStoryArea();

                        PrintStory(0, "주인공은 금서와 지도를 챙겼다.");
                    }
                    else if (stageLevel == 4)
                    {
                        // 4스테이지 클리어
                        PrintStory(0, "모든 재앙의 근원이 무너졌다.");
                        PrintStory(1, "남양도호부를 뒤덮었던 검은 기운이");
                        PrintStory(2, "천천히 사라지기 시작했다.");
                        PrintStory(3, "긴 싸움이 끝난 듯 보였다.");

                        WaitForEnter();

                        ClearStoryArea();

                        PrintStory(0, "그러나...");
                        PrintStory(1, "주인공은 금서의 마지막 장을 떠올렸다.");
                        PrintStory(2, "그곳에는 아직 읽지 못한 기록이 남아 있었다.");
                        PrintStory(3, "그리고 그 기록에는");
                        PrintStory(4, "마지막 재앙보다 더 오래된 존재가 적혀 있었다.");

                        WaitForEnter();

                        ClearStoryArea();

                        PrintStory(0, "주인공: \"설마... 이것까지 사실이라면.\"");
                        PrintStory(1, "모든 사건의 끝에서");
                        PrintStory(2, "또 다른 전설이 모습을 드러내고 있었다.");
                    }
                    else
                    {
                        PrintStory(0, "최종 재앙이 쓰러졌다.");
                        PrintStory(1, "조선을 뒤덮었던 재앙의 기운이");
                        PrintStory(2, "서서히 사라지기 시작했다.");

                        WaitForEnter();

                        ClearStoryArea();

                        PrintStory(0, "그러나...");
                        PrintStory(1, "모든 것이 끝난 것은 아니었다.");
                        PrintStory(2, "주인공은 금서에 적힌 마지막 기록을 떠올렸다.");

                        WaitForEnter();

                        ClearStoryArea();

                        PrintStory(0, "주인공: \"아직 남은 것이 있는 건가...\"");

                        WaitForEnter();

                        ClearStoryArea();

                        PrintStory(0, "긴 싸움 끝에");
                        PrintStory(1, "조선에 드리웠던 재앙은 막을 내렸다.");
                        PrintStory(2, "그러나 그날의 진실은");
                        PrintStory(3, "오래도록 사람들의 기억 속에 남았다.");

                        WaitForEnter();

                        ClearStoryArea();

                        PrintStory(0, "=== 진엔딩의 조건을 확인할 수 있다. ===");
                    }

                    WaitForEnter();

                    bossDefeated = true;

                    if (stageLevel < 4)
                    {
                        stageLevel++;
                    }
                    else
                    {
                        // 4스테이지 최종보스 클리어 → 일반 엔딩
                        ClearStoryArea();

                        PrintStory(0, "모든 재앙의 근원이 사라졌다.");
                        PrintStory(1, "긴 싸움이 끝났다.");
                        PrintStory(2, "주인공은 천천히 한양을 향해 걸음을 옮겼다.");

                        WaitForEnter();

                        ClearStoryArea();

                        PrintStory(0, "한양에 돌아온 주인공은 정조에게 모든 일을 보고했다.");
                        PrintStory(1, "정조: \"수고했네.\"");
                        PrintStory(2, "정조: \"이제 백성들이 다시 평온을 되찾을 수 있겠군.\"");

                        WaitForEnter();

                        ClearStoryArea();

                        PrintStory(0, "그러나 주인공은 문득 하늘을 올려다보았다.");
                        PrintStory(1, "아직 무언가가 남아 있는 듯한 기분이 들었다.");
                        PrintStory(2, "하지만 그것이 무엇인지는 알 수 없었다.");

                        WaitForEnter();

                        ClearStoryArea();

                        PrintStory(0, "긴 재앙은 끝났다.");
                        PrintStory(1, "그리고 조선에는 다시 평온한 날이 찾아왔다.");
                        PrintStory(2, "================================");
                        PrintStory(3, "          일반 엔딩");
                        PrintStory(4, "================================");

                        WaitForEnter();

                        return;
                    }
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

                    PrintStory(0, "이무기의 거대한 몸이 천천히 무너졌다.");
                    PrintStory(1, "천년 동안 이어져 온 봉인이 완전히 풀렸다.");
                    PrintStory(2, "그리고 이무기의 몸에서 눈부신 빛이 흘러나왔다.");

                    WaitForEnter();

                    ClearStoryArea();

                    PrintStory(0, "주인공: \"이것이... 진정한 여의주인가?\"");
                    PrintStory(1, "손에 들어온 여의주에서는");
                    PrintStory(2, "이전에 느껴보지 못한 강력한 기운이 느껴졌다.");

                    WaitForEnter();

                    ClearStoryArea();

                    PrintStory(0, "[ 진정한 여의주 획득 ]");

                    inventory.removeItem("봉인된 여의주");

                    Item* trueOrb = new Item(
                        "진정한 여의주",
                        ItemType::Quest,
                        9999,
                        0
                    );

                    inventory.addItem(trueOrb);

                    trueEnding = true;

                    WaitForEnter();

                    ClearStoryArea();

                    PrintStory(0, "주인공은 진정한 여의주를 품에 넣고");
                    PrintStory(1, "다시 한양으로 향했다.");

                    WaitForEnter();

                    ClearStoryArea();

                    PrintStory(0, "궁궐에 돌아온 주인공은");
                    PrintStory(1, "정조에게 모든 사건의 진실을 보고했다.");

                    WaitForEnter();

                    ClearStoryArea();

                    PrintStory(0, "정조: \"그래... 결국 모든 재앙의 근원은\"");
                    PrintStory(1, "정조: \"이 여의주와 연결되어 있었던 것이군.\"");

                    WaitForEnter();

                    ClearStoryArea();

                    PrintStory(0, "정조: \"수고했네.\"");
                    PrintStory(1, "정조: \"그대가 조선을 구했구나.\"");

                    WaitForEnter();

                    ClearStoryArea();

                    PrintStory(0, "긴 재앙이 끝났다.");
                    PrintStory(1, "그리고 조선에는 다시 평온이 찾아왔다.");

                    WaitForEnter();

                    ClearStoryArea();

                    PrintStory(0, "================================");
                    PrintStory(1, "          진 엔딩");
                    PrintStory(2, "================================");
                    PrintStory(3, "모든 조건을 달성하고");
                    PrintStory(4, "재앙의 진실까지 밝혀냈습니다.");

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