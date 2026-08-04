#include "PlayerHud.h"
#include "Player.h"

#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

namespace
{
    const int HudX = 1;
    const int HudY = 1;
    const int HudWidth = 44;   // 테두리 포함 전체 폭
    const int HudHeight = 6;   // 테두리 포함 전체 높이
    const int BarWidth = 20;

    void HudGotoXY(int x, int y)
    {
        COORD pos;
        pos.X = static_cast<SHORT>(x);
        pos.Y = static_cast<SHORT>(y);

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    }

    void HudSetColor(int color)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(color));
    }

    // 다음 화면 출력과 겹치지 않도록 HUD 영역 전체를 공백으로 지운다.
    void ClearHudRegion()
    {
        HudSetColor(15);

        for (int row = 0; row < HudHeight; row++)
        {
            HudGotoXY(HudX, HudY + row);
            cout << string(HudWidth, ' ');
        }
    }

    void DrawBorder(int y)
    {
        HudGotoXY(HudX, y);
        cout << "+" << string(HudWidth - 2, '-') << "+";
    }

    // 한글 표시 폭 문제 때문에 오른쪽 테두리는 맞추지 않고 왼쪽만 그린다.
    void PrintRow(int y, const string& content)
    {
        HudGotoXY(HudX, y);
        cout << "| " << content;
    }

    int GetHpBarColor(int current, int max)
    {
        if (max <= 0)
        {
            return 8;
        }

        float ratio = static_cast<float>(current) / static_cast<float>(max);

        if (ratio >= 0.5f)
        {
            return 10; // 초록
        }

        if (ratio >= 0.2f)
        {
            return 14; // 노랑
        }

        return 12; // 빨강
    }

    void DrawStatBar(int y, const string& label, int current, int max, int barColor)
    {
        int safeMax = (max <= 0) ? 1 : max;

        int filled = static_cast<int>(static_cast<float>(current) / safeMax * BarWidth);

        if (filled < 0)
        {
            filled = 0;
        }

        if (filled > BarWidth)
        {
            filled = BarWidth;
        }

        PrintRow(y, label + " [");

        HudSetColor(barColor);
        cout << string(filled, '#');

        HudSetColor(8);
        cout << string(BarWidth - filled, '-');

        HudSetColor(15);
        cout << "] " << current << "/" << max;
    }
}

void DrawPlayerHUD(Player* player)
{
    if (player == nullptr)
    {
        return;
    }

    // 전투 로그를 이어 찍는 도중에 호출될 수 있으므로,
    // 그리기 전 커서 위치를 저장해뒀다가 끝나고 그대로 복원한다.
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    COORD savedPos = info.dwCursorPosition;

    ClearHudRegion();
    HudSetColor(15);

    DrawBorder(HudY);

    PrintRow(HudY + 1, player->getName() + " (Lv." + to_string(player->getLevel()) + ")");

    DrawStatBar(HudY + 2, "HP", player->getHp(), player->getMaxHp(), GetHpBarColor(player->getHp(), player->getMaxHp()));

    DrawStatBar(HudY + 3, "MP", player->getMp(), player->getMaxMp(), 9);

    PrintRow(HudY + 4, "ATK:" + to_string(player->getAttack()) + "  DEF:" + to_string(player->getDefence()) + "  GOLD:" + to_string(player->getGold()));

    DrawBorder(HudY + 5);

    HudSetColor(15);

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), savedPos);
}

void MoveCursorBelowPlayerHUD()
{
    HudGotoXY(HudX, HudY + HudHeight + 1);
}
