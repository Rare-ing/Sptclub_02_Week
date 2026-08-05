#include "GameUI.h"
#include "Game.h"
#include "Title.h"

#include <iostream>
#include <vector>
#include <conio.h>
#include <limits>

using namespace std;


// 기존 코드 호환용
vector<string> logs;
// =====================================
// 스토리 영역 삭제
// =====================================

void ClearStoryArea()
{
    for (int y = 9; y <= 31; y++)
    {
        GotoXY(1, y);

        cout << string(118, ' ');
    }
}
// =====================================
// 스토리 출력
// =====================================

void PrintStory(int line, const string& text)
{
    int y = 11 + line;

    // 스토리 영역을 벗어나면 출력하지 않음
    if (y > 31)
        return;

    GotoXY(4, y);
    cout << string(100, ' ');

    GotoXY(4, y);
    cout << text;
}

void AddLog(const string& text)
{
    logs.push_back(text);


    if (logs.size() > 5)
    {
        logs.erase(logs.begin());
    }
}
void DrawLog()
{
    // 로그칸 삭제했으므로 아무것도 안함
}
// =====================================
// 선택 영역 삭제
// =====================================

void ClearChoiceArea()
{
    for (int y = 33; y <= 36; y++)
    {
        GotoXY(1, y);

        cout << string(118, ' ');
    }
}
// =====================================
// 메인 메뉴
// =====================================

void DrawMainMenu(bool unlockImoogi)
{
    ClearChoiceArea();


    GotoXY(4, 33);
    cout << "1. 길을 걸어간다";


    GotoXY(25, 33);
    cout << "2. 스테이터스";


    GotoXY(50, 33);
    cout << "3. 인벤토리";


    GotoXY(75, 33);
    cout << "4. 영약방";


    GotoXY(95, 33);
    cout << "5. 보스 도전";



    if (unlockImoogi)
    {
        GotoXY(4, 34);
        cout << "6. 봉인된 여의주 해방";


        GotoXY(60, 34);
        cout << "7. 종료";
    }
    else
    {
        GotoXY(4, 34);
        cout << "6. 종료";
    }
}
// =====================================
// 전투 메뉴
// =====================================
void DrawBattleMenu()
{
    ClearChoiceArea();


    GotoXY(4, 33);
    cout << "1. 공격";


    GotoXY(25, 33);
    cout << "2. 스킬";


    GotoXY(50, 33);
    cout << "3. 행낭";
}
// =====================================
// 입력칸
// =====================================
void DrawInputArea()
{
    GotoXY(4, 38);

    cout << string(114, ' ');

    GotoXY(4, 38);
    cout << "입력 : ";
}
void InputCursor()
{
    GotoXY(12, 38);
}
// =====================================
// 엔터 대기
// =====================================

void WaitForEnter()
{
    DrawInputArea();
    InputCursor();

    std::string input;
    std::getline(std::cin, input);
}
void WaitForScript()
{
    GotoXY(20, 30);
    cout << "아무키나 입력";

    _getch();
}
void PlayScript(const std::vector<std::string>& lines)
{
    for (const std::string& line : lines)
    {
        system("cls");

        GotoXY(20, 10);
        cout << line;

        WaitForScript();
    }

    DrawGameFrame();
}
int GetInput()
{
    string input;

    getline(cin, input);


    // 아무것도 입력하지 않고 엔터
    if (input.empty())
    {
        return -1;
    }
    try
    {
        return stoi(input);
    }
    catch (...)
    {
        return -1;
    }
}

void DrawChoice(const string& text)
{
    ClearChoiceArea();

    GotoXY(4, 33);

    cout << text;
}

void ClearPotionArea()
{
    for (int y = 10; y <= 31; y++)
    {
        GotoXY(1, y);
        cout << string(118, ' ');
    }
}


void DrawPotionWorkshopMenu()
{
    ClearChoiceArea();

    GotoXY(4, 33);
    cout << "번호 입력하여 영약을 조제 하십시오";

    GotoXY(55, 33);
    cout << "특수 제작";

    GotoXY(80, 33);
    cout << "0. 약선방 나가기";
}

void ClearInventoryArea()
{
    for (int y = 10; y <= 31; y++)
    {
        GotoXY(1, y);

        cout << string(118, ' ');
    }
}


void DrawInventoryMenu()
{
    ClearChoiceArea();

    GotoXY(4, 33);
    cout << "1. 행낭 확인";

    GotoXY(25, 33);
    cout << "2. 이름으로 검색";

    GotoXY(50, 33);
    cout << "3. 단약 사용";

    GotoXY(75, 33);
    cout << "0. 행낭 나가기";
}