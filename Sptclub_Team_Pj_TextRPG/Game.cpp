#include "Game.h"
#include "Player.h"
#include "Title.h"
#include <cstdlib>
#include <iostream>


void StartGame(Character& player)
{
    std::cout << "\n";
    std::cout << player.getName() << "(" << player.getJob() << ")의 이야기가 시작됩니다...\n";
    std::cout << "(게임 내용 준비 중)\n";
}

void DrawGameFrame()
{
    system("cls");

    // ========================================
    // 전체 프레임
    // ========================================

    // 맨 위
    GotoXY(0, 0);
    std::cout << "+";
    for (int x = 1; x < 119; x++)
    {
        std::cout << "-";
    }
    std::cout << "+";

    // 세로 테두리
    for (int y = 1; y < 39; y++)
    {
        GotoXY(0, y);
        std::cout << "|";

        GotoXY(119, y);
        std::cout << "|";
    }

    // ========================================
    // HP / MP 영역 끝
    // ========================================

    GotoXY(0, 3);
    std::cout << "+";
    for (int x = 1; x < 119; x++)
    {
        std::cout << "-";
    }
    std::cout << "+";

    // ========================================
    // 메인 화면 끝
    // ========================================

    GotoXY(0, 22);
    std::cout << "+";
    for (int x = 1; x < 119; x++)
    {
        std::cout << "-";
    }
    std::cout << "+";

    // ========================================
    // 메뉴 영역 끝
    // ========================================

    GotoXY(0, 26);
    std::cout << "+";
    for (int x = 1; x < 119; x++)
    {
        std::cout << "-";
    }
    std::cout << "+";

    // ========================================
    // 아래쪽
    // ========================================

    GotoXY(0, 39);
    std::cout << "+";
    for (int x = 1; x < 119; x++)
    {
        std::cout << "-";
    }
    std::cout << "+";

    // ========================================
    // 제목
    // ========================================

    GotoXY(53, 1);
    std::cout << "환 요 전";
}

/*
void DrawPlayerHUD(Player* player)
{
    if (player == nullptr)
        return;

    GotoXY(4, 0);

    int maxHp = player->getMaxHp();
    int hp = player->getHp();

    int maxMp = player->getMaxMp();
    int mp = player->getMp();

    const int barLength = 20;

    int hpBar = (hp * barLength) / maxHp;
    int mpBar = (mp * barLength) / maxMp;

    std::cout << "HP [";

    for (int i = 0; i < barLength; i++)
    {
        if (i < hpBar)
            std::cout << "#";
        else
            std::cout << "-";
    }

    std::cout << "] " << hp << " / " << maxHp;

    GotoXY(4, 1);

    std::cout << "MP [";

    for (int i = 0; i < barLength; i++)
    {
        if (i < mpBar)
            std::cout << "#";
        else
            std::cout << "-";
    }

    std::cout << "] " << mp << " / " << maxMp;
}
*/
void ClearGameMenu()
{
    for (int y = 23; y < 26; y++)
    {
        GotoXY(1, y);
        std::cout << std::string(118, ' ');
    }
}