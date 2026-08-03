#include "Title.h"
#include "AsciiArt.h"

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <cstdlib>
#include <ctime>

#pragma comment(lib,"winmm.lib")

using namespace std;

//이동
void GotoXY(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//커서 숨기기
void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor;

    cursor.dwSize = 1;
    cursor.bVisible = FALSE;

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

//커서 다시 보이기
void ShowCursor()
{
    CONSOLE_CURSOR_INFO cursor;

    cursor.dwSize = 25;
    cursor.bVisible = TRUE;

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

//색상
void SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//하늘
void DrawSky()
{
    SetColor(15);

    for (int i = 0; i < Art::SkyHeight; i++)
    {
        GotoXY(0, i);

        cout << Art::Sky[i];
    }
}

//산
void DrawMountain()
{
    for (int i = 0; i < Art::MountainHeight; i++)
    {
        GotoXY(0, 10 + i);

        cout << Art::Mountain[i];
    }
}

//로고 
const int LogoRow = 1;

void DrawLogo()
{
    SetColor(14);

    for (int i = 0; i < Art::LogoHeight; i++)
    {
        GotoXY(0, LogoRow + i);

        cout << Art::Logo[i];
    }

    SetColor(15);
}

void DrawBackground()
{
    system("cls");

    DrawSky();

    DrawMountain();

    DrawLogo();
}


const int WalkerRow = 17;          // 검사 
const int WalkerMountainIndex = 7; // 자리 지우기용 
const int FogRow = 21;             // Y좌표 
const int PathLeftX = 19;          // 산길 
const int PathRightX = 89;


//잔상제거
void EraseWalker()
{
    for (int i = 0; i < Art::ManHeight; i++)
    {
        GotoXY(0, 10 + WalkerMountainIndex + i);

        cout << Art::Mountain[WalkerMountainIndex + i];
    }
}

//검사
void DrawWalker(int x, int frame)
{
    SetColor(11);

    for (int i = 0; i < Art::ManHeight; i++)
    {
        GotoXY(x, WalkerRow + i);

        cout << Art::Walk[frame][i];
    }

    SetColor(15);
}

//안개
void DrawFog(int frame)
{
    SetColor(8);

    const std::string* fog = Art::Fog1;

    if (frame == 1)
    {
        fog = Art::Fog2;
    }
    else if (frame == 2)
    {
        fog = Art::Fog3;
    }

    for (int i = 0; i < Art::FogHeight; i++)
    {
        GotoXY(0, FogRow + i);

        cout << fog[i];
    }

    SetColor(15);
}

//별 
void DrawStars(int tick)
{
    SetColor(15);

    for (int i = 0; i < Art::StarCount; i++)
    {
        int y = Art::StarY[i];

        if (y >= LogoRow && y < LogoRow + Art::LogoHeight)
        {
            continue;
        }

        GotoXY(Art::StarX[i], y);

        bool on = ((tick + i * 3) % 6) < 3;

        cout << (on ? '*' : ' ');
    }
}

// 키 깜빡임
const int PressRow = 38;
const int PressCol = 35;

void DrawPressPrompt(int tick)
{
    SetColor(10);

    GotoXY(PressCol, PressRow);

    bool on = (tick % 6) < 3;

    if (on)
    {
        cout << Art::Press;
    }
    else
    {
        cout << string(Art::Press.length(), ' ');
    }

    SetColor(15);
}

//검사
void PlayIntroAnimation()
{
    srand((unsigned)time(nullptr));

    int x = PathLeftX;
    int walkFrame = 0;
    int fogFrame = 0;
    int tick = 0;

    while (!_kbhit())
    {
        EraseWalker();

        DrawFog(fogFrame);
        DrawStars(tick);
        DrawWalker(x, walkFrame);
        DrawPressPrompt(tick);

        Sleep(180);

        x++;

        if (x > PathRightX)
        {
            x = PathLeftX;
        }

        walkFrame = (walkFrame + 1) % 4;
        fogFrame = (fogFrame + 1) % 3;
        tick++;
    }

    _getch();
}

// 이름 입력 전 짧게 보여줄 스토리 한 줄감
const std::string StoryLine = "조용하던 산골 마을에 낯선 기운이 감돌기 시작했다...";
const std::string StoryPrompt = "아무키나 입력";

const int StoryRow = 19;
const int StoryPromptRow = StoryRow + 2;

void PlayStoryIntro()
{
    system("cls");

    SetColor(15);

    GotoXY(20, StoryRow);
    cout << StoryLine;

    SetColor(8);

    GotoXY(20, StoryPromptRow);
    cout << StoryPrompt;

    SetColor(15);

    while (!_kbhit())
    {
        Sleep(50);
    }

    _getch();

    system("cls");
}

void ShowTitle()
{
    // 콘솔
    system("mode con cols=120 lines=40");

    SetConsoleTitle(TEXT("환요전"));

    HideCursor();

    // BGM 재생
    PlaySound(TEXT("Title.wav"),
        NULL,
        SND_FILENAME | SND_ASYNC);

    // 배경 출력
    DrawBackground();

    // 애니메이션 (아무 키 입력 전까지 반복)
    PlayIntroAnimation();

    PlayStoryIntro();

    // 이름 입력 화면으로 넘어갈 준비
    GotoXY(0, 0);

    ShowCursor();
}
