#include "MonsterHud.h"
#include "Monster.h"

#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

namespace
{
    const int HudX = 76;          // 오른쪽 위치
    const int HudY = 3;
    const int HudWidth = 44;
    const int HudHeight = 6;
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
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
            static_cast<WORD>(color));
    }

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

    void PrintRow(int y, const string& content)
    {
        HudGotoXY(HudX, y);
        cout << "| " << content;
    }

    int GetHpBarColor(int current, int max)
    {
        if (max <= 0)
            return 8;

        float ratio = static_cast<float>(current) / max;

        if (ratio >= 0.5f)
            return 10;

        if (ratio >= 0.2f)
            return 14;

        return 12;
    }

    void DrawStatBar(int y,
        const string& label,
        int current,
        int max,
        int barColor)
    {
        int safeMax = (max <= 0) ? 1 : max;

        int filled =
            static_cast<int>(
                static_cast<float>(current)
                / safeMax
                * BarWidth);

        if (filled < 0)
            filled = 0;

        if (filled > BarWidth)
            filled = BarWidth;

        PrintRow(y, label + " [");

        HudSetColor(barColor);
        cout << string(filled, '#');

        HudSetColor(8);
        cout << string(BarWidth - filled, '-');

        HudSetColor(15);

        cout << "] "
            << current
            << "/"
            << max;
    }
}

void DrawMonsterHUD(Monster* monster)
{
    ClearHudRegion();

    HudSetColor(15);

    DrawBorder(HudY);

    if (monster == nullptr)
    {
        DrawBorder(HudY + 5);
        return;
    }

    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(
        GetStdHandle(STD_OUTPUT_HANDLE),
        &info);

    COORD savedPos = info.dwCursorPosition;

    ClearHudRegion();

    HudSetColor(15);

    DrawBorder(HudY);

    PrintRow(
        HudY + 1,
        monster->getName() +
        " (Lv." +
        to_string(monster->getLevel()) +
        ")");

    DrawStatBar(
        HudY + 2,
        "HP",
        monster->getHp(),
        monster->getMaxHp(),
        GetHpBarColor(
            monster->getHp(),
            monster->getMaxHp()));

    PrintRow(
        HudY + 3,
        "ATK : " +
        to_string(monster->getPower()));

    PrintRow(
        HudY + 4,
        "DEF : " +
        to_string(monster->getDefence()));

    DrawBorder(HudY + 5);

    HudSetColor(15);

    // 필요하면 복원
    // SetConsoleCursorPosition(
    //     GetStdHandle(STD_OUTPUT_HANDLE),
    //     savedPos);
}
